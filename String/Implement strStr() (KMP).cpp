/* mplement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf(). */

//CODE

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t idx = haystack.find(needle);     //unsigned integer type
        return idx != string::npos ? idx : -1;
    }
};
