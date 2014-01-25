/*
 ** possible input: 
 ** (1) contains other characters not belong to 0~9
 ** (2) negative number
 ** (3) overflow and underflow
 */

int atoi(const char *str) {
    int j = 0;
    int temp[strlen(str)];
    long long num = 0, k = 1;
    int flag = 1;    
    
    while (*str && *str == ' ')
        str++;
    
    if (*str == '+')
        str++;
    else if (*str == '-') {
        str++;
        flag = -1;
    }
    
    while(*str) {
        if (isdigit(*str))
            temp[j++] = *str-'0';
        else
            break;
        str++;
    }
    
    for(j-=1; j>=0; j--) {
        num += temp[j]*k;
        k *= 10;
        if (num > INT32_MAX)
            break;
    }  
    
    if (num*flag > INT32_MAX)
        return INT32_MAX;
    else if (num*flag < INT32_MIN)
        return INT32_MIN;
    
    return (int)num*flag;
}


