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
        result[1].push_back(secondM[temp1[i]][temp2[i]]);
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
    vector<unsigned char> left(Block, 0);
    GFMult128(left, ci, calculatedKey[0]);
    vector<unsigned char> right(Block, 0);
    GFMult128(right, di, calculatedKey[1]);
    vector<unsigned char> result;
    for (int i = 0; i < 16; i++) {
        result.push_back(left[i]^right[i]);
    }
    return result;
}

vector<unsigned char> AssociatedVector(vector<unsigned char> associatedMessage, vector<unsigned char> bt)
{
    vector<unsigned char> result(16, 0x00);
    int associatedMessageLength = associatedMessage.size()/16;
    vector<unsigned char> temp;
    for (int i = 0; i < 16; i++) {
        temp.push_back(associatedMessage[i]);
    }
    GFMult128(result, temp, bt);
    for (int i = 1; i < associatedMessageLength; i++) {
        temp.clear();
        for (int j = 0; j < 16; j++) {
            //Да пошла ты нахуя студия не будет тут больше инта блять
            temp.push_back(associatedMessage[i*16 + j] ^ result[j]);
        }
        GFMult128(result, temp, bt);
    }
    return result;
}
