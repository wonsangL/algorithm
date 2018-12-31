#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string parseResult(int result) {
	string answer = "";

	int hour = result / 60;
	int min = result % 60;

	if (hour < 10)
		answer += "0";

	answer += to_string(hour) + ":";

	if (min < 10)
		answer += "0";

	return answer += to_string(min);
}

string solution(int n, int t, int m, vector<string> timetable) {
	int answer;
	vector<int> schedule;
	vector<vector<int>> passenger(n);

	int lastShuttle = 9 * 60 + t * (n - 1);
	int shuttleTime = 9 * 60;
	int index = 0;

	for (string input : timetable) {
		int find = input.find(":");

		string hour = input.substr(0, find);
		string min = input.substr(find + 1);

		int time = stoi(hour) * 60 + stoi(min);

		schedule.push_back(time);
	}

	sort(schedule.begin(), schedule.end());

	for (int time : schedule) {
		if (time > lastShuttle)
			break;

		while (time > shuttleTime && index < n) {
			shuttleTime += t;
			index++;
		}

		if (passenger[index].size() >= m)
			index++;

		if (index >= n)
			break;

		passenger[index].push_back(time);
	}

	if (passenger[n - 1].size() < m) {
		answer = lastShuttle;
	}		
	else {
		int max = -1;

		for (int time : passenger[n - 1]) {
			if (time > max)
				max = time;
		}

		answer = max - 1;
	}
 
	return parseResult(answer);
}

int main() {
	cout << solution(10, 60, 2, { "09:10", "09:09", "08:00" }) << endl;
	return 0;
}