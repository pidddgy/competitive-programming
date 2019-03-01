// https://dmoj.ca/problem/phantom2

#include <bits/stdc++.h>
using namespace std;

int maxab = 1000005;
bool Pr[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < maxab; i++) {
        Pr[i] = true;
    } 

    for(int p = 2; p*p <= maxab; p++) {
        if(Pr[p]) {
            for(int i = p+p; i <= maxab; i += p) {
                Pr[i] = false;
            }
        }
    }

    Pr[0] = false;
    Pr[1] = false;

    for(int i = 0; i < N; i++) {
        int a, b;   
        cin >> a >> b;
            
        int r = 0;
        for(int j = a; j < b; j++) {
            if(Pr[j]) r++;
        }

        cout << r << endl;
    }
}
