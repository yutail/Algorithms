// O(n^2)
int lis(int A[], int n) {
    int *d = new int[n];
    int len = 1;
    
    for (int i=0; i<n; i++) {
        d[i] = 1;
        for (int j=0; j<i; j++) {
            if (A[j] < A[i] && d[j]+1 > d[i])
                d[i] = d[j] + 1;
        }
        if (len < d[i])
            len = d[i];
    }
    delete[] d;
    return len;
}


// O(nlogn)
int lis(int A[], int n) {
    int *d = new int[n];
    int left, right;
    int len = 1;
    d[0] = A[0];
    
    for (int i=1; i<n; i++) {
        int left = 0;
        int right = len;
        while (left <= right) {   //二分查找d[i]的插入位置
            int mid = (left+right) / 2;
            if (d[mid] < A[i])
                left = mid + 1;
            else
                right = mid - 1;
        }
        d[left] = A[i];   //插入
        if (left > len) //d[i]比现有的所有数字都大，所以left才会大于len
            len++;
    }
    delete[] d;
    return len;
}

