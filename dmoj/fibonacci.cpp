// https://dmoj.ca/problem/fibonacci    

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int unsigned long long

const int MOD = (int)1e9+7;

struct Matrix {
    vector<vector<int>> vals;
    int rows, cols;
    Matrix(vector<vector<int>> valss) {
        this->vals = valss;
        this->rows = vals.size();
        this->cols = vals[0].size();
    }
    
    Matrix operator*(const Matrix &other) const{
        int n = this->rows;
        int m = other.cols;

        assert(this->cols == other.rows);
        vector<vector<int>> res(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < this->cols; k++) {
                    res[i][j] += this->vals[i][k] * other.vals[k][j];
                    res[i][j] %= MOD;
                }
            }
        }        

        return res;
    }

    void printVals() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cerr << this->vals[i][j] << " ";
            }
            cerr << endl;
        }
    }
};

Matrix identityMatrix(int n) {
    vector<vector<int>> vals(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        vals[i][i] = 1;
    }

    return Matrix(vals);
}

Matrix mpow(Matrix a, int exp) {
    if(exp == 0) return identityMatrix(max(a.rows, a.cols));

    Matrix t = mpow(a, exp / 2);
    if(exp & 1) return t * t * a;
    return t * t;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> initVals = {{0, 1}};
    vector<vector<int>> MVals = {{0, 1}, {1, 1}};

    Matrix dp(initVals);
    Matrix M(MVals);

    M = mpow(M, N-1);
    dp = dp*M;

    cout << dp.vals[0][1] << endl;
}
