/* Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration */
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> bfs;
	    vector<int> visitedNodes(V+1, 0); //of size V+1 and all initialised with 0
        for(int i = 1; i <= V; i++) { //traverse all nodes
            if(!visitedNodes[i]){ //not visited nodes
                queue<int> q;
                q.push(i); //push the adjacent nodes
                visitedNodes[i] = 1; //after visiting the node, make it 1
                while(!q.empty()){
                    int n = q.front();  //first element from queue
                    q.pop();        //remove it
                    bfs.push_back(n); //push the current node into bfs
                    //do the same to all the adjacent nodes
                    for(auto it : adj[n]){
                        if(!visitedNodes[it]){
                            q.push(it); //put them in queue
                            visitedNodes[it] = 1;    //mark them as 1 (visited)
                        }
                    }
                }
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
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
