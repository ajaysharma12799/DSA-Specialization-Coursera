#include <iostream>

using namespace std;

int number_of_coin(int number) {
    int count = 0;
    while(number != 0) {
        if(number >= 10) {
            number -= 10;
            count++;
        }
        else if (number >= 5) {
            number -= 5;
            count++;
        }
        else {
            number -= 1;
            count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int number, result;
    cin>>number;   
    result = number_of_coin(number);
    cout<<result;
    return 0;
}
