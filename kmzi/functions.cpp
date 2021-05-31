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

vector<unsigned char> f(vector<unsigned char> w)
{
    return QuasigroupOperation1( Lambda( QuasigroupOperation1( w, key[0] ) ), key[1] );
}

vector<unsigned char> Phi(vector<unsigned char> x)
{
    vector<unsigned char> result;
    for (int i = 0; i < 16; i++) {
        result.push_back((unsigned char)(x[i] + alpha[i]));
    }
    return result;
}

vector<unsigned char> QuasigroupOperation1IV(vector<unsigned char> left, vector<unsigned char> right)
{
    vector<unsigned char> result;
    vector<unsigned char> temp1 = QuasigroupOperation1(Lambda(QuasigroupOperation1(left, iv[0])), key[2]);
    vector<unsigned char> temp2 = QuasigroupOperation1(Lambda(QuasigroupOperation1(right, iv[1])), key[2]);
    for (int i = 0; i < 16; i++) {
        result.push_back(firstM[ temp1[i] ][ temp2[i] ]);
    }
    return result;
}

vector<unsigned char> QuasigroupOperation2IV(vector<unsigned char> left, vector<unsigned char> right)
{
    vector<unsigned char> result;
    vector<unsigned char> temp1 = QuasigroupOperation2(Lambda(QuasigroupOperation1(left, iv[0])), key[2]);
    vector<unsigned char> temp2 = QuasigroupOperation2(Lambda(QuasigroupOperation1(right, iv[1])), key[2]);
    for (int i = 0; i < 16; i++) {
        result.push_back(secondM[temp1[i]][temp2[i]]);
    }
    return result;
}

vector<vector<unsigned char>> g(vector<unsigned char> left, vector<unsigned char> right)
{
    vector<vector<unsigned char>> result = { QuasigroupOperation1IV(left, right), QuasigroupOperation2IV(left, right) };
    return result;
}
