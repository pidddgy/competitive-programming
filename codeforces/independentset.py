#!python3

import sys
sys.setrecursionlimit(10**6) 
maxn = 100005
# maxn = 10
mod = 1000000007

vis = [0]*maxn
white = [0]*maxn
black = [0]*maxn

G = [[] for _ in range(maxn)]


def dfs(s):
    vis[s] = True
    white[s] = 1
    black[s] = 1

    for adj in G[s]:
        if(not vis[adj]):
            vis[adj] = True
            dfs(adj)

            white[s] *= (white[adj]+black[adj])
            black[s] *= white[adj]

            white[s] %= mod
            black[s] %= mod


n = int(input())

for i in range(n-1):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)

dfs(1)

print((white[1]+black[1]) % mod)

# print(white)
# print(black)
