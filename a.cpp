#include<bits/stdc++.h>

using namespace std;

map<string ,int > ind;
string name[20];
double mag_attack[20], phys_attack[20], mag_inf[20], phys_inf[20];
int cost[20];
int ans = 2000000000;
int t1[300], t2[300];
string res[300];
int sz1, sz2;
int ans_sz;

inline void upd(int sum)
{
	double all1 = 0, all2 = 0;
	for(int k = 1; k <= sz2; ++k)
		for(int l = 1; l <= sz1; ++l)
		{
			int i = t2[k];
			int j = t1[l];
			double p1 = max(mag_attack[i] * mag_inf[j], phys_attack[i] * phys_inf[j]);
			double p2 = max(mag_attack[j] * mag_inf[i], phys_attack[j] * phys_inf[i]);
			all1 += p1;
			all2 += p2;
		}
	all1 *= sz2;
	all2 *= sz1;
	if(all1 > all2)
	{
		if(sum < ans)
		{
			ans = sum;
			ans_sz = sz2;
			for(int i = 1; i <= sz2; ++i)
				res[i] = name[t2[i]];
		}
	}
}

inline void go(int pos, int sum)
{
	if(sum > ans)
		return;
	if(pos > 10)
	{
		upd(sum);
		return;
	}
	for(int cnt = 0; cnt <= 30; ++cnt)
	{
		go(pos + 1, sum);
		t2[++sz2] = pos;
		sum += cost[pos];
	}
	for(int cnt = 0; cnt <= 30; ++cnt)
	{
		sz2--;
		sum -= cost[pos];
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i = 1; i <= 5; ++i)
	{
		cin >> name[i];
		ind[name[i]] = i;
		cin >> mag_attack[i] >> phys_attack[i] >> mag_inf[i] >> phys_inf[i] >> cost[i];
	}
	for(int i = 6; i <= 10; ++i)
	{
		cin >> name[i];
		ind[name[i]] = i;
		cin >> mag_attack[i] >> phys_attack[i] >> mag_inf[i] >> phys_inf[i] >> cost[i];
	}
	for(int i = 1; i <= 5; ++i)
	{
		string type;
		int x;
		cin >> type >> x;
		for(int j = 1; j <= x; ++j)
			t1[++sz1] = ind[type];
	}
	go(6, 0);
	cout << ans << '\n';
	for(int i = 1; i <= ans_sz; ++i)
		cout << res[i] << '\n';
	return 0;
}