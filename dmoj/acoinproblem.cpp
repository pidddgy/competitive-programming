#include <bits/stdc++.h>
#define maxv 10500
#define int long long
#define maxn 2005
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define eb emplace_back


using namespace std;

int pre[maxv];
int cur[maxv];
int d[maxn];


struct query {
    pii data;
    int ind;

    query(pii D, int I) {
        data = D;
        ind = I;
    }
};

bool compareQ(query &l, query &r) {
    if(l.data.fi == r.data.fi) {
        return l.data.se < r.data.se;
    }

    return l.data < r.data;
}
signed main() {
    int N, V;
    cin >> N >> V;

    for(int i = 1; i <= N; i++) cin >> d[i];


    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < maxv; j++) {
            pre[j] = INT_MAX;
            cur[j] = INT_MAX;
        }
    }

    pre[0] = 0;
    for(int i = 0; i < maxv; i++) {
        if(d[1]*i >= maxv) break;
        else {
            pre[d[1]*i] = i;
        }
    }

    vector<query> queries;
    for(int i = 1; i <= V; i++) {
        int c, l;
        cin >> c >> l;


        query thing = query({l,c}, i);

        queries.push_back(thing);
    }


    sort(queries.begin(), queries.end(), compareQ);


    map<int, int> ans;
    int qind =0;

    for(int i = 1; i <= 1; i++) {
        for(int j = 0; j < maxv; j++) {
            // cout << "dp at ind " << i << " " << j << " is " << pre[j] << endl;

            while((queries[qind].data.fi == i) and (queries[qind].data.se == j)) {
                ans[queries[qind].ind] = pre[j];
                qind++;
            }

        }
    }

    for(int i = 2; i <= N; i++) {
        cur[0] = 0;
        for(int j = 1; j < maxv; j++) cur[j] = INT_MAX;
        for(int j = 0; j < maxv; j++) {
            if(j-d[i] >= 0) {
                if(pre[j-d[i]] not_eq INT_MAX)
                    cur[j] = min(cur[j], pre[j-d[i]]+1);
                if(cur[j-d[i]] not_eq INT_MAX)
                    cur[j] = min(cur[j], cur[j-d[i]]+1);
                
            }

            cur[j] = min(cur[j], pre[j]);

            // cout << "dp at ind " << i << " " << j << " is " << cur[j] << endl;
            while((queries[qind].data.fi == i) and (queries[qind].data.se == j)) {
                ans[queries[qind].ind] = cur[j];
                qind++;
            }
        }

        for(int j = 0; j < maxv; j++) {
            pre[j] = cur[j];
        }

    }
    
    for(int i = 1 ; i<=V;i++) {
        if(ans[i] == INT_MAX) cout << -1 << endl; 
        else cout << ans[i] << endl;
    }
    
}