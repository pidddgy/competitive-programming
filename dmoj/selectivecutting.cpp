// https://dmoj.ca/problem/dmopc14c2p6

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define int long long
using namespace std;
int N;

struct Query {
    int a;
    int b;
    int q;
    int index;
};

struct Compare {
     bool operator()(Query l, Query r) {
        return l.q > r.q; 
    }
};

int bit[100500];

void add(int ind, int val) {
    for(int i = ind; i <= N; i += i & -i) {
        bit[i] += val;
    }
}

int sum(int l, int r) {
    int lans = 0;
    for(int i = l-1; i >= 1; i -= i & -i) {
        assert(i != 0);

        lans += bit[i];
    }

    int rans = 0;
     for(int i = r; i >= 1; i -= i & -i) {
        assert(i != 0);

        rans += bit[i];
    }

    return rans-lans;
}

signed main() {
    cin >> N;
    
    vector<int> vals[20005];
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        vals[a].emplace_back(i);
    }

    int Q;
    cin >> Q;

    Query queries[Q+1];
    for(int i = 1; i <= Q; i++) {
        cin >> queries[i].a >> queries[i].b >> queries[i].q;
        queries[i].index = i;

        queries[i].a++;
        queries[i].b++;
    }

    sort(queries+1, queries+Q+1, Compare());

    // for(int i = 1; i <= Q; i++) {
    //     cout << queries[i].a << " " << queries[i].b << " " << queries[i].q << endl;
    // }

    int qind = 1;
    int massind = 20000;
    
    map<int, int> ans;

    while(massind >= 1) {
        for(int x: vals[massind]) {
            // cout << "adding to " << x << " from " << massind << endl;
            add(x, massind);
        }

        for(; qind <= Q; qind++) {
            if(queries[qind].q >= massind) {
                // cout << "querying " << queries[qind].a << " " << queries[qind].b << " " << queries[qind].q << endl;
                ans[queries[qind].index] = sum(queries[qind].a, queries[qind].b);
                // cout << "answer for query " << queries[qind].index << " is " << ans[queries[qind].index] << endl;
            } else {
                break;
            }
        }
        massind--;
        // cout << endl;
    }

    assert(qind == Q+1);

    for(int i = 1; i <= Q; i++ ) {
        cout << ans[i] << endl;
    }
}