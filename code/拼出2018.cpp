// 给定一个数字数组int nums[]，其中数字，请在其中选出一组数字，使其满足：
// 1. 和==2018
// 2. 选出的这组数字，个数越少越好。


#include <bits/stdc++.h>
using namespace std;

void core(const vector<int>& A, int index,int k, int sum, int target,vector<int>& cur,vector<vector<int> >& res)
{
    if(sum == target)
    {
        res.push_back(cur);
        return;
    }

    if(index == A.size())
        return;
    if(sum > target)
        return;

    cur.push_back(A[index]);
    core(A,index+1,k,sum+A[index],target,cur,res);
    cur.pop_back();
    core(A,index+1,k,sum,target,cur,res);
}

vector<int> KSum(vector<int>& A,int k,int target)
{
    vector<int> cur;
    vector<vector<int> > res;
    core(A,0,k,0,target,cur,res);
    int min = 0x7FFFFFFF;
    int minIndex = -1;
    for(int i = 0;  i < res.size(); ++i)
    {
        if(res[i].size() < min)
        {
            min = res[i].size();
            minIndex = i;
        }
    }
    return res[minIndex];
}

//这里我们不用限制k的取值范围
int main()
{
	vector<int> n;
	n.push_back(2016);
	n.push_back(2018);
	n.push_back(1);
	n.push_back(1);
	vector<int> m = KSum(n,0,2018);
	for(int i = 0 ; i < m.size(); ++i)
		cout<<m[i]<<endl;
}