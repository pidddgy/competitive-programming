// https://codeforces.com/contest/1262/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define pii pair<int ,int>
#define fi first
#define se second

void rev(string &aa, int l, int r) {
    int rr;
    if((r-l+1) % 2 == 1) {
        rr = ((l+r)/2) - 1;
    } else {
        rr = (l+r)/2;
    }

    watch(rr)
    int R = r;
    for(int i = l; i <= rr; i++) {
        swap(aa[i], aa[R]);
        R--;

    }
}
int main() {
    // string s = ".))())(((";
    // rev(s, 3, 5);
    // cout << s << endl;
    int T;
    cin >> T;

    while(T--) {
        int n, k;
        cin >> n >> k;
        string s; cin >> s;
        s = "."+s;

        vector<pii> ans;
        
        
        while(true) {
            bool change = false;
            for(int i = 1; i <= n-1; i++) {
                if(s[i] == ')' and s[i+1] == '(') {
                    swap(s[i], s[i+1]);
                    ans.emplace_back(i, i+1);
                    change = true;
                }
            }
            if(!change) break;
        }

        int cnt = 0;
        while(cnt < k) {
            for(int i = 2; i <= n-2; i++) {
                if(s[i] == '(' and s[i+1] == ')') {
                    swap(s[i], s[i+1]);
                    ans.emplace_back(i, i+1);
                    cnt++;
                    if(cnt == k) break;
                }
            }
        }

        cout << ans.size() << endl;
        for(pii x: ans) {
            cout << x.fi << " " << x.se << endl;
        }

     


    }
}