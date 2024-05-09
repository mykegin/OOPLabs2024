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
		if(p1.second!=p2.second)
			return p1.second < p2.second;

		return p1.first > p2.first;
	}
};

int main()
{
	string prop;
	ifstream myFile("input.txt");

	if (!myFile)
	{
		printf("Eroare deschidere fisierului");
		return 1;
	}

	if (!getline(myFile, prop))
	{
		printf("Eroare getline");
		return 1;
	}

	map<string, int> nrcuv;

	int k = 0;

	transform(prop.begin(), prop.end(), prop.begin(), tolower);

	for (int i = 0; i < prop.size(); i++)
		cout << prop[i];

	for (int i = 0; i < prop.size(); i++)
	{
		if (prop[i] == ' ' || prop[i] == '.' || prop[i] == '!' || prop[i] == ',' || prop[i] == '?')
		{
				string word = prop.substr(k,i-k);
				k = i+1;

				if (!word.empty()) 
				{
					cout << "Am bagat cuvantul \"" << word << "\" in map\n";
					nrcuv[word]++;
				}
		}
	}

	/*
	while (true)
	{
		const int found = prop.find_first_of(" ,.?!");
		if (found == -1) break;

		string word = prop.substr(0, found);
		transform(word.begin(), word.end(), word.begin(), tolower);
		prop.erase(prop.begin(), prop.begin() + found + 1);

		if (!word.empty()) {
			cout << "Added the word \"" << word << "\" to the map\n";
			nrcuv[word]++;
		}
	}
	*/

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pqueue;

	for (const auto& i : nrcuv)
	{
		pqueue.emplace(i);
	}

	while (!pqueue.empty())
	{
		cout << pqueue.top().second << " => " << pqueue.top().first << '\n';
		pqueue.pop();
	}

	return 0;
}