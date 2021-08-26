void sort012(int a[], int n)
    {
        // coode here 
        int left = 0, mid = 0, right = n - 1;
        for(int mid = 0; mid <= right; mid++){
            if(a[mid] == 0){
                swap(a[mid], a[left]);
                left++;
            }
            if(a[mid] == 2){
                swap(a[mid], a[right]);
                right--;
            }
        }
    }
