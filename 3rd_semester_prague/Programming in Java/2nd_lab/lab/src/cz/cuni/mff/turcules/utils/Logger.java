package cz.cuni.mff.turcules.utils;
import cz.cuni.mff.turcules.utils.*;
public class Logger {
    private Printer p;
    private int level;
    public void addPrinter(Printer p){
        this.p=p;
    }
    public void setLevel(int level){
        this.level=level;
    }
    public void log(int level,String msg){
        if(level>=this.level)
            p.print(msg);
    }
}
