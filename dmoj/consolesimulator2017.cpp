// https://dmoj.ca/problem/dmopc16c2p6

#include <bits/stdc++.h>
#define pis pair<int, string>
#define fi first
#define se second
using namespace std;

map<string, vector<string>> G;
vector<pis> inp;
int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a; 
        string b;

        cin >> a >> b;
        inp.emplace_back(a, b);
    }

    vector<string> cur;
    G[inp[0].se] = vector<string>();
    cur.push_back(inp[0].se);
    for(int i = 1; i < inp.size(); i++) {
        // cout << "currently on " << inp[i].fi << " " << inp[i].se << endl;
        if(inp[i].fi < inp[i-1].fi) {
            cur.pop_back();
            // cout << "popping" << endl;
        } else if(inp[i].fi > inp[i-1].fi) {
            cur.push_back(inp[i].se);
            // cout << "pushing" << endl;
        }

        G[*(cur.rbegin()-1)].emplace_back(inp[i].se);
        cout << "emplacing back " << inp[i].se << " to " << *(cur.rbegin()-1) << endl;
    }

}