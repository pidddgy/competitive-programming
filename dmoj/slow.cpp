// https://dmoj.ca/problem/coci08c5p4

#include <bits/stdc++.h>
#define maxn 30
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
bool adj[maxn][maxn];
int cnt[maxn];
int newcnt[maxn];
int prevday[maxn];
int today[maxn];
int main() {
    int N, H;
    cin >> N >> H;


    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            char cute; cin >> cute;
            if(cute == '1') {
                adj[i][j] = true;
            }
        }
    }

    for(int day = 1; day <= H; day++) {
        for(int i = 1; i <= N; i++) today[i] = 0;
        // watch(day)
        if(day == 1) {
            for(int x = 1; x <= N; x++) {
                if(adj[1][x]) {
                    cnt[x]++;
                    today[x]++;
                }
            }
        } else {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    if(adj[i][j]) {
                        if(prevday[j] % 2 == 0) {
                            cnt[i] += 2;
                            today[i] += 2;
                        } else {
                            cnt[i] += 1;
                            today[i]++;
                        }
                    }
                }
            }
        }

        for(int i = 1; i <= N; i++) {
            prevday[i] = today[i];
        }


        // for(int i = 1; i <= N; i++)
        //     cout << cnt[i] << " ";
        // cout << endl;
        
        for(int i = 1; i <= N; i++)
            cout << today[i] << " ";
        cout << endl;
    }

    int sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += cnt[i];
    }

    cout << sum << endl;
}