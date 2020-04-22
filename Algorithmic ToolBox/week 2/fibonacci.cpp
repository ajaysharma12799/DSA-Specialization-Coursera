#include <iostream>
#include <math.h>

#define MAX 1000

using namespace std;

int f[MAX] = { 0 };

int fibonacciNaive(int n) { // normal fibonacci algo
    if(n <= 1) {
        return n;
    }
    return fibonacciNaive(n-1) + fibonacciNaive(n-2);
}

int fibonacciFast(int n) { // fast fibonacci algo using golden ratio
    double phi = (1 + sqrt(5)) / 2;
    int fib = pow(phi, n) / sqrt(5);
    return fib;
}

int fibonacciMemoisation(int n) { // fibonacci algo using memoisation
    if(n == 0) {
        return 0;
    }
    if(n == 1 || n == 2) {
        return (f[n] = 1);
    }

    if(f[n]) { // if f[n] is already computed
        return f[n];
    }
    int k = (n & 1)? (n+1)/2 : n/2;

    f[n] = (n & 1)? (fibonacciMemoisation(k)*fibonacciMemoisation(k) + fibonacciMemoisation(k-1)*fibonacciMemoisation(k-1)) : (2*fibonacciMemoisation(k-1) + fibonacciMemoisation(k))*fibonacciMemoisation(k);

    return f[n];
}

int main(int argc, char const *argv[])
{
    int number, fibNaive, fibFast, fibMemo;
    cin>>number;

    f[0] = 0; f[1] = 1;

    // fibNaive = fibonacciNaive(number);
    // fibFast = fibonacciFast(number);
    fibMemo = fibonacciMemoisation(number);

    cout<<fibMemo;
    return 0;
}