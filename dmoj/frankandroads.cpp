// https://dmoj.ca/problem/vmss15c1p4

#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;

struct compare {  
   bool operator()(const pair<int, int>& l, const pair<int, int>& r) {  
       return l.second > r.second;  
   }  
};  

int main() {
    int T; int N; int M; int G;
    scanf("%i%i%i%i", &T, &N, &M, &G);
    bool isFoodBasics[N+1];
    fill(isFoodBasics, isFoodBasics+N+1, false);

    for(int i = 0; i < G; i++) {
        int loc;
        scanf("%i", &loc);
        isFoodBasics[loc] = true;
    }
    //.first = dest, .second = weight
    vector< pair<int, int> > graph[M+1];
    for(int road = 1; road < M+1; road++) {
        int A; int B; int weight;
        scanf("%i%i%i", &A, &B, &weight);
        graph[A].emplace_back(B, weight);
    }

    int dist[N+1];
    bool visited[N+1];

    fill(dist, dist+N+1, INF);
    dist[0] = 0;
    fill(visited, visited+N+1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> PQ;
    PQ.push({0, 0});

    while(!PQ.empty()) {
        pair<int, int> smallest = PQ.top();
        PQ.pop();

        for(auto adjacent: graph[smallest.first]) {
            int distance = dist[smallest.first] + adjacent.second;
            if(distance < dist[adjacent.first]) {
                dist[adjacent.first] = distance;
                PQ.push({ adjacent.first, dist[adjacent.first]});
            }
            if(!visited[adjacent.first]) {
                visited[adjacent.first] = true;
                PQ.push({ adjacent.first, dist[adjacent.first] });
            }
        }
    }

    int fbWithinRange = 0;
    for(int i = 0; i < N+1; i++) {

        if(dist[i] <= T && isFoodBasics[i]) {
            fbWithinRange++;
        }
    }
    printf("%i\n", fbWithinRange);
}
