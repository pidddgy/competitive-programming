#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int c; int r;
    cin >> c >> r;

    int currx = 0;
    int curry = 0;

    for(;;) {
        int x; int y;
        cin >> x >> y;
        if(x == 0 && y == 0)
            break;
        
        currx += x;
        curry += y;

        if(currx > c)
            currx = c;
        if(currx < 0)
            currx = 0;

        if(curry > r)
            curry = r;
        if(curry < 0) 
            curry = 0;

        cout << currx << " " << curry << "\n";
    }
}
