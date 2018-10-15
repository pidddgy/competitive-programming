#include <bits/stdc++.h>
using namespace std;

char canGetThere = 'N';
int N, M, A, B;
vector< vector<int> > houses(2000);
int main()
{
    scanf("%i%i%i%i", &N,  &M, &A, &B);
    for(int i = 0; i < M; i++)
    {
        int vertexA, vertexB;
        scanf("%i%i", &vertexA, &vertexB);
        houses[vertexA - 1].emplace_back(vertexB);
        houses[vertexB - 1].emplace_back(vertexA);
    }

    queue<int> Q;
    vector<bool> visited(N, false);
    Q.push(A);
    visited[A - 1] = false;
    while(!Q.empty())
    {
        int front = Q.front();
        Q.pop();

        if(front == B)
        {
            canGetThere = 'G';
            break;
        } else {
            for(unsigned i = 0; i < houses[front - 1].size(); i++)
            {
                if(!visited[houses[front - 1][i] - 1])
                {
                    visited[houses[front - 1][i] - 1] = true;
                    Q.push(houses[front - 1][i]);
                }
            }
        }
    }
    printf("%cO SHAHIR!\n", canGetThere);
}
