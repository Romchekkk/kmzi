#pragma once

#include <vector>

using std::vector;

// Операция *
vector<unsigned char> QuasigroupOperation1(vector<unsigned char> left, vector<unsigned char> right);

// Операция *'
vector<unsigned char> QuasigroupOperation2(vector<unsigned char> left, vector<unsigned char> right);

// Биекция лямбда с хорошими рассеивающими свойствами
vector<unsigned char> Lambda(vector<unsigned char> x);

// Отображение f(w), зависящее от ключа k
vector<unsigned char> f(vector<unsigned char> w, vector<vector<unsigned char>> key);

// Отображение фи, зависящее от константы альфа
vector<unsigned char> Phi(vector<unsigned char> x, vector<unsigned char> alpha);

// Отображение g(k, iv)
vector<vector<unsigned char>> g(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv);