// https://dmoj.ca/problem/raytracing

#include <bits/stdc++.h>
using namespace std;

int bits[9000][9000];
int N;
void upd(int tree, int ind, int val) {
    for(int i = ind; i <= N; i += i & -i) {
        bits[tree][ind] += val;
    }
}

int query(int tree, int ind) {
    int ans = 0;
    for(int i = ind; i >= 1; i -= i & -i) {
        ans += bits[tree][i];
    }

    return ans;
}
int main() {
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        upd(a[i], i, 1);
    }

    int Q;
    cin >> Q;

    for(int i = 1; i <= Q; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            int I, J, A, B;
            cin >> I >> J >> A >> B;

            
        } else {
            int in, h;
            cin >> in >> h;

            in++;
            upd(a[in], in, -1);
            a[in] = h;
            upd(a[in], in, 1);
        }
    }
}