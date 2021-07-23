/* Given a string s, find the length of the longest substring without repeating characters. */

//CODE

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);// a string can have 256 diff characters
        
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while(right < n){
            if(mpp[s[right]] != -1) //the character at the right index exists or nor
                left = max(mpp[s[right]] + 1, left);    //if greater than left, then update the value
            
            mpp[s[right]] = right;//update the current index and insert it in hashmap
            
            len = max(len, right - left + 1); //find the range
            right ++;
        }
        return len;
    }
};
