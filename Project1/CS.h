#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <winuser.h>
#include <msclr/marshal_cppstd.h>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace msclr::interop;

class CS
{
public:
	CS(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv, vector<unsigned char> alpha, vector<unsigned char> i0, vector<unsigned char> lambda, vector<vector<unsigned char>> OLS1, vector<vector<unsigned char>> OLS2);
	CS(string key, string iv, string alpha, string i0, string lambda, string OLS1, string OLS2);
	CS(const CS& copy);
	~CS();

	string getMessageNumber();
	vector<vector<unsigned char>> cipher(string messageFilename, string associatedDataFilename);

private:
	vector<vector<unsigned char>> _key;
	vector<vector<unsigned char>> _iv;
	vector<unsigned char> _alpha;
	vector<unsigned char> _i0;
	vector<vector<unsigned char>> _OLS1;
	vector<vector<unsigned char>> _OLS2;
	vector<unsigned char> _lambda;
	size_t _messageNumber;

	// Умножение в GF(128)
	size_t BIT(size_t value);
	void ShiftRight(vector<unsigned char>& SHFT);
	void xor_block(vector<unsigned char>& ZBLOCK, vector<unsigned char>& VBLOCK);
	void GFMult128(vector<unsigned char>& Z, const vector<unsigned char> X, const vector<unsigned char> YBLOCK);

	// Операция *
	vector<unsigned char> QuasigroupOperation1(vector<unsigned char> left, vector<unsigned char> right);

	// Операция *'
	vector<unsigned char> QuasigroupOperation2(vector<unsigned char> left, vector<unsigned char> right);

	// Биекция лямбда с хорошими рассеивающими свойствами
	vector<unsigned char> Lambda(vector<unsigned char> x);

	// Отображение f(w), зависящее от ключа k
	vector<unsigned char> f(vector<unsigned char> w);

	// Отображение фи, зависящее от константы альфа
	vector<unsigned char> phi(vector<unsigned char> x);

	// Отображение g(k, iv)
	vector<vector<unsigned char>> g();

	// Сложение по модулю 2^128
	vector<unsigned char> summ(vector<unsigned char> left, vector<unsigned char> right);

	// Блок гаммы
	vector<unsigned char> gamma(vector<unsigned char> blockNumber, vector<vector<unsigned char>> calculatedKey);

	// Вычисление ассоциированного вектора
	vector<unsigned char> AssociatedVector(vector<unsigned char> associatedMessage, vector<unsigned char> bt);

	// Шифрование открытого текста
	vector<vector<unsigned char>> mrt(vector<unsigned char> plaintext, vector<vector<unsigned char>> calculatedKey, size_t len_p);

	// Перевод десятичного числа в двоичное
	vector<unsigned char> decToBin(size_t dec);

	// Перевод десятичного числа в шестнадцатиричное, длиной до 8 байт
	vector<unsigned char> decToHex8bytes(size_t dec);

	// Операция конкатенации длинн шифрованных данных и ассоциированных данных
	vector<unsigned char> lenghtConcat(size_t lenMessage, size_t lenAssMessage);

	// Вычисление имитовставки (метки)
	vector<unsigned char> immitationInsert(vector<unsigned char> A, vector<vector<unsigned char>> m, vector<vector<unsigned char>> calculatedKey);

	unsigned char hexToDec(string hex);
	vector<unsigned char> readMessage(string filename);
	vector<unsigned char> readOneDimensionalVector(string filename);
	vector<vector<unsigned char>> readTwoDimensionalVector(string filename);
	void nextMessage();
};

inline CS::CS(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv, vector<unsigned char> alpha, vector<unsigned char> i0, vector<unsigned char> lambda, vector<vector<unsigned char>> OLS1, vector<vector<unsigned char>> OLS2)
	: _key(key), _iv(iv), _alpha(alpha), _i0(i0), _OLS1(OLS1), _OLS2(OLS2), _lambda(lambda)
{
	_messageNumber = 1;
}

inline CS::CS(string key, string iv, string alpha, string i0, string lambda, string OLS1, string OLS2)
{
	_key = this->readTwoDimensionalVector(key);
	_iv = this->readTwoDimensionalVector(iv);
	_alpha = this->readOneDimensionalVector(alpha);
	_i0 = this->readOneDimensionalVector(i0);
	_lambda = this->readOneDimensionalVector(lambda);
	_OLS1 = this->readTwoDimensionalVector(OLS1);
	_OLS2 = this->readTwoDimensionalVector(OLS2);
	_messageNumber = 1;
}

