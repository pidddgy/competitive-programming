// https://dmoj.ca/problem/ecoo18r1p2

#include <bits/stdc++.h>
using namespace std;
const int MAX_INT = 2147483647;
int main() {
    for(int tc = 0; tc < 10; tc++) {
        int N; cin >> N;
        vector<int> routes[N];
        int routeID[N];
        int minV = MAX_INT;

        for(int ro = 0; ro < N; ro++) {
            int ID; int R; 
            cin >> ID >> R;
            routeID[ro] = ID;
            int D;
            for(int i = 0; i < R; i++) {
                cin >> D;
                routes[ro].push_back(D);
                if(D < minV) minV = D;
            }
        }

        vector<int> cute;
        for(int ro = 0; ro < N; ro++) {
            for(int i = 0; i < routes[ro].size(); i++) {
                if(routes[ro][i] == minV) {
                    cute.push_back(routeID[ro]);
                    break;
                }
            }
        }
        sort(cute.begin(), cute.end());
        cout << minV << " {" << cute[0];
        if(cute.size() >= 2)
            for(int i = 1; i < cute.size(); i++) {
                cout << "," << cute[i];
            }
        cout << "}\n";
    }
}
