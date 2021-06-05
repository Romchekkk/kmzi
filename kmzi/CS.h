#pragma once

#include <vector>

#define Block 16

using std::vector;

class CS
{
public:
	CS(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv, vector<unsigned char> alpha, vector<unsigned char> i0, vector<vector<unsigned char>> OLS1, vector<vector<unsigned char>> OLS2, vector<unsigned char> lambda);
	~CS();

	vector<vector<unsigned char>> cipher(vector<unsigned char> message, vector<unsigned char>associatedData);

private:
	vector<vector<unsigned char>> _key;
	vector<vector<unsigned char>> _iv;
	vector<unsigned char> _alpha;
	vector<unsigned char> _i0;
	vector<vector<unsigned char>> _OLS1;
	vector<vector<unsigned char>> _OLS2;
	vector<unsigned char> _lambda;
	int _messageNumber;

	// Умножение в GF(128)
	char BIT(unsigned char value);
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
	vector<vector<unsigned char>> mrt(vector<unsigned char> plaintext, vector<vector<unsigned char>> calculatedKey, unsigned long len_p);

	// Перевод десятичного числа в двоичное
	vector<unsigned char> decToBin(unsigned long long dec);

	// Перевод десятичного числа в шестнадцатиричное, длиной до 8 байт
	vector<unsigned char> decToHex8bytes(unsigned long long dec);

	// Операция конкатенации длинн шифрованных данных и ассоциированных данных
	vector<unsigned char> lenghtConcat(int lenMessage, int lenAssMessage);

	// Вычисление имитовставки (метки)
	vector<unsigned char> immitationInsert(vector<unsigned char> A, vector<vector<unsigned char>> m, vector<vector<unsigned char>> calculatedKey);

	void nextMessage();
};

CS::CS(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv, vector<unsigned char> alpha, vector<unsigned char> i0, vector<vector<unsigned char>> OLS1, vector<vector<unsigned char>> OLS2, vector<unsigned char> lambda)
	: _key(key), _iv(iv), _alpha(alpha), _i0(i0), _OLS1(OLS1), _OLS2(OLS2), _lambda(lambda)
{
	_messageNumber = 1;
}

CS::~CS()
{}

inline vector<vector<unsigned char>> CS::cipher(vector<unsigned char> message, vector<unsigned char> associatedData)
{
	int len = message.size();

	vector<vector<unsigned char>> calculatedKey = this->g();
	vector<unsigned char> A = this->AssociatedVector(associatedData, calculatedKey[1]);
	vector<vector<unsigned char>> m = this->mrt(message, calculatedKey, len / 16);
	vector<unsigned char> mark = this->immitationInsert(A, m, calculatedKey);
	vector<vector<unsigned char>> result = { associatedData };
	for (int i = 0; i < len / 16; i++) {
		result.push_back(m[i]);
	}
	result.push_back(mark);
	this->nextMessage();

	return result;
}

inline char CS::BIT(unsigned char value)
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

	for (int i = 0; i < Block; i++)
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
	for (int i = 0; i < Block; i++)
	{
		ZBLOCK[i] = ZBLOCK[i] ^ VBLOCK[i];
	}
}

