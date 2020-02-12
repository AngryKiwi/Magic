#include <math.h>
//#include <mutex>
//std::mutex lock;

//    bool isPrime(int n) {
//        bool primeNum = true;

//        if (n < 2) {
//            primeNum = false;
//        }

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
class primes
{

private:
	int count;
	int star;
	int sto;

public:

	int getCount()
	{
		return count;
	}
	int getStart()
	{
		return star;
	}
	int getStop()
	{
		return sto;
	}

	bool isPrime(int num)
	{
		bool isPrim = true;
		if (num > 2 && num % 2 == 0)
		{
			isPrim = false;
		}
		int top = sqrt(num) + 1;
		for (int i = 3; i < top; i += 2)
		{
			if (num % i == 0)
			{
				isPrim = false;
			}
		}
		return isPrim;
	}

	primes(int start, int stop)
	{
		count = 0;
		 star = start;
		 sto = stop;
		for (int i = start; i < stop; i++)
		{
			if (isPrime(i))
		{
				count++;

			}
		}
	}
};
