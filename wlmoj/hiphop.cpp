// https://mcpt.ca/problem/lcc19c2s5

#include <bits/stdc++.h>
#define int long
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

struct query {
    int a, b, ind;

    query(int aa, int bb, int indd) {
        a = aa;
        b = bb;
        ind = indd;
    }
};

bool compq (query &l, query &r) {
    int lma = max(l.a, l.b);
    int lmi = min(l.a, l.b);

    int rma = max(r.a, r.b);
    int rmi = min(r.a, r.b);

    if(lma == rma) {
        return lmi <= rmi;
    } else return lma <= rma;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];
    
    vector<query> queries;
    int queryind = 0;
    for(int i = 1; i <= Q; i++) {
        int cute, cutee;
        cin >> cute >> cutee;
        queries.emplace_back(cute, cutee, i);
    }

    sort(queries.begin(), queries.end(), compq);

    // for(query x: queries) {
    //     cout << x.a << " " << x.b << " " << x.ind << endl;
    // }
    int answer[Q+1];

    int dp[N+1];
    for(int i = 1; i <= N; i++) {
        for(int i = 1; i <= N; i++) dp[i] = INT_MAX;
        dp[i] = 0;
        for(int j = i; j <= N; j++) {
            dp[i] = 0;
            dp[j+1] = min(dp[j+1], dp[j]+abs(a[j+1]-a[j]));
            // cout << "setting j+1 to " << dp[j+1] << endl;
            dp[j+2] = min(dp[j+2], dp[j]+abs(a[j+2]-a[j]));

            if((queries[queryind].a == i and queries[queryind].b == j) || (queries[queryind].a == j and queries[queryind].b == i)) {
                answer[queries[queryind].ind] = dp[j];
                queryind++;
            }

            // cout << "dp " << i << " " << j << " is " << dp[j] << endl;
        }
    }
    
    for(int i = 1; i <= Q; i++) {
        cout << answer[i] << endl;
    }
}