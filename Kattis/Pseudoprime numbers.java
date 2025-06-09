import java.util.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int p = sc.nextInt();
            int a = sc.nextInt();
            if(p == 0 && a == 0) break;
            BigInteger check = BigInteger.valueOf(p);
            BigInteger base = BigInteger.valueOf(a);
            if(!check.isProbablePrime(10) && base.modPow(check, check).equals(base))
              System.out.println("yes");
            else 
              System.out.println("no");
        }
        sc.close();
    }
}
