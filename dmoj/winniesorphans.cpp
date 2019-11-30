// https://globalnews.ca/news/5829793/ontario-school-cellphone-ban/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    int mi = 2147483647;
    int miind = -1;

    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        for(int j = 1; j <= M; j++) {
            int cute; cin >> cute;
            if(cute == 1 or cute == 10) cnt++;
        }

        if(cnt < mi) {
            miind = i;
            mi = cnt;
        }
    }

    cout << miind << endl;
}