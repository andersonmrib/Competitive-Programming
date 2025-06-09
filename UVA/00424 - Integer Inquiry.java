import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) throws Exception{
		
		Scanner sc = new Scanner(System.in);
		BigInteger sum = BigInteger.ZERO;
		
		while(true){
		  String line = sc.next();  
		  if(line.equals("0")) break;
		  sum = sum.add(new BigInteger(line));
		}
		
		System.out.println(sum);
		sc.close();
	}
}