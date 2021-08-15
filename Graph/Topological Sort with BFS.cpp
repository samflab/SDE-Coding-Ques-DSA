/* Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.*/
//CODE
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[]) 
	{
	    // code here
	    queue<int> q;
	    vector<int> indegree(N, 0); //indegree vector of size N, all initilaised to 0
	    for(int i = 0; i < N; i++){
	        for(auto it : adj[i]){ //for adjacent nodes
	            indegree[it]++; // increase the indegree if there are any incoming nodes
	        }
	    }
	    for(int i = 0; i < N; i++){
	        if(indegree[i] == 0){ //if the indegree is zero, push to queue
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo; //answer vector
	    while(!q.empty()){
	        int node = q.front(); //keep the first value
	        q.pop();
	        topo.push_back(node); //push the value to queue
	        for(auto it: adj[node]){ //for all adjacent nodes
	            indegree[it] --; //reduce the indegree
	            if(indegree[it] == 0) //if current node's indegree is 0, push it to queue
	                q.push(it);
	        }
	    }
	    return topo;
	}
	
};
	 
// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
