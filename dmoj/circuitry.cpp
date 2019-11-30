// https://dmoj.ca/problem/mec16p4

#include <bits/stdc++.h>
#define maxn 505
using namespace std;

int N, M;
#define endl '\n'
#pragma GCC optimize "Ofast"
#define ll long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


struct Edge {
    int bv, ev, cost, index;
    Edge(int BV = 0, int EV = 0, int COST = 0, int INDEX = 0) {
        bv = BV;
        ev = EV;
        cost = COST;
        index = INDEX;
    }
};
vector<Edge> edges;

Edge edgeatind[250000];
bool seen[maxn][maxn];


bool compEdge(Edge l, Edge r) {
    return l.cost < r.cost;
}

int disj[maxn];
int size[maxn];

int findp(int n) {
    if(disj[n] == n) return n;
    else {
        disj[n] = findp(disj[n]);
        return(disj[n]);
    }   
}

void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    if(size[c] > size[d]) {
        swap(c, d);
    }

    // c is smaller

    disj[c] = d;
    size[c] += size[d];
}

void clear() {
    for(int i = 1; i <= N; i++) {
        disj[i] = i;
        size[i] = 1;
    }
}

int main() {

    //cin >> N >> M;
    scan(N);
    scan(M);
    for(int i = 1; i <= M; i++) {
        int A, B, L;
        scan(A);
        scan(B);
        scan(L);
      //  cin >> A >> B >> L;

        edges.emplace_back(A, B, L, i);
        edgeatind[i] = Edge(A, B, L, i);
    }
    
    sort(edges.begin(), edges.end(), compEdge);
    clear();
    int target = 0;
    for(Edge e: edges) {
        if(findp(e.bv) != findp(e.ev)) {
            merge(e.bv, e.ev);
            target += e.cost;
        }
    }

    
    for(int i = 1; i <= M; i++) {
        int banned = i;

        clear();
        int cnt = 0;
        int totCost = 0;
        for(Edge e: edges) {
            if(findp(e.bv) != findp(e.ev) && e.index != banned) {
                merge(e.bv, e.ev);
                totCost += e.cost;
                cnt++;
            }
            if(cnt == N-1) break;
        }

        if(cnt != N-1 or totCost > target) {
            cout << "useful" << endl;
            continue;
        }
        
        clear();
        cnt = 1;
        totCost = edgeatind[i].cost; 
        merge(edgeatind[i].bv, edgeatind[i].ev);

        for(Edge e: edges) {
            if(findp(e.bv) != findp(e.ev) && e.index) {
                merge(e.bv, e.ev);
                totCost += e.cost;
                cnt++;
            }
            if(cnt == N-1) break;
        }

        if(cnt != N-1 or totCost > target) {
            cout << "not useful" << endl;
        } else {
            cout << "so so" << endl;
        }
    }
}