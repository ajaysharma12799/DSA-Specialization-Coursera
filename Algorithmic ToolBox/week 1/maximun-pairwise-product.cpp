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

int main(int argc, char const *argv[])
{
    int n, input;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>input;
        v.push_back(input);
    }
    long long result = maxPairwiseProduct(v);
    cout<<result;
    return 0;
}
