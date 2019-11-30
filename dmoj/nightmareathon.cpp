// https://dmoj.ca/problem/gfssoc2j5

#include <bits/stdc++.h>
const int maxnq = 500005;
using namespace std;

int a[maxnq];
int maxleft[maxnq];
int maxright[maxnq];
int freqleft[maxnq];
int freqright[maxnq];

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
        maxleft[i] = max(maxleft[i-1], a[i]);

    for(int i = n; i >= 1; i--)
        maxright[i] = max(maxright[i+1], a[i]);

    for(int i = 1; i <= n; i++) {
        if(maxleft[i] > maxleft[i-1])
            freqleft[i] = 1;
        else if(a[i] == maxleft[i-1])
            freqleft[i] = freqleft[i-1]+1;
        else 
            freqleft[i] = freqleft[i-1];
    }

    for(int i = n; i >= 1; i--) {
        if(maxright[i] > maxright[i+1])
            freqright[i] = 1;
        else if(a[i] == maxleft[i+1])
            freqright[i] = freqright[i+1]+1;
        else
            freqright[i] = freqright[i+1];
    }

    for(int i = 1; i <= q; i++) {
        int A, B; cin >> A >> B;

        int lm = maxleft[A-1];
        int rm = maxright[B+1];

        cout << max(lm, rm) << " ";

        if(lm > rm)
            cout << freqleft[A-1] << "\n";
        else if(rm > lm)
            cout << freqright[B+1] << "\n";
        else
            cout << freqleft[A-1] + freqright[B+1] << "\n";
    }
}
