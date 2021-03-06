
class prime

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        int start = 1000;
        int stop = 1000000;
        int count = 0;
        for (int n = start; n < stop; n++) {
            if (isPrime(n)) {
                count++;
            }
        }
        long endTime = System.currentTimeMillis();
        System.out.println("Count: " + count + "\nRuntime (ms): " + (endTime-startTime));
    }

    public static boolean isPrime(int num) {
        
        boolean isPrim = true;
        if (num > 2 && num % 2 == 0) {
            isPrim = false;
        }
        int top = (int) Math.sqrt(num) + 1;
        for (int i = 3; i < top; i += 2) {
            if (num % i == 0) {
                isPrim = false;
            }
        }
        return isPrim;
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
