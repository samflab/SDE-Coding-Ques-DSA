//Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
//CODE

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]){
	    //initiallty mark both the arrays as 1
	    vis[node] = 1;
	    dfsVis[node] = 1;
	    for(auto it : adj[node]){   //look for adjacent nodes
	        if(!vis[it]){           //if adjacent node not visited
	        //if a dfsVis happens to go inside another dfs call then another 
	            if(checkCycle(it, adj, vis, dfsVis))    //check for a cycle
	                return true;        //return true as cycle is detected
	                
	           //if the node has been visited, then dfsVis will also be visited
	            else if(dfsVis[it])
	                return true; //so return true
	        }
	    }
	    dfsVis[node] = 0; //else mark it a 0 again if there's no cycle
	    return false;   //no cycle, return false
	}
	bool isCyclic(int N, vector<int> adj[]) 
	{
	   	// code here
	   	int visited[N], dfsVisited[N];
	   	//assign 0 to both the arrays
	   	memset(visited, 0, sizeof visited);
	   	memset(dfsVisited, 0, sizeof dfsVisited);
	   	
	   	for(int i = 0; i < N; i++){
	   	    if(!visited[i]){    //not visited previously
	   	        if(checkCycle(i, adj, visited, dfsVisited)) //call the check cycle function
	   	            return true;
	   	    }
	   	}
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
