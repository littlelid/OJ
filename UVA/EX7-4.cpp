#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;

int n;
int is_prime[33] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};
int a[20];
int vis[20];
void dfs(int n, int cur, int *a);
int main(void)
{
	int kase = 0;
	while(scanf("%d", &n) == 1)
	{
		if(kase) cout << endl;
		memset(a, 0, sizeof(a));
		a[0] = 1;
		kase += 1;
		cout << "Case "<< kase << ":" << endl;
		dfs(n, 1, a);
	}
    
}

void dfs(int n, int cur, int *a)
{
	if(cur == n) 
	{
		for(int i = 0; i < n; i++)
		{
			if(i) cout << ' '; 
			cout << a[i];
		}	
		cout << endl;
		return;
	}

	for(int i = 2; i <= n; i++)
	{
		if(!vis[i] && (!cur || is_prime[a[cur - 1] + i]) && (n == 1 || cur != n - 1 || is_prime[i + a[0]]) )
		{
			a[cur] = i;
			vis[i] = 1;
			dfs(n, cur + 1, a);
			vis[i] = 0;
		}
	}
}

