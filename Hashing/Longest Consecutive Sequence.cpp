/* Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time. */

//CODE

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet; //hash table
        for(int i =0; i < nums.size(); i++){
            hashSet.insert(nums[i]);        //insert all values in hash table
        }
        
        int longestStreak = 0;      //checking for the longest sequence
        
        for(int i = 0; i < nums.size(); i++){
            if(!hashSet.count(nums[i] - 1)){        //checking if 1 less than the nymber exists in hashtable or not
                int currentNum = nums[i];   //if it doesn't exists, start the current streak from it
                int currentStreak = 1;  
                
                while(hashSet.count(currentNum + 1)){   //checking if the current number's nexts are present in hash table
                    currentNum += 1;    //incrementing the currentNumber
                    currentStreak += 1;     //incrementing the count
                }
                
                longestStreak = max(longestStreak, currentStreak);  
            }
        }
        
        return longestStreak;
    }
};
