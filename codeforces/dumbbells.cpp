// https://codeforces.com/problemsets/acmsguru/problem/99999/549

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int m[n+1];
    int c[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> m[i] >> c[i];
    }

    // try to sum to sum
    for(int sum = 1; sum <= 8003; sum++) {
        priority_queue<int> a[4005];
        
        for(int i = 1; i <= n; i++) {
            a[m[i]].push(c[i]);
        }
        
        for(int i = 1; i <= 4000; i++) {
            while(!a[i].empty() && !a[sum-i].empty())
        }
        


    }
}