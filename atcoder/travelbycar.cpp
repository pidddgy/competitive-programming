// https://atcoder.jp/contests/abc143/tasks/abc143_e

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second


using namespace std;

// the thingy that goes inside priority queue
struct Cute {
    int refills;
    int tot;
    int dest;  

    Cute(int r, int t, int d) {
        refills = r;
        tot = t;
        dest = d;
    }
};

// return true if l and r need to be swapped
struct Compare {
    bool operator()(Cute &l, Cute &r) {
        if(l.refills > r.refills) return true;
        else if(l.refills < r.refills) return false;
        else if(l.refills == r.refills) {
            return l.tot > r.tot;
        }
    }
};

signed main() {
    // priority_queue<Cute, vector<Cute>, Compare> pq;
    // pq.push(Cute(1, 1, 2));
    // pq.push(Cute(2, 1, 2));
    // pq.push(Cute(1, 1, 3));
    // pq.push(Cute(2, 2, 4));
    // pq.push(Cute(2, 1, 3));
    // pq.push(Cute(1, 23, 3));

    // while(pq.size()) {
    //     Cute S = pq.top();
    //     pq.pop();
    //     cout << S.refills << " " << S.tot << " " << S.dest << endl;
    // }





    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, L;
    cin >> N >> M >> L;

    vector<pii> G[N+1]; // .fi == cost, .se = dest
    for(int i = 1; i <= M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        G[A].emplace_back(C, B);
        G[B].emplace_back(C, A);


    }

    pii dist[N+1][N+1]; //.fi == refills, .se = total distance
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dist[i][j] = {LLONG_MAX, LLONG_MAX};
        }
    }
    
    for(int st = 1; st <= N; st++) {
        priority_queue<Cute, vector<Cute>, Compare> pq;
        pq.push(Cute(0, 0, st));

        while(!pq.empty()) {
            Cute S = pq.top();
            pq.pop();

            for(pii adj: G[S.dest]) {
                if(S.)
            }
        } 
    }


}