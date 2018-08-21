#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
	int n,k,m = 0;
	cin>>n>>k;
	set<pair<int,int> > s;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		s.emplace(x,i);
	}
	vector<pair<int,int> > v;
	while(k && s.size() > 1 && s.rbegin()->first - s.begin()->first > 1)
	{
		auto a = *s.begin(),b=*s.rbegin();
		s.erase(a),s.erase(b);
		k--;
		a.first++;
		b.first--;
		s.insert(a);
		s.insert(b);
		v.emplace_back(b.second,a.second);
	}
	cout<<s.rbegin()->first - s.begin()->first << " " << r.size() <<endl;
	for(auto p:v)
		cout<<p.first<<" "<<p.second<<endl;
	return 0;
}