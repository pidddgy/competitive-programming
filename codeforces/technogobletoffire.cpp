// https://codeforces.com/problemset/problem/1121/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    
    int p[N+1];
    int s[N+1];

    for(int i = 1; i <= N; i++) cin >> p[i];
    for(int i = 1; i <= N; i++) cin >> s[i];

    int st[M+1];
    fill(st, st+M+1, false);
    for(int i = 1; i <= N; i++) {
        st[s[i]] = max(st[s[i]], p[i]);
    }

    int res = 0;
    while(K--) {
        int a;
        cin >> a;

        if(st[s[a]] != p[a]) {
            res++;
        }
    }

    cout << res << endl;

}
