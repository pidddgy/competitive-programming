// https://dmoj.ca/problem/wac3p4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

const int maxn = 100500;

int deg[maxn];
int size[maxn];
int disj[maxn];

int findp(int n) {
    if(disj[n] != n) {
        return disj[n] = findp(disj[n]);
    } else {
        return n;
    }
}

void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    if(c != d) {
        disj[c] = d;
        // cout << "merging " << a << "," << b << endl;
        // watch(size[c])
        // watch(size[d])
        size[d] += size[c];
        // watch(size[c])
    } else {
        // cout << "no merge " << endl;
    }


}

void init() {
    for(int i = 1; i <= maxn-5; i++) {
        disj[i] = i;
        size[i] = 1;
    }
}


int main() {
    int N, Q;
    cin >> N >> Q;

    init();

    set<int> nz;

    int odd = 0;
    for(int i = 1; i <= Q; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        
        nz.emplace(a);
        nz.emplace(b);

        if(x % 2 == 1) {
            if(deg[a] % 2 == 0) {
                odd++;
            } else {
                odd--;
            }

            deg[a]++;

            if(deg[b] % 2 == 0) {
                odd++;
            } else {
                odd--;
            }

            deg[b]++;
        }

        // watch(odd)
        merge(a, b);

        string ans = "NO";
        // watch(a)
        // watch(findp(a))
        // watch(size[findp(a)])
        // watch(size[findp(b)])
        if(size[findp(a)] == nz.size()) {
            if(odd == 2 or odd == 0) {
                ans = "YES";
            }
        }
        
        cout << ans << endl;
        // cout<<endl;
    }


    
}