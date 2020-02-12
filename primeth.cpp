#include <iostream>
#include <thread>
#include "prime.h"
// to compile with threading:
// g++ primethread.cc -std=c++11 -pthread -o primeth

int main(int argc, char const *argv[])
{
   //Range to find primes in

   int min = 1000;
   int max = 1000000;
   int totalCount = 0;

   int start = 0;
   int stop = 0;
   int nthreads = 16;

   std::thread *threads[nthreads];
   //primes *prim[nthreads];
   for (int i = 0; i < nthreads; i++)
   {
      start = (((max / nthreads) * i) + min);
      stop = ((max / nthreads) * (i + 1)) + min;

      if (stop > max)
      {
         stop = max;
      }
      threads[i] = new std::thread(primes ,start, stop);
   }

   for (int i = 0; i < nthreads; i++)
   {
      threads[i]->join();
      totalCount += primes->getCount();
      std::cout << "Thread: " << i
                << "\nRange: " << prim[i]->getStart() << " - " << prim[i]->getStop()
                << "\nCount: " << prim[i]->getCount() << "\n";
   }
   std::cout << totalCount;

   return 0;
}
