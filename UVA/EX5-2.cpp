#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;
vector<int> data;
int n;
int abs(int x)
{
    return x > 0?x:(-x);
}
void compute()
{
    int record = data[0];
    for(int i = 0; i < n - 1; i++)
    {
        data[i] = abs(data[i] - data[i + 1]);
    }
    data[n - 1] = abs(data[n - 1] - record);
}

int check()
{
    int flag = 1;
    int size_ = data.size();

    for(int i = 0; i < size_; i++)
    {
        if(data[i] != 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(void)
{
    int T;
    cin >> T;
    while(T--)
    {
        data.clear();
        cin >> n;
        int num;
        for(int i = 0; i < n; i++)
        {
            cin >> num;
            //cout << "\tget: " << num;
            data.push_back(num);
        }
        //cout << endl;
        int flag = 0;
        for(int i = 0; i < 1000; i++)
        {


            compute();
            flag = check();
            if(flag)
            {
                printf("ZERO\n");
                break;
            }
        }
        if(!flag)
        {
            printf("LOOP\n");
        }
    }
}
