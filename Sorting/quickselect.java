public static void swap(int[] data, int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

public static int partition(int[] data, int first, int last) {
	int pivot = data[first];
	int left = first, right = last;
	
	while (left < right)
	{
		// Search for an element bigger than the pivot from the left part
		while (data[left] <= pivot && left < right)
			left++;
		
		// Search for an element smaller than the pivot from the right part
		while (data[right] > pivot)
			right--;
		
		// Swap the two elements found
		if (left < right)
			swap(data, left, right);
	}
	
	// move the pivot element to its final position (in the middle)
	swap(data, first, right);
	return right;
}

public static int quickSelect(int[] data, int first, int last, int k) {
	if (first >= last)
		return first;
	
	int pivot = partition(data, first, last);
	
	int len = pivot - first;		// length of the left part
	
	if (len > k)
		return quickSelect(data, first, pivot - 1, k);

	if (len < k)
		return quickSelect(data, pivot + 1, last, k - len - 1);
	
	return pivot;
}