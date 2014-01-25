public class Stack<Item> {

	private Node top;
    private int N;
    
    private class Node {
        Item item;
        Node next;
    }

	public Stack() {
		this.top = null;
        this.N = 0;
	}
    
    public void push(Item item) {
		Node temp = new Node();
        temp.item = item;
		temp.next = this.top;
		this.top = temp;
        N++;
	}

	public Item pop() {
        if(this.isEmpty())
            return null;
        Node temp = this.top;
        Item item = temp.val;
        this.top = temp.next;
        N--;
        return item;
	}
	
	boolean isEmpty() {
		return (this.top == null);
	}
    
    public int size() {
        return N;
    }

}