inline void CS::GFMult128(vector<unsigned char>& Z, const vector<unsigned char> X, const vector<unsigned char> YBLOCK)
{
	std::fill(Z.begin(), Z.end(), 0);
	vector<unsigned char> V = YBLOCK;
	vector<unsigned char> R(Block, 0xe1);

	for (int i = 0; i < Block; i++)
	{
		for (int j = 0; j < Block / 2; j++)
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
	for (int i = 0; i < 16; i++) {
		result.push_back(_OLS1[left[i]][right[i]]);
	}
	return result;
}

inline vector<unsigned char> CS::QuasigroupOperation2(vector<unsigned char> left, vector<unsigned char> right)
{
	vector<unsigned char> result;
	for (int i = 0; i < 16; i++) {
		result.push_back(_OLS2[left[i]][right[i]]);
	}
	return result;
}

inline vector<unsigned char> CS::Lambda(vector<unsigned char> x)
{
	vector<unsigned char> result;
	for (int i = 0; i < 16; i++) {
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
	for (int i = 0; i < 16; i++) {
		result.push_back(x[i] ^ _alpha[i]);
	}
	return result;
}

inline vector<vector<unsigned char>> CS::g()
{
	vector<vector<unsigned char>> result = { {}, {} };
	vector<unsigned char> temp1 = this->QuasigroupOperation1(this->Lambda(this->QuasigroupOperation1(_key[0], _iv[0])), _key[2]);
	vector<unsigned char> temp2 = this->QuasigroupOperation1(this->Lambda(this->QuasigroupOperation1(_key[1], _iv[1])), _key[2]);
	for (int i = 0; i < 16; i++) {
		result[0].push_back(_OLS1[temp1[i]][temp2[i]]);
		result[1].push_back(_OLS2[temp1[i]][temp2[i]]);
	}
	return result;
}

inline vector<unsigned char> CS::summ(vector<unsigned char> left, vector<unsigned char> right)
{
	vector<unsigned char> result = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	unsigned char perenos = 0x00;
	for (int i = 15; i >= 0; i--) {
		int sum = left[i] + right[i] + perenos;
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
	vector<unsigned char> left(Block, 0);
	GFMult128(left, ci, calculatedKey[0]);
	vector<unsigned char> right(Block, 0);
	GFMult128(right, di, calculatedKey[1]);
	vector<unsigned char> result;
	for (int i = 0; i < 16; i++) {
		result.push_back(left[i] ^ right[i]);
	}
	return result;
}

inline vector<unsigned char> CS::AssociatedVector(vector<unsigned char> associatedMessage, vector<unsigned char> bt)
{
	vector<unsigned char> result(16, 0x00);
	int associatedMessageLength = associatedMessage.size() / 16;
	vector<unsigned char> temp;
	for (int i = 0; i < 16; i++) {
		temp.push_back(associatedMessage[i]);
	}
	GFMult128(result, temp, bt);
	for (int i = 1; i < associatedMessageLength; i++) {
		temp.clear();
		for (int j = 0; j < 16; j++) {
			temp.push_back(associatedMessage[i * 16 + j] ^ result[j]);
		}
		GFMult128(result, temp, bt);
	}
	return result;
}

inline vector<vector<unsigned char>> CS::mrt(vector<unsigned char> plaintext, vector<vector<unsigned char>> calculatedKey, unsigned long len_p)
{
	vector<vector<unsigned char>> result(len_p);
	vector<unsigned char> tempCB;
	vector<unsigned char> odin = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };
	vector<unsigned char> blockNumber = odin;

	for (int i = 0; i < len_p; i++)
	{
		tempCB = this->gamma(blockNumber, calculatedKey);
		for (int j = 0; j < Block; j++)
		{
			result[i].push_back(plaintext[(i * 16) + j] ^ tempCB[j]);
		}
		blockNumber = this->summ(blockNumber, odin);
	}
	return result;
}

inline vector<unsigned char> CS::decToBin(unsigned long long dec)
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

inline vector<unsigned char> CS::decToHex8bytes(unsigned long long dec)
{
	vector<unsigned char> result(8, 0x00);
	vector<unsigned char> bin = this->decToBin(dec);
	while (bin.size() % 8 != 0) {
		bin.push_back(0);
	}
	int len = bin.size() / 8;
	for (int i = 0; i < len; i++) {
		unsigned char number = 0;
		int power = 1;
		for (int j = 0; j < 8; j++) {
			number += bin[i * 8 + j] * power;
			power *= 2;
		}
		result[8 - i - 1] = number;
	}
	return result;
}

inline vector<unsigned char> CS::lenghtConcat(int lenMessage, int lenAssMessage)
{
	unsigned long long lenMessageBite = lenMessage * 8;
	unsigned long long lenAssMessageBite = lenAssMessage * 8;
	vector<unsigned char> lenByteMessage = this->decToHex8bytes(lenMessageBite);
	vector<unsigned char> lenByteAssMessage = this->decToHex8bytes(lenAssMessageBite);
	vector<unsigned char> result = lenByteMessage;
	for (int i = 0; i < 8; i++) {
		result.push_back(lenByteAssMessage[i]);
	}
	return result;
}

inline vector<unsigned char> CS::immitationInsert(vector<unsigned char> A, vector<vector<unsigned char>> m, vector<vector<unsigned char>> calculatedKey)
{
	vector<unsigned char> result;
	vector<unsigned char> temp;
	vector<unsigned char> mult = A;
	int len = m.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 16; j++) {
			temp.push_back(mult[j] ^ m[i][j]);
		}
		GFMult128(mult, temp, calculatedKey[1]);
		temp.clear();
	}
	vector<unsigned char> lmla = this->lenghtConcat(len, A.size());
	for (int i = 0; i < 16; i++) {
		temp.push_back(lmla[i] ^ mult[i]);
	}
	GFMult128(mult, temp, calculatedKey[1]);
	for (int i = 0; i < 16; i++) {
		result.push_back(mult[i] ^ calculatedKey[0][i]);
	}
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
