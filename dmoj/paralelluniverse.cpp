#include <bits/stdc++.h>
#define endl '\n'
#define ui unsigned int
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

ui left(ui n) {return n*2+1;} 
ui right(ui n) {return n*2+2;}
ui mid(ui a, ui b) {return (a+b)/2;} 

ui seg[400000];
ui a[100000];   

void build(ui ind, ui l, ui r) {
    if(l == r) {
        seg[ind] = a[l];
    } else {
        ui m = mid(l, r);
        build(left(ind), l, m);
        build(right(ind), m+1, r);

        seg[ind] = seg[left(ind)] & seg[right(ind)];
    }
}

ui ret, ql, qr;
void query(ui ind, ui l, ui r) {
    if(ql <= l && r <= qr) {
        ret &= seg[ind];
        return;
    }

    ui m = mid(l, r);

    if(ql <= m) query(left(ind), l, m);
    if(qr >= m+1) query(right(ind), m+1, r);
}

ui val;
ui uind;
void update(ui ind, ui l, ui r) {
    if(l == r) {
        seg[ind] = val;
        return;
    }

    ui m = mid(l, r);
    if(uind <= m) {
        update(left(ind), l, m);
    } else {
        update(right(ind), m+1, r);
    }

    seg[ind] = seg[left(ind)] & seg[right(ind)];
}

int main() {
    ui N, Q;
    cin >> N >> Q;

    for(ui i = 1; i <= N; i++) cin >> a[i];

    build(1, 1, N);

    while(Q--) {
        char t;
        cin >> t;

        if(t == 'U') {
            cin >> uind >> val;
            update(1, 1, N);
        } else if (t == 'Q') {
            cin >> ql >> qr >> ret;
            query(1, 1, N);

            cout << ret << endl;
        }

    }
}
