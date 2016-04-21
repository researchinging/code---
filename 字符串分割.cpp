
#include<string>
#include<vector>

using namespace std;

string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

void split(string& s, string& delim,vector< string >* ret)
{
	size_t last = 0;
	size_t index=s.find_first_of(delim,last);
	while (index!=string::npos)
	{
		ret->push_back(s.substr(last,index-last));
		last=index+1;
		index=s.find_first_of(delim,last);
	}
	if (index-last>0)
	{
		ret->push_back(s.substr(last,index-last));
	}
}