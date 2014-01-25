void insertionSort(int A[]; int lo; int hi) {
	for (int i=lo+1; i<=hi; i++) {
		int valueToInsert = A[i];
        int k = i;
		while (k>lo && valueToInsert < A[k-1]) {
            A[k] = A[k-1];
            k--;
        }
        A[k] = valueToInsert;
    }
}

// Sort List
ListNode *insertionSort(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    ListNode *result = NULL;
    
    while (head != NULL) {
        ListNode *curr = head;
        head = head->next;
        
        if (result==NULL || result->val > curr->val) {
            curr->next = result;
            result = curr;
        }
        else {
            ListNode *temp = result;
            while (temp != NULL) {
                if (temp->next==NULL || temp->next->val > curr->val) {
                    curr->next = temp->next;
                    temp->next = curr;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    return result;
}

