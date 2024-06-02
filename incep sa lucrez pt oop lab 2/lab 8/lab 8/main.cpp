#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
#include <queue>
#include <string>
#include <map>
#include <vector>

class Compare
{
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2)
	{
		if (p1.second != p2.second)
			return p1.second < p2.second;

		return p1.first > p2.first;
	}
};

using namespace std;
int main()
{
	string p, cuv;
	fstream fs;
	fs.open("input.txt");
	getline(fs, p);

	map <string, int> cuvinte;

	transform(p.begin(), p.end(), p.begin(), tolower);

	int i, k=0;
	for (i = 0; i < p.length(); i++)
	{
		if (p[i] == ' ' || p[i] == ',' || p[i] == '.' || p[i] == '?' || p[i] == '!' || p[i] == ';')
		{
			cuv = p.substr(k, i - k);
			if(!cuv.empty())
			{
				cuvinte[cuv]++;
			}

			k = i + 1;
		}
	}

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pqueue;

	for (const auto& i : cuvinte)
	{
		pqueue.emplace(i);
	}

	while (!pqueue.empty())
	{
		cout << pqueue.top().first << " => " << pqueue.top().second << '\n';
		pqueue.pop();
	}
}