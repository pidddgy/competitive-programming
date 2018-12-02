#include <bits/stdc++.h>
using namespace std;

struct Beacon {
    int x; int y; int r;
};

int main() {
    int B; int Q;
    scanf("%i%i", &B, &Q);
    
    vector<int> e[B];
    Beacon b[B];

    for(int i = 0; i < B; i++)
        scanf("%i%i%i", &b[i].x, &b[i].y, &b[i].r);
    
    // Make edges
    for(int i = 0; i < B; i++) {
        for(int j = 0; j < B; j++) {
            int xdist = abs(b[i].x - b[j].x);
            int ydist = abs(b[i].y - b[j].y);
            double totalDist = sqrt(pow(xdist, 2) + pow(ydist, 2));

            if(totalDist <= b[i].r && i != j)
                e[i].push_back(j);
        }
    }

    // Answer queries
    for(int i = 0; i < Q; i++) {
        bool found = false;
        int a; int b;
        scanf("%i%i", &a, &b); 
        a=a-1; b=b-1;

        // BFS from beacon a to b
        queue<int> Q;
        bool vis[B]; for(int i = 0; i < B; i++) vis[i] = false;
        Q.push(a);
        vis[a] = true;

        while(!Q.empty()) {
            int s = Q.front();
            Q.pop();
            if(s == b) 
                found = true;
            for(auto v:e[s])
                if(!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
        }
        if(found) 
            printf("YES\n");
        else
            printf("NO\n");
    }
}
