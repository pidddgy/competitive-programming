// https://mcpt.ca/problem/ahc19p4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
string cy(int n) {
    if(n == 1) return "1";

    string res = "";
    for(int i = n; i > n/2; i--) {
        res += to_string(i);
    }

    res += "1";

    for(int i = n/2; i > 1; i--) {
        res += to_string(i);
    }

    if(n % 2 == 1) {
        swap(res[n/2], res[(n/2)-1]);
    }
    return res;
}
int main() {
    int N, K;
    cin >> N >> K;

    // cout << cy(5) << endl;
    int c = N-K;
    int i = 1;

    vector<int> begin;
    deque<int> end;

    int a = N;
    int b = 1;
    int made = 0;

    // watch(c)
    while(c > 1) {
        c--;
        begin.emplace_back(a);
        end.push_front(b);

        a--;
        b++;
        made++;
    }
    
    string s = cy(N - (made*2));
    for(char &x: s) {
        x += made;
    }

    for(auto x: begin) cout << x << " ";
    for(auto x: s) cout << x << " ";
    for(auto x: end) cout << x << " ";
    cout << endl;


    


}