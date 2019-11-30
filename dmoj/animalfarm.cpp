// https://dmoj.ca/problem/ccc10s4

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair

using namespace std;
struct Edge {
    int be, en, w;
    Edge(int Be, int En, int W) {
        be = Be;
        en = En;
        w = W;
    }
};

int haash(int i, int j) {
    return(i*1005)+j;
}

int disj[105];
bool sooort(Edge l, Edge r) {
    return(l.w < r.w);
}

int findp(int n) {
    if(n == disj[n]) return n;
    else return disj[n] = findp(disj[n]);
}

void merge(int a, int b) {
    int a_p = findp(a);
    int b_p = findp(b);

    disj[a_p] = b_p;
}

int krus(vector<Edge> edges) {
    sort(edges.begin(), edges.end(), sooort);
    for(int i = 1; i <= 104; i++) disj[i] = i;
    
    int use = 0;
    for(auto edge: edges) {
        if(findp(edge.be) != findp(edge.en)) {
            merge(edge.be, edge.en);
            use += edge.w;
        }
    }

    return use;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int disj[N+1];
    
    unordered_map<int, Edge> edgeMap;
    vector<Edge> inEdge;
    vector<Edge> outEdge;

    for(int i = 1; i <= N; i++) {

        int e; cin >> e;
        int c[e+1];
        int W[e+1];

        for(int j = 1; j <= e; j++)
            cin >> c[j];
        
        for(int j = 1; j <= e; j++) {
            cin >> W[j];
        }       
         
        for(int j = 1; j <= e; j++) {
            int big;
            if(j+1 > e) big = 1;
            else big = j+1;

            int a = max(c[j], c[big]);
            int b = min(c[j], c[big]);
            int h = haash(a, b);

            if(edgeMap.find(h) == edgeMap.end()) {
                Edge newEdge = Edge(i, 0, W[j]);
                edgeMap.emplace(h, newEdge);
            } else {
                Edge newEdge = edgeMap.at(h);
                newEdge.en = i;
                
                inEdge.push_back(newEdge);
                outEdge.push_back(newEdge);
        
                edgeMap.erase(h);
            }
        }


    }

    for(auto a: edgeMap) {
        outEdge.push_back(a.se);
    }

    int inans = krus(inEdge);
    int outaans = krus(outEdge);

    cout << min(inans, outaans) << endl;

}
