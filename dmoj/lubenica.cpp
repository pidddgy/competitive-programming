// https://dmoj.ca/problem/coci08c5p4

#include <bits/stdc++.h>
#define maxn 30
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'

#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
bool adj[maxn][maxn];
long cnt[maxn];
long newcnt[maxn];
long prevday[maxn];

int main() {

    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    long N, H;
    cin >> N >> H;
    vector<int> today(N+1);

    vector<pii> edges;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            char cute; cin >> cute;
            if(cute == '1') {
                if(!adj[i][j]) {
                 //   cout << "appending " << i << "," << j << endl;
                    edges.emplace_back(i, j);
                }
                adj[i][j] = true;
                adj[j][i] = true;
                
            }
        }
    }

    vector<vector<int>> pattern;
    for(int day = 1; day <= H; day++) {
        for(int i = 1; i <= N; i++) today[i] = 0;
        if(day == 1) {
            for(int x = 1; x <= N; x++) {
                if(adj[1][x]) {
                    cnt[x]++;
                    today[x]++;
                }
            }
        } else {
            for(pii e: edges) {
                if(prevday[e.fi] % 2 == 0) {
                    cnt[e.se] += 2;
                    today[e.se] += 2;
                } else {
                    cnt[e.se]++;
                    today[e.se]++;
                }

                if(prevday[e.se] % 2 == 0) {
                    cnt[e.fi] += 2;
                    today[e.fi] += 2;
                } else {
                    cnt[e.fi] ++;
                    today[e.fi]++;
                }
            }
        }

        today[0] = -1;

        if(day != 1)
        pattern.emplace_back(today);

        if(day != 1)
        if(pattern.size() % 2 == 0) {

            bool same = true;

            for(unsigned int i = 0; i < pattern.size()/2; i++) {
                unsigned int j = i+(pattern.size()/2);
                for(unsigned int k = 0; k < pattern[i].size(); k++) {
                    if(pattern[i][k] != pattern[j][k]) {
                        same = false;
                        break;
                    }
                }
                if(same == false) break;
            }

            if(same) {
                long sum = 0;
                for(long x: cnt) sum += x;

                long patternsum = 0;
                for(int i = 0; i < pattern.size()/2; i++) {
                    for(int j: pattern[i])
                        patternsum += j;
                    patternsum++;
                }

                sum += ((H-day)/(pattern.size()/2) * patternsum);

                for(int i = 1; i <= (H-day)%(pattern.size()/2); i++) {
                    long sumsum = 0;
                    for(long x: pattern[i-1]) sumsum += x;
                    
                    sumsum++;

                    sum += sumsum;
                }
                
                cout << sum << endl;
                return 0;
            }
        }
        for(int i = 1; i <= N; i++) {
            prevday[i] = today[i];
        }

    }

    long sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += cnt[i];
    }

    cout << sum << endl;
}

/*
5 10
01000
10110
01000
01001
00010

132

4 1000
0110
1000
1001
0010

9992

4 14
0110
1000
1001
0010

131
*/