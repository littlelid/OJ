#include<iostream>
#include<iostream>
#include<string>
using namespace std;

void print(string pre, string mid, int l1, int r1, int l2, int r2);
int main(void)
{
    string pre, mid;
    while(cin >> pre >> mid)
    {
        print(pre, mid, 0, pre.size(), 0, mid.size());
        cout << endl;
    }

}
void print(string pre, string mid, int l1, int r1, int l2, int r2)
{
    if(r1 - l1 <= 0) return;
    
    int k = l2;
    while(mid[k] != pre[l1]) k++;
    
    int l_size = k - l2;
    int r_size = r2 - k - 1;
    print(pre, mid, l1+1, l1 + l_size + 1, l2, k);
    print(pre, mid, l1 + l_size + 1, r1, k + 1, r2);

    cout << pre[l1];
}
