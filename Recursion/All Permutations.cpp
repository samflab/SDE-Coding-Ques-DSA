/* Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order. */

//CODE

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n]; //map array to check if the numbers are included in the ds or not
        
        for(int i = 0; i < n; i++)
            freq[i] = 0;        //initialising it with 0, means no element has been stored in ds 
        
        recursionPermute(ds, nums, ans, freq);
        return ans;
    }
    
    void recursionPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
        int n = nums.size();
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(!freq[i]){       //check if the element is taken or not
                ds.push_back(nums[i]);  //push the element into ds
                freq[i] = 1;    //mark as 1 after pushing the element to ds
                recursionPermute(ds, nums, ans, freq);
                
                freq[i] = 0;    //after this, unmark the map
                ds.pop_back();      //remove the element
            }
        }
    }
};
