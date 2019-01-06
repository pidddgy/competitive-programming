// https://dmoj.ca/problem/nccc2j4s2

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    pii aqt[3];
    int totalArea = 0;
    for(int i = 0; i < 3; i++) {
        cin >> aqt[i].fi >> aqt[i].se;
        totalArea *= aqt[i].fi;
        totalArea *= aqt[i].se;
    }

    // Check if perfect square
    int root = round(sqrt(totalArea));
    if(pow(root, 2) == totalArea) {
        for(int i = 0; i < 3; i++) {
            
        }
    }
}