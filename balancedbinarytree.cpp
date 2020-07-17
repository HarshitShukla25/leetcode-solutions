
private class Node {
    private int value;
    private Node right;
    private Node left;
}
 
public boolean isBalanced(Node n) {
    if (balancedHeight(n) > -1) return true;
    return false;
}
 
public int balancedHeight(Node n) {
    if (n == null) return 0;
    int h1 = balancedHeight(n.right);
    int h2 = balancedHeight(n.left);
 
    if (h1 == -1 || h2 == -1) return -1;
    if (Math.abs(h1 - h2) > 1) return -1;
    if (h1 > h2) return h1 + 1;
    return h2 + 1;

private class Node {
    private int value;
    private Node right;
    private Node left;
}
 
public boolean isBalanced(Node n) {
    if (balancedHeight(n) > -1) return true;
    return false;
}
 
public int balancedHeight(Node n) {
    if (n == null) return 0;
    int h1 = balancedHeight(n.right);
    int h2 = balancedHeight(n.left);
 
    if (h1 == -1 || h2 == -1) return -1;
    if (Math.abs(h1 - h2) > 1) return -1;
    if (h1 > h2) return h1 + 1;
    return h2 + 1;
}