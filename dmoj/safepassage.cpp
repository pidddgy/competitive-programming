// https://dmoj.ca/problem/naq15g

#include <bits/stdc++.h>
#define MAXINT 2147483647
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    string cloakLoc = "gate";
    vector<int> G;
    vector<int> D;
    for(int i = 0; i < N; i++) {
        int aqt;
        cin >> aqt;
        G.push_back(aqt);
    }

    sort(G.begin(), G.end());

    while(!G.empty()) {
        if(cloakLoc == "gate") {
            // Get two with least difference
            if(G.size() >= 2) {
                int minDiff = MAXINT;
                for(int i = 0; i < G.size()-1; i++) {
                    if(G[i+1] - G[i] < minDiff) {
                        minDiff = G[i+1] - G[i];
                    }
                }
            }
        }
        break;
    }
}