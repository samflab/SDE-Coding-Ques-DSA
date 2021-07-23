/* Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B. */
//CODE

int Solution::solve(vector<int> &A, int B) {
    map<int, int> freq;
    int count = 0;
    int xorr = 0;

    for(auto it: A){
        xorr = xorr ^ it;   //compute the xor with the elements

        if(xorr == B){      //if its giving the subarray XOR as B
            count++;       //increasing count
        }

        if(freq.find(xorr ^ B) != freq.end())     //check the hash table if the xor ^ B exists or not
            count += freq[xorr ^ B];    //increase the count by how many number of times its increasing

        freq[xorr] += 1;    //insert it into the hash map
        

    
    }
    return count;
}
