// Dynamic Programming Time Complexity: O(n)
int maxSubSum(int A[], int n) {
    if (n <= 0)
        return 0;
    int *dp = new int[n];
    dp[0] = A[0];
    
    for (int i=1; i<n; i++) {
        dp[i] = max(dp[i-1]+A[i], A[i]);
    }
    int maxValue = INT_MIN;
    for (int k=0; k<n; k++) {
        maxValue = max(maxValue, dp[k]);
    }
    return maxValue;
}

// Divide and Conquer Time Complexity: O(nlogn)
int maxSubSum(int A[], int lo, int hi) {
    if (lo == hi)
        return A[lo];
    
    int mid = (lo + hi) / 2;
    int maxLeft = maxSubSum(A, lo, mid);
    int maxRight = maxSubSum(A, mid+1, hi);
    
    int maxCross;
    int sum = 0;
    int temp1=INT_MIN, temp2=INT_MIN;
    for (int i=mid+1; i<=hi; i++) {
        sum += A[i];
        if (sum > temp1)
            temp1 = sum;
    }
    sum = 0;
    for (int k=mid; k>=lo; k--) {
        sum += A[k];
        if (sum > temp2)
            temp2 = sum;
    }
    maxCross = temp1 + temp2;
    return max(maxCross, max(maxLeft, maxRight));
}

