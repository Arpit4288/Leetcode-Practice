class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
    int n=prices.size();
    sort(prices.begin(),prices.end());
    int units=0;
    int spend=0;
    int i=0;
    while(i<n)
    {
        units=prices[i]+prices[i+1];
        spend=money-units;
        i++;
        break;
    }        
    if(spend>=0)
    return spend;
    return money;
    }
};