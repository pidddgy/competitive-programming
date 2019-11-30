// https://dmoj.ca/problem/dwite07c2p4

#include <bits/stdc++.h>

using namespace std;
int main() {
    for(int tc = 0; tc < 5; tc++) {
        string str;
        cin >> str;

        stack<char> S;

        bool flag = false;
        for(auto chr: str) {
            if(chr == '(' or chr == '{' or chr == '[') {
                S.push(chr);
            }
            
            else if (chr == ')') {
                if(S.size()){
                    if(S.top() == '(') {
                        S.pop();
                    }
                }

                else flag = true;
            }

            else if (chr == '}') {
                if(S.size()){
                    if(S.top() == '{') {
                        S.pop();
                    }
                }

                else flag = true;
            }

            else if (chr == ']') {
                if(S.size()){
                    if(S.top() == '[') {
                        S.pop();
                    }
                }

                else flag = true;
            }

            if(flag) break;
        }

        if(S.size() == 0 && not flag) cout << "balanced" << endl;
        else cout << "not balanced" << endl;
    }

    
}
