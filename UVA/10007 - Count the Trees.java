import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		BigInteger catNum[] = new BigInteger[301];
		BigInteger fac[] = new BigInteger[301];
		
		catNum[0] = BigInteger.ONE;
		for(int i=1; i<301; i++){
		  catNum[i] = (catNum[i-1]
		               .multiply(BigInteger.valueOf((i-1) * 4 + 2)))
		               .divide(BigInteger.valueOf(i+1));
		}
		
		fac[0] = BigInteger.ONE;
		for(int i=1; i<301; i++)
		  fac[i] = fac[i-1].multiply(BigInteger.valueOf(i));
		  
		String line;  
		while((line = br.readLine()) != null){
		    int n = Integer.parseInt(line.trim());
		    if(n == 0) break;
		    BigInteger ans = catNum[n].multiply(fac[n]);
		    System.out.println(ans);
		}
	}
}