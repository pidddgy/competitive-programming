// https://codeforces.com/contest/704/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

queue<int> e[300500];
queue<pii> Q;
map<int, int> marked;
int unread = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int lastPushed = 0;
    for(int ind = 1; ind <= q; ind++) {
        int type, x;
        cin >> type >> x;

        if(type == 1) {
            lastPushed++;
            e[x].push(lastPushed);
            Q.push(pii(lastPushed, x));
            unread++;
        } else if(type == 2) {
            unread -= e[x].size();

            // watch(unread)
            // watch(x)
            // watch(e[x].size())
            while(e[x].size()) {
                marked[e[x].front()] = true;
                e[x].pop();
            }
        } else if(type == 3) {
            while(!Q.empty() and Q.front().fi <= x) {
                pii ix = Q.front();
                Q.pop();
                
                if(!marked[ix.fi]) {
                    marked[ix.fi] = true;
                    e[ix.se].pop();
                    unread--;
                }
            }
        }

        cout << unread << endl;
    }
}