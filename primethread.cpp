#include <iostream>
#include <thread>
#include <mutex>
#include <math.h>
// to compile with threading:
// g++ primethread.cc -std=c++11 -pthread -o primeth

std::mutex lock;
int numPrime = 0;
int prim = 0;
int star = 0;
int sto = 0;

int min = 1000;
int max = 1000000;

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

void primeThread(int start, int stop)
{
	int temp = 0;

	for (int i = start; i <= stop; i++)
	{
		if (isPrime(i))
		{
			temp++;
		}
	}

	lock.lock();
	star = start;
	sto = stop;
	prim = temp;
	numPrime += temp;
	lock.unlock();
}

int main(int argc, char const *argv[])
{

	int start = 0;
	int stop = 0;
	int nthreads = 4;

	std::thread *threads[nthreads];

	for (int i = 0; i < nthreads; i++)
	{
		start = (((max / nthreads) * i) + min);
		stop = ((max / nthreads) * (i + 1)) + min;
		if (stop > max)
		{
			stop = max;
		}

		std::thread *th = new std::thread(primeThread, start, stop);
		threads[i] = th;
		//  std::cout << "\nThread: " << i << "\nRange: " << start << " - " << stop;
	}

	for (int i = 0; i < nthreads; i++)
	{
		threads[i]->join();
		std::cout << "\nThread: " << i << "\nRange: " << star << " - " << sto << "\nCount: " << prim << "\n";
	}

	std::cout << "\nTotalCount: " << numPrime;

	return 0;
}
