// https://dmoj.ca/problem/dmpg19s1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    long long int a, b, c, N;
    cin >> a >> b >> c >> N;
    
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            for(int k = 0; k <= 100; k++) {
                if((a*i) + (b*j) + (c*k) == N) {
                    cout << "QUEST CLEARED" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "TRY AGAIN" << endl;
    
}
