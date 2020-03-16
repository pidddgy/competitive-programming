// http://codeforces.com/contest/1213/problem/D2

#include <bits/stdc++.h>
#define maxn 200500
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    sort(a+1, a+N+1);

    vector<int> cute[maxn];
    for(int i = 1; i <= N; i++) {
        int j = 0;
        while(a[i]) {
            if(cute[a[i]].size() != K) {
                cute[a[i]].emplace_back(j);
            }
            j++;
            a[i] = floor(a[i]/2);
        }
        if(cute[a[i]].size() != K) {
            cute[a[i]].emplace_back(j);
        }
    }

    int ans = 2147483647;
    for(int i = 0; i <= maxn-5; i++) {
        int op = 0;
        for(int x: cute[i]) {
            op += x;
        }

        if(cute[i].size()==K)
        ans = min(ans, op);
    }

    cout << ans << endl;
}