#pragma once

#include <vector>

using std::vector;

void generateOLS(vector<vector<int>>& firstM, vector<vector<int>>& secondM);
void swapColumns(vector<vector<int>>& t1, vector<vector<int>>& t2, int n);
void swapRows(vector<vector<int>>& t1, vector<vector<int>>& t2, int n);
vector<vector<int>> transpose(vector<vector<int>> table, int n);