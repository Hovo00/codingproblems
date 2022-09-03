#include <iostream>
#include <iomanip>
#include <unordered_set>

void printMatrix(int** p, const int n);

void createMatrix(int** (&), const int n);

void deleteMatrix(int** p, const int n);

void fillMatrix(int** p, const int n);

void set_zeroes(int** p, const int n) {
	std::unordered_set<int> cols;
	std::unordered_set<int> rows;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (p[i][j] == 0) {
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	std::cout << std::endl;
	for (auto& i : cols) {
		for (int j = 0; j < n; ++j) {
			p[j][i] = 0;
		}
	}
	for (auto& i : rows) {
		for (int j = 0; j < n; ++j) {
			p[i][j] = 0;
		}
	}
}


int main()

{
	int** p;
	int n = 5;

	createMatrix(p, n);
	fillMatrix(p, n);
	printMatrix(p, n);
	std::cout << "zero filled";
	set_zeroes(p, n);
	printMatrix(p, n);
	deleteMatrix(p, n);
}


void createMatrix(int** (&p), const int n)
{
	p = new int* [n];

	for (int i = 0; i < n; ++i) {
		p[i] = new int[n];
	}
}

void fillMatrix(int** p, const int n)

{
	int t = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i][j] = t++;

		}
	}

}

void printMatrix(int** p, const int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << std::setw(4) << p[i][j];
		}
		std::cout << std::endl;
	}
}

void deleteMatrix(int** p, const int n)
{
	for (int i = 0; i < n; ++i) {
		delete[] p[i];
	}
	delete[] p;

}
