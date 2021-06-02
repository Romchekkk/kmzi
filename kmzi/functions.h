#pragma once

#include <vector>
#include "best_functions.h"
#define Block 16
using std::vector;

// �������� *
vector<unsigned char> QuasigroupOperation1(vector<unsigned char> left, vector<unsigned char> right);

// �������� *'
vector<unsigned char> QuasigroupOperation2(vector<unsigned char> left, vector<unsigned char> right);

// ������� ������ � �������� ������������� ����������
vector<unsigned char> Lambda(vector<unsigned char> x);

// ����������� f(w), ��������� �� ����� k
vector<unsigned char> f(vector<unsigned char> w, vector<vector<unsigned char>> key);

// ����������� ��, ��������� �� ��������� �����
vector<unsigned char> phi(vector<unsigned char> x, vector<unsigned char> alpha);

// ����������� g(k, iv)
vector<vector<unsigned char>> g(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv);

// �������� �� ������ 2^128
vector<unsigned char> summ(vector<unsigned char> left, vector<unsigned char> right);

vector<unsigned char> gamma(vector<unsigned char> blockNumber, vector<vector<unsigned char>> calculatedKey, vector<unsigned char> i0, vector<unsigned char> alpha, vector<vector<unsigned char>> key);
