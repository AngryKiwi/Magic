
import java.util.Arrays;
import java.util.Random;

public class selection {

    static void selectionSort(int array[]) {
        for (int j = 2; j < array.length; j++) {
            int key = array[j];
            int i = j - 1;

            while (i > 0 && array[i] > key) {
                array[i + 1] = array[i];
                i--;
            }
            array[i + 1] = key;
        }
    }

    static void merge(int array[], int p, int q, int r) {
        int i, j, k;
        
        
        int n1 = q - p + 1;
        int n2 = r - q;

        // Temp arrays
        int L[] = new int[n1];
        int R[] = new int[n2];

        //Copy data to temp arrays L[] and R[] 
        for (i = 1; i < n1; i++) {
            L[i] = array[p + i - 1];
        }
        for (j = 1; j < n2; j++) {
            R[j] = array[q + j];
        }

        i = 1; // Initial index of first subarray 
        j = 1; // Initial index of second subarray 
        for (k = p; k < r; k++) {
            if (L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
        }
    }

    static void mergeSort(int array[], int p, int r) {
        if (p < r) {

            int q = ((p + r) / 2);

            // Sort first and second halves 
            mergeSort(array, p, q);
            mergeSort(array, q + 1, r);

            merge(array, p, q, r);
        }
    }

    public static void main(String[] args) {
        for (int j = 1000; j <= 10000; j += 1000) {
            // Initialize an array with the intervals
            int[] array = new int[j];
            //Populate array
            Random RandNumbers = new Random();
            for (int i = 0; i < array.length; i++) {
                //  array[i] = i;
                array[i] = RandNumbers.nextInt(100000);
                // System.out.println(array[i]);
            }

            {
                long start = System.nanoTime();
                selectionSort(array);

                //   for (int i = 0; i < array.length; ++i) 
                //     System.out.println(array[i] + " "); 
                long end = System.nanoTime();
                // System.out.println(end - start); // uncomment to see the runtime
            }

            {
                long start = System.nanoTime();
                mergeSort(array, 1, array.length);

                //   for (int i = 0; i < array.length; ++i) 
                //     System.out.println(array[i] + " "); 
                long end = System.nanoTime();
                System.out.println(end - start); // uncomment to see the runtime
            }
        }
    }
}
