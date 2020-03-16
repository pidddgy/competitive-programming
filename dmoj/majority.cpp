// https://dmoj.ca/problem/dmopc19c3p3

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'

    int N;
    cin >> N;
    
    int a[N+1];
    vector<int> ind;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        if(a[i] == 1) {
            ind.emplace_back(i);
        }
    }

    int psa[N+1];
    psa[0] = 0;

    for(int i = 1; i <= N; i++) {
        psa[i] = psa[i-1];
        if(a[i] == 1) psa[i]++;
    }



}