package cz.cuni.mff.turcules.hello.homework;

public class Multiply {
    public static void main(String[] args){
        if(args.length > 0) {
            int number = Integer.parseInt(args[0]);
            for (int i = 1; i <= 10; i++) {
                if(number>0 && number<=9)
                    System.out.printf("%2d * %d = %2d%n", i, number, i * number);
                if(number>9 && number<100)
                    System.out.printf("%2d * %d = %3d%n", i, number, i * number);
            }
        }
        else System.out.println("No argument provided.");
    }
}