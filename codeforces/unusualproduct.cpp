// https://codeforces.com/contest/405/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    int n;
    cin >> n;

    int a[n+1][n+1];
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%i", &a[i][j]);

            if(i == j)
            sum += a[i][j];
        }
    }

    sum %= 2;

    int q;
    scanf("%i", &q);

    while(q--) {
        int type;
        scanf("%i", &type);

        if(type == 1 or type == 2) {
            int _;
            scanf("%i", &type);
            sum ^= 1;
        } else {
            printf("%i", sum);
        }
    }
    puts("");
}