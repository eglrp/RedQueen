#include <bits/stdc++.h>
using namespace std;

void cal_next(char* str,int* next, int len)
{
	next[0] = -1;
	int k = -1;
	for(int i = 1; i < len; ++i)
	{
		while(k != -1 && str[k+1] != str[i])
			k = next[k];
		if(str[k+1] == str[i])
			k = k + 1;
		next[i] = k;
	}
}

int KMP(char* str,int slen,char* ptr,int plen)
{
	int* next = new int[plen];
	cal_next(ptr,next,plen);
	int k = -1;
	for (int i = 0; i < slen; ++i)
	{
		while( k != -1 && ptr[k+1] != str[i])
			k = next[k];
		if(ptr[k+1] == str[i])
			k++;
		if(k == plen - 1)
		{
			return i - plen + 1;
		}
	}
	return -1;
}

int main()
{
	char *str = "bacbababadababacambabacaddababacasdsd";
    char *ptr = "ababaca";
    int a = KMP(str, 36, ptr, 7);
    cout<<a<<endl;
    return 0;
}
