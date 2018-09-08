// Tudor and the Pusheens
// https://dmoj.ca/problem/ddrp3

#include <bits/stdc++.h>

using namespace std;

int main() {
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

    for(int server = 0; server < N; server++)
    {
      if(server == vertexA - 1)
      {
        servers[server].push_back(vertexB);
        servers[vertexB - 1].push_back(vertexA);
      }
    }
  }

  int S;
  int T;
  cin >> S >> T;

  // Get smallest distance from S to T using bfs
  queue< pair<int, vector<int> > > Q;
  vector<bool> visited(N, false);

  Q.push({ S, {S} });
  visited[0] = true;

  while(!Q.empty())
  {
    int front = Q.front().first;
    vector<int> path = Q.front().second;
    Q.pop();

    if(front == T)
    {
      int edgesNeeded = path.size() - 1;
      cout << M - edgesNeeded << endl;
      break;
    } else {
      for(unsigned adj = 0; adj < servers[front - 1].size(); adj++)
      {
        if(!visited[servers[front - 1][adj] - 1])
        {
          visited[servers[front - 1][adj] - 1] = true;
          vector<int> newPath = path;
          newPath.emplace_back(servers[front - 1][adj]);
          Q.push({ servers[front - 1][adj], newPath });
        } 
      }
    }
  }
  return 0;
}
