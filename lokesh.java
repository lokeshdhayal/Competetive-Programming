import java.util.*;
import java.math.BigInteger;
import java.util.Scanner;
public class lokesh {
	public static void main(String args[]){
		int N = 0;
		Scanner sc = new Scanner(System.in);
		while(true){
			N = sc.nextInt();
			if(N == 0){break;}
			BigInteger a = BigInteger.ZERO;
			for(int i = 0;i < N;i++){
				BigInteger p = sc.nextBigInteger();
				a = a.add(p);
			}
			System.out.println(a);
		}
	}
}