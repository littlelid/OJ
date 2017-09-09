#include<cstdio>
#include<iostream>
#include<vector>


class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) { 
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        int sums[m + 1][n + 1];
        memset(sums, 0, sizeof(sums));
        //cout << "*1*" << endl;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                //cout << i << ' ' << j << endl;
                int nums = matrix[i - 1][j - 1];
                //cout << "***" << endl;
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + nums;
                //cout << i << ' ' << j << endl;
                
            }
        }

        //cout << "*2*" << endl;
        int ans = 0;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i - 1][j -1] == 0)
                    continue;
                
                for(int k = i; k <= m; k++)
                {
                    
                    for(int l = j; l <= n; l++)
                    {
                        if(matrix[k - 1][l -1] == 0)
                            break;
                        
                        if((k - i + 1) * (l - j + 1) == sums[k][l] - sums[k][j -1] - sums[i -1][l] + sums[i - 1][j - 1])
                        {
                            ans = max(ans, (k - i + 1) * (l - j + 1));
                            ans = min(ans, k);
                        }                        

                    }
                   
                }
            }
        }
        return ans;
    }
};