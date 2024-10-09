package cz.cuni.mff.turcules.test;

import cz.cuni.mff.turcules.utils.*;
public class LoggerMain {
    public static void main(String[] args){
        Logger l=new Logger();
        GenericPrinter p1=new LabelPrinter("Hello");
        GenericPrinter p2=new TimestampPrinter();
        l.addPrinter(p1);
        l.setLevel(1);
        l.log(2,"OK");
        l.addPrinter(p2);
        l.log(3,"Time");
        p1.print(1);
    }
}
