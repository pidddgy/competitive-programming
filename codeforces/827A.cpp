// https://codeforces.com/contest/827/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

const int maxn = 3000500;

char ans[maxn];
string strs[maxn];
int at[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < maxn; i++) {
        ans[i] = 'a';
        at[i] = -1;
    }

    int n;
    cin >> n;

    int len = 0;
    for(int i = 1; i <= n; i++) {
        string t;
        int k;
        cin >> t >> k;

        strs[i] = t;

        while(k--) {
            int x;
            cin >> x;

            if(at[x] == -1) {
                at[x] = i;
            } else if(strs[at[x]].size() < t.size()) {
                at[x] = i;
            }
            len = max(len, (int)x+((int)t.size()-1));
        }
    }

    int cur = -1;
    int curPos = -1;
    for(int i = 1; i <= len; i++) {
        if(at[i] != -1) {
            if(cur == -1) {
                cur = at[i];
                curPos = 0;
            } else {
                int stay = i + strs[cur].size()-curPos-1;
                int change = i+ strs[at[i]].size()-1;

                if(change >= stay) {
                    cur = at[i];
                    curPos = 0;           
                }

            }
        }
        
        if(curPos == -1 or cur == -1) {
            cout << 'a';
            continue;
        }
        if(curPos < strs[cur].size()) {
            cout << strs[cur][curPos];
        } else {
            cout << 'a';
        }

        curPos++;
    }

    cout << endl;
}