// Divide and Conquer

void mergeSort(int A[], int lo, int hi) {
    if (lo<hi) {
        int mid = (lo+hi)/2;
        mergeSort(A, lo, mid);
        mergeSort(A, mid+1, hi);
        merge(A, lo, mid, hi);
    }
}

void merge(int A[], int lo, int mid, int hi) {
    
    int i=lo, j=mid+1, k=lo;
    while (i<=mid || j<=hi) {
        if (i>mid)
            T[k++] = A[j++];
        else if (j>hi)
            T[k++] = A[i++];
        else if (A[i]<A[j])
            T[k++] = A[i++];
        else
            T[k++] = A[j++];
    }
    for (j=lo; j<=hi; j++)
        A[j] = T[j];
}


// Merge sort for linked list
ListNode *mergeSort(ListNode *head) {
    if (head==NULL || head->next==NULL)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;
    
    while (fast!=NULL && fast->next!=NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    prev->next = NULL;
    ListNode *l1 = mergeSort(head);
    ListNode *l2 = mergeSort(slow);
    
    return merge(l1, l2);
}

ListNode *merge(ListNode *l1, ListNode *l2) {
    
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    
    while (l1!=NULL && l2!=NULL) {
        if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        }
        else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    
    if (l1 != NULL)
        curr->next = l1;
    if (l2 != NULL)
        curr->next = l2;
    
    return dummy->next;
}


