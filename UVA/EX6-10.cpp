#include<iostream>
#include<string.h>
#define MAXN 1000
using namespace std;
int sum[MAXN];
int left_;
int right_;
void build(int p);
int main(void)
{
    int kase = 0;
    int first_ = 1;
    while(1)
    {
        if(first_) first_ = 0;
        else cout << endl;
        kase++;
        memset(sum, 0, sizeof(sum));
        left_ = MAXN + 1;
        right_ = -1;

        int v;
        cin >> v;
        if(v == -1) break;
        int p = MAXN / 2;
        sum[p] = v;

        build(p - 1);
        build(p + 1);

        cout << "Case " << kase << ":" << endl;
        int first = 1;
        for(int i = left_ + 1; i < right_; i++)
        {
            if(first) first = 0;
            else cout << " ";
            cout << sum[i];
        }
        cout << endl;
    }
}

void build(int p)
{
    if(p < left_) left_ = p;
    if(p > right_) right_ = p;
    int v;
    cin >> v;
    if(v == - 1) return;

    sum[p] += v;
    build(p - 1);
    build(p + 1);
}










