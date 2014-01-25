void selectionSort(int A[], int lo, int hi) {
	int i;
	int index;
	for (i=lo; i<hi; i++) {
		index = getSmallest(A, i, hi);
		swap(A, i, index);
	}	
}

int getSmallest(int A[]; int lo; int hi) {
	int small;
	small = lo;
	for (int j=lo+1; j<=hi; i++)
		if(A[j] < A[small])
			small = j;

	return small;
} 

void swap(int A[]; int i, int j) {
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}


