// https://codeforces.com/contest/1371/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

int a[400][400];

void clear() {
    for(int i = 0; i < 400; i++) {
        for(int j = 0; j < 400; j++) {
            a[i][j] = 0;
        }
    }
}

int sq(int n) {
    return n*n;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        clear();

        int n, k;
        cin >> n >> k;

        int cnt = 0;
        int o = 0;
        while(cnt < k) {
            int i = 0;
            int j = i+o;
            for(int tmp = 0; tmp < n; tmp++) {
                a[i][j] = 1;
                j++;
                j %= n;
                cnt++;
                i++;

                if(cnt == k) break;
            }
            if(cnt == k) break;
            o++;
        }


        int mir = INT_MAX, mar = 0;
        int mic = INT_MAX, mac = 0;

        for(int i = 0; i < n; i++) {
            int rsum = 0, csum = 0;
            for(int j = 0; j < n; j++) {
                rsum += a[i][j];
                csum += a[j][i];
            }    

            mir = min(mir, rsum);
            mar = max(mar, rsum);

            mic = min(mic, csum);
            mac = max(mac, csum);
        }

        cout << sq(mar-mir) + sq(mac-mic) << endl; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }    
}

/*
11111
11111

2, 1
12111
21111

3, 2
12211
22111

4, 3
12221
22211

5, 4
12222
22221

1, 5
22222
22222

22222
22222

*/