#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

// void findLCM(int number1, int number2) {
//     long long minValue = 0;
//     vector<int> v;
//     vector<int> :: iterator itr;

//     for(long i=1; i<= (long long)number1*number2; i++) {
//         if(i % number1 == 0 && i % number2== 0) {
//             v.push_back(i);
//         }
//     }
//     cout<<"\n Factor are : ";
//     for(itr = v.begin(); itr != v.end(); itr++) {
//         minValue = *min_element(v.begin(), v.end());
//         cout<<*itr<<"  ";
//         // cout<<*itr;
//     }
//     cout<<"\nMin Value : "<<minValue;
// }

int euclidGCD(int number1, int number2) {
    if(number1 == 0) {
        return number2;
    }
    return euclidGCD(number2 % number1, number1);
}

long long findLCMEuclid(long number1, long number2) {
    return (number1 * number2) / euclidGCD(number1, number2);
}

int main(int argc, char const *argv[])
{
    int number1, number2;
    cin>>number1>>number2;

    // findLCM(number1, number2);
    cout<<findLCMEuclid(number1, number2);
    
    return 0;
}
