#ifndef __DIGRAPH_MATRIX_H
#define __DIGRAPH_MATRIX_H

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
using namespace std;



enum mark_t { UNDISCOVERED, DISCOVERED, EXPLORED };

class DigraphMatrix
{
private:
  int n;
  vector<vector<bool>> Adj;
  
public:


  //Reads in digraph from given file
  //Stores graph as an adjacency matrix
  DigraphMatrix(const string&);
  //getNeighbors function
    vector<int> getNeighbors(int) const;
    vector<int> getOutNeighbors(int) const;
    vector<int> getInNeighbors(int) const;

    vector<int> sstartDFS(int);
    void fstartDFS(int);
    void firstDFS(unordered_map<int, mark_t>&, const int&);
    void secondDFS(unordered_map<int, mark_t>&, const int&, int, vector<int>&);

  //Returns number of vertices
  int getOrder() const { return n; }

  

  //Returns vector containing component ID for each vertex
  vector<int> stronglyConnectedComponents();



  //Fills Stack
  void fillOrder(int v, bool visited[], stack<int> &Stack);
};

#endif