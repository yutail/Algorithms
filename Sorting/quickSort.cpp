// Choose a pivot and then do patition
void quickSort(int A[], int lo, int hi) {
    int par = partition(A, lo, hi);
    if (lo < par)           // Sort the left half
        quickSort(A, lo, par);
    if (par+1 < hi)         // Sort the right half
        quickSort(A, par+1, hi);
}

int partition(int A[], int lo, int hi) {
    int pivot = A[(lo + hi) / 2];
    while (lo <= hi) {
        while (A[lo] < pivot)
            lo++;
        while (A[hi] > pivot)
            hi--;
        if (lo <= hi) {
            swap(A, lo, hi);
            lo++;
            hi--;
        }
    }
    return lo;
}

void swap(int A[], int i, int j) {
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Sort List
ListNode *sortList(ListNode *head) {
    ListNode *tail = NULL;
    return quickSort(head, tail);
}

ListNode *quickSort(ListNode *head, ListNode *&tail) {
    // Base Case
    if(head == NULL || head->next == NULL) {
        tail = head;
        return head;
    }
    
    // Partition accorsing to head->val
    ListNode *beforeStart = NULL, *beforeEnd = NULL;
    ListNode *afterStart = NULL, *afterEnd = NULL;
    ListNode *p = head->next;
    
    while(p != NULL) {
        if(p->val < head->val) {
            if(beforeStart == NULL) {
                beforeStart = p;
                beforeEnd = p;
            }
            else {
                beforeEnd->next = p;
                beforeEnd = p;
            }
        }
        else {
            if(afterStart == NULL) {
                afterStart = p;
                afterEnd = p;
            }
            else {
                afterEnd->next = p;
                afterEnd = p;
            }
        }
        p = p->next;
    }
    
    if(beforeEnd != NULL)
        beforeEnd->next = NULL;
    if(afterEnd != NULL)
        afterEnd->next = NULL;
    
    // Recursive sort quickSort(head_left, tail_left) and quickSort(head_right, tail_right)
    ListNode *tail_left = NULL, *tail_right = NULL;
    
    ListNode *head_left = quickSort(beforeStart, tail_left);
    ListNode *head_right = quickSort(afterStart, tail_right);
    
    ListNode *new_head = NULL;
    
    // Merge head_left, head_right and mid
    new_head = (head_left == NULL) ? head : head_left;
    if(tail_left != NULL) tail_left->next = head;
    
    head->next = head_right;
    tail = (tail_right == NULL) ? head : tail_right;
    
    return new_head;
}
