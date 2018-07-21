/**
 * 一般的括号匹配问题是这样的：
给出一个字符串，判断这个括号匹配是不是合法的括号匹配。
如"((" 和 "())"都不是合法的括号匹配，但是"()()()"，"(()())()"等就是合法的括号匹配。
这个问题解决起来非常简单，相信大家都知道怎么解决。
现在给出一个加强版的括号匹配问题： 给出n个由括号 '(' 和 ‘)’ 组成的字符串，
请计算出这些字符串中有多少对字符串满足si + sj是合法的括号匹配。
如果si + sj和sj + si都是合法的括号匹配(i ≠ j)，
那么这两种搭配都需要计入答案；如果对于si，si + si是合法的括号匹配，那么也需要计入答案。
 *
 * 对于每个字符串，用栈判断是否合法，每次栈为空或者栈中只有一种类型的括号，那
 * 么就是合法的，否则不合法。统计完后，用乘法原理累加即可。
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

string s;
map<int,int> l;
map<int,int> r;
stack<char> S;

int main()
{
	int n;
	cin >> n;
	int com = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>s;
		while(!S.empty())
			S.pop();
		int sz = s.length();
		for(int i = 0; i < sz; i++)
		{
			if(s[i] == '(')
			{
				S.push(s[i]);
			}
			else
			{
				if(S.empty())
				{
					S.push(s[i]);
				}
				else
				{
					if(S.top() == '(')
						S.pop();
					else
						S.push(s[i]);
				}
			}
		}

		int ln = 0, rn =0;
		if(S.empty())
		{
			com++;
			continue;
		}

		while(!S.empty())
		{
			char t = S.top();
			if(t == '(')
				ln++;
			else
				rn++;
			S.pop();
		}

		if(ln == 0)
		{
			r[rn]++;
		}
		else if(rn == 0)
		{
			l[ln]++;
		}
	}
		long long ans = (long long)com * com;
		for(auto it = l.begin(); it != l.end(); ++it)
		{
			int tmp = it->first;
			int num = it->second;
			ans += 1LL * num * r[tmp];
		}

		cout<<ans<<endl;
	
	return 0;
}