import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
		  BigInteger x = new BigInteger(sc.next());
		  BigInteger y = new BigInteger(sc.next());
		  
		  System.out.println(x.multiply(y));
		}
		sc.close();
	}
}