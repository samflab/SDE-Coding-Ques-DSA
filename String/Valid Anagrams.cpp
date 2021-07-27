/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 */
 //CODE
 
 class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;       //diff lengths, not an anagram
        unordered_map<char, int> mpp;
        
        for(int i =0; i < s.size(); i++){
            mpp[s[i]]++;        //increment count of characters in hashtable
        }
        
        for(int i =0; i< t.size(); i++){
            if(mpp[t[i]])
                mpp[t[i]]--;        //decrement the count of the same characters in hashtable
            else
                return false;
        }
        
        
        return true;
    }
};
