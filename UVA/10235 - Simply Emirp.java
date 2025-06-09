import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
		    int n = sc.nextInt();
		    BigInteger value1 = BigInteger.valueOf(n);
		    String strRev = new StringBuffer(value1.toString()).reverse().toString();
		    int reversed = Integer.parseInt(strRev);
		    BigInteger value2 = BigInteger.valueOf(reversed);
		    System.out.print(n + " is ");
		    if(!value1.isProbablePrime(10))
		      System.out.println("not prime.");
		    else if((n != reversed) && value2.isProbablePrime(10))
		      System.out.println("emirp.");
		 else
		      System.out.println("prime.");
		}
	}
}