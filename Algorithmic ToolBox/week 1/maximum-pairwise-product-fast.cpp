#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
long long maxPairwiseProduct(const vector<int>& v) {
    long long product = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            // product = max(product, (long long(v[i])) * v[j]);
            if( (long long)(v[i])*v[j] > product) {
                product = (long long)(v[i]) * v[j];
            }
        }
    }
    return product;
}

long long maxPairwiseProductFast(const vector<int>& v) {
    int size = v.size();

    int maxIndex1 = -1;
    for(int i=0; i<size; i++)
        if( (maxIndex1 == -1) || (v[i] > v[maxIndex1]) )
            maxIndex1 = i;
    
    int maxIndex2 = -1;
    for(int j=0; j<size; j++)
        if( (j != maxIndex1) && ( (maxIndex2 == -1) || (v[j] > v[maxIndex2]) ) )
            maxIndex2 = j;
    
    return ( (long long) (v[maxIndex1]) ) * v[maxIndex2];
}

int main(int argc, char const *argv[])
{
    int n, input;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>input;
        v.push_back(input);
    }
    long long result = maxPairwiseProductFast(v);
    cout<<result;
    return 0;
}
