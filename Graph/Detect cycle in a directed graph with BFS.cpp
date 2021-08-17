/* */
//CODE
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int N, vector<int> adj[]) 
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
	    
	   int count = 0; //counter variable
	    while(!q.empty()){
	        int node = q.front(); //keep the first value
	        q.pop();
	        count ++;
	        for(auto it: adj[node]){ //for all adjacent nodes
	            indegree[it] --; //reduce the indegree
	            if(indegree[it] == 0) //if current node's indegree is 0, push it to queue
	                q.push(it);
	        }
	    }
	    if(count == N)
	        return false;
	   return true;
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
