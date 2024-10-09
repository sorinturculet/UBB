package cz.cuni.mff.turcules.utils;

public class LabelPrinter extends GenericPrinter{
    private String myLabel;
    public LabelPrinter(String label){
        this.myLabel=label;
        System.out.println("in LabelPrinter:");
    }
    @Override
    public void print(String msg){
        super.print(this.myLabel + " " + msg);
    }
}
