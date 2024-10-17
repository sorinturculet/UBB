package cz.cuni.mff.turcules.programs;


import cz.cuni.mff.turcules.util.BinarySearchTree;

public class Main {
    public static void main(String[] argv) {
        BinarySearchTree binaryTree = new BinarySearchTree();

        for (String arg : argv) {
            int number;
            try{
                number=Integer.parseInt(arg);
            }
            catch(Exception e){
                System.out.println("INPUT ERROR");
                return;
            }
            binaryTree.addNode(number);
        }
        for(var node:binaryTree){
            System.out.println(node);
        }
    }
}
