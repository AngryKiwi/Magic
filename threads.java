/**************************************************
 * Author: Tevin De La Garza
 * Date: 2/10/2020
 * 
 * Assignment: Use threads to calculate prime
 *  numbers from a certain range. Depending on 
 *  how many threads one can use, this will divide
 *  up the range and process the prime numbers
 *  all at once.
 * 
 *************************************************/
public class threading {

    public static void main(String[] args) {
        
        // Threads wanting to use and range of prime numbers.
        int nthreads = 8;
        int min = 1000;
        int max = 1000000;

        int start = 0;
        int stop = 0;
        int totalCount = 0;

        // Take the run time of algorithm.
        long startTime = System.currentTimeMillis();
        
        // Create thread objects and primes objects.
        Thread[] ths = new Thread[nthreads];
        primes[] prim = new primes[nthreads];

        for (int i = 0; i < nthreads; i++) {
            // Finding the range of each threads with an offset of min.
            start = (((max / nthreads) * i) + min);
            stop = ((max / nthreads) * (i + 1)) + min;
            
            // Sets stop to be the max value and offset does not affect it.
            if (stop > max) {
                stop = max;
            }
            
            
            prim[i] = new primes(start, stop);
            ths[i] = new Thread(prim[i]);
            ths[i].start();

        }
        for (int i = 0; i < nthreads; i++) {
            try {
                ths[i].join();
                // totalCount += prim[i].primes.size();
                totalCount += prim[i].count;
                System.out.println("Thread: " + i
                        + "\nRange: " + prim[i].start + " - " + prim[i].stop
                        + "\nCount: " + prim[i].count + "\n");
            } catch (InterruptedException e) {
            // TODO Auto-generated catch block
                e.printStackTrace();
            }  // blocking operation
            //  System.out.println(count);
        }
        long endTime = System.currentTimeMillis();
        System.out.println("Total Count: " + totalCount + "\nRunTime(ms): " + (endTime - startTime));
    }
}
