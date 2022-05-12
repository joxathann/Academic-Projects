#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <stack>


using namespace std;

stack<int> s;
stack<int> rev_s;
vector<int> component;
#include "digraphMatrix.h"
//driver:Johnathan Gonzalez
//navigagtor: Bryce

DigraphMatrix::DigraphMatrix(const string& File){
 fstream file;
 file.open(File);
 //number of vertices and edges
 int m;
 file >> this->n;
 file >> m;
 vector<bool> row(this->n, 0);

 for(int i = 0; i<n;i++){
     Adj.push_back(row);
     
 }

 for(int i = 0; i<Adj.size(); i++){
     for(int j = 0;j<row.size(); j++){
        int v1, v2;
        file >> v1;
        file >> v2;
        Adj[v1][v2] = 1;
        cout << Adj[i][j] << " ";
    
        //transpose[v2][v1] = Adj[v1][v2];
        //cout << transpose[i][j] << " ";
     }
     cout << endl;
 }
 file.close();
}


vector<int> DigraphMatrix::getOutNeighbors(int x) const
{
  vector<int> N;
  //Scan N(v) to get out neighbors
  for (int i = 0; i < n; i++){
        if(Adj[x][i] == 1){
            N.push_back(i);
        }
    }
  

  return N;
}

vector<int> DigraphMatrix::getInNeighbors(int x) const
{
    vector<int> N;

        for(int i =0; i<n; i++)
            if(Adj[i][x] == 1)
                N.push_back(i);
            
    return N;
}

//From class, modified a bit to fit the variables of the digraph class
void DigraphMatrix::firstDFS(unordered_map<int, mark_t>& marks, const int& x){
    vector<int> out = getOutNeighbors(x);
    
    marks[x]= DISCOVERED;
    
    for(auto i: out){
        if(marks[i] == UNDISCOVERED){
            firstDFS(marks, i);
        }
        
    }
    
    
    marks[x] = EXPLORED;
    cout << x << ", ";
    s.push(x);

    
}

//starts DFS function at lowest vertex ID
void DigraphMatrix::fstartDFS(int start){
 unordered_map<int, mark_t> marks;

 for(int i =0; i< this->getOrder(); i++){
     marks[i] = UNDISCOVERED;
 }

 
 firstDFS(marks, start);
 for(int i = 0; i < this->getOrder(); i++){
     if(marks[i] == UNDISCOVERED){
         firstDFS(marks, i);
     }
 }


}


vector<int> DigraphMatrix::sstartDFS(int start){
    unordered_map<int,mark_t> marks;
    int count = 0;
    vector<int> SCC(n);
    for( int i = 0 ; i < this->getOrder(); i++){
        marks[i] = UNDISCOVERED;

    }
    
    while(!s.empty()){
        if(marks[s.top()] == UNDISCOVERED){
            
            secondDFS(marks, s.top(), count, SCC);
            count++;
        }
            
            s.pop();
    }
return SCC;
}

void DigraphMatrix::secondDFS(unordered_map<int, mark_t>& marks, const int& x, int count, vector<int>& SCC){
   vector<int> in = getInNeighbors(x);
   
    
    marks[x] = DISCOVERED;
    
    for(auto i: in){
        if(marks[i] == UNDISCOVERED){
            secondDFS(marks, i, count,SCC);   
        }
    }
        
    marks[x] = EXPLORED;
    
    SCC[x] = count;

    
}


  
vector<int>  DigraphMatrix::stronglyConnectedComponents()
{
    
    fstartDFS(0);
     
    
    vector<int> SCC = (sstartDFS(s.top()));

    
return SCC;
}
    
