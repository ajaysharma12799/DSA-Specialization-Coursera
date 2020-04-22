#include <iostream>
#include <vector>

using namespace std;

int fib(long long n) {
    if (n <= 1) {
        return n;
    }

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
};

int main(int argc, char const *argv[])
{
    int number, result;
    cin>>number;
    result = fib(number);
    cout<<result;
    return 0;
}
