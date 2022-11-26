package JAVA_PTIT;

import java.util.*;
import java.math.*;

public class J03033 {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0){
            BigInteger a = new BigInteger(sc.nextLine());
            BigInteger b = new BigInteger(sc.nextLine());
            BigInteger c = a.gcd(b);
            System.out.println(a.divide(c).multiply(b));
        }
    }
}
