import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) throws Exception{
		int N, A;
		// without using BufferedReader and PrintWriter
		// you can get a limit of ~2.2
		// I mean... horrible time anyway
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	    
	    String line;
	    while((line = br.readLine()) != null){
	      
	      StringTokenizer st = new StringTokenizer(line);
	      N = Integer.parseInt(st.nextToken());
	      A = Integer.parseInt(st.nextToken());
	      
	      BigInteger sum = BigInteger.ZERO;
	      BigInteger base = BigInteger.valueOf(A);
	      
	      for(int i=1; i<=N; i++){
	        BigInteger power = base.pow(i);
	        sum = sum.add(BigInteger.valueOf(i).multiply(power));
	      }
	      
	      pw.println(sum);
	      pw.flush();
	      
	    }
	    pw.close();
	}
}

/* 
// code without those fancy readers and printers
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) {
		int N, A;
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
		  N = sc.nextInt();
		  A = sc.nextInt();
		  BigInteger sum = BigInteger.ZERO;
		  BigInteger base = BigInteger.valueOf(A);
		  
		  for(int i=1; i<=N; i++){
		    BigInteger power = base.pow(i);
		    sum = sum.add(BigInteger.valueOf(i).multiply(power));
		  }
		  
		  System.out.println(sum);  
		}
	}
}

*/