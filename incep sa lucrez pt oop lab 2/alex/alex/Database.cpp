#include "Database.h"

Database& Database::operator+=(Entry* e)
{
	entries.push_back(e);
	return (*this);
}

Database& Database::operator-=(string name)
{
	auto it = remove_if(entries.begin(), entries.end(),
		[&name](Entry* entry) { return entry->GetName() == name; });
	entries.erase(it, entries.end());
	return (*this);
}

void Database::Print()
{
	for (const auto& entry : entries) {
		entry->Print();
	}
	cout << endl;
}
