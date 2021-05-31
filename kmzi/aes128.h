#pragma once
#include <vector>

using std::vector;

/* Under the 16-byte key at k, encrypt the 16-byte plaintext at p and store it at c. */
void aes128e(vector<unsigned char>& c, const vector<unsigned char> p, const vector<unsigned char> k);