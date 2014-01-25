node *reverse_iterative(node *head) {
	if (head == NULL)
		return NULL;
    
	node *result, *curr, *post;
 	curr = head;
    result = NULL;

	while (curr != NULL) {
		post = curr->next;
		curr->next = result;
		result = curr;
		curr = post;
	}	
	return result;
}

node *reverse_recursive(node *head) {
	if (head == NULL)
		return NULL;
	if (head->next = NULL)
		return head;

	node *prev, *curr;
	prev = head;
	curr = reverse_recursive(head->next);
	prev->next->next = prev;
    prev->next = NULL;

	return curr;
}
