// https://dmoj.ca/problem/tss17b

#include <bits/stdc++.h>
#define ld double
#define endl '\n'
#define watch(x) cout << fixed << (#x) << " is " << (x) << endl;
using namespace std;
int N, Q;

ld eucdis(int a, int b) {
    int A = abs(a);
    int B = abs(b);
    if(A == 0 and B == 0) {
        return 0;
    } else if(A == 0) {
        return(sqrt(B*B));
    } else if(B == 0) {
        return(sqrt(A*A));
    }

    ld asq = A*A;
    ld bsq = B*B;

    // watch(asq+bsq)
    return sqrt(abs(asq+bsq));
}
int main() {
    cout << eucdis(1000000,0) << endl;
    cin >> N >> Q;

    int pfi[N];
    int pse[N];

    for(int i = 0; i < N; i++) {
        cin >> pfi[i] >> pse[i];
        pfi[i] = abs(pfi[i]);
        pse[i] = abs(pse[i]);
    }

    ld dis[N];
    for(int i = 0; i < N; i++) {
        dis[i] = eucdis(pfi[i], pse[i]);
    }


    sort(dis, dis+N);

    for(int thing = 0; thing < Q; thing++) {
        ld query; cin >> query;
        watch(query)
        for(ld x: dis) {
            cout << x<< endl;
        }
    }



}