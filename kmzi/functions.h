#pragma once

#include <vector>
#include "best_functions.h"
#define Block 16
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
vector<unsigned char> phi(vector<unsigned char> x, vector<unsigned char> alpha);

// Отображение g(k, iv)
vector<vector<unsigned char>> g(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv);

// Сложение по модулю 2^128
vector<unsigned char> summ(vector<unsigned char> left, vector<unsigned char> right);

vector<unsigned char> gamma(vector<unsigned char> blockNumber, vector<vector<unsigned char>> calculatedKey, vector<unsigned char> i0, vector<unsigned char> alpha, vector<vector<unsigned char>> key);
