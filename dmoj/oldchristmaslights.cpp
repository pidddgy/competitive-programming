// https://dmoj.ca/problem/year2016p7

#include <bits/stdc++.h>
#define endl '\n'
#define maxn 100500
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

int a[maxn];
int miseg[maxn*4];
int maseg[maxn*4];
int lateseg[maxn*4];
int latest[maxn];
int N, K, Q;

string buildtype;

int left(int n) { return (n*2)+1;}
int right(int n) { return (n*2)+2;}
int mid(int a, int b) { return (a+b)/2;}

void build(int tree[], int ind, int l, int r) {
    if(l == r) {
        if(buildtype == "malatest") {
            tree[ind] = latest[l];
        }
        else
            tree[ind] = a[l];
    } else {
        int m = mid(l, r);
        build(tree, left(ind), l, m);
        build(tree, right(ind), m+1, r);
        
        if(buildtype == "miseg") {
            tree[ind] = min(tree[left(ind)], tree[right(ind)]);
        }

        if(buildtype == "maseg") {
            tree[ind] = max(tree[left(ind)], tree[right(ind)]);
        }

        if(buildtype == "malatest") {
            tree[ind] = max(tree[left(ind)], tree[right(ind)]);
        }
    }

   // cout << "setting " << l << "," << r  << " - " << ind << " to " << tree[ind] << endl;

}

int ql, qr;
string querytype;
int query(int tree[], int ind, int l, int r) {
    if(ql <= l && r <= qr) {
        return tree[ind];
    } 

    int m = mid(l, r);
    
    int res;
    if(querytype == "miseg") {
        res = 2147483647;
    } else if(querytype == "maseg" or querytype == "malatest") {
        res = -2147483647;
    }

    if(ql <= m) {
        if(querytype == "miseg")
            res = min(res, query(tree, left(ind), l, m));
        else if(querytype == "maseg" or querytype == "malatest") {
            res = max(res, query(tree, left(ind), l, m));
        }
    }

    if(qr >= m+1) {
        if(querytype == "miseg")
            res = min(res, query(tree, right(ind), m+1, r));
        else if(querytype == "maseg" or querytype == "malatest") {
            res = max(res, query(tree, right(ind), m+1, r));
        }
    }

    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> a[i];

    buildtype = "miseg";
    build(miseg, 1, 1, N);

    buildtype = "maseg";
    build(maseg, 1, 1, N);
    
    for(int i = 1; i <= N; i++) {
        int l = i;
        int r = N;
        int be = i;
        watch(i)

        while(l <= r) {
            int m = (l+r)/2;
            
            ql = i;
            qr = m;

            querytype = "miseg";
            int mi = query(miseg, 1, 1, N);

            querytype = "maseg";
            int ma = query(maseg, 1, 1, N);

            watch(ql)
            watch(qr)

            watch(mi)
            watch(ma)

            if(abs(ma-mi) <= K) {
                be = max(be, m);
                l = m+1;
            } else {
                r = m-1;
            } 
        }

        latest[i] = be;
    }

}