
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class MathTool {
    
    //find fibonacci series
    static long[] fibonacci(int n) {
        long [] fib = new long[n+1];
        fib[0] = 0;
        fib[1] = 1;
        
        for(int i=2; i<=n; i++)
            fib[i] = fib[i-1] + fib[i-2];
        return fib;
    }
    
    //find factorial for very large int (BigInteger)
    static BigInteger[] bigFactorial(int n) {
        BigInteger [] fact = new BigInteger[n+1];
        fact[1] = BigInteger.ONE;
        
        for(int i=2; i<=n; i++)
            fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        return fact;
    }
    
    //find factorial for int up to n
    static long[] getFactorial(int n) {
        long [] fact = new long[n+1];
        fact[1] = 1;
        for(int i=2; i<=n; i++)
            fact[i] = i * fact[i-1];
        return fact;
    }
    
    //find factorial for small int
    static int factorial(int n) {
        int result = 1;
        for(int i=1; i<=n; i++)
            result *= i;
        return result;
    }
    
    //BigInteger sqrt
    static boolean work;
    static BigInteger sqrtB(BigInteger A) {
        BigInteger temp = A.shiftRight(BigInteger.valueOf(A.bitLength()).shiftRight(1).intValue());
        BigInteger result = null;
        
        while(true) {
            result = temp.add(A.divide(temp)).shiftRight(1);
            if(!temp.equals(result))
                temp = result;
            else 
                break;
        }
        
        work = false;
        if(result.multiply(result).equals(A))
            work = true;
        return result;
    }
    
    ///get the factor of the number (factorization)
    static List<Integer> factorization(int n) {
        int num = n;
        List<Integer> factor = new ArrayList<Integer>();
        
        for(int i=2; i<=n/i; i++) {
            while(n%i == 0){
                factor.add(i);
                n /= i;
            }
        }
        if(n > 1)
            factor.add(n);
        return factor;
    }
    //generate prime numbers using sevie of eranthesis
    static boolean[] generatePrime(int n) {
        boolean [] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);
        
        for(int i=2; i*i<=n; i++)
            if(isPrime[i])
                for(int j=i; i*j<=n; j++)
                    isPrime[i*j] = false;
        return isPrime;
    }
    
    //find the Least Common Multiple
    static int LCM(int a,int b) {
        return (a*b) / GCD(a,b);
    }
    
    //find the Greatest Common Divisor (int)
    static int GCD(int a,int b) {
        if(b == 0)
            return a;
        return GCD(b, a%b);
    }
    //convert base's using BigInteger
    static String convertBaseBigInteger(String n,int from,int to) {
        BigInteger b = new BigInteger(n,from);
        return b.toString(to);
    }
    //convert base's without BigInteger
    static String convertBase(int n,int from,int to) {
        int num = toDecimal(n,from);
        return convertDecimal(num, to);
    }
    
    //convert decimal to any base
    static String convertDecimal(int num,int base) {
        int q = num / base;
        int r = num % base;
        
        if(1 == 0) 
            return ""+r;
        return convertDecimal(q, base);
    }
    
    //convert any base to Decimal
    static int toDecimal(int n,int base) {
        int v = 0,total = 0,power = 0;
        String s = ""+n;
        s = s.toUpperCase();
        char c;
        
        for(int i=s.length()-1; i>=0; i--) {
            c = s.charAt(i);
            
            if(c>='0' && c<='9')
                v = c-'0';
            else if(c>='A' && c<='Z')
                v = 10 + (c-'A');
            total += v * Math.pow(base, power++);
        }
        return total;
    }
}
