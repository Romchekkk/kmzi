#include <stdio.h>		// Used for printing and debugging
#include <stdint.h>
#include <vector>
#include "aes128gcm.h"
using std::vector;

// ************************************************************************//
// Definitions		                                                        //
// ************************************************************************//

/* Block Length in bytes */
#define Block 16

/* IV Length in bytes */
#define IVlen 12

  // ************************************************************************ //
 // Private variables                                                        //
// ************************************************************************ //

/* Hash subkey */
static vector<unsigned char> H(Block, 0);

/* J0 = IV || 0^31 ||1 */
static vector<unsigned char> J0(Block, 0);

/* CB Block used in the CTR */
static vector<unsigned char> CB(Block, 0);

/* OUTPUT of the GHASH function */
static vector<unsigned char> OUTPUT(Block, 0);

/* R used for the multiplication in GF(2^128) */
/* R = 11100001 || 0^120 */
static vector<unsigned char> R(Block, 0xe1);

/* Z "zero" variable used in the multiplication function */
static vector<unsigned char> Z(Block, 0);

/* V used inside the GCTR function */
static vector<unsigned char> V(Block, 0);

/* 16 byte array of the concatenation of len(A) and len(C) */
static vector<unsigned char> len_concat(Block, 0);

/* Hold and shift the values of len(A) */
static unsigned int len_ad_bits;
//static vector<unsigned char> len_a(Block / 2, 0);

/* Hold and shift the values of len(C) */
static unsigned int len_c_bits;
//static vector<unsigned char> len_c(Block / 2, 0);

/* 32 bit variable to hold the increments modulus 32 bits */
static unsigned long increment;

// ************************************************************************ //
// Private functions                                                        //
// ************************************************************************ //

/* Prints the array blocks */
static void PrintVector(vector<unsigned char> myArray, unsigned char arraySize) {

	unsigned char i, j;

	for (i = 0; i < arraySize; i++)
	{
		printf("%#X ", myArray[i]);
	}

	printf("%s\n", "");
}

/* Hash subkey is created. H = E(K, 0^128) */
static void InitialHashSubkey(vector<unsigned char>& ENC, const vector<unsigned char> k) {

	//memset(ENC, 0, Block);	// H variable is set to 0
	std::fill(ENC.begin(), ENC.end(), 0); // H variable is set to 0
	aes128e(ENC, ENC, k);	// H (all zeros) is encrypted with the Key
}

static void AssignVectors(vector<unsigned char>& v1, vector<unsigned char> v2) {
	for (int i = 0; i < v2.size(); ++i) {
		v1[i] = v2[i];
	}
}

/* J0 is defined. len(IV)=96, then let J0 = IV || 0^31 || 1 */
static void J0Definition(vector<unsigned char>& J0, const vector<unsigned char> IV) {
	std::fill(J0.begin(), J0.end(), 0);
	AssignVectors(J0, IV);
	//vector<unsigned char> ::iterator it = J0.begin();
	//std::advance(it, IV.capacity());
	//std::fill(it, J0.end(), 0);
	//memcpy(J0, IV, IVlen);		// IV is copied to J0
	increment = 1;				// increment variable set to 1
	J0[Block - 1] = increment;	// increment is added to the end of J0
}

/*  Byte block is incremented by 1. Incrementing Function incs(X)=MSBlen(X)-s(X) || [int(LSBs(X))+1 mod 2s]s Fixed to 32 */
static void IncrementingFunction(vector<unsigned char>& INC) {

	increment += 1;										// Array received is increased by 1

	for (int i = 0; i < 4; ++i)
	{
		INC[Block - 1 - i] = increment >> 8 * i & 0xFF;	// increment value is pushed to the last 4 bytes of the INC array (J0)	
	}
	//PrintVector(INC, 16);
}

