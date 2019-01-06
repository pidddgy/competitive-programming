// https://dmoj.ca/problem/ccc05j3

#include <bits/stdc++.h>
#include <vector>

using namespace std;
int main()
{
  vector<string> directions = {"HOME"};
  string instruction;
  
  // Get directions until the user types in "SCHOOL"
  for(;;)
  {
    cin >> instruction;
    if(instruction == "SCHOOL")
    {
      break;
    }
    else 
    {
      directions.push_back(instruction);
    }
  }

  // Go over `directions` in reverse order, flipping R or L
  for(int it = directions.size(); it >= 0; it -= 2) 
  {
    // directions[it+1] is the direction that Jane turns to go onto it'th street
    if(directions[it + 1] == "R") 
    {
      if(directions[it] == "HOME") 
      {
        cout << "Turn LEFT into your HOME." << "\n";
      } 
      else 
      {
        cout << "Turn LEFT onto " << directions[it] << " street." "\n";
      }
    }
    
    if(directions[it + 1] == "L") 
    {
      if(directions[it] == "HOME") 
      {
        cout << "Turn RIGHT into your HOME." << "\n";
      } else 
      {
        cout << "Turn RIGHT onto " << directions[it] << " street." "\n";
      }
    } 
  }
  return 0;
}
