题目：N个桶里有N个球，每个桶里有且只有一个球，桶和球上都有序号(1-N不重复)。
现要求桶里的球的序号和桶的序号不能相同，试算出有多少种组合。

通过举例可得递推公式：
n!(1-1/2!+1/3!-1/4!+1/5!...+(-1)n/N!）


int Func(int N)
{
	if(N < 1)
		return -1;

	int signal = N&1 ? 1:-1;
	int tmpFac = 1;
	int result = 0;

	//这里运用了中间变量，避免了表达式中的除法
	for(int i = N; i >= 1; --i)
	{
		signal = -1 * signal;
		result += signal * tmpFac;
		tmpFac = tmpFac * i;
	}

	result += tmpFac;

	return result;
}
