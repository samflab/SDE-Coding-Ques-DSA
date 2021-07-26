/* Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits */

//CODEclass Solution {
public:
    int myAtoi(string str) {
        if( str.empty())
            return 0;   //string empty, return 0
        int len = str.length(), i=0, sign = 1;
        
        while( i<len && str[i] == ' ')
            i++;    //when encounters space, increment i
        
        if(i<=len)
            return 0;       //entire string is full of spaces
        
        if(str[i] == '-'){
            sign = 0;
            i++;
        }
        else if(str[i] == '+')
            i++;
        
        long int out = 0;
        
        while(str[i] >= '0' && str[i] <= '9'){  //checking for range
            out = out * 10;                     //shift it one unit place
            if(out <= INT_MIN || out >= INT_MAX)
                break;
            out = out + (str[i] - '0');         //the last digit to make a number
            i++;
        }
        
        if(sign == 0)
            out = -1 * out; //negative number
        if(out <= INT_MIN)
            return INT_MIN;
        if(out >= INT_MAX)
            return INT_MAX;
        return (int)out;
    }
};

