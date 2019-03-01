// https://dmoj.ca/problem/nccc7j3

#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int N, K;
    cin >> N >> K;
    
    cout << N - (N / (K+1)) << endl;
}
