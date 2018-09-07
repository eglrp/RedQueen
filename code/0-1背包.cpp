/**
 * 0-1 背包问题。总共有三件物品，背包可容纳5磅的东西，物品1 重1磅，价值60元，
 * 物品2 重2磅，价值100元，物品3 重3磅 价值120元。怎么才能最大化背包所装物品的价值。
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N = 3, V = 5;   //N是物品数量，V是背包容量
	int C[4] = {0,1,2,3};
	int W[4] = {0,60,100,120};
	int f[N+1][V+1] = {0};
	for (int i = 0; i <= V; ++i)
	{
    	f[0][i]=0;
	}
	for (int i = 1; i <= N; ++i)
	{
    	f[i][0]=0;
    	for(int j=1;j<=V;j++)
    	{
        	if(j<C[i])
            	f[i][j]=f[i-1][j];
        	else
            	f[i][j]=(f[i-1][j] > f[i-1][j-C[i]] + W[i]) ? f[i-1][j]:(f[i-1][j-C[i]]+W[i]);
    	}
	}

	cout<<f[N][V]<<endl;
	return 0;
}