/* The bit representation of position value is returned */
static char BIT(unsigned char value) {
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

/* Byte block received is shifted to the right */
static void ShiftRight(vector<unsigned char>& SHFT) {

	unsigned char prevcarry = 0x00;			// Carry of the previous position
	unsigned char currcarry = 0x00;			// Carry of the current position

	for (int i = 0; i < Block; i++)			// From 0 to 15 to iterate through the whole 16 bytes
	{
		prevcarry = currcarry;				// Previous carry is equal to the new carry

		if (SHFT[i] & 0x01)					// If the LSB of the byte is 1, we carry
			currcarry = 0x80;
		else
			currcarry = 0x00;				// Else the carry is 0

		SHFT[i] >>= 0x01;					// We shift the byte to the right by 1 position
		SHFT[i] += prevcarry;				// And we add the previous carry to the byte
	}

	/*
	printf("%s\n", "Shift: ");
	PrintVector(V, Block);*/
}

/* Byte blocks received are XORed */
static void xor_block(vector<unsigned char>& ZBLOCK, vector<unsigned char>& VBLOCK) { //  ןמ & םו םאהמ
	for (int i = 0; i < Block; i++)
	{
		ZBLOCK[i] = ZBLOCK[i] ^ VBLOCK[i];				// Every byte of the array is XORed
	}
}

/* GCTR function computed with the key K */
static void GCTR(vector<unsigned char>& C, const vector<unsigned char> J0, const vector<unsigned char> plaintext, const vector<unsigned char> k, const unsigned long len_p) {

	vector<unsigned char> tempCB(Block, 0);	// Used to save the last state of CB
	AssignVectors(CB, J0);
	//CB = J0;

	//memcpy(CB, J0, Block);

	for (int i = 0; i < len_p; i++)		// Index i used to iterate from 0 to len_p and later access values with index j 
	{

		aes128e(tempCB, CB, k);			// CIPHK(CBi)

		/*printf("%s\n", "CB Encrypted value:");
		PrintVector(tempCB, Block);*/

		for (int j = 0; j < Block; j++)	// Along with index i, we access the values of the plaintext up to the len_p
		{
			C[(i * Block) + j] = plaintext[(i * Block) + j] ^ tempCB[j];	// Yi = Xi XOR CIPHK(CBi)
		}
		IncrementingFunction(CB);	// For i = 2 to n, let CBi = inc32(CBi-1)
	}
}

/* Multiplication in GF(2^128) */
static void GFMult128(vector<unsigned char>& Z, const vector<unsigned char> X, const vector<unsigned char> YBLOCK) {

	std::fill(Z.begin(), Z.end(), 0);
	//memset(Z, 0, Block);
	V = YBLOCK;
	//memcpy(V, YBLOCK, Block);

	for (int i = 0; i < Block; i++)						// Iterate through the whole 128 bits on the array (16 bytes)
	{
		for (int j = 0; j < Block / 2; j++)				// From i = 0 to 16 and j = 0 to 8
		{
			if (X[i] & BIT(7 - j))
			{											// Obtain the bit i from X, if it's different than 0
				xor_block(Z, V);						// Z and V are XORed
			}

			if (V[15] & 0x01)							// Test the LSB of V, if is 1
			{
				ShiftRight(V);							// The block is shifted to the right
				V[0] ^= R[0];							// V is XORed with the R constant previously defined R = 11100001 || 0^120
			}
			else
			{
				ShiftRight(V);					// Shift V withouth XORing
			}
		}
	}
}

/*
inline vector<unsigned char> decToBin(unsigned long long dec)
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

vector<unsigned char> decToHex8bytes(unsigned long long dec)
{
	vector<unsigned char> result(8, 0x00);
	vector<unsigned char> bin = decToBin(dec);
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
*/
inline vector<unsigned char> decToBin(size_t dec)
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

inline vector<unsigned char> decToHex8bytes(size_t dec)
{
	vector<unsigned char> result(8, 0x00);
	vector<unsigned char> bin = decToBin(dec);
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

inline vector<unsigned char> lenghtConcat(size_t lenMessage, size_t lenAssMessage)
{
	unsigned long long lenMessageBite = lenMessage * 8;
	unsigned long long lenAssMessageBite = lenAssMessage * 8;
	vector<unsigned char> lenByteMessage = decToHex8bytes(lenMessageBite);
	vector<unsigned char> lenByteAssMessage = decToHex8bytes(lenAssMessageBite);
	vector<unsigned char> result = lenByteMessage;
	for (size_t i = 0; i < 8; i++) {
		result.push_back(lenByteAssMessage[i]);
	}
	return result;
}

/* Creation of the block concatenating A, C, len(A), len(C) */
void ByteConcatenation(vector<unsigned char>& concat, const vector<unsigned char> A, const vector<unsigned char> C, int len_ad, int len_p, int len_total) {

	/*unsigned long long lenMessageBite = C.size() * 8;
	unsigned long long lenAssMessageBite = A.size() * 8;
	vector<unsigned char> lenByteMessage = decToHex8bytes(lenMessageBite);
	vector<unsigned char> lenByteAssMessage = decToHex8bytes(lenAssMessageBite);
	vector<unsigned char> result = lenByteMessage;
	for (int i = 0; i < 8; i++) {
		result.push_back(lenByteAssMessage[i]);
	}
	//return result;
	*/
	vector<unsigned char> len_a(Block / 2, 0);
	vector<unsigned char> len_c(Block / 2, 0);
	//memset(len_c, 0, 8);					// len_c is set to 0
	std::fill(len_c.begin(), len_c.end(), 0);
	//memset(len_a, 0, 8);					// len_a is set to 0
	std::fill(len_a.begin(), len_a.end(), 0);
	//memset(concat, 0, len_total);			// concat is set to 0
	std::fill(concat.begin(), concat.end(), 0);

	len_c_bits = len_p * 8 * Block;			// Bit len of C in Dec	(stored in an int)
	len_ad_bits = len_ad * 8 * Block;		// Bit len of AD in Dec (stored in an int)
/*
	for (int i = 0; i < len_ad; i++)
	{
		len_a[i] = (len_ad_bits >> 8 * i) & 0xFF;	// Len in hex is shifted to the right and ANDed with 0xFF to get the value
	}

	for (int i = 0; i < len_p; i++)
	{
		len_c[i] = (len_c_bits >> 8 * i) & 0xFF;	// Len in hex is shifted to the right and ANDed with 0xFF to get the value
	}

	for (int i = (Block - 1); i > -1; i--)			// Iterate from 15 to 0 to store the two 8 bytes arrays with the lenght
	{
		if (i > 7)
		{
			len_concat[i] = len_c[7 - i % 8];		// Starting from right to left, first the ciphertext is added
		}
		else
		{
			len_concat[i] = len_a[7 - i % 8];		// Then the AAD length is added
		}
	}
*/
	len_concat = lenghtConcat(C.size(), A.size());

	for (int i = 0; i < len_total; i++)				// Once the concatenation of the lenght is shifted and stored, we can compute the final concatenation
	{
		if (i < len_ad * Block)
		{
			concat[i] = A[i % (len_ad * Block)];	// A is added to the concat array
		}
		else if (i >= len_ad * Block && i < (len_ad * Block) + (len_p * Block))
		{																			// Then C is added to the concat array, From 0 to 31
			concat[i] = C[(i - len_ad * Block) % (len_p * Block)];					// The index for accessing concat is reset to 0
		}																			// i - len_ad in bits modulo len_p in bits
		else
		{
			concat[i] = len_concat[i % Block];		// Finally we add the concatenation of len(A) and len(C)
		}
	}

	//printf("%s\n", "Concatenation: ");
	//PrintVector(concat, len_total);
}

/* GHASH function computed using H and X */
static void GHASH(vector<unsigned char>& OUT, const vector<unsigned char> H, const vector<unsigned char> X, const unsigned int len_total) {

	// GHASH Variables
	vector<unsigned char> Y(Block, 0);
	vector<unsigned char> tempX(Block, 0);

	for (int i = 0; i < (len_total / Block); i++)		// For the total length of the concatenation (bits / 16)
	{
		for (int j = 0; j < Block; j++)					// From 0 to size of Block in bytes (16)
		{
			tempX[j] = X[(i * Block) + j];				// Get the block from X and add it to tempX
		}

		xor_block(Y, tempX);							// XOR current block (tempX) with Y (initially is all zeroes)
		/*printf("After XORing: \n");
		PrintVector(Y, Block);*/

		GFMult128(Z, H, Y);								// Multiply H and Y in GF 2^128, Z is a zero array
		/*printf("After Multiplicating GF 2^128: \n");
		PrintVector(Z, Block);*/

		//memcpy(Y, Z, Block);							// The result of the multiplication is copied to Y
		Y = Z;
	}
	//memcpy(OUT, Y, Block);								// Finally the Y block is copied to OUT variable
	OUT = Y;
}

/* Main GCM-AES 128 function */
void aes128gcm(vector<unsigned char>& ciphertext, vector<unsigned char>& tag, const vector<unsigned char> k, const vector<unsigned char> IV, vector<unsigned char> plaintext, vector<unsigned char> add_data)
{
	while (plaintext.size() % 16 != 0) {
		plaintext.push_back(0x00);
	}
	while (add_data.size() % 16 != 0) {
		add_data.push_back(0x00);
	}

	const unsigned long len_p = plaintext.size() / 16;
	const unsigned long len_ad = add_data.size() / 16;
	unsigned int len_total = (len_p * Block) + (len_ad * Block) + Block;	// Total lenght of the concatenation in bytes.
	vector<unsigned char> concat(len_total);										// Char array that holds the concatenation to be passed to GHASH
	//vector<unsigned char> concat;
	/*
	// Key
	printf("%s\n", "Key:");
	PrintVector(k, Block);

	// IV
	printf("%s\n", "IV:");
	PrintVector(IV, 12);

	// Plaintext
	printf("%s\n", "Plaintext:");
	PrintVector(plaintext, Block);

	// ADD
	printf("%s\n", "ADD:");
	PrintVector(add_data, len_ad * Block);
	*/

	InitialHashSubkey(H, k);	// H is computed with zero array H and k H = E(K, 0^128)
	J0Definition(J0, IV);		// J0 is defined. len(IV)=96, then let J0 = IV || 0^31 || 1
	IncrementingFunction(J0);	// First we increase J0 before passing to GCTR

	GCTR(ciphertext, J0, plaintext, k, len_p);	// GCTR is called to compute all the ciphertext using the plaintext, k and J0

	ByteConcatenation(concat, add_data, ciphertext, len_ad, len_p, len_total);	// A, C, len(A) and len(C) are concatenated
	//concat = lenghtConcat(ciphertext.size(), add_data.size());
	GHASH(OUTPUT, H, concat, len_total);		// GHASH is called using the previous computed concat, H

	J0Definition(J0, IV);			// J0 is redefined because the previous version had increments.
	GCTR(tag, J0, OUTPUT, k, 1);	// GCTR is called to generate the TAG, we pass 1 as the length is always 16 bytes long 

	/*printf("TAG: \n");
	PrintVector(tag, Block);*/
}