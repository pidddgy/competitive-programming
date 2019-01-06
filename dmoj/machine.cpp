// https://dmoj.ca/problem/lkp18c2p4

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N; string aqt;
    cin >> N;
    cin.ignore();
    getline(cin, aqt);
    int total = 0;
    set<string> thingy;
    for(int i = 0; i < N; i++) {
        string thing;
        for(int j = 0; j <= i; j++) {
            thing.push_back(aqt[j]);
        }
        if(equal(thing.rbegin(), thing.rend(), aqt.rbegin())) {
            thingy.insert(thing);
        }
    }

    for(int i = 0; i < N; i++) {
        string thing;
        for(int j = 0; j <= i; j++) {
            thing.push_back(aqt[N-j]);
        }
        if(strncmp(aqt.c_str(), thing.c_str(), thing.size()))
            thingy.insert(thing);
    }

    for(int len = 1; len <= N; len++) {
        for(int i = 0; i <= N-len; i++) {
            int j = i+len-1;

            string thing = "";
            for(int k = i; k <= j; k++) {
                thing.push_back(aqt[k]);
            }
            if(thingy.find(thing) != thingy.end()) {
                total++;
            }
        }
    }
    cout << total << endl;
}
