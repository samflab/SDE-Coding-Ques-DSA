/* Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..

 */

//CODE

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(int node, vector<int>&visitedNode, vector<int> adj[], vector<int>&storeDFS){
	    storeDFS.push_back(node); //push the current node
	    visitedNode[node] = 1;  //mark the visited node as 1
	    for(auto it : adj[node]){
	        if(!visitedNode[it]){
	            dfs(it, visitedNode, adj, storeDFS);
	        }
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> storeDFS;
	    vector<int> visitedNodes(V+1, 0); // v+1 size all initilased to 0
	    for(int i = 1; i <= V; i++){
	        if(!visitedNodes[i]){   //if nodes are unvisited
	            dfs(i, visitedNodes, adj, storeDFS); //call dfs
	        }
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
