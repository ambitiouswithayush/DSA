class Solution {
public:
    int N,M,K;
    int MOD=1e9+7;
    int dp[51][51][101];
    int solve(int index,int searchCost,int maxSofar){
        if(index==N){
            if(searchCost==K){
                return 1;
            }
            return 0;
        }
        int result=0;
        if(dp[index][searchCost][maxSofar]!=-1){
            return dp[index][searchCost][maxSofar];
        }
        for(int i=1;i<=M;i++){
            if(i>maxSofar){
                result=(result+solve(index+1,searchCost+1,i))%MOD;
            }
            else
                result=(result+solve(index+1,searchCost,maxSofar))%MOD;
        }
        return dp[index][searchCost][maxSofar]=result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;

        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};