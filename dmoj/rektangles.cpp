// https://dmoj.ca/problem/ac19p4

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

map<pii, bool> have;
int main() {
    int N;
    cin >> N;
    vector<pii> cute;
    cute.emplace_back(420, 69);
    for(int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        cute.emplace_back(a, b);
        
        have[{a, b}] = true;

    }

    int ma = -2147483647;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;

            // cout << "on " << cute[i].fi << "," <<  cute[i].se << " ";
            // cout << "with " << cute[j].fi << "," <<  cute[j].se << endl;

            int a = cute[i].fi;
            int b = cute[i].se;
            int x = cute[j].fi;
            int y = cute[j].se;
            if(a >= x or b >= y) continue;

            // cout << "checking for " << a << "," << y << " and " << x << "," << b << endl;

            if(have[{a, y}] and have[{x, b}]) {
                // cout << "found" << endl;
                // cout << "area would be " << abs(x-a) * abs(y-b) << endl;
                ma = max(ma, abs(x-a) * abs(y-b));
            }
            // cout << endl;
        }
    }

    ma = max(0, ma);
    cout << ma << endl;
}