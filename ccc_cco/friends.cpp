// Friends - CCC '07 S3
// https://dmoj.ca/problem/ccc07s3

#include <bits/stdc++.h>

using namespace std;

struct Person
{
  int number;
  vector<Person> hasToBeFriendlyTo;
  Person(int num)
  {
    number = num;
  }
  void addPerson(Person object)
  {
    hasToBeFriendlyTo.push_back(object);
  }
};

pair<bool, int> bfs(int personA, int personB, vector<Person> people)
{
  vector<bool> visited(people.size(), false);
  queue<Person> cuteQueue;
  int nodesInBetween = -1;

  visited[0] = true;
  cuteQueue.push(people[personA - 1]);

  while(!cuteQueue.empty())
  {
    nodesInBetween++;
    Person s = cuteQueue.front();
    cuteQueue.pop();
    if(s.number == personB)
    {
      return{true, nodesInBetween};
    } else {
      for(unsigned cuteFriend = 0; cuteFriend < s.hasToBeFriendlyTo.size(); cuteFriend++)
      {
        if(!visited[s.hasToBeFriendlyTo[cuteFriend].number])
        {
          visited[s.hasToBeFriendlyTo[cuteFriend].number] = true;
          cuteQueue.push(people[s.hasToBeFriendlyTo[cuteFriend].number - 1]);
        }
      }
    }
  }
  return{false, 0};
}

int main() 
{
  vector<pair<int, int>> edges;
  vector<Person> people;
  int numberOfEdges; cin >> numberOfEdges;
  
  // Get all the edges
  for(int i = 0; i < numberOfEdges; i++)
  {
    int friendlinessGiver;
    int friendlinessReceiver;
    cin >> friendlinessGiver >> friendlinessReceiver;
    edges.push_back({friendlinessGiver, friendlinessReceiver});
  }

  // Make sure we know how many people we have to define
  vector<int> allEdgeNums;
  for(auto& edge: edges)
  {
    int a = edge.first;
    int b = edge.second;

    allEdgeNums.push_back(a);
    allEdgeNums.push_back(b);
    }
    int highestNumInAllEdges = *max_element(allEdgeNums.begin(), allEdgeNums.end());

  // Make the graph without the edges
  for(int num = 1; num < highestNumInAllEdges + 1; num++)
  { 
    people.emplace_back(num);
  }

  // Add edges to graph
  for(unsigned person = 0; person < people.size(); person++)
  {
    for(unsigned edge = 0; edge < edges.size(); edge++)
    {
      if(people[person].number == edges[edge].first)
      {
        people[person].addPerson(people[edges[edge].second - 1]);
      }
    }
  }
  
  // Get input forever and end when user types in 0 0
  for(;;)
  {
    int personA, personB;
    cin >> personA >> personB;
    
    if(personA == 0 && personB == 0)
    {
      break;
    }

    // Have person A bfs person B 
    pair<bool, int> atob = bfs(personA, personB, people);

    if(atob.first)
    {
      cout << "Yes " << atob.second - 1 << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
