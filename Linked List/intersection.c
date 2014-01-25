node *intersectionPoint(node *head1, node *head2) {
    if (!head1 || !head2)
        return NULL;
    
    int d1 = getLength(head1);
    int d2 = getLength(head2);
    int d = d1 - d2;
    if (d < 0)
        return intersectionPoint(head2, head1);
    
    node *curr1 = head1;
    node *curr2 = head2;
    
    while (curr1 != NULL && d > 0) {
        curr1 = curr1->next;
        if (curr1 == NULL)
            return NULL;
        d--;
    }
    
    while (curr1!=NULL && curr2!=NULL) {
        if (curr1 == curr2)
            return curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return NULL;
}

int getLength(node *head) {
    if (head == NULL)
        return 0;
    node *curr = head;
    int len = 0;
    while (curr != NULL) {
        curr = curr->next;
        len++;
    }
    return len;
}
