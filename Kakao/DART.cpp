#include<iostream>
#include<vector>
#include <string>
#include<math.h>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> score;

	for (int i = 0; i < dartResult.length(); i++) {
		if (dartResult[i] >= 48 && dartResult[i] <= 57) {
			if (dartResult[i] == '1' && i < dartResult.length() - 2) {
				if (dartResult[i + 1] == '0') {
					score.push_back(10);
					i++;
					continue;
				}
			}

			score.push_back(dartResult[i] - 48);
		}
		else if (dartResult[i] == '*' || dartResult[i] == '#') {
			if (dartResult[i] == '#') {
				*(score.end() - 1) *= -1;
			}
			else {
				if (score.size() == 1) {
					*(score.end() - 1) *= 2;
					continue;
				}

				*(score.end() - 1) *= 2;
				*(score.end() - 2) *= 2;
			}
		}
		else {
			if (dartResult[i] == 'D') {
				*(score.end() - 1) = pow(*(score.end() - 1), 2);
			}
			else if(dartResult[i] == 'T'){
				*(score.end() - 1) = pow(*(score.end() - 1), 3);
			}
		}
	}

	for (int i = 0; i < score.size(); i++) {
		answer += score[i];
	}

	return answer;
}

//테스트 코드
//int main() {
//	cout << solution("1S2D*3T") << endl;
//	cout << solution("1D2S#10S") << endl;
//	cout << solution("1D2S0T") << endl;
//	cout << solution("1S*2T*3S") << endl;
//	cout << solution("1D#2S*3S") << endl;
//	cout << solution("1T2D3D#") << endl;
//	cout << solution("1D2S3T*") << endl;
//}