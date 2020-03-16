// https://dmoj.ca/problem/dmopc19c4p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    while(N--) {
        string s;
        cin >> s;

        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) continue;
            
            if(st.empty()) {
                st.push(s[i]);
            } else {
                if(s[i] == ')' and st.top() == '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        if(st.size()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}