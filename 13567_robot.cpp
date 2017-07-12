#include<iostream>
#include<string>
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

typedef struct _coord {
	int x;
	int y;
}COORD;

using namespace std;

int main(){
	int direction = 2; //first, heading for right
	int M = 0, n = 0, input = 0;
	string command;
	COORD coord = { 0, 0 };


	std::cin >> M;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >>command;
		std::cin >> input;

		if (command.compare("MOVE") == 0) {
			switch (direction) {
			case UP:
				coord.y += input;
				break;
			case DOWN:
				coord.y -= input;
				break;
			case LEFT:
				coord.x -= input;
				break;
			case RIGHT:
				coord.x += input;
				break;
			}
		}
		else {
			if (input == 0){
				direction += 1;

				if (direction > 3)
					direction = 0;
			}
			else {
				direction -= 1;

				if (direction < 0)
					direction = 3;
			}		
		}	

		if (coord.x > M || coord.y > M || coord.x < 0 || coord.y < 0) {
			std::cout << "-1" << std::endl;
			return 0;
		}
	}

	std::cout << coord.x << " " << coord.y << std::endl;
	return 0;
}