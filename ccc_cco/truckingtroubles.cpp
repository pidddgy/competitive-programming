// https://dmoj.ca/problem/ccc03s5

#include <bits/stdc++.h>
using namespace std;
const int MIN_INT = -2147483647;
const int MAX_INT = 2147483647;

struct Compare {  
   bool operator()(const pair<int, int>& l, const pair<int, int>& r) {  
       return l.second > r.second;  
   }  
};  

int main() {
    int C, R, D;
    scanf("%i%i%i", &C, &R, &D);

    vector<pair<int, int>> graph[C+1]; // .first == dest, .second == weight supported
    int dests[D+1];

    for(int i = 1; i < R+1; i++) {
        int x, y, w;
        scanf(" %i%i%i", &x, &y, &w);
        graph[x].emplace_back(y, w);
        graph[y].emplace_back(x, w);
    }
    for(int i = 1; i < D+1; i++)
        scanf(" %i", &dests[i]);
    
    int maxW[C+1]; fill(maxW, maxW+C+1, MIN_INT);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> PQ;

    PQ.push({1, MAX_INT});
    maxW[1] = 0;

    while(!PQ.empty()) {
        int S = PQ.top().first; PQ.pop();
        
        // Get most expensive path from current node
        for(auto adj: graph[S]) {
            int weight = min(maxW[S], adj.second);
            if(maxW[adj.first] == 0) {
                maxW[adj.first] = adj.second;
                PQ.push({adj.first, maxW[adj.first]});
            }
            if(weight > maxW[adj.first]) {
                maxW[adj.first] = weight;
                PQ.push({ adj.first, maxW[adj.first]});
            }
        }
    }
    int maxWeightSupported = MAX_INT;
    for(int i = 1; i < D+1; i++) {
        if(maxW[dests[i]] < maxWeightSupported)
            maxWeightSupported = maxW[dests[i]];
    }
    printf("%i\n", maxWeightSupported);
}
