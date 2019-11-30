// https://dmoj.ca/problem/tsoc16c1p5

#include <bits/stdc++.h>
using namespace std;

    vector<vector<short int>> P;

int main() {
    int N;
    cin >> N;

    vector<short int> orig;

    for(int i = 1; i <= N; i++) orig.emplace_back(i);


    P.emplace_back(orig);

    while(next_permutation(orig.begin(), orig.end())) {
        P.emplace_back(orig);
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int qi; cin >> qi;
        
        for(auto x: P[qi]) cout << x << " ";
        cout << endl;
    }
    
}
