// if there is no element found, then a[right] < target < a[left]
// right = -1, when target < a[0]; left = n, when target > a[n-1].

// iterative
int binarySearchIterative(int A[], int n, int target) {
    int left = 0;
    int right = n-1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] < target)
            left = mid+1;
        else if (A[mid] > target)
            right = mid-1;
        else
            return mid;
    }
    return -1;
}

// recursice
int binarySearchRecursive(int A[], int left, int right, int target) {
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    
    if (A[mid] < target)
        return binarySearchRecursive(A, mid+1, right, target);
    else if (A[mid] > target)
        return binarySearchRecursive(A, left, mid-1, target);
    else
        return mid;
}