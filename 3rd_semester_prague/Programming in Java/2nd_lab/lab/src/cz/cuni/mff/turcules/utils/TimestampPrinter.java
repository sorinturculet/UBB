package cz.cuni.mff.turcules.utils;
import cz.cuni.mff.turcules.utils.GenericPrinter;
public class TimestampPrinter extends GenericPrinter {
    public TimestampPrinter(){
        System.out.println("in TimestampPrinter:");
    }
    @Override
    public void print(String msg){
        super.print(new java.util.Date()+" "+msg);
    }
}
