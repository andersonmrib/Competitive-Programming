import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
		  int n = sc.nextInt();
		  
		  BigInteger factorialVal = BigInteger.ONE;
		  for(int i=2; i<=n; i++)
		    factorialVal = factorialVal.multiply(BigInteger.valueOf(i));
		    
		  String str = factorialVal.toString();
		  int ans = 0;
		  
		  for(char c : str.toCharArray())
		    ans += c - '0';
		    
		  System.out.println(ans);
		}
	}
}