class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minbuy = prices[0];
        for(auto price: prices) {
            maxprofit = max(maxprofit,price-minbuy);
            minbuy = min(minbuy,price);
        }
        return maxprofit;
    }
};
