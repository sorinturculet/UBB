package cz.cuni.mff.turcules.utils;
import cz.cuni.mff.turcules.utils.Printer;
public class GenericPrinter implements Printer {
    public GenericPrinter(){
        System.out.println("in GenericPrinter:");
    }
    public void print(String msg){
        System.out.println(msg);
    }
}
