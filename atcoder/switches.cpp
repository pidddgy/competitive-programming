// https://atcoder.jp/contests/abc128/tasks/abc128_c

#include <bits/stdc++.h>
#define pb push_back
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int ans = 0;
int N, M;
vector<int> A[15];
int p[15];
void permute(string s =".") {
    if(s.size()==N+1) {
       // watch(s)
        bool all = true;
        for(int i = 1; i <= M; i++) {
            int cnt = 0;
            for(int j: A[i]) {
               // cout << "a_" <<i <<" has " << j << endl;
                if(s[j]=='1') cnt++;
            }

            if(cnt%2!=p[i]) {
                all=false;
            }
        //    cout << "cnt for " << i << " is " << cnt << endl;
        } 

        if(all) {
          //  cout << "works" << endl;
            ans++;
        }
       // cout << endl;
    } else {
        permute(s+"1");
        permute(s+"0");
    }
}
int main() {
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        int a;
        cin >> a;
        for(int j = 1; j <= a; j++) {
            int b;
            cin >> b;

            A[i].pb(b);
            
        }
    }

    for(int i = 1; i <= M; i++) cin >> p[i];
    permute();
    cout << ans << endl;

}