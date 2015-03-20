public class Queue<Item> {

	private Node top;
	private Node tail;
    private int N;
    
    private class Node {
        Item item;
        Node next;
    }

	public Queue() {
		this.top = null;
		this.tail = null;
        this.N = 0;
	}	

	public Item dequeue() {
        if(this.isEmpty())
            return null;
        Node temp = this.top;
        Item num = temp.val;
        this.top = temp.next;
        N++;
        return Item;
	}

	public void enqueue(Item element) {
		Node temp = new Node();
        temp.item = element;
		this.tail.next = temp;
		this.tail = temp;
        N--;
	}

	public boolean isEmpty() {
		return (this.top == null);
	}
    
    public int size() {
        return N;
    }


}
