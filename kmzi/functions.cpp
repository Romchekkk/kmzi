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

vector<unsigned char> lambda(vector<unsigned char> x)
{
    vector<unsigned char> result;
    for (int i = 0; i < 16; i++) {
        result.push_back(lambdaVector[x[i]]);
    }
    return result;
}

vector<unsigned char> Fk(vector<unsigned char> w)
{
    return QuasigroupOperation1( lambda( QuasigroupOperation1( w, key[0] ) ), key[1] );
}
