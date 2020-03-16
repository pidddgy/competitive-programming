#include <bits/stdc++.h>
using namespace std;

int disj[10500];
int findp(int n) {
    if(disj[n] == n) return n;
    else return disj[n] = findp(disj[n]);
}
    
void merge(int a, int b) {
    int a_p = findp(a);
    int b_p = findp(b);
    
    disj[a_p] = b_p;
}


int main() {

    for(int i = 1; i <= 10000; i++) disj[i] = i;
    
    int V, E;
    cin >> V >> E;

    vector<int> G[V+1];
    for(int i = 1; i <= E; i++) {
        int a,b;
        cin >> a >> b;

        G[a].emplace_back(b);
    }

    


}