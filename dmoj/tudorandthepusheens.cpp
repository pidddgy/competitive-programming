// Tudor and the Pusheens
// https://dmoj.ca/problem/ddrp3

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int N;
  int M;
  cin >> N >> M;
  vector< vector<int> > servers(N + 1);

  // Create graph
  for(int i = 0; i < M; i++)
  {
    int vertexA;
    int vertexB;

    cin >> vertexA >> vertexB;

    servers[vertexA - 1].push_back(vertexB);
    servers[vertexB - 1].push_back(vertexA);
  }

  int S;
  int T;
  cin >> S >> T;

  // Get smallest distance from S to T using bfs
  queue< pair<int, int > > Q;
  vector<bool> visited(N, false);

  Q.push({ S, 1 });
  visited[S - 1] = true;

  while(!Q.empty())
  {
    int front = Q.front().first;
    int distance = Q.front().second;
    Q.pop();

    if(front == T)
    {
      int edgesNeeded = distance - 1;
      cout << M - edgesNeeded << "\n";
      break;
    } else {
      for(unsigned adj = 0; adj < servers[front - 1].size(); adj++)
      {
        if(!visited[servers[front - 1][adj] - 1])
        {
          visited[servers[front - 1][adj] - 1] = true;
          int newDistance = distance + 1;
          Q.push({ servers[front - 1][adj], newDistance });
        } 
      }
    }
  }
  return 0;
}
