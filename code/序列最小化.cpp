/**
 *有一个长度为N的序列。一开始，这个序列是1, 2, 3,... n - 1, n的一个排列。
对这个序列，可以进行如下的操作：
每次选择序列中k个连续的数字，然后用这k个数字中最小的数字替换这k个数字中的每个数字。
我们希望进行了若干次操作后，序列中的每个数字都相等。请你找出需要操作的最少次数。
 *
 *
 *第一行：两个数字n, k，含义如题，满足2 <= k <= n <= 105；
  第二行：n个数字，是1, 2, 3,...n的一个排列。
 * 
 * 贪心，枚举1的相对位置，把序列分割为前半段和后半段，
 * 每次最多替换k - 1个数字，前半段的次数加后半段的次数，每次更新答案。
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
	int n,k;
	cin >> n >>k;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	if(k >= n)
		cout << "1"<<endl;
	int location = -1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1)
			location = i;
	}
	int ans = N;
	for(int i = 0; i < k; i++)
	{
		int cnt = 0;
		int pre = location - i - 1;
		int sub = pre + k;
		sub = n - sub;
		if(pre > 0 && pre <= n)
		{
			cnt += pre / (k-1);
			if(pre % (k-1))
				cnt++;
		}
		if(sub > 0)
		{
			cnt += sub/(k-1);
			if(sub % (k-1))
				cnt++;
		}
		ans = min(cnt,ans);
	}
	ans = ans + 1;
	cout<<ans<<endl;

	return 0;
}