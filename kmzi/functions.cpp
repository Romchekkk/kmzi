#include "functions.h"
#include "Data.h"

vector<unsigned char> QuasigroupOperation1(vector<unsigned char> left, vector<unsigned char> right)
{
    vector<unsigned char> result;
    for (int i = 0; i < 16; i++) {
        result.push_back(firstM[ left[i] ][ right[i] ]);
    }
    return result;
}

vector<unsigned char> QuasigroupOperation2(vector<unsigned char> left, vector<unsigned char> right)
{
    vector<unsigned char> result;
    for (int i = 0; i < 16; i++) {
        result.push_back(secondM[left[i]][right[i]]);
    }
    return result;
}

vector<unsigned char> Lambda(vector<unsigned char> x)
{
    vector<unsigned char> result;
    for (int i = 0; i < 16; i++) {
        result.push_back(lambdaVector[x[i]]);
    }
    return result;
}

vector<unsigned char> f(vector<unsigned char> w, vector<vector<unsigned char>> key)
{
    return QuasigroupOperation1( Lambda( QuasigroupOperation1( w, key[0] ) ), key[1] );
}

vector<unsigned char> phi(vector<unsigned char> x, vector<unsigned char> alpha)
{
    vector<unsigned char> result;
    for (int i = 0; i < 16; i++) {
        result.push_back(x[i] ^ alpha[i]);
    }
    return result;
}

vector<vector<unsigned char>> g(vector<vector<unsigned char>> key, vector<vector<unsigned char>> iv)
{
    vector<vector<unsigned char>> result = { {}, {} };
    vector<unsigned char> temp1 = QuasigroupOperation1(Lambda(QuasigroupOperation1(key[0], iv[0])), key[2]);
    vector<unsigned char> temp2 = QuasigroupOperation1(Lambda(QuasigroupOperation1(key[1], iv[1])), key[2]);
    for (int i = 0; i < 16; i++) {
        result[0].push_back(firstM[temp1[i]][temp2[i]]);
        result[0].push_back(secondM[temp1[i]][temp2[i]]);
    }
    return result;
}

vector<unsigned char> summ(vector<unsigned char> left, vector<unsigned char> right)
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

vector<unsigned char> gamma(vector<unsigned char> blockNumber, vector<vector<unsigned char>> calculatedKey, vector<unsigned char> i0, vector<unsigned char> alpha, vector<vector<unsigned char>> key)
{
    vector<unsigned char> wi = summ(blockNumber, i0);
    vector<unsigned char> ci = f(wi, key);
    vector<unsigned char> di = phi(ci, alpha);
    vector<unsigned char> left;
    GFMult128(left, ci, calculatedKey[0]);
    vector<unsigned char> right;
    GFMult128(right, di, calculatedKey[1]);
    vector<unsigned char> result;
    for (int i = 0; i < 16; i++) {
        result.push_back(left[i]^right[i]);
    }
    return result;
}
