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
vector<unsigned char> f(vector<unsigned char> w);

// ����������� ��, ��������� �� ��������� �����
vector<unsigned char> Phi(vector<unsigned char> x);

// �������� * � �������� iv
vector<unsigned char> QuasigroupOperation1IV(vector<unsigned char> left, vector<unsigned char> right);

// �������� *' � �������� iv
vector<unsigned char> QuasigroupOperation2IV(vector<unsigned char> left, vector<unsigned char> right);

// ����������� g(k, iv)
vector<vector<unsigned char>> g(vector<unsigned char> left, vector<unsigned char> right);