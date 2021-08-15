/* Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph. */
//CODE

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
	public:
	void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int>adj[]){
	    vis[node] = 1;
	    for(auto it : adj[node]){ //look for it adjacents
	        if(!vis[it]){ //if adjacent nodes are not visited
	            findTopoSort(it, vis, st, adj);
	        }
	    }
	    
	    st.push(node); //keep pushing the visited node
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<int> vis(N, 0); //visited vector of size N, all initialised to 0
	    for(int i = 0; i < N; i++){
	        if(vis[i] == 0){    //if not visited
	            findTopoSort(i, vis, st, adj); //call topo osrt
	        }
	    }
	    vector<int> topo; //final answer
	    while(!st.empty()){
	        topo.push_back(st.top()); //push all the elements of stack into this vector
	        st.pop();
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
