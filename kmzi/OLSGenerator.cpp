#include "OLSGenerator.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

void generateOLS(vector<vector<int>>& firstM, vector<vector<int>>& secondM)
{
	int n = 256;
	
	vector<int> GF;	

	for (int i = 0; i < n; i++) {
		GF.push_back(i);
	}

	for (int i = 0; i < n; i++) {
		vector<int> temp1;
		vector<int> temp2;
		for (int j = 0; j < n; j++) {
			temp1.push_back((GF[i] + GF[j]) % n);
			temp2.push_back((2 * GF[i] + GF[j]) % n);
		}
		firstM.push_back(temp1);
		secondM.push_back(temp2);
		temp1.clear();
		temp2.clear();
	}

	int k = 0;
	for (int i = 0; i < 2*n; i++) {
		int r = rand() % 2;
		if (r == 0) {
			swapColumns(firstM, secondM, n);
		}
		else {
			swapRows(firstM, secondM, n);
		}
		k++;
	}

}

void swapColumns(vector<vector<int>>& t1, vector<vector<int>>& t2, int n)
{
	int i = rand()%n;
	int j = rand()%n;
	while (i == j) {
		j = rand()%n;
	}
	vector<int> temp = t1[i];
	t1[i] = t1[j];
	t1[j] = temp;
	temp.clear();
	temp = t2[i];
	t2[i] = t2[j];
	t2[j] = temp;
	temp.clear();
}

void swapRows(vector<vector<int>>& t1, vector<vector<int>>& t2, int n)
{
	t1 = transpose(t1, n);
	t2 = transpose(t2, n);
	swapColumns(t1, t2, n);
	t1 = transpose(t1, n);
	t2 = transpose(t2, n);
}

vector<vector<int>> transpose(vector<vector<int>> table, int n)
{
	vector<vector<int>> result;

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			temp.push_back(table[j][i]);
		}
		result.push_back(temp);
		temp.clear();
	}

	return result;
}
