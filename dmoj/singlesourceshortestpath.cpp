// https://dmoj.ca/problem/sssp

#include<bits/stdc++.h>
using namespace std;

const int INF = 2147483647;
int N; int M;

struct compare {  
   bool operator()(const pair<int, int>& l, const pair<int, int>& r) {  
       return l.second > r.second;  
   }  
};  

int main() {
    scanf("%i%i", &N, &M);

    // Init graph, .first == destination, .second == weight
    vector<pair<int, int>> graph[N+1];

    // Set edges/weights
    for(int edge = 1; edge < M+1; edge++) {
        int weight; int nodeA; int nodeB;
        scanf(" %i%i%i", &nodeA, &nodeB, &weight);
        graph[nodeA].emplace_back(nodeB, weight);
        graph[nodeB].emplace_back(nodeA, weight);
    }
    int dist[N+1];
    bool visited[N+1];
    fill(dist, dist+N+1, INF);
    fill(visited, visited+N+1, false);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> PQ;
    PQ.push({1, 0});

    while(!PQ.empty()) {
        pair<int, int> smallest = PQ.top();
        PQ.pop();
        for(auto adjacent:graph[smallest.first]) {
            int distance = dist[smallest.first] + adjacent.second;
            if(distance < dist[adjacent.first]) {
                dist[adjacent.first] = distance;
                PQ.push({ adjacent.first, dist[adjacent.first] });
            }
            
            if(!visited[adjacent.first]) {
                visited[adjacent.first] = true;
                PQ.push({ adjacent.first, dist[adjacent.first] });
            }
        }
    }

    for(int i = 1; i < N+1; i++) {
        if(dist[i] == INF) {
            printf("-1 ");
        } else {
            printf("%i ", dist[i]);
        }           
    printf("\n");    
    }
}
