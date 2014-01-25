void heapSort(int A[], int n) {

    heapify(A, n);

    for (int i=n-1; i>0; i--) {
		swap(A, 0, i);
		siftDown(A, 0, i-1);
    }    
}

void heapify(int A[], int n) {
    int start = (n-2) / 2;
    while (start >= 0) {
        siftDown(A, start, n-1);
        start--;
    }
}

void siftDown(int A[], int start, int end) {
    int root = start;
    
    while (2*root+1 <= end) {
        int child = 2*root + 1;
        int swap = root;
	    
        if (A[swap] < A[child])
            swap = child;
        if (child+1<=end && A[swap]<A[child+1])
            swap = child+1;
        if (swap != root) {
            swap(A, root, swap);
            root = swap;
        }
        else
            break;
    }
}

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
