// https://dmoj.ca/problem/year2019p2

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    pii S[N];
    for(int i = 0; i < N; i++) {
        cin >> S[i].fi;
        cin >> S[i].se;
    }

   int state[N]; for(int i = 0; i < N; i++) state[i] = 0;

    for(int i = 0; i < M; i++) {
        int curr = 1;
        for(;;) {
            if(curr == N+1) {
                if(state[curr-1] == 0) {
                    state[curr-1] = 1;
                }
                else if(state[curr-1] == 1) {
                    state[curr-1] = 0;
                }
                break;
            }

            else if(state[curr-1] == 0) {
                state[curr-1] = 1;
                curr = S[curr-1].fi;
            } else {
                state[curr-1] = 0;
                curr = S[curr-1].se;
            }

        }
        for(int i = 0; i < N; i++) {
                cout << state[i];
            }
            cout << endl;
    }
    // for(int i = 0; i < N; i++)
    //     cout << state[i];
    // cout << "\n";
}
