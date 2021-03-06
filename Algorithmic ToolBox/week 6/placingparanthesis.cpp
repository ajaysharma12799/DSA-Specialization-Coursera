#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long eval(long long a, long long b, char op){
    if (op == '*'){
        return a * b;
    }
    else if (op == '+'){
        return a + b;
    }
    else if (op == '-'){
        return a - b;
    }
    else{
        assert(0);
    }
}
vector<long long> MinAndMax(int i, int j, vector <vector<long long> > m, vector <vector<long long> > M, vector<char> op){
    long long MIN = LLONG_MAX;
    long long MAX = LLONG_MIN;
    for(int k = i; k < j; k++){
        long long a = eval(M[i][k], M[k+1][j], op[k]);
        long long b = eval(M[i][k], m[k+1][j], op[k]);
        long long c = eval(m[i][k], M[k+1][j], op[k]);
        long long d = eval(m[i][k], m[k+1][j], op[k]);
        MIN = min(MIN, min(a, min(b, min(c, d))));
        MAX = max(MAX, max(a, max(b, max(c, d))));
    }
    vector<long long> MinMax(2);
    MinMax[0] = MIN;
    MinMax[1] = MAX;
    return MinMax;
}
long long get_maximum_value(const string &exp){
    int n = (exp.size() + 1)/2;
    vector <vector<long long> > Min(n, vector<long long>(n));
    vector <vector<long long> > Max(n, vector<long long>(n));
    vector<char> Operator(exp.size()-n);
    for(int i = 0; i < exp.size(); i++){
        if(i % 2 == 0){
            Min[i/2][i/2] = exp.at(i)-48;
            Max[i/2][i/2] = exp.at(i)-48;
        }
        else
            Operator[(i-1)/2] = exp.at(i);
    }
    for(int s = 1; s < n; s++){
        for(int i = 0; i < (n-s); i++){
            vector<long long> MinMax(2);
            int j = i + s;
            MinMax = MinAndMax(i, j, Min, Max, Operator);
            Min[i][i+s] = MinMax[0];
            Max[i][i+s] = MinMax[1];
        }
    }
    return Max[0][n-1];
}

int main(){
    string s;
    cin >> s;
    cout << get_maximum_value(s) << '\n';
}