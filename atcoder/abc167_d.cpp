// https://atcoder.jp/contests/abc167/tasks/abc167_d

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

const int maxn = 200500;

// seen when we had x left
int A[maxn], seen[maxn];

void timeOut() {
    while(1) {

    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        seen[i] = -1;
    }

    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    bool modded = false;
    int cur = 1;
    
    while(K > 0) {
        seen[cur] = K;
        int next = A[cur];

        if(seen[next] != -1 and !modded) {
            int cycleLen = seen[next]-seen[cur]+1;
            K %= cycleLen;
            modded = true;
            continue;
        }

        cur = next;
        K--;
    }
    
    cout << cur << endl;
}
