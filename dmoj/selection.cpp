// https://dmoj.ca/problem/dmopc19c2p3

#include <bits/stdc++.h>
#define maxn 400005
#define pii pair<int, int>
#define fi first
#define se second
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;
int N, M;
int seg[25][maxn*4];
int cnt[25][maxn];

int a[maxn];

int left(int n) {return (n*2)+1;} 
int right(int n) {return (n*2)+2;}
int mid(int a, int b) {return (a+b)/2;} 

int bInd;
void build(int ind, int l, int r) {
    if(l == r) {
        seg[bInd][ind] = cnt[bInd][l];
    } else {
        int m = mid(l,r);
        build(left(ind), l, m);
        build(right(ind), m+1, r);

        seg[bInd][ind] = seg[bInd][left(ind)] + seg[bInd][right(ind)];
    }
    // cout << "there are " << seg[bInd][ind] << " of " << bInd << " between " << l << " and " << r << endl;
}
int uind;
void update(int ind, int l, int r) {
    if(l == r) {
        seg[bInd][ind] = cnt[bInd][l];
        return;
    }

    int m = mid(l, r);
    if(uind <= m) {
        update(left(ind), l, m);
    } else {
        update(right(ind), m+1, r);
    }

    seg[bInd][ind] = seg[bInd][left(ind)] + seg[bInd][right(ind)];
}

int ql, qr;
int query(int ind, int l, int r) {
    if(ql <= l && r <= qr) {
        return seg[bInd][ind];
    }

    int ret = 0;
    int m = mid(l, r);

    if(ql <= m) ret += query(left(ind), l, m);
    if(qr >= m+1) ret += query(right(ind), m+1, r);
    
    return ret;
}

int main() {
    cin >> N >> M;


    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < maxn; j++) {
            cnt[i][j] = 0;
            a[j] = 0;
        }
    }

     for(int i = 0; i < 25; i++) {
        for(int j = 0; j < maxn*4; j++) {
            seg[i][j] = 0;
        }
    }

    for(int i = 1; i <= N; i++) {
        cin >> a[i];

        cnt[a[i]][i] = 1;
    }


    for(int i = 0; i <= 20; i++) {
        bInd = i;
        build(1, 1, N);
    }

    for(int i = 1; i <= M; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            int A, B;
            cin >> A >> B;

            bInd = a[A];

            // watch(a[A])
            
            // if(cnt[a[A]][A] != 1) {
            //     cout << a[A] << " " << A << " debug" << endl;
            // }

            // cout << "setting " << a[A] << " " << A << " to 0 " << endl;
            assert(cnt[a[A]][A] == 1);
            cnt[a[A]][A] = 0;
            uind = A;

            update(1, 1, N);
            a[A] = B;


            bInd = B;
            // cout << "setting " << B << " " << A << " to 1 " << endl;

            cnt[B][A] = 1;
            update(1, 1, N);

            

        } else if(type == 2) {

            int l, r, c;
            cin >> l >> r >> c;

            // cout << "on query " << i << endl;
            
            int rem = c;
            ql = l;
            qr = r;
            for(int j = 20; j >= 0; j--) {
                bInd = j;
                int cute = query(1, 1, N);
                // cout << "there are " << cute << " of " << j << " in " << l << " to " << r << endl;
                if(cute >= rem) {
                    cout << j << endl;
                    break;
                } else rem -= cute;
            }

        }
    }


}