import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) {
	  Scanner sc = new Scanner(System.in);
	  
	  int N = sc.nextInt();
	  while(N-- > 0){
	    BigInteger sum = BigInteger.ZERO;
	    StringBuffer sb = new StringBuffer(sc.next());
	    sb.reverse();
	    sum = sum.add(new BigInteger(sb.toString()));
	    
	    sb = new StringBuffer(sc.next());
	    sb.reverse();
	    sum = sum.add(new BigInteger(sb.toString()));
	    
	     String num = new StringBuffer(sum.toString()).reverse().toString();
         String ans = num.replaceFirst("^0+", "");
	    
	    System.out.println(ans);
	  }	
	}
}