inline CS::CS(const CS& copy)
	: _key(copy._key), _iv(copy._iv), _alpha(copy._alpha), _i0(copy._i0), _OLS1(copy._OLS1), _OLS2(copy._OLS2), _lambda(copy._lambda)
{
	_messageNumber = copy._messageNumber;
}

inline CS::~CS()
{}

inline string CS::getMessageNumber()
{
	char str[6] = "";
	_itoa_s(_messageNumber, str, 10);
	return string(str);
}

inline vector<vector<unsigned char>> CS::cipher(string messageFilename, string associatedDataFilename)
{
	vector<unsigned char> message = readMessage(messageFilename);
	while (message.size() % 16 != 0) {
		message.push_back(0x00);
	}
	vector<unsigned char> associatedData = readMessage(associatedDataFilename);
	while (associatedData.size() % 16 != 0) {
		associatedData.push_back(0x00);
	}
	size_t len = message.size();

	vector<vector<unsigned char>> calculatedKey = this->g();
	vector<unsigned char> A = this->AssociatedVector(associatedData, calculatedKey[1]);
	vector<vector<unsigned char>> m = this->mrt(message, calculatedKey, len / 16);
	vector<unsigned char> mark = this->immitationInsert(A, m, calculatedKey);
	vector<vector<unsigned char>> result = { associatedData };
	for (size_t i = 0; i < len / 16; i++) {
		result.push_back(m[i]);
	}
	result.push_back(mark);
	this->nextMessage();

	return result;
}

inline size_t CS::BIT(size_t value)
{
	switch (value)
	{
	case 7:
		value = 0x80;
		break;
	case 6:
		value = 0x40;
		break;
	case 5:
		value = 0x20;
		break;
	case 4:
		value = 0x10;
		break;
	case 3:
		value = 0x08;
		break;
	case 2:
		value = 0x04;
		break;
	case 1:
		value = 0x02;
		break;
	case 0:
		value = 0x01;
		break;
	}
	return value;
}

inline void CS::ShiftRight(vector<unsigned char>& SHFT)
{
	unsigned char prevcarry = 0x00;
	unsigned char currcarry = 0x00;

	for (size_t i = 0; i < 16; i++)
	{
		prevcarry = currcarry;

		if (SHFT[i] & 0x01)
			currcarry = 0x80;
		else
			currcarry = 0x00;

		SHFT[i] >>= 0x01;
		SHFT[i] += prevcarry;
	}
}

inline void CS::xor_block(vector<unsigned char>& ZBLOCK, vector<unsigned char>& VBLOCK)
{
	for (size_t i = 0; i < 16; i++)
	{
		ZBLOCK[i] = ZBLOCK[i] ^ VBLOCK[i];
	}
}

inline void CS::GFMult128(vector<unsigned char>& Z, const vector<unsigned char> X, const vector<unsigned char> YBLOCK)
{
	std::fill(Z.begin(), Z.end(), 0);
	vector<unsigned char> V = YBLOCK;
	vector<unsigned char> R(16, 0xe1);

	for (size_t i = 0; i < 16; i++)
	{
		for (size_t j = 0; j < 16 / 2; j++)
		{
			if (X[i] & BIT(7 - j))
			{
				xor_block(Z, V);
			}

			if (V[15] & 0x01)
			{
				ShiftRight(V);
				V[0] ^= R[0];
			}
			else
			{
				ShiftRight(V);
			}
		}
	}
}

inline vector<unsigned char> CS::QuasigroupOperation1(vector<unsigned char> left, vector<unsigned char> right)
{
	vector<unsigned char> result;
	for (size_t i = 0; i < 16; i++) {
		result.push_back(_OLS1[left[i]][right[i]]);
	}
	return result;
}

inline vector<unsigned char> CS::QuasigroupOperation2(vector<unsigned char> left, vector<unsigned char> right)
{
	vector<unsigned char> result;
	for (size_t i = 0; i < 16; i++) {
		result.push_back(_OLS2[left[i]][right[i]]);
	}
	return result;
}

inline vector<unsigned char> CS::Lambda(vector<unsigned char> x)
{
	vector<unsigned char> result;
	for (size_t i = 0; i < 16; i++) {
		result.push_back(_lambda[x[i]]);
	}
	return result;
}

