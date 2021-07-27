/* Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "",  repeated 1 time is "abc" and repeated 2 times is "abcabc".

  */
  
 //CODE
 
 class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string s="";    //empty result string
        int count = 0;
        while(s.size()<B.size())    
        {
            s+=A;           //keep appending A to S till the size is less that that of B
            count++;
        }
        if(s.find(B)!=string::npos)     //if s has B until it reaches null
            return count;
        s+=A;           
        count++;
        if(s.find(B)!=string::npos)     
            return count;
        
        return -1;
    }
};
