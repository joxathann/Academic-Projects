#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "digraphMatrix.h"

int main()
{
  //creates object digraphMatrix which is where we make the first adjacency matrix from 
  DigraphMatrix g("sample-graph1.txt");
  //from object g create integer vector of SCCs
  vector<int> component = g.stronglyConnectedComponents();


//prints integer vector
  cout << "SCC IDs: ";
  for (int cid : component)
    cout << ' ' << cid;
  cout << '\n';

  return 0;
}