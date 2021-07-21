/* Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1. */

//CODE
vector<int> Solution::prevSmaller(vector<int> &nums) {
    
    
        int n = nums.size(); 
        vector<int> nse(n, -1);     //nse named vector initialised with -1
        stack<int> st; 
        for(int i = 0;i<=2*n-1;i++) {       //starting from the left , with twice the elements as the same vector has been copied, for a circular transition
            while(!st.empty() && st.top() >= nums[i%n]) {   //if them elements from top >= elements in array, until the smaller element is found
                st.pop();                   //pop all the elements >= arr[i]
            }
            
            if(i<n) {
                if(!st.empty()) nse[i] = st.top(); //if the arr[i] is not <= st.top(), we use the topmost value from stack
            }
            st.push(nums[i%n]);     //we have to take that element and push it onto the stack
        }
        return nse; 
 
}
