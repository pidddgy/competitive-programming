// Tokitsukaze and Enhancement

#include <bits/stdc++.h>
using namespace std;

char getCat(int n) {
    int a = n%4;
    if(a == 1) return 'A';
    else if(a == 3) return 'B';
    else if(a == 2) return 'C';
    else return 'D';
}
int main() {
    int x;
    cin >> x;

    char bestCat = getCat(x);
    int change = 0;

    // +1
    if(getCat(x+1) < bestCat) {
        change = 1;
        bestCat = getCat(x+1);
    }

    if(getCat(x+2) < bestCat) {
        change = 2;
        bestCat = getCat(x+2);
    }



    cout << change << " " << bestCat << endl;

    



    
}