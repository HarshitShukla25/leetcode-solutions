public class MaxStack {
 
    private class Node {
        private int value;
        private Node next;
        private Node oldMax;
    }
 
    private Node stack;
    private Node max;
 
    public MaxStack() {}
 
    public void push(int x) {
        Node n = new Node();
        n.value = x;
 
        if (stack == null) {
            stack = n;
        } else {
            n.next = stack;
            stack = n;
        }
 
        if (max == null || n.value > max.value) {
            n.oldMax = max;
            max = n;
        }
    }
 
    public int pop() {
        if (stack == null) throw new NullPointerException;
        Node n = stack;
        stack = n.next;
        max = n.oldMax;
        return n.value;
    }
 
    public int max() {
        if (max == null) throw new NullPointerException;
        return max.value;
    }
}