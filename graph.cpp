/*

    This code is about implemantation of Undirected Unweighted.
    For Directed Unweighted graph just remove 1 line from addEdge command.
    For Undirected Weighted graph we have to chnage definition of egde.
    For trees the code is very simialar
*/


#include <bits/stdc++.h>
using namespace std;

class graph   //implemantation of Unweighted graph
{
    private:
        int size;
        vector<vector<int>> edge; //should have used sets,lists here 
        bool* visited;
                                
    public:
        graph(){     //Constructor
            size=0;
            edge.resize(0);
            visited=new bool[size];
        }
        
        graph(int size){    //Constructor with varible
             this->size=size;
             edge.resize(size);
             visited=new bool[size];
             for(int i=0;i<size;i++)
             {
                 visited[i]=0;
             }
        }
        
        void addEdge(int x,int y);
        void dfs(int start);
};

void graph::addEdge(int x,int y)
{
    edge[x].push_back(y);  //elements are 0 indexed
    edge[y].push_back(x);
}

void graph::dfs(int start)
{
    visited[start]=1;
    cout<<start<<" ";
    
    for(auto i:edge[start])
    {
        if(visited[i]==0){dfs(i);}
    }
}




int main() {
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,5);
    
    g.dfs(0);
    
    
    
    return 0;
}
