// https://dmoj.ca/problem/dmopc15c6p3

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

long long d[200005];
int main() {
    #define int long long
    int N, M, K;
    cin >> N >> M >> K;

    
    for(int i = 1; i <= N; i++)  d[i] = 0;

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        d[a]--;
        d[b+1]++;
    }

    for(int i = 1; i <= N; i++) d[i] += d[i-1];
    for(int i = 1; i <= N; i++) d[i] += M;

    //for(int i = 1; i <= N; i++) cout << d[i] << endl;

    int r = 1;
    int ret = 2147483647;
    int sum = 0;

    for(int l = 1; l <= N; l++) {
        while(sum < K && r <= N) {
           // watch(l)
            //watch(r)
            sum += d[r];

            //watch(sum)

            //cout << endl;
            r++;
        }

        if(sum < K) break;

        ret = min(r-l, ret);
        sum -= d[l];
    }

    if(ret == 2147483647) cout << -1 << endl;
    else cout << ret << endl;
}

