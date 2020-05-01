/*
github: matrix patterns

Build pattern matrix
[0,1,2,3,4]
[5,6,7,8,9]
[10,11,12,13,14]

*/
#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int>> input) {
	for (vector<int> ve : input) {
		for (int value : ve) {
			cout << value << ", ";
		}
		cout << "\n";
	}
	cout << "\n";
}
vector<vector<int>> make_vector3(int number_of_col, int number_of_row) {
	vector<int> tmp(number_of_col, 0);
	vector<vector<int>> output(number_of_row, tmp);
	int count = 0;
	for (int i = 0; i < number_of_col; i++) {
		output[0][i] += count++;
	}
	for (int i = 1; i < number_of_row; i++) {
		output[i][number_of_col - 1] += count++;
	}
	for (int i = number_of_col - 2; i >= 0; i--) {
		output[number_of_row - 1][i] += count++;
	}
	for (int i = number_of_row - 2; i > 0;i--) {
		output[i][0] += count++;
	}
	return output;
}
vector<vector<int>> make_vector2(int number, int how_many){
	vector<vector<int>> output;
	int count = 0;
	for (int i = 0; i < how_many; i++) {
		vector<int> tmp;
		tmp.clear();
		if (i % 2 == 0) {
			for (int o = 0; o < number; o++) {
				tmp.push_back(count++);
			}
		}
		else {
			for (int o = 0; o < number; o++) {
				tmp.insert(tmp.begin(), count++);
			}
		}
		output.push_back(tmp);
	}
	return output;
}

vector<vector<int>> make_vector(int number, int how_many){
	vector<vector<int>> output;
	int count = 0;
	for (int i = 0; i < how_many; i++) {
		vector<int> tmp;
		tmp.clear();
		for (int o = 0; o < number; o++) {
			tmp.push_back(count++);			
		}
		output.push_back(tmp);
	}
	return output;
}
int main()
{
	vector<vector<int>> input = make_vector3(3, 4);
	print(input);
	return 0;
}