#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// void printArray(vector<int> v) {
//     cout<<"\n Returned Index : ";
//     for(auto itr = v.begin(); itr != v.end(); itr++) {
//         cout<<*itr<<" ";
//     }
// }

// void binarySearch(vector<int> elementArray, int searchElement, int size) {
//     vector<int> result;

//     for(int i=0; i<size; i++) {
//         if(binary_search(elementArray.begin(), elementArray.end(), searchElement)) {
//             result.push_back(i);
//         }
//         else {
//             result.push_back(-1);
//         }
//     }

//     printArray(result);
// };

// int bSearch(vector<int> elementArray, int searchElement, int low, int high) {
//     while(low <= high) {
//         int mid = (low+high)/2;

//         if(searchElement == elementArray[mid]) { // checking whether mid element is equal to search element
//             return mid;
//         }

//         if(searchElement > elementArray[mid]) { // if search element is greater than mid element then recurse to right
//             // return bSearch(elementArray, searchElement, low, mid+1);
//             low = mid+1;
//         }
//         else {
//             high = mid-1;
//         }

//         // return bSearch(elementArray, searchElement, low, mid-1); // if search element is less than mid element then recurse to left
//     }
//     return -1;
// }

int binary_search(vector<int> &a, int x)
{
  long long left = 0;
  long long right = (int)a.size() - 1;
  while (left <= right)
  {
    long long mid = left + (right - left) / 2;
    if (x == a[mid])
    {
      return mid;
    }
    if (a[mid] < x)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  // int mid = left + right / 2;
  return -1;
}

int main(int argc, char const *argv[])
{
    int number_of_element, number_of_key;
    vector<int> elementArray, keyArray;

    // cout<<"\n Enter number of element : ";
    cin>>number_of_element;

    // cout<<"\n enter element in array : ";
    for(int i=0; i<number_of_element; i++) {
        int input;
        cin>>input;
        elementArray.push_back(input);
    }

    // cout<<"\n Enter number of key : ";
    cin>>number_of_key;

    // cout<<"\n enter key in array : ";
    for(int i=0; i<number_of_key; i++) {
        int input;
        cin>>input;
        keyArray.push_back(input);
    }

    for(int i=0; i<keyArray.size(); i++) {
        // binarySearch(elementArray, keyArray[i], keyArray.size());
        // cout<<"\n\t element of keyArray : "<< keyArray[i];
        // cout<<bSearch(elementArray, keyArray[i], 0, keyArray.size()-1)<<" ";
        // cout<<bSearchFast(elementArray, keyArray[i], 0, keyArray.size()-1)<<" ";
        cout << binary_search(elementArray, keyArray[i]) << ' ';
    }
    return 0;
}