inline vector<unsigned char> CS::f(vector<unsigned char> w)
{
	return this->QuasigroupOperation1(this->Lambda(this->QuasigroupOperation1(w, _key[0])), _key[1]);
}

inline vector<unsigned char> CS::phi(vector<unsigned char> x)
{
	vector<unsigned char> result;
	for (size_t i = 0; i < 16; i++) {
		result.push_back(x[i] ^ _alpha[i]);
	}
	return result;
}

inline vector<vector<unsigned char>> CS::g()
{
	vector<vector<unsigned char>> result = { {}, {} };
	vector<unsigned char> temp1 = this->QuasigroupOperation1(this->Lambda(this->QuasigroupOperation1(_key[0], _iv[0])), _key[2]);
	vector<unsigned char> temp2 = this->QuasigroupOperation1(this->Lambda(this->QuasigroupOperation1(_key[1], _iv[1])), _key[2]);
	for (size_t i = 0; i < 16; i++) {
		result[0].push_back(_OLS1[temp1[i]][temp2[i]]);
		result[1].push_back(_OLS2[temp1[i]][temp2[i]]);
	}
	return result;
}

inline vector<unsigned char> CS::summ(vector<unsigned char> left, vector<unsigned char> right)
{
	vector<unsigned char> result = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	unsigned char perenos = 0x00;
	for (size_t i = 15; i > 0; i--) {
		size_t sum = left[i] + right[i] + perenos;
		if (sum > 255) {
			result[i] = ((unsigned char)sum);
			perenos = 0x01;
		}
		else {
			result[i] = ((unsigned char)sum);
			perenos = 0x00;
		}
	}
	return result;
}

inline vector<unsigned char> CS::gamma(vector<unsigned char> blockNumber, vector<vector<unsigned char>> calculatedKey)
{
	vector<unsigned char> wi = this->summ(blockNumber, _i0);
	vector<unsigned char> ci = this->f(wi);
	vector<unsigned char> di = this->phi(ci);
	vector<unsigned char> left(16, 0);
	GFMult128(left, ci, calculatedKey[0]);
	vector<unsigned char> right(16, 0);
	GFMult128(right, di, calculatedKey[1]);
	vector<unsigned char> result;
	for (size_t i = 0; i < 16; i++) {
		result.push_back(left[i] ^ right[i]);
	}
	return result;
}

inline vector<unsigned char> CS::AssociatedVector(vector<unsigned char> associatedMessage, vector<unsigned char> bt)
{
	vector<unsigned char> result(16, 0x00);
	size_t associatedMessageLength = associatedMessage.size() / 16;
	vector<unsigned char> temp;
	for (size_t i = 0; i < 16; i++) {
		temp.push_back(associatedMessage[i]);
	}
	GFMult128(result, temp, bt);
	for (size_t i = 1; i < associatedMessageLength; i++) {
		temp.clear();
		for (size_t j = 0; j < 16; j++) {
			temp.push_back(associatedMessage[i * 16 + j] ^ result[j]);
		}
		GFMult128(result, temp, bt);
	}
	return result;
}

inline vector<vector<unsigned char>> CS::mrt(vector<unsigned char> plaintext, vector<vector<unsigned char>> calculatedKey, size_t len_p)
{
	vector<vector<unsigned char>> result(len_p);
	vector<unsigned char> tempCB;
	vector<unsigned char> odin = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };
	vector<unsigned char> blockNumber = odin;

	for (size_t i = 0; i < len_p; i++)
	{
		tempCB = this->gamma(blockNumber, calculatedKey);
		for (size_t j = 0; j < 16; j++)
		{
			result[i].push_back(plaintext[(i * 16) + j] ^ tempCB[j]);
		}
		blockNumber = this->summ(blockNumber, odin);
	}
	return result;
}

inline vector<unsigned char> CS::decToBin(size_t dec)
{
	vector<unsigned char> result;
	while (dec != 0) {
		if (dec % 2 == 0) {
			result.push_back(0);
		}
		else {
			result.push_back(1);
			dec -= 1;
		}
		dec /= 2;
	}
	return result;
}

