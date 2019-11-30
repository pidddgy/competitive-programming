// https://dmoj.ca/problem/ncco3d2p1

#include <bits/stdc++.h>
#define MAXN 50005
#define MAXINT 2147483647
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

int a[MAXN];
int mi[MAXN * 4];
int ma[MAXN * 4];

int left(int n) {return n*2+1;}
int right(int n) {return n*2+2;}
int mid(int a, int b) {return (a+b)/2;}

void build(int ind, int l, int r) {
    if(l == r) {
        mi[ind] = a[l];
        ma[ind] = a[l];
    } else {
        int m = mid(l, r);
        build(left(ind), l, m);
        build(right(ind), m+1, r);

        mi[ind] = min(mi[(left(ind))], mi[right(ind)]);
        ma[ind] = max(ma[(left(ind))], ma[right(ind)]);
    }
}

int ql, qr;
int ret;

void queryMi(int ind, int l, int r) {
    if(l >= ql && r <= qr) {
        ret = min(ret, mi[ind]);
        return;
    } 

    int m = mid(l, r);
    if(ql <= m)
        queryMi(left(ind), l, m);
    
    if(qr >= m+1)
        queryMi(right(ind), m+1, r);

}

void queryMa(int ind, int l, int r) {
    if(l >= ql && r <= qr) {
        ret = max(ret, ma[ind]);
        return;
    } 
    int m = mid(l, r);
    if(ql <= m)
        queryMa(left(ind), l, m);
    
    if(qr >= m+1)
        queryMa(right(ind), m+1, r);

    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    build(1, 1, N);

    for(int i = 1; i <= Q; i++) {
        cin >> ql >> qr;

        ret = -MAXINT;
        queryMa(1, 1, N);

        int ma = ret;

        ret = MAXINT;
        queryMi(1, 1, N);

        int mi = ret;

        cout << ma-mi << "\n";
    }

}