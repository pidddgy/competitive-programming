// https://dmoj.ca/problem/wac1p2

#include <bits/stdc++.h>
#define maxn 100005
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;


int N, M, K;
int disj[maxn];
vector<int> group[maxn];
vector<int> G[maxn];

int findp(int n) {
    if(disj[n] == n) return n;
    else return disj[n] = findp(disj[n]);
}

void merge(int a, int b) {
    int a_p = findp(a);
    int b_p = findp(b);

    disj[a_p] = b_p;
}

int main() {
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) disj[i] = i;

    for(int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        merge(u, v);
        // for(int i = 1; i <= N; i++) {
        //     cout << disj[i] << " ";
        // }
        // cout << endl;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= N; i++) findp(i);

    // find number of group
    // non zero
    int nzgroups = 0;
    for(int i = 1; i <= N; i++) {
        if(group[disj[i]].size() == 0) {
            nzgroups++;
        }

        // cout << "emplacing " << i << " to group " << disj[i] << endl;
        group[disj[i]].emplace_back(i);
    }

    // num of redundant edges
    int redundant = 0;
    for(int i = 1; i <= N; i++) {
        if(group[i].size() != 0) {
            // watch(i)
            int edges = 0;
            for(auto x: group[i]) {
                // watch(x)
                for(auto e: G[x]) { // might tle
                    edges++;
                    // watch(e)
                }
            }

            assert(edges%2==0);
            edges /= 2;

            redundant += edges - (group[i].size()-1);
        }
    }

    // we need to build build # of edges
    int build = nzgroups-1;
    int free = min(redundant, K);

    assert(build >= 0);
    cout << max(0, build-free) << endl;
}