inline vector<unsigned char> CS::decToHex8bytes(size_t dec)
{
	vector<unsigned char> result(8, 0x00);
	vector<unsigned char> bin = this->decToBin(dec);
	while (bin.size() % 8 != 0) {
		bin.push_back(0);
	}
	size_t len = bin.size() / 8;
	for (size_t i = 0; i < len; i++) {
		unsigned char number = 0;
		size_t power = 1;
		for (size_t j = 0; j < 8; j++) {
			number += static_cast<unsigned char>(bin[i * 8 + j] * power);
			power *= 2;
		}
		result[8 - i - 1] = number;
	}
	return result;
}

inline vector<unsigned char> CS::lenghtConcat(size_t lenMessage, size_t lenAssMessage)
{
	unsigned long long lenMessageBite = lenMessage * 8;
	unsigned long long lenAssMessageBite = lenAssMessage * 8;
	vector<unsigned char> lenByteMessage = this->decToHex8bytes(lenMessageBite);
	vector<unsigned char> lenByteAssMessage = this->decToHex8bytes(lenAssMessageBite);
	vector<unsigned char> result = lenByteMessage;
	for (size_t i = 0; i < 8; i++) {
		result.push_back(lenByteAssMessage[i]);
	}
	return result;
}

inline vector<unsigned char> CS::immitationInsert(vector<unsigned char> A, vector<vector<unsigned char>> m, vector<vector<unsigned char>> calculatedKey)
{
	vector<unsigned char> result;
	vector<unsigned char> temp;
	vector<unsigned char> mult = A;
	size_t len = m.size();
	for (size_t i = 0; i < len; i++) {
		for (size_t j = 0; j < 16; j++) {
			temp.push_back(mult[j] ^ m[i][j]);
		}
		GFMult128(mult, temp, calculatedKey[1]);
		temp.clear();
	}
	vector<unsigned char> lmla = this->lenghtConcat(len, A.size());
	for (size_t i = 0; i < 16; i++) {
		temp.push_back(lmla[i] ^ mult[i]);
	}
	GFMult128(mult, temp, calculatedKey[1]);
	for (size_t i = 0; i < 16; i++) {
		result.push_back(mult[i] ^ calculatedKey[0][i]);
	}
	return result;
}

inline unsigned char CS::hexToDec(string hex)
{
	unsigned char leftByte = 0;
	unsigned char rightByte = 0;
	if (hex[0] >= '0' && hex[0] <= '9') {
		leftByte = hex[0] - '0';
	}
	else {
		leftByte = hex[0] - 87;
	}
	if (hex[1] >= '0' && hex[1] <= '9') {
		rightByte = hex[1] - '0';
	}
	else {
		rightByte = hex[1] - 87;
	}
	return leftByte*16 + rightByte;
}

inline vector<unsigned char> CS::readMessage(string filename)
{
	vector<unsigned char> result;
	ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile) {
		string str = "Файл " + filename + " не существует";
		MessageBox::Show(marshal_as<String^>(str), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return result;
	}
	unsigned char s;
	char n = '\0';
	do {
		s = inputFile.get();
		result.push_back(s);
		n = inputFile.peek();
	} while (n != EOF);
	return result;
}

inline vector<unsigned char> CS::readOneDimensionalVector(string filename)
{
	vector<unsigned char> result;
	ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile) {
		string str = "Файл " + filename + " не существует";
		MessageBox::Show(marshal_as<String^>(str), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		throw std::invalid_argument("received negative value");
	}
	string s = "";
	char next = '\n';
	do {
		inputFile >> s;
		next = inputFile.peek();
		result.push_back(this->hexToDec(s));

	} while (next != EOF);
	return result;
}

inline vector<vector<unsigned char>> CS::readTwoDimensionalVector(string filename)
{
	vector<vector<unsigned char>> result;
	ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile) {
		string str = "Файл " + filename + " не существует";
		MessageBox::Show(marshal_as<String^>(str), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		exit(1);
		
	}
	string s = "";
	char next = '\n';
	size_t i = -1;
	do {
		
		if (next == '\n') {
			result.push_back(vector<unsigned char>());
			i++;
		}
		inputFile >> s;
		next = inputFile.peek();
		result[i].push_back(this->hexToDec(s));
		if (result[i].size() == 255) {
			std::cout << "qwe" << std::endl;
		}
	} while (next != EOF);
	return result;
}

inline void CS::nextMessage()
{
	++_messageNumber;
	vector<unsigned char> odin = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };
	if (_messageNumber % 2 == 0) {
		_iv[0] = summ(_iv[0], odin);
	}
	else {
		_iv[1] = summ(_iv[1], odin);
	}
}
