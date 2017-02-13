#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
struct Record{
	int idx;
	int date;
	int time;
	float cost;
	Record(int idx, int date, int time, float cost):idx(idx),date(date),time(time),cost(cost){}
	
	bool operator < (const Record& r) const 
	{
		return cost < r.cost || (cost == r.cost && date < r.date ) || (cost == r.cost && date == r.date && time < r.time);
	}
};

int main(void)
{
	string line;
	vector<string> log;

    while(1)
    {
		getline(cin, line);
		if(line.size() == 0) break;

		log.push_back(line);
    }
	vector<Record> info;
	for(int i = 0; i < log.size(); i++)
	{
		char task[15];
        int year, month, date, hour, min, sec, msec;
		float cost;
		const char *temp = log[i].data();
		sscanf(temp, " %s %d-%d-%d %d:%d:%d,%d %f(s) ", task, &year, &month, &date, &hour, &min, &sec, &msec, &cost);
		//cout << task << ' ' <<year<< ' ' << month<< ' ' << date<< ' ' << hour<< ' ' << min<< ' ' << sec<< ' ' << msec<< ' ' << cost<< ' ' << endl ;
		info.push_back(Record(i, year*10000 + month * 100 + date, hour * 10000000 + min * 100000 + sec * 1000 + msec, cost));
	}
	
	sort(info.begin(), info.end());
	for(int i = 0; i < info.size(); i++)
	{
		cout << log[info[i].idx] << endl;
	}

}

