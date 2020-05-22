#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<deque>
#include<string>
#include <ctime>

using namespace std;

int main() {
	typedef deque<string> prefix;
	map<prefix, vector<string>> stateTab;

	const int NPREF = 3;
	const int MaXGEN = 1000;

	string str;		
	prefix pref;		
	map<prefix, vector<string>>::iterator it;	 	
	prefix firstWords;				

	ifstream input("input.txt");
	if (input.is_open())
	{
		for (int i = 0; i < NPREF; i++) 
		{			
			input >> str;
			pref.push_back(str);			
		}
		firstWords = pref;
		while (input >> str) 
		{						

			stateTab[pref].push_back(str);
			pref.pop_front(); 			
			pref.push_back(str); 			

		}
	}
	else 
	{
		cout << "cannot open\n";
	}
	input.close();

	ofstream output("output.txt");

	pref = firstWords;

	for (int i = 0; i < NPREF; i++) 
	{   			
		output << firstWords[i] << ' ';
	}

	int n;				
	srand(time(NULL));

	for (int i = 0; i < MaXGEN; i++) 
	{
		it = stateTab.find(pref);
		if (it != stateTab.end())
		{

			n = rand() % it->second.size(); 		
											
			output << it->second[n] << ' ';		
			pref.pop_front();			
			pref.push_back(it->second[n]);  	
											
		}
	}
	output.close();							

	return 0;
}