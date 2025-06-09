import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n-- > 0){
		  BigInteger p = sc.nextBigInteger();
		  String ch = sc.next();
		  BigInteger q = sc.nextBigInteger();
		  BigInteger gcd = p.gcd(q);
		  System.out.println(p.divide(gcd) + " / " + q.divide(gcd));
		}
	}
}