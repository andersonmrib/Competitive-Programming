import java.util.*;
import java.io.*;

public class Main
{
    private static PrintWriter pw;

    private static void ArabicToRoman(int a){

        TreeMap<Integer, String> myPair = new TreeMap<Integer, String>(Collections.reverseOrder());
        myPair.put(1000, "M"); myPair.put(900, "CM"); myPair.put(500, "D");
        myPair.put(400, "CD"); myPair.put(100,  "C"); myPair.put(90, "XC");
        myPair.put(50, "L");   myPair.put(40, "XL");  myPair.put(10, "X");
        myPair.put(9, "IX");   myPair.put(5, "V");    myPair.put(4, "IV");
        myPair.put(1, "I");

        Set keys = myPair.keySet();
        for(Iterator i = keys.iterator(); i.hasNext();){
            Integer key = (Integer) i.next();
            String Romanvalue = (String) myPair.get(key);
            while(a >= key){
                pw.print(Romanvalue);
                a -= key;
            }
        }
        pw.printf("\n");
    }

    private static int ArabicValue(char letter){
        switch(letter){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    private static void RomanToArabic(String roman){
        int ans = 0;
        for(int i=0; i<roman.length(); i++)
            if((i + 1 < roman.length()) && ArabicValue(roman.charAt(i)) < ArabicValue(roman.charAt(i+1))){
                ans += ArabicValue(roman.charAt(i+1)) - ArabicValue(roman.charAt(i));
                i++;
            }
            else
                ans += ArabicValue(roman.charAt(i));
        pw.printf("%d\n", ans);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        while(true) {
            String str = br.readLine();
            if(str == null) break;
            if(Character.isDigit(str.charAt(0))) ArabicToRoman(Integer.parseInt(str));
            else                                 RomanToArabic(str);
        }
        pw.close();
    }
}
