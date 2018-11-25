// https://dmoj.ca/problem/ccc18j5

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;

int main() {
    int N;
    scanf("%i", &N);

    vector<int> book [N+1];

    for(int i = 1; i < N+1; i++) {
        int M;
        scanf("%i", &M);
        vector<int> pageOptions;
        for(int j = 1; j < M+1; j++) {
            int option = 0;
            scanf("%i", &option);
            if(option != 0)
                pageOptions.push_back(option);
        }
        book[i] = pageOptions;
    }

    bool visited[N+1];
    queue<int> Q;

    bool minPathSizeFound = false;
    int firstNodeWithoutChildren = 0;
    int parents[N+1];

    fill(parents, parents+N+1, 0);
    fill(visited, visited+N+1, false);
    Q.push(1);
    visited[1] = true;

    while(!Q.empty()) {
        int top = Q.front();
        Q.pop();
        for(auto adj: book[top]) {
            if(!visited[adj]) {
                Q.push(adj);
                parents[adj] = top;
                visited[adj] = true;
            }
        }
        if(book[top].size() == 0) {
            if(!minPathSizeFound) {
                minPathSizeFound = true;
                firstNodeWithoutChildren = top;
            }
        }
    }
    int count = 1;
    int temp = firstNodeWithoutChildren;

    for(;;){
        temp = parents[temp];
        count++;
        if(temp == 1)
            break;
    }
    
    bool canVisitAllPages = true;
    for(int i = 1; i < N+1; i++)
        if(!visited[i])
            canVisitAllPages = false;

    if(canVisitAllPages)
        printf("Y\n");
    else 
        printf("N\n");

    printf("%i\n", count);
}
