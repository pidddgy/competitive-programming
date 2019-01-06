// https://dmoj.ca/problem/ccc06j4

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    bool depend[8][8];
    bool done[8];
    int count[8];

    // Fill arrays with 0/false
    for(int i = 1; i < 8; i++) {
        for(int j = 1; j < 8; j++)
            depend[i][j] = false;
        count[i] = 0;
        done[i] = false;
    }
    
    // Preset dependencies
    depend[1][7] = true;
    depend[1][4] = true;
    depend[2][1] = true;
    depend[3][4] = true;
    depend[3][5] = true;

    count[1] = 1;
    count[4] = 2;
    count[5] = 1;
    count[7] = 1;

    for(;;) {
        int a; int b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        depend[a][b] = true;
        count[b]++;
    }

    vector<int> order;
    for(;;) {
        bool found = false;
        for(int i = 1; i < 8; i++) {
            if(count[i] == 0 && !done[i]) {
                found = true;
                done[i] = true;
                order.push_back(i);

                for(int j = 1; j < 8; j++) {
                    if(depend[i][j]) {
                        depend[i][j] = false;
                        count[j]--;
                    }
                }
                break;
            }
        } 
        if(!found) break;
    }

    bool allTasksDone = true;
    for(int i = 1; i < 8; i++)
        if(!done[i]) allTasksDone = false;

    if(allTasksDone) {
        for(unsigned i = 0; i < order.size(); i++)
            cout << order[i] << " ";
        cout << "\n";
    }
    else
        cout << "Cannot complete these tasks. Going to bed.\n";
}
