package cz.cuni.mff.turcules.util;

import java.util.Iterator;

public class DynamicArray implements Iterable{
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
            if (length >= 0) System.arraycopy(a, 0, b, 0, length);
            a=b;
            capacity*=2;
        }
        a[length]=i;
        length++;
    }
    public Object get(int i) throws Exception {
        if(i<0 || i>=length)
            throw new Exception("ArrayIndexOutOfBoundsException");//i is not valid
        return a[i];
    }
    public void remove(int i) throws Exception {
        if(i<0 || i>=length)
            throw new Exception("ArrayIndexOutOfBoundsException");//i is not valid
        for(int j=i;j<length-1;j++)
            a[j]=a[j+1];
        length--;
    }
    public void remove(Object i) throws Exception {
        int j=0;
        while(j<length && a[j]!=i){
            j++;
        }
        if(j==length)
            throw new Exception("ObjectDoesntExist");//Object i is not in the array
        for(;j<length-1;j++)
            a[j]=a[j+1];
        length--;
    }
    public int size(){
        return length;
    }

    @Override
    public Iterator iterator() {
        return new Iterator(){
            private int index=0;
            @Override
            public boolean hasNext(){
                return index<length;
            }
            @Override
            public Object next(){
                return a[index++];
            }
        };
    }
}
