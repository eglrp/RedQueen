int minCoins1(vector<int> arr, int aim)
{
    if(arr.empty() || aim < 0)
        return -1;

    int n = arr.size();
    int max = INT_MAX;

    int dp[n][aim+1];
    //这里对dp要初始化,都为0
    for(int j = 1; j <= aim; j++)
    {
        dp[0][j] = max;
        if(j - arr[0] >= 0 && dp[0][j - arr[0]] != max)
        {
            dp[0][j] = dp[0][j - arr[0]] + 1;
        }
    }
    int left = 0;
    for(int i = 1; i < n; i++)
    {
        for (int j = 1; j <= aim; j++)
        {
            left = max;
            if(j - arr[i] >= 0 && dp[i][j - arr[i]] != max)
            {
                left = dp[i][j - arr[i]] + 1;
            }
            dp[i][j] = min(left, dp[i-1][j]);
        }
    }
    return dp[n-1][aim] != max ? dp[n-1][aim] : -1;
}