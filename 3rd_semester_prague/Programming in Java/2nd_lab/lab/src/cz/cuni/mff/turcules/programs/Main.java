package cz.cuni.mff.turcules.programs;
import cz.cuni.mff.turcules.util.*;
public class Main {
    public static void main(String[] argv) {
        int START = 2000000000;
        int count = 0;
        float g=START;
        System.out.println(g);
        for (float f = START; f < START + 50; f++) {
            count++;
        }
        System.out.println(count);
    }
}
