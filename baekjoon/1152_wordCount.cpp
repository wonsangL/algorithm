#include<iostream>
#include<string>

using namespace std;

int main() {
	string input;
	int find = -1, result = 1;

	getline(cin, input);

	do {
		find = input.find(" ", find + 1);
		
		if(find != 0 && find != -1 && find != input.length() - 1)
			result++;
	} while (find != -1);

	if (input.length() > 0)
		if (input.length() == 1 && input[0] == ' ')
			cout << 0 << endl;
		else
			cout << result << endl;
	else
		cout << 0 << endl;
}