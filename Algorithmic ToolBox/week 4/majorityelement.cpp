#include <algorithm>

#include <iostream>

#include <vector>

using namespace std;

// int majorityElement(vector < int > v) {
//     int size = v.size();
//     for (int i = 0; i < v.size(); i++) {
//         int currentElement = v[i], count = 0;
//         for (int j = 0; j < v.size(); j++) {
//             if (v[j] == currentElement) {
//                 count++;
//             }
//         }

//         if (count > (size / 2)) {
//             // return v[i];
//             return 1;
//         }
//     }
//     return 0;
// }

int majorityElementFast(vector < int > v) { // this function take time-complexity of O(n logn)

    int count = 0, maxElement = -1, temp = v[0], vectorSize = v.size();

    sort(v.begin(), v.end()); // sorting array
    for (int i = 0; i < v.size(); i++) {
        if (temp == v[i]) { // checking if same element occour then increse count
            count++;
        } else { // else checking with other elements
            count = 1;
            temp = v[i];
        }

        if (maxElement < count) {
            maxElement = count;
            if (maxElement > (vectorSize / 2)) {
                return 1;
            }
        }
    }
    return 0;

}

// int majorityRecursive(vector<int> v, int left, int right) {

// }

int main(int argc, char const * argv[]) {
    // CODE WILL COME HERE
    int number_of_element, result;
    vector < int > v;

    // cout << "\n enter number of element : ";
    cin >> number_of_element;

    for (int i = 0; i < number_of_element; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    result = majorityElementFast(v);
    // cout << "Majority of Element : " << result;
    cout<<result;
    return 0;
}