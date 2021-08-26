 int n = prices.size();
        
        int profit = 0, minimumPrice = INT_MAX;
        
        for(int i = 0; i < n; i++){
            minimumPrice = min(minimumPrice, prices[i]);
            profit = max(profit, prices[i] - minimumPrice);
        }
        
        return profit;
