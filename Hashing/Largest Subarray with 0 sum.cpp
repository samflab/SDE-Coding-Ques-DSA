/* Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0. */
//CODE

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp;
    int maxSum = 0;
    int currSum = 0;
    
    for(int i = 0; i < n; i++){
        currSum += A[i];
        if(currSum == 0){   //if sum equals 0, it will be max subarray till now
            maxSum = i + 1; //update the length
        }
        else{
            if(mpp.find(currSum) != mpp.end()){ //check if that sum exists in the hash table or not
                maxSum = max(maxSum, i - mpp[currSum]); //then get the length of the subarray
            }
            else{
                mpp[currSum] = i;//or update the hash table
            }
        }
    }
    return maxSum;
}
