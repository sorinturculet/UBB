package cz.cuni.mff.turcules.utils;

public interface Printer{
    void print(String msg);
    default void print(int number){
        System.out.println("print number in interface");
        print(String.valueOf(number));
    }

}
