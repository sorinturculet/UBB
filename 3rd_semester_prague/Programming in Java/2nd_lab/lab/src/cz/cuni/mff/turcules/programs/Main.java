package cz.cuni.mff.turcules.programs;
import cz.cuni.mff.turcules.util.*;


public class Main {
    public static void main(String[] argv) {
        DynamicArray dynamicArray = new DynamicArray();

        // Add all command-line parameters to the dynamic array
        for (String arg : argv) {
            dynamicArray.add(arg);
        }

        // Iterate over the dynamic array and print each element on a separate line
//        for (int i = 0; i < dynamicArray.size(); i++) {
//            System.out.println(dynamicArray.get(i));
//        }
        //Iterate over the dynamic array using Iterator
        for(var d:dynamicArray){
            System.out.println(d);
        }
    }
}
