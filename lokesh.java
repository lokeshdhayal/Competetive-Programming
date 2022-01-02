import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;
import java.util.*;
import java.math.BigDecimal;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
      /*  if (System.getProperty("ONLINE_JUDGE") == null) {
            try {
                System.setOut(new PrintStream(
                    new FileOutputStream("output.txt")));
                sc = new Scanner(new File("input.txt"));
            }
            catch (Exception e) {
            }
            long startTime = System.nanoTime();
            long endTime = System.nanoTime();
            System.out.println("Took "+(endTime - startTime) + " ns"); 
        } */
       // int t = sc.nextInt();
        BigDecimal a = new BigDecimal(2.71828);
        a = a.pow(100000005,100000007);
        System.out.println(a);
    }
}
