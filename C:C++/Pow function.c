double pow2(double a, int n)
{
    if(n == 0)
        return 1;
    else
        return a*pow2(a, n-1);
}

double pow(double x, int n) {
    if(n == 0)
        return 1;
    else if(n < 0) {
        if(n == INT32_MIN)
            return 1/x*pow(1/x, -1*(n+1));
        else
            return pow(1/x, -1*n);
    }
    else if(n&1) {
        return x*pow(x, n-1);
    }
    else {
        double result = pow(x, n>>1);
        return result*result;
    }
}


