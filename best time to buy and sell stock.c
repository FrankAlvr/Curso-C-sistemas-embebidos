int maxProfit(int* prices, int pricesSize) {
    if(pricesSize == 0 || pricesSize == 1)
        return 0;
    
    int* left = prices; 
    int* right = prices+1;
    int profit = 0;

    while(right < prices + pricesSize){
        if(*left < *right){
            if((right+1) < (prices + pricesSize)){
                profit = profit + (*right - *left);
                left = right;
            }else{
                profit = profit + (*right - *left);
                return profit;
            }
            
        }else if(*right < *left){
            left = right;
        }
        right++;
    }

    return profit;

}
