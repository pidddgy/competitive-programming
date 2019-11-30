// https://dmoj.ca/problem/wac1p3

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define MAXN 100005
#define MAXINT 2147483647
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int par[MAXN];
int depth[MAXN];
vector<int> children[MAXN];
bool vis[MAXN];
bool compLeaf(pii l, pii r) {
    return l.se > r.se;
}
int main() {
    
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < MAXN; i++) depth[i] = MAXINT;

    int N, M, K;
    cin >> N >> M >> K;

    for(int i = 2; i <= N; i++) {
        cin >> par[i];

        children[par[i]].emplace_back(i);
    }

    stack<int> st;
    vector<pii> leaf;

    st.push(1);
    depth[1] = 0;

    while(!st.empty()) {
        int S = st.top();  
        st.pop();

        if(children[S].empty()) {
            leaf.emplace_back(S, depth[S]);
        }

        for(int adj: children[S]) {
            if(depth[adj] > depth[S]+1) {
                depth[adj] = depth[S]+1;
                st.push(adj);
            }
        }
    }

    sort(leaf.begin(), leaf.end(), compLeaf);
    
    int ind = 1;
    vector<int> ans;

    par[1] = -1;
    for(pii l: leaf) {
        int ap = 0;
        int cur = l.fi;

        for(;;) {
            if(vis[cur]) break;
            vis[cur] = true;
            ap++;
            cur = par[cur];
            if(cur==-1)break;
        }

        ans.push_back(ap);
    }

    sort(ans.begin(), ans.end(), greater<int>());
    while(ans.size() < M) ans.emplace_back(0);
        //for(auto x: ans) cout << x << endl;

    int i = 1;
    ind = 0;
    while(i <= M) {
        if(i == M) cout << ans[ind];
        else cout << ans[ind] << " ";

        i++;
        ind++;
        if(ind == K) ind = 0;
    } 
    cout << endl;
}