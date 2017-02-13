#include "iostream"
using namespace std;

int check();
int fail;

int main()
{
	int first = 1;

	int T;
	cin >> T;

	while(T--)
	{
        fail = 0;
        check();
        if(first)
        {
            first = 0;
        }
        else
        {
            cout << endl;
        }
        if (fail)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
	return 0;
}

int check()
{
	int WL, DL, WR, DR;
	cin >> WL >> DL >> WR >> DR;

	if (WR != 0 && WL != 0)
	{
		if (WR * DR != WL * DL)
		{
			fail = 1;
			return -1;
		}
		else
		{
			return WR + WL;
		}
	}

	int l_sum, r_sum ;
	if(WL != 0)
	{
        l_sum = WL;
	}
	else
	{
        l_sum = check();
	}

	if(WR != 0)
	{
        r_sum = WR;
	}
	else
	{
        r_sum = check();
	}

	if (l_sum * DL != r_sum * DR)
	{
		fail = 1;
		return -1;
	}
	else
	{
		return l_sum + r_sum;
	}
}

