/* You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space. */
//CODE
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2; //staring with 2nd last index
        while(low <= high) {
            int mid = (low + high) >> 1;    //finding mid
            if(nums[mid] == nums[mid^1]) {  //current and next numbers
                low = mid + 1;  //low becomes next of mid
            } 
            else {
                high = mid - 1; //high becomes previous of mid
            }
        }
        return nums[low]; 
    }
};
