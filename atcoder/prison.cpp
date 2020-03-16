// https://atcoder.jp/contests/abc127/tasks/abc127_c

#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int psa[maxn];
int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int l, r;
        cin >> l >> r;

        psa[l]++;
        psa[r+1]--;
    }

    for(int i = 1; i < maxn; i++) {
        psa[i] += psa[i-1];
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
  //      cout << psa[i] << endl;
        if(psa[i] == M) ans++;
    }

    cout<<ans<<endl;
}
