// https://codeforces.com/contest/1248/problem/A    

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int t; cin >> t;

    while(t--) {
        int ans = 0;
        int N; cin >> N;

        int p[N];
        unordered_map<int, int> pcnt;
        int podd = 0, peven = 0, qodd = 0, qeven = 0;
        for(int i = 0; i < N; i++) {
            cin >> p[i];
            if(p[i] % 2 == 0) {
                peven++;
            } else {
                podd++;
            }

            ans += pcnt[p[i]]; 
            pcnt[p[i]] ++;
        }

        int M;
        cin >> M;

        int q[M];
        unordered_map<int, int> qcnt;

        for(int i = 0; i < M; i++) {
            cin >> q[i];
            if(q[i]%2==0){
                qeven++;
            } else {
                qodd++;
            }

            ans += qcnt[q[i]];
            qcnt[q[i]]++;


        }

        // int toteven = peven + qeven;
        // int totodd = podd + qodd;
        // ans += (toteven * (toteven-1)) / 2;

        // ans += (totodd * (totodd-1)) / 2;

        ans += peven * qeven;
        ans += podd * qodd;

        // watch(peven);
        // watch(qeven);
        // watch(podd)
        // watch(qodd)

        

        cout << ans << endl;

        // cout<<endl;
    }
}