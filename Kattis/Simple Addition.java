import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger sum = BigInteger.ZERO;
		
		sum = sum.add(new BigInteger(br.readLine()));
	    sum = sum.add(new BigInteger(br.readLine()));
		
		System.out.println(sum);
	}
}