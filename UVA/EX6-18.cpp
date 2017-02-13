#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<queue>

#define MAX_COOD 110
using namespace std;

struct node
{
	int x, y, z;
	node(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

const int dx[] = { 0,  0,  0,  0,  1, -1 };
const int dy[] = { 0,  0,  1, -1,  0,  0 };
const int dz[] = { 1, -1,  0,  0,  0,  0 };
int compress(int n, int* x, int* v);
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int pic[MAX_COOD][MAX_COOD][MAX_COOD];
		int x[MAX_COOD], y[MAX_COOD], z[MAX_COOD];
		int xv[MAX_COOD], yv[MAX_COOD], zv[MAX_COOD];
		memset(pic, 0, sizeof(pic));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d%d", x + 2 * i, y + 2 * i, z + 2 * i, x + 2 * i + 1, y + 2 * i + 1, z + 2 * i + 1);
			x[2 * i + 1] += x[2 * i]; y[2 * i + 1] += y[2 * i]; z[2 * i + 1] += z[2 * i];
		}
		int mx = compress(2 * n, x, xv);
		int my = compress(2 * n, y, yv);
		int mz = compress(2 * n, z, zv);

		for (int i = 0; i < n; i++)
		{
			for (int j = x[2 * i]; j < x[2 * i + 1]; j++)
			{
				for (int k = y[2 * i]; k < y[2 * i + 1]; k++)
				{
					for (int l = z[2 * i]; l < z[2 * i + 1]; l++)
					{
						pic[j][k][l] = 1;
					}
				}
			}
		}

		queue<node> q;
		node t = node(0, 0, 0);
		pic[0][0][0] = -1;
		q.push(t);
		while (!q.empty())
		{
			node a = q.front(); q.pop();

			for (int i = 0; i < 6; i++)
			{
				int tx = a.x + dx[i], ty = a.y + dy[i], tz = a.z + dz[i];
				if (tx >= 0 && ty >= 0 && tz >= 0 && tx < mx && ty < my && tz < mz && pic[tx][ty][tz] == 0)
				{
					pic[tx][ty][tz] = -1;
					node ta = node(tx, ty, tz);
					q.push(ta);

				}
			}
		}

		long long vol = 0, suf = 0;
		for (int i = 1; i < mx - 1; i++)
		{
			int delta_x = xv[i + 1] - xv[i];
			for (int j = 1; j < my - 1; j++)
			{
				int delta_y = yv[j + 1] - yv[j];
				for (int k = 1; k < mz - 1; k++)
				{
					int delta_z = zv[k + 1] - zv[k];
					if (pic[i][j][k] != -1) vol += (long long)delta_x * delta_y * delta_z;
					for (int l = 0; l < 6; l++)
					{
						if (pic[i][j][k] != -1 && pic[i + dx[l]][j + dy[l]][k + dz[l]] == -1)
						{
							suf += dx[l] ? delta_y*delta_z : (dy[l] ? delta_x*delta_z : delta_x*delta_y);
						}
					}
				}
			}
		}
		printf("%lld %lld", vol, suf);
	}
}

int  compress(int n, int* x, int* v)
{
	memcpy(v, x, sizeof(int) * n);
	v[n] = -1;
	sort(v, v + n + 1);
	int m = unique(v, v + n + 1) - v;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (x[i] == v[j])
			{
				x[i] = j;
				break;
			}
		}
	}

	return m;
}
