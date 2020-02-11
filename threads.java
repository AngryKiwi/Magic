/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author tevin
 */
public class threads {

    public static void main(String[] args) {
        int nthreads = 4;
        int count = 0;
        //ranges to find primes
        int min = 10;
        int max = 100;
        
        int start = 0;
        int stop = 0;
        
        long startTime = System.currentTimeMillis();
        Thread[] ths = new Thread[nthreads];
        for (int i = 0; i < nthreads; i++){
            start = (((max/nthreads)*i)+min); 
            stop = ((max/nthreads)*(i+1))+min;
            if(stop > max){
                stop = max;
            }
            prime prim = new prime(start, stop, min);
            Thread th = new Thread(prim);
            ths[i] = th;
            th.start();
            System.out.println("Thread: " + i + " \n Range: " + start + " - " + stop);
           
        }
        for (int i = 0; i < nthreads; i++) {
            try {
                ths[i].join();
            } catch (InterruptedException e) {
// TODO Auto-generated catch block
                e.printStackTrace();
            }  // blocking operation
          //  System.out.println(count);
        }
        long endTime = System.currentTimeMillis();
        System.out.println(endTime - startTime);
    }
}
