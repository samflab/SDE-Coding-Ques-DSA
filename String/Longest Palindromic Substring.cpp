/* Given a string s, return the longest palindromic substring in s. */
//CODE
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;   //if string is empty or has 1 character
        int max_len = 1;
        int n = s.length();
        int st = 0, end = 0;
        
        // Odd length
        for(int i = 0; i < n-1; ++i){
            int l = i, r = i;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){   //checking for palindrome
                    l--; r++;
                }else
                    break;
            }
            int len = r-l-1;
            if(len > max_len){
                max_len = len;
                st = l+1;
                end = r-1;
            }
        }
        
        // Even length
        for(int i = 0; i < n-1; ++i){
            int l = i, r = i+1;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--; r++;
                }else
                    break;
            }
            int len = r-l-1;
            if(len > max_len){
                max_len = len;
                st = l+1;
                end = r-1;
            }
        }
        
        return s.substr(st, max_len);
    }
};
