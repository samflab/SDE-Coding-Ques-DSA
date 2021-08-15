/* There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite. */

//CODE

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);    //colour vector of size n, all initilaised to 0
        for(int i = 0; i < n; i++){
            if(color[i] == 0){  //if not coloured 
                color[i] = 1;   //then assign a colour, mark it 1
                queue<int> q;
                q.push(i);      //push the current node to queue
                while(!q.empty()){
                    int x = q.front();  //first node to x
                    q.pop();            //pop the first node
                    for(auto it : graph[x]){    //for all values in graph
                        if(color[it] == color[x])   //if color of the node in graph is the same as the current node
                            return false;
                        else if(color[it] == 0){    //mark it 0
                            color[it] =- color[x];
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};
