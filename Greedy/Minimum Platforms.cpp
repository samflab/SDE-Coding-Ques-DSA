/* Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms. */
//CODE

// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	//sort arrival and departure array
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int platform = 1, result = 1;
    	int i = 1, j = 0;
    	
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){   //departure time is greater
    	        platform++;         //require more platform
    	        i++;                //checking for next train arriavl
    	    }
    	    
    	    else if(arr[i] > dep[j]){   
    	        platform--;
    	        j++;
    	    }
    	    if(platform > result){
    	        result = platform;
    	    }
    	}
    	return result;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
