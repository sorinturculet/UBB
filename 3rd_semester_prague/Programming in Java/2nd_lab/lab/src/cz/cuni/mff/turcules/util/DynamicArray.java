package cz.cuni.mff.turcules.util;

public class DynamicArray {
    int capacity;
    int length;
    Object[] a;
    public DynamicArray(){
        capacity=2;
        length=0;
        a= new Object[capacity];
    }
    public void add(Object i){
        if(length==capacity){
            Object[] b= new Object[capacity*2];
            for(int j=0;j<length;j++){
                b[j]=a[j];
            }
            a=b;
            capacity*=2;
        }
        a[length]=i;
        length++;
    }
    public Object get(int i){
        if(i<0 || i>=length)
            return null; //out of bounds
        return a[i];
    }
    public void remove(int i){
        if(i<0 || i>=length)
            return;//i is not valid
        for(int j=i;j<length-1;j++)
            a[j]=a[j+1];
        length--;
    }
    public void remove(Object i){
        int j=0;
        while(j<length && a[j]!=i){
            j++;
        }
        if(j==length)
            return; //element doesnt exist
        for(;j<length-1;j++)
            a[j]=a[j+1];
        length--;
    }
    public int size(){
        return length;
    }
}
