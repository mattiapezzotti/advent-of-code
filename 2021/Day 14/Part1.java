import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Part1 {
	
	static int FROM = 0;
	static int TO = 1;
	static String temp, trash, newString, current;
	static int[] common = new int[1000];
	static String[][] transform;
	
	public static void main(String args[]) throws FileNotFoundException {
		
		Scanner inputFile = new Scanner(new File("input.txt"));

	    long result = 0;
        int i;
        long max = 0, min = 10000;
	    
	    transform = new String[1000][2];

        temp = inputFile.next();
        
        for(i=0; inputFile.hasNext(); i++){
        	transform[i][FROM] = inputFile.next();
            trash = inputFile.next();
            transform[i][TO] = inputFile.next();
        }
        
        int sizeTransform = i;

        for(int step=0; step<10; step++){
        	newString = "";
            for(int j=0; j<temp.length()-1; j++){
                current = temp.charAt(j) + "" + temp.charAt(j+1);
                for(i=0; i<sizeTransform; i++)
                    if(current.equals(transform[i][FROM])){
                    	newString += current.charAt(0) + "" + transform[i][TO];
                    }
            }
            temp = newString + current.charAt(1);
        }
        
        for(i=0; i < temp.length(); i++) {
        	common[temp.charAt(i)]++;
        }
        
        for(i=0; i < temp.length(); i++) {
	        if(common[temp.charAt(i)] > max)
	    		max = common[temp.charAt(i)];
	    	else if(common[temp.charAt(i)] < min)
	    		min = common[temp.charAt(i)];
        }
        	

        result = max - min;
    
	    System.out.println("Result: " + result);
	    inputFile.close();
		}
}
