#include<cstdio>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    getchar();
    while(T--)
    {
        map<string, string> d1, d2;
        d1.clear();d2.clear();
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;

        string key1, value1;
        int state = 0;
        for(int i = 1; i < s1.size(); i++)
        {
            if (s1[i] == ':')
            {
                state = 1;
                continue;

            }
            if (s1[i] == ',' || (s1[i] == '}' && key1.size() > 0) )
            {

                d1[key1] = value1;
                key1.clear();
                value1.clear();

                state = 0;
                continue;
            }

            if(state == 0)
            {
                key1.push_back(s1[i]);
            }
            if(state == 1)
            {
                value1.push_back(s1[i]);
            }
        }

        string key2, value2;
        state = 0;
        for(int i = 1; i < s2.size(); i++)
        {
            if (s2[i] == ':')
            {
                state = 1;
                continue;

            }
            if (s2[i] == ',' || (s2[i] == '}' && key2.size() > 0) )
            {
                d2[key2] = value2;
                key2.clear();
                value2.clear();

                state = 0;
                continue;
            }

            if(state == 0)
            {
                key2.push_back(s2[i]);
            }
            if(state == 1)
            {
                value2.push_back(s2[i]);
            }
        }

        map<string, string>::iterator it;
        set<string> keys1, keys2;
        keys1.clear();keys2.clear();
        for(it = d1.begin(); it != d1.end(); it++)
            keys1.insert(it->first);
        for(it = d2.begin(); it != d2.end(); it++)
            keys2.insert(it->first);

        set<string> keys_p, keys_m, keys_i;
        set_difference( keys2.begin(), keys2.end(),  keys1.begin(), keys1.end(), inserter(keys_p, keys_p.begin() ) );
        set_difference( keys1.begin(), keys1.end(),  keys2.begin(), keys2.end(), inserter(keys_m, keys_m.begin() ) );
        set_intersection( keys1.begin(), keys1.end(),  keys2.begin(), keys2.end(), inserter(keys_i, keys_i.begin() ) );




        vector<string> v_p, v_m, v_c;
        v_p.clear();v_m.clear();v_c.clear();
        set<string>::iterator its;
        for(its = keys_p.begin(); its !=keys_p.end(); its++)
            v_p.push_back(*its);
        for(its = keys_m.begin(); its !=keys_m.end(); its++)
            v_m.push_back(*its);

        for(its = keys_i.begin(); its != keys_i.end(); its++)
        {
            if(d1[*its] != d2[*its])
            {
                v_c.push_back(*its);
            }
        }

        sort(v_p.begin(), v_p.end());
        sort(v_m.begin(), v_m.end());
        sort(v_c.begin(), v_c.end());

        if(v_p.size() == 0 && v_m.size() == 0 && v_c.size() == 0 )
        {
            cout << "No changes" << endl;
        }
        else
        {
            if(v_p.size() != 0)
            {
                cout << "+";
                for(int i = 0; i < v_p.size() - 1; i++)
                {
                    cout << v_p[i] << ",";
                }
                cout << v_p[v_p.size() - 1] << endl;
            }
            if(v_m.size() != 0)
            {
                cout << "-";
                for(int i = 0; i < v_m.size() - 1; i++)
                {
                    cout << v_m[i] << ",";
                }
                cout << v_m[v_m.size() - 1] << endl;
            }

            if(v_c.size() != 0)
            {
                cout << "*";
                for(int i = 0; i < v_c.size() - 1; i++)
                {
                    cout << v_c[i] << ",";
                }
                cout << v_c[v_c.size() - 1] << endl;
            }
        }


        cout << endl;

    }
}
/*

    set<int> S1, S2, S3;
    S1.insert(1);S1.insert(3);S1.insert(2);
    S2.insert(4);S2.insert(3);S2.insert(2);
    set_difference( S1.begin(), S1.end(),  S2.begin(), S2.end(),
            inserter( S3, S3.begin() ) );

    set<int>::iterator ii;
    for(ii=S3.begin();ii!=S3.end();ii++)
        cout<<(*ii)<<' ';

    map<string, string>::iterator it;
        for(it = d1.begin(); it != d1.end(); it++)
            cout << it->first << ':' << it->second << ' ';

    for(it_ = keys1.begin(); it_ != keys1.end(); it_++)
            cout << *it_<< ' ';
        cout << endl;

        for(it_ = keys2.begin(); it_ != keys2.end(); it_++)
            cout << *it_ << ' ';
        cout << endl;


        set<string>::iterator it_;

    set<string>::iterator ii;
        cout << "p: " << keys_p.size() << endl;
        for(ii=keys_p.begin();ii!=keys_p.end();ii++)
            cout<<(*ii)<<' ';
        cout << endl;
        cout << "m: " << keys_m.size() << endl;
        for(ii=keys_m.begin();ii!=keys_m.end();ii++)
            cout<<(*ii)<<' ';
        cout << endl;
        cout << "i: " << keys_i.size() << endl;
        for(ii=keys_i.begin();ii!=keys_i.end();ii++)
            cout<<(*ii)<<' ';
        cout << endl;
*/
