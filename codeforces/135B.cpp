// https://codeforces.com/contest/135/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define ld long double
#define pld pair<ld, ld>
#define pldi pair<pld, int>
#define fi first
#define se second

ld EPS = 1e-9;

bool close(ld a, ld b) {
    return(fabs(a-b) <= EPS);
}
ld slope(pld p1, pld p2) { 
    ld x1 = p1.fi;
    ld y1 = p1.se;

    ld x2 = p2.fi;
    ld y2 = p2.se;

    return ((ld)((y2 - y1) / (x2 - x1))); 
} 


// thanks geeksforgeks
ld dist(pld p1, pld p2) {
    ld x1 = p1.fi;
    ld y1 = p1.se;

    ld x2 = p2.fi;
    ld y2 = p2.se;

    // watch(sqrtf(powf(x2 - x1, 2.0) +  
                // powf(y2 - y1, 2.0)))
    // Calculating distance 
    return fabs(sqrtf(powf(fabs(x2 - x1), 2.0) +  
                powf(fabs(y2 - y1), 2.0) * 1.0)); 
} 

int sqr(int n) {
    return n*n;
}

bool isRectangle(double x1, double y1,
                 double x2, double y2,
                 double x3, double y3,
                 double x4, double y4)
{
  double cx,cy;
  double dd1,dd2,dd3,dd4;

  cx=(x1+x2+x3+x4)/4;
  cy=(y1+y2+y3+y4)/4;

  dd1=sqr(cx-x1)+sqr(cy-y1);
  dd2=sqr(cx-x2)+sqr(cy-y2);
  dd3=sqr(cx-x3)+sqr(cy-y3);
  dd4=sqr(cx-x4)+sqr(cy-y4);
  return dd1==dd2 && dd1==dd3 && dd1==dd4;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    vector<pldi> pts;
    for(int i = 0; i < 8; i++) {
        int x, y;
        cin >> x >> y;

        pts.emplace_back(pld((ld)x, (ld)y), i+1);
    }
    dist(pld(3, 3), pld(1.2, 1.2));

    for(int thing = 1; thing <= 3; thing++)
    do {
        // for(pld x: pts) {
        //     cerr << x.fi << " " << x.se << endl;
        // }
        set<ld> sq;
        for(int i = 0; i < 2; i++) {
           sq.emplace(dist(pts[i].fi, pts[i+1].fi));
        }
        sq.emplace(dist(pts[0].fi, pts[3].fi));
        sq.emplace(dist(pts[0].fi, pts[1].fi));

        sq.emplace(dist(pts[3].fi, pts[2].fi));
        sq.emplace(dist(pts[3].fi, pts[0].fi));

        sq.emplace(dist(pts[1].fi, pts[0].fi));
        sq.emplace(dist(pts[1].fi, pts[2].fi));

        set<ld> rect;
        rect.emplace(dist(pts[4].fi, pts[5].fi));
        rect.emplace(dist(pts[4].fi, pts[7].fi));

        rect.emplace(dist(pts[6].fi, pts[7].fi));
        rect.emplace(dist(pts[6].fi, pts[5].fi));   
            vector<int> inds;
            for(int ind = 0; ind < 8; ind++) {
                inds.emplace_back(pts[ind].se);
            }
            if(inds == vector<int>({1, 2, 4, 3, 6, 5, 8, 7})) continue;
        
        if(sq.size() == 1 and rect.size() <= 2) {
            cerr << "HIIII" << endl;
            if(pts[0].fi.fi <= pts[3].fi.fi)
            if(pts[1].fi.fi <= pts[2].fi.fi)
            if(pts[0].fi.se <= pts[1].fi.se)
            if(pts[3].fi.se <= pts[2].fi.se)

            if(pts[4].fi.fi <= pts[7].fi.fi)
            if(pts[5].fi.fi <= pts[6].fi.fi)
            if(pts[4].fi.se <= pts[5].fi.se)
            if(pts[7].fi.se <= pts[6].fi.se)

            if(close(slope(pts[4].fi, pts[5].fi), slope(pts[7].fi, pts[6].fi)))
            // if(close(slope(pts[4].fi, pts[7].fi), slope(pts[1].fi, pts[3].fi)))

            
            


            if(close(slope(pts[0].fi, pts[1].fi)*slope(pts[0].fi, pts[3].fi), -1.0) or (pts[0].fi.fi == pts[1].fi.fi and pts[0].fi.se == pts[3].fi.se)) {
                if(close(slope(pts[4].fi, pts[7].fi)*slope(pts[4].fi, pts[5].fi), -1.0) or (pts[4].fi.fi == pts[7].fi.fi and pts[4].fi.se == pts[5].fi.se)) {
                if(close(slope(pts[4].fi, pts[7].fi)*slope(pts[7].fi, pts[6].fi), -1.0) or (pts[4].fi.fi == pts[7].fi.fi and pts[7].fi.se == pts[6].fi.se)) {
                    cout << "YES" << endl;
                    for(int i = 0; i < 4; i++) {
                        cout << pts[i].se << " ";
                    }
                    cout << endl;
                    for(int i = 4; i < 8; i++) {
                        cout << pts[i].se << " ";
                    }
                    cout << endl;

                    // for(pldi x: pts) {
                    //     cerr << x.fi << " " << x.se << endl;
                    // }
                    return 0;
                }
                } 
            } 
            // return 0;
        }

    } while(next_permutation(pts.begin(), pts.end()));

    cout << "NO" << endl;
}