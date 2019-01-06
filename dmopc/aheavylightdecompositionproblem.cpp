// https://dmoj.ca/problem/dmopc17c4p2

#include <bits/stdc++.h>
using namespace std;

pair< int, vector<int> > nodes[1000];
int backEdges[1000] = { 0 };

int main() {
    int N; int Q;
    scanf("%i%i", &N, &Q);

    for(int i = 0; i < N; i++) {
        int val;
        scanf("%i", &val);
        nodes[i].first = val;
    }

    for(int i = 0; i < N - 1; i++) {
        int vertexA;
        int vertexB;

        scanf("%i%i", &vertexA, &vertexB);
        nodes[vertexA - 1].second.emplace_back(vertexB);
        nodes[vertexB - 1].second.emplace_back(vertexA);
    }

    for(int j = 0; j < Q; j++) {
        int typeOfQuery;
        int S;
        int T;
        scanf("%i%i%i", &typeOfQuery, &S, &T);

        queue<int> queueThing;
        vector<bool> visited(N, false);

        queueThing.push(S);
        visited[S - 1] = true;

        while(!queueThing.empty()) {
            int front = queueThing.front();
            queueThing.pop();

            if(front == T)
                break;
            else {
                for(unsigned adj = 0; adj < nodes[front - 1].second.size(); adj++) {
                    if(!visited[nodes[front - 1].second[adj] - 1]) {
                        visited[nodes[front - 1].second[adj] - 1] = true;
                        backEdges[nodes[front - 1].second[adj] - 1] = front;
                        queueThing.push(nodes[front - 1].second[adj]);
                    }
                }
            }
        }
        vector<int> path;
        int temp = T;
              
        while(temp != S) {
            path.emplace_back(nodes[temp - 1].first);
            temp = backEdges[temp - 1];
        }
        path.emplace_back(nodes[S - 1].first);
        
        // Get mean
        if(typeOfQuery == 1) {
            int total = 0;

            for(unsigned i = 0; i < path.size(); i++)
                total += path[i];

            if((total % path.size()) * 2 < path.size())
                cout << total / path.size() << '\n';
            else
                cout << (total + path.size() - 1) / path.size() << '\n';
        } 

        // Get median
        else if (typeOfQuery == 2) {
            sort(path.begin(), path.end());

            if(path.size() % 2 == 0) {
                int x = path[path.size() / 2];
                int y = path[path.size() / 2 - 1];
                int a = x + y;
                const int b = 2;

                if((a * 2) < b)
                    cout << a / b << '\n';
                else
                    cout << (a + b - 1) / b << '\n';
            }
            else
                cout << path[path.size() / 2] << '\n';
        }
        
        // Get mode
        else if (typeOfQuery == 3) {
            sort(path.begin(), path.end());

            int mostCounted = 0;
            int mostCountedVal = 0;
            
            for(unsigned i = 0; i < path.size(); i++) {
                int countOccurence = count(path.begin(), path.end(), path[i]);
                if(countOccurence > mostCounted) {
                    mostCounted = countOccurence;
                    mostCountedVal = path[i];
                }
                
            }
            cout << mostCountedVal << '\n';
        }
    }
    return 0;
}
