// Iterative
int kthSmall(int A[], int k, int lo, int hi) {
    if (lo == hi)
        return A[lo];
    
    int pivotIndex = partition(A, lo, hi, lo);

    while (pivotIndex != k) {
        pivotIndex = partition(A, lo, hi, lo);
        if (k < pivotIndex)
            hi = pivotIndex - 1;
        else        
            lo = pivotIndex + 1;
    }
    return A[k];
}

int partition(int A[], int lo, int hi, int pivotIndex) {
    int pivot = A[pivotIndex];
    swap(A, hi, pivotIndex);  // Move pivot to end
    int last = lo, i;
    for (i=lo+1; i<=hi;i++) {
        if(A[i]<pivot)
        {
            last++;
            swap(A, last, i);
        }
    }
    swap(A, last, lo);    
    return last;
}

void swap(int list[], int i, int j) {
    int hold = list[i];
    list[i] = list[j];
    list[j] = hold;    
}



