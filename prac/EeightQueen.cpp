#include<cstdio>
#include<iostream>

using namespace std;

void my_search(int n, int cur, int *a);

int total = 0;
int a[8];
int main(void)
{
	my_search(8, 0, a);
    cout << "*****" << endl; 
	cout << total;
    cout << "*****" << endl; 
}

void my_search(int n, int cur, int *a)
{
    if(cur == n)
	{
		total += 1;
		for(int i = 0; i < n; i++) cout << a[i];
		cout << endl;
		return;
	}
	for(int i = 0; i < n; i++)
	{
		int ok = 1;
		for(int j = 0; j < cur; j++)
		{
			if(i == a[j] || cur - j == a[j] - i || cur - j == i - a[j])
			{
			    ok = 0;
				break;
			}
		}	
		if(ok)
	    {
		    a[cur] = i;
//       cout << i << endl;
			my_search(n, cur + 1, a);	
		}

	}
}
