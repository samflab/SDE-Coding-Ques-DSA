vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i = 0, j = 0, k = 0;
            vector<int> ans;
            int x = INT_MIN;
            while(i < n1 && j < n2 && k < n3){
                if(A[i] == B[j] && B[j] == C[k] && x != A[i]){
                    ans.push_back(A[i]);
                    x = A[i];
                    i++;
                    j++;
                    k++;
                }
                else{
                    if(min(A[i], min(B[j], C[k])) == A[i])
                        i++;
                    else if(min(A[i], min(B[j], C[k])) == B[j])
                        j++;
                    else if(min(A[i], min(B[j], C[k])) == C[k])
                        k++;
                }
            }
            
            return ans;
        }
