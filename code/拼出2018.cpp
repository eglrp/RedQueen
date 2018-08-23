// 给定一个数字数组int nums[]，其中数字，请在其中选出一组数字，使其满足：
// 1. 和==2018
// 2. 选出的这组数字，个数越少越好。


#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2018, MAX_V = 2018; 
int dp[MAX_N][MAX_V];
bool flag[MAX_N][MAX_V];

bool compare(int a,int b)
{
 return a>b;
}

std::vector<int> MakeUp2018(std::vector<int> num)
{

	sort(num.begin(),num.end(),compare);
	int n = num.size();

	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=num.size();i++)
    {
        dp[i][0]=0;
    }
	memset(flag,false,(n+1)*(MAX_V+1)*sizeof(bool));

	bool isFind = false;

	for(int i=1; i<=n ;i++)
    {
        for(int j=1;j<=MAX_V;j++)
        {
            if(dp[i-1][j-num[i-1]]!=-1)
            {
                dp[i][j]=dp[i-1][j];
                if(num[i-1]<=j)
                {
                	
                    dp[i][j]=dp[i-1][j-num[i-1]]+num[i-1];
                    flag[i][j]=true;
                    //由于一定有一个解，而且装背包是从物品的质量从大到小装的，
                    //所以得到第一个满足的解就可以跳出
                    if(dp[i][j] == 2018)
                    {
                    	isFind = true;
                    	break;
                    }
                }
            }
        } 
        if(isFind == true)
            break;
    }

    int i = num.size();
    int j = MAX_V;
    std::vector<int> result;
    while(i >= 0 && j >= 0)
    {
    	if(flag[i][j])
    	{
    		result.push_back(num[i-1]);
    		j = j - num[i-1];
    	}
    	--i;
    }
    return result;
}

int main()
{
	vector<int> n;
	n.push_back(1000);
	n.push_back(1000);
	n.push_back(9);
	n.push_back(9);
	vector<int> m = MakeUp2018(n);
	for(int i = 0 ; i < m.size(); ++i)
		cout<<m[i]<<endl;
}