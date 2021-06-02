#pragma once

#include <vector>

using namespace std;

void GFMult128(vector<unsigned char>& Z, const vector<unsigned char> X, const vector<unsigned char> YBLOCK);
void GCTR(vector<unsigned char>& C, const vector<unsigned char> plaintext, vector<unsigned char> blockNumber, vector<vector<unsigned char>> calculatedKey, vector<unsigned char> i0, vector<unsigned char> alpha, vector<vector<unsigned char>> key, const unsigned long len_p);
