
/**
 * HW 2 CODE 1/24/2020
 *
 * @author tevin
 */
import java.util.Random;

public class sortingmain {

    static void insertionSort(int array[]) {
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

    static void mergeSort(int array[], int p, int r) {
        if (p < r) {

            int q = (p + r) / 2;

            // sort the left array and the right array
            mergeSort(array, p, q);
            mergeSort(array, q + 1, r);

            merge(array, p, q, r);
        }
    }

    static void merge(int arr[], int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;

        // temp arrays left and right
        int L[] = new int[n1];
        int R[] = new int[n2];

        // copy array data to left and right arrays
        for (int i = 0; i < n1; i++) {
            L[i] = arr[p + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[q + j + 1];
        }

        int i = 0;
        int j = 0;
        int k = p;

        // makes sure i is less than n1 and j is less than n2
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i]; // update the array so it is sorted
                i++;
            } else {
                arr[k] = R[j]; // update the array so it is sorted
                j++;
            }
            k++;
        }
    }

    public static void main(String[] args) {
        System.out.println("n elements, selection time, sorted selection time, merge time, sorted merge time");

        for (int j = 1000; j <= 10000; j += 1000) {
            // Initialize an array with the intervals
            int[] array = new int[j];
            int[] sortedArray = new int[j];
            //Populate array
            Random RandNumbers = new Random();
            for (int i = 0; i < array.length; i++) {
                //  array[i] = i;
                array[i] = RandNumbers.nextInt(100000);
            }
            for (int i = 0; i < array.length; i++) {
                //  array[i] = i;
                sortedArray[i] = i;
            }

            /************************************************
             * uncomment to see that the code is 
             * sorting the random integers in the array
             * using merge sort
             ************************************************/
            
//            {
//                for (int i = 0; i < array.length; ++i) {
//                    System.out.print(array[i] + ", "); // testing sorted order
//                }
//                System.out.println();
//
//                mergeSort(array, 0, array.length - 1);
//                for (int i = 0; i < array.length; ++i) {
//                    System.out.print(array[i] + ", "); // testing sorted order
//                }
//                System.out.println();
