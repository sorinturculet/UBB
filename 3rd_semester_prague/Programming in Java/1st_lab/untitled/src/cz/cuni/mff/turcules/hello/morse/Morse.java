package cz.cuni.mff.turcules.hello.morse;

public class Morse {
    public static void main(String[] args){
    if(args.length > 0) {
        char[] english = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                'y', 'z'};   //Defining a Character Array of the English Letters numbers and Symbols so that we can compare and convert later

        String[] morse = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                ".---", "-.-", ".-..", "--", "-.", "---", ".---.", "--.-", ".-.",
                "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; //a-z

        for(String arg:args){
            String message="";
            for(int index=0;index<arg.length();index++){
                //we suppose the input is right.
                int number=arg.charAt(index)-'a';
                message+=morse[number];
            }
            System.out.println(message);
        }
    }
        else System.out.println("No argument provided.");
}
}
