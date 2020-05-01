// https://codeforces.com/contest/1238/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define int long long
    #define endl '\n'
    srand(time(0));

    int t;
    cin >> t;

    while(t--) {
        int h, n;
        cin >> h >> n;

        vector<int> a;
        for(int i = 1; i <= n; i++) {
            int _;
            cin >> _;
            
            a.emplace_back(_);
        }

        if(a.back() != 0) a.emplace_back(0);
        int mi = INT_MAX;
        for(int r = 0; r < 300; r++) {
            int ans = 0;
            for(int i = 0; i < a.size()-1;) {
                if(a[i]-a[i+1] == 1) {
                    if(a[i+1] == 0) break;

                    if(a[i]-a[i+2] == 2) {
                        i = i+2;
                    } else {
                        ans += (a[i]-a[i+2])/2;
                    }
                    i = i+2;
                } else if(a[i]-a[i+1] == 2) {
                    i++;
                } else {
                    ans += (a[i]-a[i+1]) / 2;
                    i++;
                    if(rand() % 4 == 0) {
                        a[i]--;
                    } else if (rand() % 4 == 1) {
                        a[i]++;
                    }
                }
            }
            mi = min(mi, ans);
        }


        cout << mi << endl;
    }
}