import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		BigInteger fac[] = new BigInteger[1001];
		fac[0] = fac[1] = BigInteger.ONE;
		for(int i=2; i<1001; i++)
		  fac[i] = fac[i-1].multiply(BigInteger.valueOf(i));
		
		String line;
		while((line = br.readLine()) != null){
		  int n = Integer.parseInt(line.trim());
		  pw.println(n + "!");
		  pw.println(fac[n]);
		}
		pw.flush();
	}
}