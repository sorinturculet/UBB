package cz.cuni.mff.turcules.util;

import java.util.Iterator;
import java.util.Stack;

public class BinarySearchTree implements Iterable<Integer> {
    private Node root;

    public BinarySearchTree() {}

    @Override
    public Iterator<Integer> iterator() {
        return new Iterator<>() {
            Stack<Node> traversal = new Stack<>();
            Node current = root;

            {
                moveLeft(current);
            }

            private void moveLeft(Node n) {
                while (n != null) {
                    traversal.push(n);
                    n = n.left;
                }
            }

            @Override
            public boolean hasNext() {
                return !traversal.isEmpty();
            }

            @Override
            public Integer next() {
                if (!hasNext()) {
                    throw new java.util.NoSuchElementException();
                }

                Node node = traversal.pop();
                int value = node.getValue();

                if (node.right != null) {
                    moveLeft(node.right);
                }

                return value;
            }
        };
    }

    private class Node {
        Node left;
        Node right;
        int value;

        public Node(int value) {
            this.value = value;
        }

        public int getValue() {
            return this.value;
        }
    }

    public void addNode(int value) {
        root = addRecursive(root, value);
    }

    private Node addRecursive(Node n, int value) {
        if (n == null) {
            return new Node(value);
        }

        if (value < n.getValue()) {
            n.left = addRecursive(n.left, value);
        } else if (value > n.getValue()) {
            n.right = addRecursive(n.right, value);
        }

        return n;
    }
}
