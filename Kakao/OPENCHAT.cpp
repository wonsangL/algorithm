#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string> log;
	unordered_map<string, string> user;

	for (string input : record) {
		int find = input.find(" ");
		string state = input.substr(0, find);
		input = input.substr(find + 1);

		find = input.find(" ");
		string id = input.substr(0, find);
		string userName = input.substr(find + 1);

		if (state == "Change" || state == "Enter") 
			user[id] = userName;
		
		if(state != "Change")
			log.push_back(state + " " + id);	
	}

	for (string result : log) {
		int find = result.find(" ");
		string state = result.substr(0, find);
		string id = result.substr(find + 1);

		if (state == "Enter")
			answer.push_back(user[id] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		else
			answer.push_back(user[id] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
	}

	return answer;
}