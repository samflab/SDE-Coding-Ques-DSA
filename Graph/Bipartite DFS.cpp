class Solution {
public:
    bool helper(vector<vector<int>> &graph, vector<int> &color, int curr){
        for(auto it: graph[curr]){
            if(color[it] == color[curr])
                return false;
            else if(color[it] == 0){
                color[it]=-color[curr];
                if(!helper(graph,color,it))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for(int i = 0; i < n; i++){
            if(color[i] == 0){
                color[i] = -1;
                if(!helper(graph, color, i))
                    return false;
            }
        }
        return true;
    }
};
