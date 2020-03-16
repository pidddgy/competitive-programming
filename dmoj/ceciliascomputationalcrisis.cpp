// https://dmoj.ca/problem/dmopc19c5p6

#include <bits/stdc++.h>
using namespace std;
// uhh i stole this from some codeforces blog post
int myrand() {
	return (((long long )rand() << 15) + rand()) % 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 1);
    clock_t z = clock();
    srand(time(0));
    int N, M;
    cin >> N >> M;

    string arr[N+1];
    int ops = 0;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(;;) {
        string cpy[N+1];
        for(int i = 1; i <= N; i++) cpy[i] = arr[i];

        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < cpy[i].size(); j++) {
                if(cpy[i][j] == '?') {
                    if(dis(gen)) {
                        cpy[i][j] = 'X';
                    } else {
                        cpy[i][j] = '.';
                    }
                }
                ops++;
            }
        }

        unordered_map<string, bool> have;

        bool bad = false;
        for(int i = 1; i <= N; i++) {
            if(have[cpy[i]]) {
                bad = true;
            } else {
                have[cpy[i]] = true;
            }
        }

        if(bad) {
            // cerr << "ops is currently " << ops << endl;
            if(((clock()-z) / (double)CLOCKS_PER_SEC) > 1.4) {
                break;
            }
        } else {
            cout << "YES" << endl;
            for(int i = 1; i <= N; i++) {
                cout << cpy[i] << endl;
            }
            return 0;
        }
    }

        for(;;) {
        string cpy[N+1];
        for(int i = 1; i <= N; i++) cpy[i] = arr[i];

        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < cpy[i].size(); j++) {
                if(cpy[i][j] == '?') {
                    if(dis(gen)) {
                        cpy[i][j] = '.';
                    } else {
                        cpy[i][j] = 'X';
                    }
                }
                ops++;
            }
        }

        unordered_map<string, bool> have;

        bool bad = false;
        for(int i = 1; i <= N; i++) {
            if(have[cpy[i]]) {
                bad = true;
            } else {
                have[cpy[i]] = true;
            }
        }

        if(bad) {
            // cerr << "ops is currently " << ops << endl;
            if(((clock()-z) / (double)CLOCKS_PER_SEC) > 2.8) {
                break;
            }
        } else {
            cout << "YES" << endl;
            for(int i = 1; i <= N; i++) {
                cout << cpy[i] << endl;
            }
            return 0;
        }
    }

    cout << "NO" << endl;
}