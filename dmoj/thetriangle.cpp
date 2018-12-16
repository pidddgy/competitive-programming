// https://dmoj.ca/problem/ioi94p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector< vector<int> > cute = {vector<int>()}; // 1 indexed
    vector< vector<int> > cuteSum = {vector<int>()}; // Also 1 indexed
    for(int i = 1; i < N+1; i++) {  
        cute.push_back(vector<int>(i+1));
        cuteSum.push_back(vector<int>(i+1));
    }

    for(int i = 1; i < N+1; i++)
        for(int j = 1; j <= i; j++)
            cin >> cute[i][j];

    cuteSum[1][1] = cute[1][1]; // Top of cuteSum == top of cute

    // Fill up sides of triangle
    for(int i = 2; i < N+1; i++) {
        cuteSum[i][1] = cute[i][1] + cuteSum[i-1][1]; // Left edge
        cuteSum[i][i] = cute[i][i] + cuteSum[i-1].back(); // Right edge
    }

    // Fill up middle of triangle
    for(int i = 3; i < N+1; i++) {
        for(int j = 2; j < cute[i].size()-1; j++) {
            cuteSum[i][j] = cute[i][j] + max(cuteSum[i-1][j], cuteSum[i-1][j-1]);
        }
    }
    
    // Iterate over base
    int maxV = -1;
    for(int i = 1; i < N+1; i++) 
        if(cuteSum[N][i] > maxV) 
            maxV = cuteSum[N][i];
    
    cout << maxV << "\n";
}
