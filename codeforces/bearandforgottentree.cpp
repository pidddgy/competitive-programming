// https://codeforces.com/contest/639/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define pii pair<int, int>
#define fi first
#define se second
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, d, h;
    cin >> n >> d >> h;

    vector<int> G[100050];
    vector<pii> out;
    int curNode = 2;
    int cur = 1;
    int attach = -1;
    set<int> nochoose;
    set<int> used;
    for(int i = 1; i <= h; i++) {
        cerr << "making edge betweeeen " << cur << " and " << curNode << endl;
        G[cur].emplace_back(curNode);
        G[curNode].emplace_back(cur);

        out.emplace_back(curNode, cur);
        used.emplace(curNode);
        used.emplace(cur);


        if(attach == -1) {
            attach = curNode;
        }
        curNode++;
        cur++;
    }

    cerr << "dont touch " << cur << endl;
    nochoose.emplace(cur);
    cur = 1;

    cerr << "now adding " << d-h << endl;
    for(int i = 1; i <= d-h; i++) {
        cerr << "making edge between " << cur << " and " << curNode << endl;
        G[cur].emplace_back(curNode);
        G[curNode].emplace_back(cur);
        
        out.emplace_back(curNode, cur);
        used.emplace(curNode);
        used.emplace(cur);

        cur = curNode;
        curNode++;
    }
    nochoose.emplace(curNode-1);
    
    watch(attach)
    watch(curNode)
    if(G[1].size() == 1)
    nochoose.emplace(1);

    for(int x: used) {
        watch(x)
        if(nochoose.count(x) == 0) {
            int attach = x;
while(curNode <= n) {
            cerr << "making edge betweeeen " << attach << " and " << curNode << endl;
            out.emplace_back(attach, curNode);
            G[attach].emplace_back(curNode);
            G[curNode].emplace_back(attach);


            curNode++;
        }
        }
        
   
    }
    watch(out.size())

    if(curNode != n+1 or out.size() != n-1 or h*2 < d or d > n or h > n) {
        cout << -1 << endl;
    } else {
        for(pii x: out) {
            cout << x.fi << " " << x.se << endl;
        }
    }

}