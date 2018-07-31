#include <bits/stdc++.h>

int main() {
  int n;
  int mostLopsidedNumber;
  int numOfPossibilities = 0;
  scanf("%i", &n);

  // Get most lopsided number
  if(n >= 5) {
    mostLopsidedNumber = 5;
  } else {
    mostLopsidedNumber = n;
  }

  // Count down until the number on the left hand >= n
  int numOnLeftHand = mostLopsidedNumber;
  while ((numOnLeftHand * 2) >= n) {
    numOfPossibilities++;
    numOnLeftHand--;
  }
  printf("%i\n", numOfPossibilities);
  return 0;
}