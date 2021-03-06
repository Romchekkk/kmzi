#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aes128.h"

/* Under the 16-byte (128-bit) key "k",
and the 12-byte (96-bit) initial value "IV",
encrypt the plaintext "plaintext" and store it at "ciphertext".
The length of the plaintext is a multiple of 16-byte (128-bit) given by len_p (e.g., len_p = 2 for a 32-byte plaintext).
The length of the ciphertext "ciphertext" is len_p*16 bytes.
The authentication tag is obtained by the 16-byte tag "tag".
For the authentication an additional data "add_data" can be added.
The number of blocks for this additional data is "len_ad" (e.g., len_ad = 1 for a 16-byte additional data).
*/

void aes128gcm(vector<unsigned char>& ciphertext, vector<unsigned char>& tag, const vector<unsigned char> k, const vector<unsigned char> IV, vector<unsigned char> plaintext, vector<unsigned char> add_data);
void ByteConcatenation(vector<unsigned char>& concat, const vector<unsigned char> A, const vector<unsigned char> C, int len_ad, int len_p, int len_total);