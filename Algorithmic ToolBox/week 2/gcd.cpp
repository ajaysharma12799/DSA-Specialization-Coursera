#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

/*
    this function is used to find gcd of number and store them into vector
*/

// void findGCD(int number1, int number2) {
//     vector<int> v;
//     vector<int> :: iterator itr;

//     for(int i=2; i<=number1 && i<=number2; i++) {
//         if(number1%i == 0 && number2%i == 0) {
//             v.push_back(i);
//         }
//     }
//     // cout<<"\n Factor are : ";
//     for(itr = v.begin(); itr != v.end(); itr++) {
//         // cout<<*itr<<"  ";
//         cout<<*itr;
//     }
// };

/*
    this function is for calculating gcd very slow algorithm
    this algorithm is brute-force approach
*/

// int gcdNaive(int number1, int number2) {
//     int current_gcd = 1;
//     for(int i=2; i<=number1 && i<=number2; i++) {
//         if( (number1%i == 0) && (number2%i == 0) ) {
//             current_gcd = i;
//         }
//     }
//     return current_gcd;
// }

// int euclidGCD(int number1, int number2) {
//     if(number1 == 0) {
//         return number2;
//     }
//     return euclidGCD(number2 % number1, number1);
// }

template <typename t>
t euclidGCD(t number1, t number2) {
    if(number1 == 0) {
        return number2;
    }
    return euclidGCD(number2 % number1, number1);
}

int main(int argc, char const *argv[])
{
    long number1, number2;
    cin>>number1>>number2;

    // findGCD(number1, number2);
    // cout<<gcdNaive(number1, number2);
    cout<<euclidGCD<long long>(number1, number2);
    
    return 0;
}
