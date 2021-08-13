/* Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.  */
//CODE
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool checkCycleBFS(int node, int V, vector<int> adj[], vector<int> &visited){
        queue<pair<int, int>> q;    //storing node and its parent
        visited[node] = true;
        q.push({node, -1}); //the node will have a parent of -1
        
        while(!q.empty()){
            int n = q.front().first;    //current node
            int parent = q.front().second; //parent node
            q.pop();
            
            for(auto it : adj[n]){
                if(!visited[it]){ //if not visited
                    visited[it] = true; //then mark as true
                    q.push({it, n}); //push the current node and parent into queue
                    
                    
                }
                else if(parent != it){
                    return true;
                }
            }
            
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> visited(V+1, 0);
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){    //if not visited
	            if(checkCycleBFS(i, V, adj, visited))   //if a cycle
	                return true;    //return true
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
