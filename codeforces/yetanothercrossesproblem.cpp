// http://codeforces.com/contest/1194/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    while(q--) 
    {
        int n, m;
        cin >> n >> m;

        int rcnt[n+1];
        int ccnt[m+1];
        int map[n+1][m+1];
        for(int i = 1; i <= n; i++) rcnt[i] = 0;
        for(int i = 1; i <= m; i++) ccnt[i] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                char sq;
                cin >> sq;

                map[i][j] = sq;
    

                if(sq == '*') {
                    rcnt[i]++;
                    ccnt[j]++;
                }
            }
        }

        int mi = (n+m)-1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int co = (n-rcnt[i]) + (m-ccnt[j]);
                if(map[i][j] == '.') {
                    co--;
                 //   cout << "HI" << endl;
                }

                mi = min(mi, co);
            }
        }

        cout << mi << endl;
    }
}
