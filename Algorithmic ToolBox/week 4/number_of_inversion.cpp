#include <iostream>
#include <vector>

using namespace std;

int number_of_inversion(vector<int> v) {
    int count = 0;
    for(int i=0; i<v.size()-1; i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i] > v[j]) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    int number_of_element, result;
    // cout<<"\n enter number of input : ";
    cin>>number_of_element;
    // cout<<"\n enter element in array : ";
    for(int i=0; i<number_of_element; i++) {
        int input;
        cin>>input;
        v.push_back(input);
    }
    result = number_of_inversion(v);
    // cout<<"\n number of inversion are : "<<result;
    cout<<result;
    return 0;
}
