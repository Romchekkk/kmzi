#pragma once

#include <vector>

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
vector<unsigned char> Phi(vector<unsigned char> x, vector<unsigned char> alpha);

// ����������� g(k, iv)
vector<vector<unsigned char>> g(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv);