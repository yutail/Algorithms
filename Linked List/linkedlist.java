public class Linkedlist {
	private Node head;
    
    private class Node {
        int item;
        Node next;
    }

	public Linkedlist(Node n) {
		this.head = n;
	}

	public void insert(Node n, Node newNode) {
		newNode.next = n.next;
		n.next = newNode;	
	}

	public void remove(int num) {
		Node prev, curr;
		
		if(head == null)
			return;

		curr = head;	
			
		while (curr != null && curr.val != num) {
			prev = curr;
			curr = curr.next;
		}
 
		if (curr == null)
			return;
		
		prev.next = curr.next;
	}
}
