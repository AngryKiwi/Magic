
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
public class prime implements Runnable {

    int start;
    int stop;
    int count;
    int min;

    public prime(int start, int stop, int min) {
        this.start = start;
        this.stop = stop;
        this.min = min;
    }

    public void run() {
        try {
            for (int i = start; i < stop; i++) {
                if (isPrime(i)) {
                   // System.out.println(i);
                    count++;
                }
            }
            System.out.println(count);
            Thread.sleep(2);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    boolean isPrime(int n) {
        boolean primeNum = true;
        
        if(n < 2){
            primeNum = false;
        }
        
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                primeNum = false;
            }
            if( n == 4)
                primeNum = false;
        }
        return primeNum;
    }

}
