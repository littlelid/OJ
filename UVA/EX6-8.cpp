#include<cstdio>
#include<vector>
#include<iostream>
#include<sstream>
#include<string.h>
#include<limits.h>

using namespace std;

int left_[10000 + 10], right_[10000 + 10];
vector<int> in, post;
int gen_tree(int L1, int R1, int L2, int R2);
void find_least(int r, int sum);
int min_sum;
int leaf;
int main(void)
{
    string line1;
    string line2;

    while(getline(cin, line1))
    {
        getline(cin, line2);

        min_sum = INT_MAX;
        leaf = -1;
        in.clear(); post.clear();
        memset(left_, -1, sizeof(left_));
        memset(right_, -1, sizeof(right_));

        int v, u;
        stringstream ss1(line1);
        stringstream ss2(line2);

        while(ss1 >> v )
        {
            in.push_back(v);
            //cout << v << endl;
        }
        while(ss2 >> u )
        {
            post.push_back(u);
            //cout << u << endl;
        }

        int root = gen_tree(0, in.size() - 1, 0, post.size() - 1);
        //cout << "build complete\n";
        find_least(root, 0);
        cout << leaf << endl;
    }
}

int gen_tree(int L1, int R1, int L2, int R2)
{


    if(L1 > R1 || L2 > R2) return -1;

    int r = post[R2];
    //cout << r << " ";


    int p = L1;
    while(r != in[p]) p++;

    int cnt = p - L1;
    left_[r]  =  gen_tree(L1,    p - 1, L2,       L2 + cnt - 1);
    right_[r] =  gen_tree(p + 1, R1,    L2 + cnt, R2 - 1);

    return r;

}

void find_least(int r, int sum)
{
    //cout << r << "\n";
    if(left_[r] == -1 && right_[r] == -1)
    {
        if(sum + r < min_sum)
        {

            leaf = r;
            min_sum = sum + r;
            //cout << "\t change" << "min_sum = " << min_sum << endl;
        }
        if(sum + r == min_sum && r < leaf)
        {
            leaf = r;
        }
        return;
    }





    if(left_[r] != -1) find_least(left_[r], sum + r);
    if(right_[r] != -1) find_least(right_[r],sum + r);

    return;

}

/*
int find_least(int r)
{

    cout << r << " ";
    if(r == - 1) return 0;

    int l_sum, r_sum;

    l_sum = find_least(left_[r]);
    r_sum = find_least(right_[r]);

    return l_sum < r_sum?l_sum + r:r_sum + r;

}
*/


