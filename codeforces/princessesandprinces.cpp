// https://codeforces.com/contest/1327/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        
        int notmatched = -1;
        unordered_map<int, bool> princetaken;
        for(int i = 1; i <= N; i++) {
            int k;
            cin >> k;

            bool matched = false;

            for(int j = 1; j <= k; j++) {
                int g;
                cin >> g;
                if(!princetaken[g] and !matched) {
                    princetaken[g] = true;
                    matched = true;
                }
            }
            if(!matched) notmatched = i;

        }

        if(notmatched == -1) {
            cout << "OPTIMAL" << endl;
        } else {
            for(int i = 1; i <= N; i++) {
                if(princetaken[i] == false) {
                    cout << "IMPROVE" << endl;
                    cout << notmatched << " " << i << endl;
                    break;
                }
            }
        }

    }
}