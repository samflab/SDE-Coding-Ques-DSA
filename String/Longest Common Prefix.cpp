/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 */
 //CODE
 
 class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        bool flag=false;
         if(strs.size()==1){    //if the string size is 1
             return strs[0];
         }
        for(int i=0;i<strs[0].length();i++){    //traverse till first string's length
            for(int r=1;r<strs.size();r++){     //traverse the entire string
                if(strs[0][i]==strs[r][i]){     
                    flag=true;
                }
                else{
                    flag=false;
                    return s;
                }
            }
            if(flag){
            s+=strs[0][i];      //append the string value
            }
         }
        return s;
    }
};
