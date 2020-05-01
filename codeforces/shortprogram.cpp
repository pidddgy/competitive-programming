// https://codeforces.com/contest/878/problem/A

#include <bits/stdc++.h>
using namespace std;
#define pci pair<char, int>
#define fi first
#define se second
#define endl '\n'
#define cerr if(false) cerr
vector<pci> ops;

int f(int n) {
    cerr << "seeing " << n << endl;
    for(pci x: ops) {
        cerr << "currently on " << x.fi << " " << x.se << endl;
        if(x.fi == '|') {
            n |= x.se;
        } else if(x.fi == '^') {
            n ^= x.se;
        } else if(x.fi == '&') {
            n &= x.se;
        }
        cerr << "n is now " << n << endl;
    }
    cerr << endl;

    return n;
}
// check if kth bit is set in N
bool kthSet(int n, int k) 
{ 
    if (n & (1 << (k - 1))) 
        return true;
    else
        return false;
} 

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    #define watch(x) cerr << (#x) << " is " << (x) << endl;


    for(int i = 1; i <= N; i++) {
        char type; int val;
        cin >> type >> val;

        ops.emplace_back(type, val);
    }

    int x = 0;
    int a = 1023;
    int o = 0;

    int cur = 1;
    for(int i = 1; i <= 10; i++) {
        cerr << "i is currently" << i << endl;
        int one = f(cur);
        int zero = f(0);

        cerr << "cur is " << cur << endl;
        watch(one)
        watch(zero)
        // both flipped
        if(!kthSet(one, i) and kthSet(zero, i)) {
            x += cur;
            cerr << "flip both" << endl;
        } 
        
        // only one is flipped
        else if(!kthSet(one, i) and !kthSet(zero, i)) {
            cerr << "subtraaaacting " << cur << endl;
            a -= cur;
            cerr << "becomes 0 " << endl;
        }

        // only zero is flipped
        else if(kthSet(one, i) and kthSet(zero, i)) {
            o += cur;
            cerr << "becomes 1" << endl;
        }
        
        cur = cur << 1;

        // otherwise dont do anything
        cerr << endl;
    }

    bitset<8> deb(x);
    bitset<8> deb2(a);
    bitset<8> deb3(o);

    cerr << deb << endl;
    cerr << deb3 << endl;
    cerr << deb2 << endl;


    cout << 3 << endl;
    cout << "^ " << x << endl;
    cout << "| " << o << endl;
    cout << "& " << a << endl;





}