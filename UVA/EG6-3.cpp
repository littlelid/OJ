#include<iostream>
#include<stack>



using namespace std;


struct mat
{
    int x;
    int y;

    mat(){}

    mat(int x, int y):x(x), y(y){}

};



int main(void)
{
    int n;
    cin >> n;
    mat dict[30];

    for(int i = 0; i < n; i++)
    {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        dict[ch - 'A'] = mat(x, y);
    }

    string s;
    while(cin >> s)
    {
        stack<mat> mul;

        int sum = 0;
        int len = s.size();

        int error = 0;
        for(int i = 0; i < len; i++)
        {
            char ch = s[i];
            if(ch == '(') continue;
            if(ch == ')')
            {
                mat b = mul.top();
                mul.pop();
                mat a = mul.top();
                mul.pop();

                if(a.y != b.x)
                {
                    error = 1;
                    break;
                }
                else
                {
                    sum += a.x * a.y * b.y;
                }
                mat t = mat(a.x, b.y);
                mul.push(t);
            }
            else
            {
                mat t = dict[ch - 'A'];
                mul.push(t);
            }
        }
        if(error)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << sum << endl;
        }
    }
}
