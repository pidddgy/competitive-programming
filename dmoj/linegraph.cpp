// https://dmoj.ca/problem/dmopc15c6p4

#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int W, B, E;
    Edge(int w, int b, int e){
        W = w;
        B = b;
        E = e;  
    }
};

bool compare(Edge& l, Edge& r) {
    return l.W < r.W; 
}

int p[100005];

int findp(int n) {
    if(n == p[n]) return n;
    else return p[n] = findp(p[n]);
}

void join(int a, int b) {
    assert(a != b);
    
    p[findp(a)] = b;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Edge> E;
    for(int i = 1; i <= N-1; i++) {
        int w; cin >> w;
        E.emplace_back(w, i, i+1);
        if(i+K <= N) E.emplace_back(0, i, i+K);
    }

    sort(E.begin(), E.end(), compare);


    for(int i = 1; i <= N; i++) p[i] = i;

    int res = 0;
    for(auto a: E) {
        if(findp(a.B) != findp(a.E)) {
            join(a.B, a.E);
            res += a.W;
        }
    }

    cout << res << endl;
}
