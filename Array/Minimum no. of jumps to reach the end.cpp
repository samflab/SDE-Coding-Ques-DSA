// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
       int maxr = arr[0];
       int jump = 1;
       int step = arr[0];
       if(arr[0] == 0)
            return -1;
       else if(n == 1){
           return 0;
       }
       else if(n <= 1)
            return 0;
       else{
           for(int i = 1; i < n; i++){
               if(i == n - 1 && step){
                   return jump;
               }
               maxr = max(arr[i] + i, maxr);
               step --;
               if(step<0)
                    return -1;
               if(step == 0){
                   jump++;
               }
               if(maxr <= i)
                return -1;
                
                step = maxr - i;
           }
       }
      // return jump;
    }
};


    
