/* Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day. */

//CODE
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    bool myCmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int activitySelection(vector<int> start, vector<int> end, int n) {
    
    vector<pair<int, int>> jobTime;
    
    for(int i = 0; i < n; i++) {
        jobTime.push_back({start[i], end[i]});
    }
    
    sort(jobTime.begin(), jobTime.end(), myCmp);

    int count = 1;
    pair<int, int> last = jobTime[0];
    
    for(int i = 1; i < n; i++)
    {
        if(jobTime[i].first >= last.second)
        {
            count++;
            last = jobTime[i];
        }
    }
    
    return count;
}
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
