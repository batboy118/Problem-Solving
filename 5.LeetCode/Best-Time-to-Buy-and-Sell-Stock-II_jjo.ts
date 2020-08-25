function maxProfit(prices: number[]): number {
    prices.push(-1);
    let has_stock = 0;
    let start = 0;
    let total = 0;
    
    for(let i = 0; i < prices.length; i++){
        if(has_stock == 0 && prices[i] < prices[i+1]){
            has_stock = 1;
            start = prices[i];
        }
        else if(has_stock == 1 && prices[i] > prices[i+1]){
            has_stock = 0;
            total += prices[i] - start;
        }
    }
    return total;
};
