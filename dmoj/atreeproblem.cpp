// https://dmoj.ca/problem/nccc2s4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

const int maxn = 50005;
int N;

struct edge {
    int dest, color;

    edge(int Dest, int Color) {
        dest = Dest;
        color = Color;
    }
};

bool bad[maxn];
vector<edge> G[maxn];
bool vis[maxn];
// bool tempvis[maxn];
set<int> tempvis;

void markAllBad(int node) {
    bad[node] = true;
    for(edge e: G[node]) {
        if(tempvis.find(e.dest) == tempvis.end()) {
            bool allbad = true;
            for(edge e: G[e.dest]) {
                if(!bad[e.dest] and e.dest != node) allbad = false;
            }

            tempvis.emplace(e.dest);
            markAllBad(e.dest);
        }
    }
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    cin >> N;

    for(int i = 0; i < N-1; i++) {
        // cout << "aaa" << endl;
        int a, b, c;
        cin >> a >> b >> c;

        G[a].emplace_back(edge(b, c));
        G[b].emplace_back(edge(a, c));
    }
    
    for(int i = 1; i <= N; i++) {
        // cout << "hallo" << endl;
        if(vis[i]) {
            // cout << "continuing on " << i << endl;
            continue;
        }
        else {
            // cout << "doot" << endl;
            vis[i] = true;
        }

        // watch(i)

        // if(bad[i]) {
        //     bool allbad = true;
        //     for(edge e: G[i]) {
        //         if(!bad[e.dest]) {
        //             allbad = false;
        //         }
        //     }

        //     if(allbad) continue;
        // }

        unordered_map<int, bool> haveColor;
        set<int> mult;
        for(edge e: G[i]) {
            if(haveColor[e.color]) {
                mult.emplace(e.color);
                // cout << "node " << i << " has multiple of color " << e.color << endl;
            }
            haveColor[e.color] = true;
        }

        for(int c: mult) {
            for(edge e: G[i]) {
                if(e.color == c) {
                    // cout << "marking all nodes in subtree of " << e.dest << " as bad " << endl;
                    tempvis = set<int>();
                    tempvis.emplace(i);
                    markAllBad(e.dest);
                }
            }
        }
    } 

    vector<int> ans;
    for(int i = 1; i <= N; i++) {
        if(!bad[i]) ans.emplace_back(i);
    }

    cout << ans.size() << endl;
    for(int x: ans) {
        cout << x << endl;
    }


}