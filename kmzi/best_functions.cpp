#include "Data.h"

/* Block Length in bytes */
#define Block 16

/* R used for the multiplication in GF(2^128) */
/* R = 11100001 || 0^120 */
static vector<unsigned char> R(Block, 0xe1);

/* V used inside the GCTR function */
static vector<unsigned char> V(Block, 0);


/* Byte blocks received are XORed */
static void xor_block(vector<unsigned char>& ZBLOCK, vector<unsigned char>& VBLOCK) {
	for (int i = 0; i < Block; i++)
	{
		ZBLOCK[i] = ZBLOCK[i] ^ VBLOCK[i];				// Every byte of the array is XORed
	}
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
				ShiftRight(V);							// Shift V withouth XORing
			}
		}
	}
}