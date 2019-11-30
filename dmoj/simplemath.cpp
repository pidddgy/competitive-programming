// https://dmoj.ca/problem/dmopc19c1p3

#include <bits/stdc++.h>
#define maxn 300003
#define maxm 500005
#define maxk 1000000003
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define MOD 1000000007
#define eb emplace_back
#define ll long long

using namespace std;

struct Edge {
    ll dest, cost;
    Edge(ll DEST, ll COST) {
        dest = DEST;
        cost = COST;
    }
};

ll N, M, K;
vector<Edge> G[maxn]; 
ll disj[maxn];
vector<Edge> component[maxn];

ll findp(ll n) {
    if(disj[n] == n) {return n;}
    else {
        disj[n] = findp(disj[n]);
        return disj[n];
    }
}

void merge(ll a, ll b) {
    ll c = findp(a);
    ll d = findp(b);

    disj[c] = d;
}

int main() {
    cin >> N >> M >> K;
    for(ll i = 1; i <= N; i++) {
        disj[i] = i;
    }

    for(ll i = 1; i <= M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        G[a].eb(b, c);
        G[b].eb(a, c);

        merge(a, b);
    }

    for(ll i = 1; i <= N; i++) {
        findp(i);

        for(Edge e: G[i]) {
            component[disj[i]].eb(e);
        }

    }

    ll ans = 0;
    bool added = false;
    for(ll i = 1; i <= N; i++) {
        if(component[i].size()==0) continue;
        else {

            ll st = component[i][0].dest;

            watch(st)
            ll highest = -1;
            ll lo = 1;
            ll hi = K;

            // binary search for highest
            while(lo <= hi) {
                ll m = (lo+hi)/2;
                bool good = true;
                ll vals[N+1];

                for(ll i = 1; i <= N; i++) {
                    vals[i] = -1;
                } 

                vals[st] = m;
                queue<ll> Q;

                Q.push(st);

                while(!Q.empty()) {
                    ll S = Q.front();
                    Q.pop();
                    
                    for(Edge adj: G[S]) {
                        if(vals[adj.dest] == -1) {
                            Q.push(adj.dest);
                            vals[adj.dest] = abs(vals[S]-adj.cost);
                            if(vals[adj.dest] == 0 or vals[S] > adj.cost or vals[S] > K) good = false;
                        } else if(vals[adj.dest] + vals[S] != adj.cost) {
                            good = false;
                        }                
                    }
                }

                if(good) {
                    lo = m+1;
                    highest = m;
                } else {
                    hi = m-1;
                }
            }

        

            st = component[i][0].dest;
            ll lowest = -1;
            lo = 1;
            hi = K;

            // binary search for smallest
            while(lo <= hi) {
                ll m = (lo+hi)/2;
                watch(m)
                bool good = true;
                ll vals[N+1];

                for(ll i = 1; i <= N; i++) {
                    vals[i] = -1;
                } 

                vals[st] = m;
                queue<ll> Q;

                Q.push(st);

                while(!Q.empty()) {
                    ll S = Q.front();
                    Q.pop();
                    
                    for(Edge adj: G[S]) {
                        if(vals[adj.dest] == -1) {
                            Q.push(adj.dest);
                            vals[adj.dest] = abs(vals[S]-adj.cost);
                            if(vals[adj.dest] == 0 or vals[S] > adj.cost or vals[S] > K) good = false;
                        } else if(vals[adj.dest] + vals[S] != adj.cost) {
                            good = false;
                        }                
                    }
                }

                if(good) {
                    hi = m-1;
                    lowest = m;
                } else {
                    // cout << "not good" << endl;
                    lo = m+1;
                }
            } 

            watch(lowest)
            watch(highest)


            if(highest != -1) {
                if(ans == 0) ans = 1;
                ans *= abs(highest-lowest)+1;
                ans %= MOD; 
            }
        }
    }

    cout << ans << endl;
}