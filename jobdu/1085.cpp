#include<cstdio>
#include<iostream>

using namespace std;
int k;
int  root(int n);
int  solve(int x, int y);
int main(void)
{
    int x, y;
    while(cin >> x)
    {
        cin >> y >> k;
        cout << solve(x, y) << endl;

    }
}
int root(int x)
{
    
    int sum = 0;
    do{
        sum = 0;
        while(x)
        {
            sum += x % k;
            x /= k;
        }
        x = sum;
    
    }while(sum >= k);
    return sum;
}

int  solve(int x, int y)
{
    //cout << x << " " << y << endl;
    if(y == 0) 
        return 1;
    if(y % 2 == 1)
        return root(root(x) * root(solve(x, y - 1)));
    else
    {
        int tmp = root(solve(x, y/2));
        //cout << "\ttmp= " << tmp << endl;
        return root(tmp*tmp);
    }

}

