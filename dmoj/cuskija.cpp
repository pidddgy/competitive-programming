// https://dmoj.ca/problem/coci08c6p4

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a[4];
    
    for(int i = 0; i < N; i++) {
        int b;
        cin >> b;

        a[b%3].emplace_back(b);
    }

    vector<int> ret;

    while(a[0].size() > 1) {
        ret.emplace_back(a[0].back()); a[0].pop_back();

        if(!a[1].empty()) {
            ret.emplace_back(a[1].back()); a[1].pop_back();
        } else if (!a[2].empty()) {
            ret.emplace_back(a[2].back()); a[2].pop_back();
        } else {
            puts("impossible");
            return 0;
        }
    }

    while(!a[1].empty()) {
        ret.emplace_back(a[1].back()); a[1].pop_back();
    }

    if(!a[0].empty()) {
        ret.emplace_back(a[0].back());
    } else if(ret.size() != 0) {
        puts("impossible");
        return 0;
    }

    while(!a[2].empty()) {
        ret.emplace_back(a[2].back()); a[2].pop_back();
    }

    for(auto x: ret) cout << x << " ";
    cout << endl;
}
