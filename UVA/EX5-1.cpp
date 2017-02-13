#include<cstdio>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

vector<string> data[1005];
int rows = 0;
int max_col = -1;
vector<int> cols;

int get_max_len(int idx)
{

    int max_len = -1;
    for(int i = 0; i < rows; i++)
    {

        if(idx < (data[i].size()) )
        {

            int size_ = data[i][idx].size();
            if(size_ > max_len)
            {

                max_len = data[i][idx].size();
            }
        }

    }

    return max_len;
}



int main(void)
{

    string line;
    string word;

    while(getline(cin, line))
    {

        stringstream ss(line);
        while(ss >> word)
        {

            data[rows].push_back(word);

        }

        int size_ = data[rows].size();
        cols.push_back(size_);
        if(size_ > max_col) max_col = size_;

        rows++;
    }

    int max_lens[max_col];

    for(int i = 0; i < max_col; i++)
    {

        max_lens[i] = get_max_len(i);
    }



    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols[i]; j++)
        {

            if(j != cols[i] - 1)
            {
                cout << data[i][j] << string(max_lens[j] - data[i][j].size() + 1, ' ');
            }
            else
            {
                cout << data[i][j];
            }
        }
        cout << endl;


    }
    return 0;
}
