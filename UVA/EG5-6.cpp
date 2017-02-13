#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

typedef queue<int> Queue;


vector<Queue> get_team;
map<int , int> get_teamId;
int main(void)
{
    int kase = 0;
    while(1)
    {
        Queue q;

        get_team.clear();
        get_teamId.clear();

        int n;
        cin >> n;
        if(n == 0) break;

        for(int i = 0; i < n; i++)
        {
            Queue temp_team;
            get_team.push_back(temp_team);

            int t;
            cin >> t;

            while(t--)
            {
                int id;
                cin >> id;
                get_teamId[id] = i;
            }
        }

        kase++;
        cout << "Scenario #" << kase << endl;
        while(1)
        {
            string s;
            int mem_id;

            cin >> s;


            char op = s[0];

            if(op == 'E')
            {

                cin >> mem_id;
                int teamId = get_teamId[mem_id];


                if (get_team[teamId].size() == 0) q.push(teamId);

                get_team[teamId].push(mem_id);

            }
            else if(op == 'D')
            {


                int teamId = q.front();

                int mem_id = get_team[teamId].front();
                cout << mem_id << endl;
                get_team[teamId].pop();

                if(get_team[teamId].size() == 0) q.pop();
            }
            else if(op == 'S')
            {
                break;
            }

        }


        cout << endl;


    }

}
