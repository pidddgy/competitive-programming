// https://codeforces.com/contest/1315/problem/B

#include <bits/stdc++.h>
#define cerr if(false) cerr
using namespace std;
int main() {
    #define int long long
    int t;
    cin >> t;

    while(t--) {
        int a, b, p;
        cin >> a >> b >> p;

        string s;
        cin >> s;

        int N = s.size();

        s = "."+s;

        int dis[N+1];
        for(int i = 1; i <= N; i++) {
            dis[i] = 0;
        }

        int cost = 0;
        char cur = '?';
        for(int i = N-1; i >= 1; i--) {
            if(s[i] != cur) {
                if(s[i] == 'A') {
                    cost += a;
                } else if(s[i] == 'B') {
                    cerr << "HIII" << endl;
                    cost += b;
                }
                cur = s[i];
            }

            dis[i] = cost;
        }

        dis[N] = 0;



        for(int i = 1; i <= N; i++) {
            cerr << dis[i] << " ";
        }
        cerr << endl;
        for(int i = 1; i <= N; i++) {
            if(dis[i] <= p) {
                cout << i << endl;
                break;
            }
        }


        cerr << endl;
        cerr << endl;


    }
}