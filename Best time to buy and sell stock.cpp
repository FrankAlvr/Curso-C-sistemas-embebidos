class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)
            return 0;
        
        int profit = 0;
        
        for(int i = 0; i < prices.size() ; i++){
            if ((i+1) < prices.size()){
                if(prices[i] < prices[i+1]){
                    if ((i+2) < prices.size()){
                    profit = profit + (prices[i+1] - prices[i]);
                    }else{
                    profit = profit + (prices[i+1] - prices[i]);
                    return profit;
                    }
                }    
            }
        }     
        return profit;
    }
};
