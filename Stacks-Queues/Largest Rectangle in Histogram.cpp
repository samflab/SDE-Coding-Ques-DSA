/* Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram. */

//CODE
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int n = A.size();
    vector<int> l(n), r(n);
    stack<pair<int, int>> left,right;

    for(int i = 0; i < n; i++){
        int x = -1;
        while(!left.empty() && left.top().first >= A[i]){
            left.pop();
        }
        if(!left.empty())
            x = left.top().second;
        l[i] = x;
        left.push({A[i], i});
    }

    for(int i = n-1; i >= 0; i--){
        int x = n;
        while(!right.empty() && right.top().first >= A[i]){
            right.pop();
        }
        if(!right.empty())
            x = right.top().second;
        r[i] = x;
        right.push({A[i], i});
    }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        l[i]++;
        r[i]--;

        ans = max(ans, A[i] *(r[i] - l[i] + 1));
    }

    return ans;
    }
};
