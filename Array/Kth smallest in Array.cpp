int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq; //contains elements in a decreasing order
        for(int i = l; i <= r; i++){
            if(pq.size() > k)       //if the length of pq is greater than k
                pq.pop();           //pop the elements at front
        }
        return pq.top();            //and return the top most element
    }
