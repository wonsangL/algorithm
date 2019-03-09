#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<stdio.h>

using namespace std;

int alphabet[26];

int main() {
	char str[50001];
	int max = 0;

	for (int i = 0; i < 26; i++)
		alphabet[i] = 0;

	while (scanf("%s", str) != EOF) {
		int idx = 0;
	
		while (str[idx] != '\0') {
			alphabet[str[idx] - 'a']++;

			if (alphabet[str[idx] - 'a'] > max)
				max = alphabet[str[idx] - 'a'];
			
			idx++;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (max == alphabet[i])
			printf("%c", 'a' + i);
	}

	return 0;
}