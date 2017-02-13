#include<cstdio>
#include<iostream>
using namespace std;

void parse(int fl, int fr, int ml, int mr);
string s1, s2;
int main(void)
{
    
    while(cin >> s1)
    {
        cin >> s2;
        int l = s1.size();
        parse(0, l - 1, 0, l - 1);
        cout << endl;
    }
}

void parse(int fl, int fr, int ml, int mr)
{
    //cout << fl << " " << fr << " " << ml << " " << mr << endl;
    char father = s1[fl];
    
    int pos = ml;
    while(s2[pos] != father) { pos++;}
    
    int len_l = pos - ml;
        
    int len_r = mr - pos;
    //cout << "\t" << father << " " << s2[pos] << " " << pos << " " << len_l << " " << len_r << endl;
    if(len_l > 0) parse(fl + 1, fl + len_l, ml, pos - 1);
    if(len_r > 0) parse(fl + len_l + 1, fr, pos + 1, mr);
    
    cout << father;
    

}