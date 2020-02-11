
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author tevin
 */
public class primes implements Runnable {

    int start;
    int stop;
    int count;
    ArrayList<Integer> primes = new ArrayList<Integer>();

    public primes(int start, int stop) {
        this.start = start;
        this.stop = stop;
        this.count = 0;
    }

    public void run() {
        // int count = 0;
        try {
            for (int n = start; n < stop; n++) {
                if (isPrime(n)) {
                    //  primes.add(n);
                    //System.out.print(n + " ");
                    //      System.out.println(n);
                    count++;
                }
            }
            Thread.sleep(2);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static boolean isPrime(int num){
    if ( num > 2 && num%2 == 0 ) {
       // System.out.println(num + " is not prime");
        return false;
    }
    int top = (int)Math.sqrt(num) + 1;
    for(int i = 3; i < top; i+=2){
        if(num % i == 0){
            //System.out.println(num + " is not prime");
            return false;
        }
    }
    //System.out.println(num + " is prime");
    return true; 
}
//    boolean isPrime(int n) {
//        boolean primeNum = true;
//
//        if (n < 2) {
//            primeNum = false;
//        }
//
//        for (int i = 2; i < n; i++) {
//            if (n % i == 0) {
//                primeNum = false;
//            }
//            if (n == 4) {
//                primeNum = false;
//            }
//        }
//        return primeNum;
//    }

}
