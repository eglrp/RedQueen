// 输入的第一行是一个正整数T，表示样例数。 接下来是T个样例，每个样例的第一行是3个正整数hp, atk，cd，
// 分别表示你的当前生命、普攻攻击力以及技能冷却时间。第二行是3个正整数x1, x2, x3，分别表示你的3个技能的攻击力。
// 第三行是6个正整数hp1, y1, hp2, y2, hp3, y3，分别表示3个敌方英雄的血量和普攻攻击力。 对于30%的数据，所有血量不超过500，
// 所有技能和普攻攻击力不超过50；对于100%的数据，所有血量不超过50000，
// 所有技能和普攻攻击力不超过100。技能的冷却时间1 <= cd <= 10。

// 对于每一个样例，输出一个整数，表示完成三杀后你最多还剩多少血量。如果不能完成，输出-1。
// 
// 输入

// 2
// 254 25 9
// 31 21 15
// 86 6 196 1 249 10
// 119 26 5
// 46 27 13
// 219 6 169 20 50 20
// 输出

// 68
// -1
// 备注:

// 样例1： 先攻击第一个敌人，使用1次技能1和3次普攻，共花费4秒击杀； 然后攻击第三个敌人，
// 先使用1次技能1和8次普攻，此时使用一次技能1（刚好冷却结束）或普攻，共花费10秒； 最后攻击第二个敌人，先使用1次技能1，然后7次普攻，共花费8秒。 
// 受到的总伤害为(6+1+10)*4 + (1 + 10) * 10 + 1 * 8 = 186，所以最终还剩68血量。 
//  样例2： 无论怎样选择攻击策略，都无法完成三杀。

int hp, atk, cd;
int x1, x2, x3;
struct A
{
	int hp, atk;
}a[3];
int p[3];
int skl[3], cdrst[3], turn[3], g;
int solve(int HP)
{
	int atksum = 0;
	for (int i = 0; i < 3; ++i)
	{
		int atk = a[p[i]].atk;
		atksum += atk;
	}
	//KILL
	for (int i = 0; i < 3; ++i)
	{
		int hp = a[p[i]].hp;
		int atk = a[p[i]].atk;
		int tim = turn[p[i]];
		HP -= tim * atksum;
		atksum -= atk;
	}
	return HP;
}
int main()
{
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		scanf("%d%d%d", &hp, &atk, &cd);
		scanf("%d%d%d", &skl[0], &skl[1], &skl[2]);
		g = 3; sort(skl, skl + 3);
		reverse(skl, skl + 3);
		while (g && skl[g - 1] <= atk)--g;
 
		//find order skill
		for (int i = 0; i < 3; ++i)
		{
			scanf("%d%d", &a[i].hp, &a[i].atk);
			turn[i] = 0;
			int hp = a[i].hp;
			for (int j = 0; j < g; ++j)cdrst[j] = 0;
			while (hp > 0)
			{
				++turn[i];
				for (int j = 0; j < g; ++j)--cdrst[j];
				bool flag = 0;
				for (int j = 0; j < g; ++j)if (cdrst[j] <= 0)
				{
					hp -= skl[j];
					cdrst[j] = cd;
					flag = 1;
					break;
				}
				if (!flag)hp -= atk;
			}
			int pause = 1;
		}
 
		//find order player
		int ans = -1;
		for (int i = 0; i < 3; ++i)p[i] = i;
		do
		{
			gmax(ans, solve(hp));
		} while (next_permutation(p, p + 3));
		printf("%d\n", ans);
	}
	return 0;
}
/*
【trick&&吐槽】
这种做法有问题，找到了反例，但是通过了比赛的所有测试数据。

next_permutation
可以发现函数next_permutation()是按照字典序产生排列的，
并且是从数组中当前的字典序开始依次增大直至到最大字典序。
*/