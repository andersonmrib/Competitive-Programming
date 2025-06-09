import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) throws Exception {
	    
	  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	  PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	  int N, F;
	  
	  int numCases = 0;
	  while(true){

        StringTokenizer st = new StringTokenizer(br.readLine());
	    N = Integer.parseInt(st.nextToken()); 
	    F = Integer.parseInt(st.nextToken());
	    if(N == 0 && F == 0) break;
	    
	    BigInteger sum = BigInteger.ZERO;
	    
	    while(N-- > 0){
	      BigInteger V = new BigInteger(br.readLine());
	      sum = sum.add(V);
	    }
	    
	    pw.printf("Bill #%d costs ", ++numCases);
	    pw.printf(sum.toString());
	    pw.printf(": each friend should pay ");
	    pw.printf(sum.divide(BigInteger.valueOf(F)).toString());
	    pw.printf("\n\n");
	  }
	  pw.close();
	}
}