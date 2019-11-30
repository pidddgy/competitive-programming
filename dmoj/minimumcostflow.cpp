#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
    int bv;
    int ev;
    ll cost;
    int active;
    Edge(int BV, int EV, ll COST, int ACTIVE) {
        bv = BV;
        ev = EV;
        cost = COST;
        active = ACTIVE;
    }
};

int disj[100005];
int findp(int n) {
    if(disj[n] == -1) return n;
    else {
        disj[n] = findp(disj[n]);
        return disj[n];
    }  
}

bool comp(Edge &l, Edge &r) {
    if(l.cost == r.cost) return l.active < r.active;
    else return l.cost < r.cost;
}
void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    disj[c] = d;
}

vector<Edge> edges;
int main() {
    fill(disj, disj+100005, -1); 
    ll N, M, D;
    cin >> N >> M >> D;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int d;
        if(i < N-1) d = 0;
        else d = 1;

        // 0 means active, 1 is inactive
        edges.emplace_back(--a, --b, c, d);
    }
    
    sort(edges.begin(), edges.end(), comp);
    int ee = 0;
    ll maxe = 0;    
    int days = 0;
    int a = 0;

    for(int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if(findp(e.bv) != findp(e.ev)) {
            merge(e.bv, e.ev);
            ee++;
            maxe = e.cost;
            days += e.active;
            a = e.active;
        }
    }

    fill(disj, disj+100005, -1); 
    if(a == 1) {
        for(auto e: edges) {
            if(findp(e.bv) != findp(e.ev)) {
                if(e.cost < maxe || (e.cost == maxe && e.active == 0)) {
                    merge(e.bv, e.ev);
                } else if(e.active == 0 && e.cost <= D) {
                    days--;
                    break;
                }
            }
        }
    }

    cout << days << endl;


}