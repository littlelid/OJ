#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        this->s1 = s1;
        this->s2 = s2;

        bool ans = isScramble(0, 0, s1.size());
        if(ans) cout << "right" << endl;
        else cout << "wrong" << endl;
        return ans;
    }

    bool isScramble(int l1, int l2, int len)
    {
        cout << l1 << ' '  << l2 << ' ' << len << endl;
        if(len == 1) return s1[l1] == s2[l2];
        
        int pos1, pos2;
        pos1 = partMatch(l1, l2, len, 1);
        pos2 = partMatch(l1, l2, len, 0);
        cout << "\t" << pos1 << ' ' << pos2 << endl;
        if(pos1 >= len || pos2 <= -1) return false;
        if(pos1 == len - 1 && pos2 == len - 1) return false;


        bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
        if(pos1 < len - 1)
        {
            flag1 = isScramble(l1, l2, pos1 + 1);
            flag2 = isScramble(l1 + pos1 + 1, l2 + pos1 + 1, len - pos1 - 1);
        }
        if(pos2 < len - 1)
        {
            flag3 = isScramble(l1, l2 + len - 1 - pos2, pos2 + 1);
            flag4 = isScramble(l1 + pos2 + 1, l2, len - pos2 - 1);
        }
        if(l1 == 0 && l2 == 0) cout << flag1 << flag2 << flag3 << flag4 << endl;
        if((flag1 && flag2) || (flag3 && flag4)) 
        {
            return true;
        }
        else 
        {
            return false;
        }

        return false;
    }

    int partMatch(int l1, int l2, int len, int flag)
    {
        map<char, int> cnts;
        int total_cnts = 0;

        int split_pos = -1;
        int ch1, ch2;
        for(int i = 0; i < len; i++)
        {
            ch1 = s1[l1 + i]; 
            if(flag) ch2 = s2[l2 + i];
            else     ch2 = s2[l2 + len - 1 - i ];
            //cout << "\t\t" << ch1 << ' ' << ch2 << endl;
            printf("\t\t %c %c\n", ch1, ch2);
            if(cnts.count(ch1) ) 
            {
                if(cnts[ch1] > 0) total_cnts -= 1;
                else              total_cnts += 1;
                cnts[ch1] -= 1;
            }
            else
            {
                cnts[ch1] = -1;
                total_cnts += 1;
            }
            if(cnts.count(ch2) ) 
            {
                if(cnts[ch2] < 0) total_cnts -= 1;
                else              total_cnts += 1;
                cnts[ch2] += 1;
            }
            else                 
            {
                cnts[ch2] = 1;
                total_cnts += 1;
            }

            if(total_cnts == 0)
            {
                split_pos = i;
                break;   
            }
        }
        return split_pos;
    }
private:
    string s1, s2;

};

int main(void)
{   
    Solution s;
    //cout << s.isScramble("hobobyrqd", "hbyorqdbo") << endl;
    cout << s.isScramble("abcdd", "dbdac") << endl;
}