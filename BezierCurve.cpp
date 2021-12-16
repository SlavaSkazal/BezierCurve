#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

	int coordinates[3][2];
	int numberOfIterations, caseOfFormula, x;
	float y, t;

	for (int i = 0; i < 3; i++) {

		cout << "Enter x: ";
		cin >> coordinates[i][0];

		cout << "Enter y: ";
		cin >> coordinates[i][1];
	}

	if (coordinates[0][0] == coordinates[1][0] && coordinates[0][0] == coordinates[2][0]
		&& coordinates[0][1] == coordinates[1][1] && coordinates[0][1] == coordinates[2][1]) {
	
		cout << "You have entered the coordinates of the point. Coordinates (x, y): " << endl; 
		cout << coordinates[0][0] << ", " << coordinates[0][1];
		cout << "Coordinates (x, y): " << endl;

		return 0;
	}
	else if (coordinates[0][0] == coordinates[1][0] && coordinates[0][0] == coordinates[2][0]) {
	
		int tempY;

		for (int i = 0; i < 2; i++) {

			for (int j = 0; j < 2 - i; j++) {

				if (coordinates[j][1] > coordinates[j + 1][1]) {

					tempY = coordinates[j][1];
					coordinates[j][1] = coordinates[j + 1][1];
					coordinates[j + 1][1] = tempY;
				}
			}
		}

		numberOfIterations = coordinates[2][1] - coordinates[0][1] + 1;

		tempY = coordinates[0][1];

		cout << "Coordinates (x, y): " << endl;

		for (int i = 0; i < numberOfIterations; i++) {
			cout << coordinates[0][0] << ", " << tempY << endl;
			tempY++;
		}

		return 0;	
	}

	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 2 - i; j++) {
		
			if (coordinates[j][0] > coordinates[j + 1][0]) {

				int temp[2];

				temp[0] = coordinates[j][0];
				temp[1] = coordinates[j][1];

				coordinates[j][0] = coordinates[j + 1][0];
				coordinates[j][1] = coordinates[j + 1][1];

				coordinates[j + 1][0] = temp[0];
				coordinates[j + 1][1] = temp[1];
			}
		}
	}

	numberOfIterations = coordinates[2][0] - coordinates[0][0] + 1;

	if (coordinates[0][0] - coordinates[1][0] * 2 + coordinates[2][0] != 0) {
		caseOfFormula = 1;
	}
	else if (coordinates[0][0] - coordinates[1][0] * 2 + coordinates[2][0] == 0 && coordinates[0][0] != coordinates[1][0]) {
		caseOfFormula = 2;
	}
	else if (coordinates[0][0] == coordinates[1][0] && coordinates[0][0] != coordinates[2][0]) {
		caseOfFormula = 3;
	}
	else {
		caseOfFormula = 0;
	}

	if (caseOfFormula > 0) {

		cout << "Coordinates (x, y): " << endl;

		for (int i = 0; i < numberOfIterations; i++) {

			x = coordinates[0][0] + i;

			if (caseOfFormula == 1) {

				t = (coordinates[0][0] - coordinates[1][0] + sqrt((coordinates[0][0] - coordinates[1][0] * 2 + coordinates[2][0]) * x + coordinates[1][0] * coordinates[1][0] - coordinates[0][0] * coordinates[2][0])) / (coordinates[0][0] - coordinates[1][0] * 2 + coordinates[2][0]);

				if (t < 0.0 || t > 1.0) {
					t = (coordinates[0][0] - coordinates[1][0] - sqrt((coordinates[0][0] - coordinates[1][0] * 2 + coordinates[2][0]) * x + coordinates[1][0] * coordinates[1][0] - coordinates[0][0] * coordinates[2][0])) / (coordinates[0][0] - coordinates[1][0] * 2 + coordinates[2][0]);
				}
			}
			else if (caseOfFormula == 2) {
				t = (x - coordinates[0][0]) / (2 * (coordinates[1][0] - coordinates[0][0]));
			}
			else if (caseOfFormula == 3) {
				t = sqrt((x - coordinates[0][0]) / (coordinates[2][0] - coordinates[1][0]));
			}

			y = ((1 - t) * (1 - t) * coordinates[0][1]) + (2 * (1 - t) * t * coordinates[1][1]) + (t * t * coordinates[2][1]);

			cout << x << ", " << y << endl;
		}
	}
	else {
		cout << "Error; unforeseen combination of coordinates" << endl;
	}

	return 0;
}