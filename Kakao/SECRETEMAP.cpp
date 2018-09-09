#include <string>
#include <vector>
#include <math.h>
#include<iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		int mask = pow(2, n - 1);
		string result = "";
		int input = arr1[i] | arr2[i];
		
		for (int j = 0; j < n; j++) {
			if (mask & input)
				result += "#";
			else
				result += " ";

			mask /= 2;
		}
			
		answer.push_back(result);
	}
	
	return answer;
}


//출력 확인용
//int main() {
//	vector<int> arr1 = { 9, 20, 28, 18, 11 };
//	vector<int> arr2 = {30, 1 ,21, 17, 28};
//	vector<string> output = solution(5, arr1, arr2);
//
//	for (int i = 0; i < output.size(); i++) {
//		cout << output[i] << endl;
//	}
//}