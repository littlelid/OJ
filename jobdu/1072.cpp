#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> nums);
int n;
int main(void)
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    while(cin >> n)
    {
        print(nums); 
    }
}

void print(vector<int> nums)
{
    if( nums.size() >= n + 2)
        return;
    vector<int> new_nums;
    new_nums.push_back(0);

    for(int i = 1; i < nums.size(); i++)
    {
        int num = nums[i - 1] + nums[i];
        if(i == 1) cout << num;
        else       cout << " " << num;
        new_nums.push_back(num);    
    }
    cout << endl;
    new_nums.push_back(0);
        
    print(new_nums);
}
