import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) throws Exception{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	    
	    BigInteger []arr = new BigInteger[1001];
	    arr[0] = BigInteger.ONE;
	    arr[1] = BigInteger.valueOf(2);
	    arr[2] = BigInteger.valueOf(3);
	    for(int i=3; i<1001; i++)
	      arr[i] = arr[i-1].add(arr[i-2]);
	    
	    String line;
        while ((line = br.readLine()) != null) { 
	        int n = Integer.parseInt(line);
	        pw.println(arr[n]);
	    }
	    pw.flush();
	    pw.close();
	}
}