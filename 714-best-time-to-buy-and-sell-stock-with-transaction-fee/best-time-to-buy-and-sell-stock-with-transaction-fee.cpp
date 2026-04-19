class Solution {
public:
    int t[50001][2];
    int FEE;
    int solve(vector<int>&prices,int day,int n,bool buy){
        if(day>=n) return 0;
        
        if(t[day][buy]!=-1)
            return t[day][buy];
        if(buy){
            int take=solve(prices,day+1,n,false)-prices[day];
            int not_take=solve(prices,day+1,n,true);
            return t[day][buy]=max(take,not_take);
        }
        else{
            int sell=prices[day]+solve(prices,day+1,n,true)-FEE;
            int not_sell=solve(prices,day+1,n,false);
            return t[day][buy]=max(sell,not_sell);
        }
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        FEE=fee;
        int n=prices.size();
        memset(t,-1,sizeof(t));
        bool buy=true;
        return solve(prices,0,n,buy);
    }
};