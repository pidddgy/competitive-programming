// https://dmoj.ca/problem/ccc18s2

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int n;
  int number;
  vector<vector<int>> table;
  vector<int> row;

  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> number;
      row.push_back(number);
    }
    table.push_back(row);
    row = {};
  }

  // Corners
  int topLeft = table[0][0];
  int topRight = table[0][n - 1];
  int bottomLeft = table[n - 1][0];
  int bottomRight = table[n - 1][n - 1];
  int smallestCorner = min({topLeft, topRight, bottomLeft, bottomRight});

  if(smallestCorner == topLeft) {
    for(int x = 0; x <= n - 1; x++) {
      for(int y = 0; y <= n - 1; y++){
        cout << table[x][y] << " ";
      }
      cout << "\n";
    }
  }

  if(smallestCorner == topRight) {
    for(int x = n - 1; x >= 0; x--) {
      for(int y = 0; y < n; y++){
        cout << table[y][x] << " ";
      }
      cout << "\n";
    }
  }

  if(smallestCorner == bottomRight) {
    for(int x = n - 1; x >= 0; x--) {
      for(int y = n - 1; y >= 0; y--){
        cout << table[x][y] << " ";
      }
      cout << "\n";
    }
  }

  if(smallestCorner == bottomLeft) {
    for(int x = 0; x <= n - 1; x++) {
      for(int y = n - 1; y >= 0; y--){
        cout << table[y][x] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}