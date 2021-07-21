/* Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

  */

//CODE

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> nge(n, -1);     //nge named vector initialised with -1
        stack<int> st; 
        for(int i = 2*n-1;i>=0;i--) {       //starting from the right of vector, with twice the elements as the same vector has been copied, for a circular transition
            while(!st.empty() && st.top() <= nums[i%n]) {   //if them elements from top <= elements in array, until the greater element is found
                st.pop();                   //pop all the elements <= arr[i]
            }
            
            if(i<n) {
                if(!st.empty()) nge[i] = st.top(); //if the arr[i] is not >= st.top(), we use the topmost value from stack
            }
            st.push(nums[i%n]);     //we have to take that element and push it onto the stack
        }
        return nge; 
    }
};
