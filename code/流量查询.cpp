/**
 * 每个输入数据仅包含一个测试点。
 *  输入第一行首先给出流量记录的总条目数 N <= 100000。接下来N行，每行对应了一个流量记录。每条流量记录的格式为 月/日/年 时/分/秒 流量： MM/DD/YYYY hr:mi:se FLOWi 表示该时刻流量统计软件记录下了FLOWi （0 <= FLOWi <= 10000且为整数）兆的流量。 输入数据保证N条流量记录的时间是递增，且同一时间没有重复的流量记录。 接下来一行给出小易查询总流量的数目M <= 100000。接下来M行，每行表示第mj次查询的起始和结束时间点。格式如下： MM/DD/YYYY hr:mi:se MM/DD/YYYY hr:mi:se 输
 * 入数据保证每次查询的结束时间一定不会早于起始时间。所有的输入数据均合法。
 *
 * 输出结果包含M行，每行对应第mj次查询，每次查询的结果为包含起始和结束两个时刻的总流量。
 
5
02/12/2016 00:00:00 10
02/18/2016 12:00:00 45
02/18/2016 23:59:59 8
02/19/2016 08:00:15 20
02/22/2016 13:00:00 31
4
01/01/2014 00:00:00 01/01/2017 00:00:00
11/11/2016 11:11:11 02/14/2017 00:05:20
02/12/2016 00:00:00 02/18/2016 23:00:00
02/18/2016 12:00:00 02/18/2016 12:00:00


114
0
55
45
 */

int casenum, casei;
int n, m;
struct A
{
	int mon, d, y, h, m, s;
	int sum;
	bool operator < (const A & b)const
	{
		if (y != b.y)return y < b.y;
		if (mon != b.mon)return mon < b.mon;
		if (d != b.d)return d < b.d;
		if (h != b.h)return h < b.h;
		if (m != b.m)return m < b.m;
		return s < b.s;
	}
}a[N];
int sum[N];
int main()
{
	while(~scanf("%d", &n))
	{
		for (int i = 1; i <= n; ++i)
		{
			int mon, d, y, h, m, s, sum;
			scanf("%d/%d/%d %d:%d:%d %d", &mon, &d, &y, &h, &m, &s, &sum);
			a[i] = { mon, d, y, h, m, s, sum };
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i)
{
			sum[i] = sum[i - 1] + a[i].sum;
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i)
		{
			int mon, d, y, h, m, s;
			scanf("%d/%d/%d %d:%d:%d", &mon, &d, &y, &h, &m, &s);
			A lft = { mon, d, y, h, m, s};
			scanf("%d/%d/%d %d:%d:%d", &mon, &d, &y, &h, &m, &s);
			A rgt = { mon, d, y, h, m, s };
			int l = lower_bound(a + 1, a + n + 1, lft) - a - 1;
			int r = upper_bound(a + 1, a + n + 1, rgt) - a - 1;
			int ans = sum[r] - sum[l];
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*
【题意】
略
【分析】
只要按照时间顺序排序求个前缀和，然后二分寻找区间范围，用前缀和快速求解
lower_bound()返回一个 iterator 它指向在[first,last)标记的有序序列中可以插入value，
而不会破坏容器顺序的第一个位置，而这个位置标记了一个不小于value 的值
*/