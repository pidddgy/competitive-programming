// https://codeforces.com/contest/1248/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    priority_queue<int> a;
    priority_queue<int, vector<int>, greater<int>> b;

    priority_queue<int> c;
    priority_queue<int, vector<int>, greater<int>> d;



    for(int i = 0; i < N; i++) {
        int cute;
        cin >> cute;
        
        a.push(cute);
        b.push(cute);
        c.push(cute);
        d.push(cute);

    }

    string mode = "a";
    int length = 0;
    int width = 0;
    for(int i = 0; i < N; i++) {
        if(mode == "a") {
            length += a.top();
            a.pop();
            mode = "b";
        } else {
            width += b.top();
            b.pop();

            mode = "a";
        }
    }

    int first = length*length + width*width;

    mode = "d";

    length = 0;
    width = 0;
    for(int i = 0; i < N; i++) {
        if(mode == "c") {
            length += c.top();
            c.pop();
            mode = "d";
        } else {
            width += d.top();
            d.pop();

            mode = "c";
        }
    }

    int sec = length*length + width*width;

    cout << max(first, sec) << endl;
    

    

    
}