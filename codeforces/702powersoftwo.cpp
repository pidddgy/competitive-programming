// https://codeforces.com/contest/702/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long

    vector<int> a;
    
    for(int i = 0; i <= 30; i++) {
        a.emplace_back(pow(2, i));
    }

    int N;
    cin >> N;

    unordered_map<int, int> have;

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        for(int p: a) {
            ans += have[p-x];
        }
        have[x]++;

    }

    cout << ans << endl;
}