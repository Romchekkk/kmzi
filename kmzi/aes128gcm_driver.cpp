#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "aes128.h"
#include "aes128gcm.h"
#include <string>
#include "aes128.h"
using std::vector;

static void PrintVector(vector<unsigned char> myArray) {

	unsigned char i, j;

	for (i = 0; i < myArray.capacity(); i++)
	{
		printf("%#x ", myArray[i]);
	}
}

int jopa() {
	vector<unsigned char> key = { 0x98,0xff,0xf6,0x7e,0x64,0xe4,0x6b,0xe5,0xee,0x2e,0x05,0xcc,0x9a,0xf6,0xd0,0x12 };
	//0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
	//0x98,0xff,0xf6,0x7e,0x64,0xe4,0x6b,0xe5,0xee,0x2e,0x05,0xcc,0x9a,0xf6,0xd0,0x12 }; //16 98fff67e64e46be5ee2e05cc9af6d012
	//0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c, 0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83,0x08 }; //feffe9928665731c6d6a8f9467308308;
	vector<unsigned char> IV = { 0x2d,0xfb,0x42,0x9a,0x48,0x69,0x7c,0x34,0x00,0x6d,0xa8,0x86 };
	//0x2d,0xfb,0x42,0x9a,0x48,0x69,0x7c,0x34,0x00,0x6d,0xa8,0x86 };
	//0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad, 0xde, 0xca, 0xf8, 0x88 }; // cafebabefacedbaddecaf888

	vector<unsigned char> plaintext = { 
		0x29, 0xb9, 0x1b, 0x4a, 0x68, 0xa9, 0x9f, 0x97, 0xc4, 0x1c, 0x75, 0x08, 0xf1, 0x7a, 0x5c, 0x7a,
		0x7a, 0xfc, 0x9e, 0x1a, 0xca, 0x83, 0xe1, 0x29, 0xb0, 0x85, 0xbd, 0x63, 0x7f, 0xf6, 0x7c, 0x01,
		0x29, 0xb9, 0x1b, 0x4a, 0x68, 0xa9, 0x9f, 0x97, 0xc4, 0x1c, 0x75, 0x08, 0xf1, 0x7a, 0x5c, 0x7a};
		//0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		//0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };
						 //0x29,0xb9,0x1b,0x4a,0x68,0xa9,0x9f,0x97,0xc4,0x1c,0x75,0x08,0xf1,0x7a,0x5c,0x7a,//,
						 //0x7a,0xfc,0x9e,0x1a,0xca,0x83,0xe1,0x29,0xb0,0x85,0xbd,0x63,0x7f,0xf6,0x7c,0x01,
						 //0x29,0xb9,0x1b,0x4a,0x68,0xa9,0x9f,0x97,0xc4,0x1c,0x75,0x08,0xf1,0x7a,0x5c,0x7a }; // 29b91b4a68a99f97c41c7508f17a5c7a7afc9e1aca83e129b085bd637ff67c0129b91b4a68a99f97c41c7508f17a5c7a
						//0xd9, 0x31, 0x32, 0x25, 0xf8, 0x84, 0x06, 0xe5, 0xa5, 0x59, 0x09, 0xc5, 0xaf, 0xf5, 0x26, 0x9a };
						//0x86, 0xa7, 0xa9, 0x53, 0x15, 0x34, 0xf7, 0xda, 0x2e, 0x4c, 0x30, 0x3d, 0x8a, 0x31, 0x8a, 0x72,
						//0x1c, 0x3c, 0x0c, 0x95, 0x95, 0x68, 0x09, 0x53, 0x2f, 0xcf, 0x0e, 0x24, 0x49, 0xa6, 0xb5, 0x25,
						//0xb1, 0x6a, 0xed, 0xf5, 0xaa, 0x0d, 0xe6, 0x57, 0xba, 0x63, 0x7b, 0x39 };

	vector<unsigned char> add_data = { 0xa0,0xca,0x58,0x61,0xc0,0x22,0x6c,0x5b,0x5a,0x65,0x14,0xc8,0x2b,0x77,0x81,0x5a,
					  0x9e,0x0e,0xb3,0x59,0xd0,0xd4,0x6d,0x03,0x33,0xc3,0xf2,0xba,0xe1,0x4d,0xa0,0xc4,
					  0x03,0x30,0xc0,0x02,0x16,0xb4,0xaa,0x64,0xb7,0xc1,0xed,0xb8,0x71,0xc3,0x28,0xf6 };
						//0xa0,0xca,0x58,0x61,0xc0,0x22,0x6c,0x5b,0x5a,0x65,0x14,0xc8,0x2b,0x77,0x81,0x5a,
						//0x9e,0x0e,0xb3,0x59,0xd0,0xd4,0x6d,0x03,0x33,0xc3,0xf2,0xba,0xe1,0x4d,0xa0,0xc4,
						//0x03,0x30,0xc0,0x02,0x16,0xb4,0xaa,0x64,0xb7,0xc1,0xed,0xb8,0x71,0xc3,0x28,0xf6 };
						//0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xab, 0xad, 0xda, 0xd2 };

	vector<vector<unsigned char>> tag_ref = {
				   {0xec,0x1c,0x5a,0xff,0xad,0x2c,0xad,0xb9,0xf5,0xeb,0xcf,0x1d,0xee,0x28,0x95,0xea},
				   {0x7f,0x05,0x0d,0x45,0x4e,0x55,0x2d,0x40,0xf1,0x73,0xbb,0xa9,0x2a,0xd9,0x23,0xe0},
				   {0x3e,0xba,0xc7,0xcf,0x15,0xee,0xf3,0xe0,0xee,0xff,0xf7,0x96,0xd7,0x87,0x0f,0x03},
				   {0xfc,0x89,0x33,0x0c,0x1d,0x86,0xf3,0x7d,0x70,0x0b,0x4d,0xcd,0x61,0x1e,0x94,0x35},
				   {0x01,0xbf,0xa5,0xb2,0x75,0xc7,0xcc,0xf8,0x52,0xea,0x28,0x97,0x87,0x76,0xbe,0x58},
				   {0x9e,0x27,0xe2,0x10,0xd6,0xe1,0xef,0x0f,0x18,0xde,0x98,0xf4,0xc3,0xd0,0xf9,0x68},
				   {0xaa,0x2f,0xe8,0x0f,0x1c,0x21,0xce,0x8a,0x5d,0x7d,0xf0,0x10,0x39,0x90,0x25,0x2e},
				   {0xc7,0x30,0x2f,0x77,0xc8,0x78,0x68,0x1f,0xe9,0x72,0x8a,0xd7,0x25,0xfc,0x74,0x01},
				   {0x54,0x77,0x45,0x9e,0x58,0x74,0x89,0xa5,0xb4,0x95,0xc7,0x73,0xd1,0x31,0x9d,0xe2},
				   {0xb4,0xdf,0xfa,0xcc,0xdd,0x27,0x27,0x17,0xef,0x9c,0x73,0x8e,0x7b,0x00,0xb9,0x41},
				   {0xe9,0x1d,0xbb,0x07,0xae,0x09,0xc2,0x62,0xe0,0xcd,0xa9,0xb2,0x89,0x91,0xb5,0x14},
				   {0xf1,0x96,0xec,0x54,0x6c,0x4c,0x0a,0xf0,0x8b,0xe0,0x88,0xba,0xb9,0x71,0x91,0x75},
				   {0x79,0x4c,0x36,0xa8,0x18,0x23,0x7e,0x57,0x68,0x6f,0xe9,0x83,0xbd,0x41,0x83,0x0d},
				   {0x78,0x8c,0xda,0x60,0xfd,0xf2,0x79,0x99,0xea,0x2e,0x86,0x47,0xd5,0xb4,0xc4,0x90},
				   {0x42,0xeb,0xba,0x9c,0xae,0xdb,0x79,0x83,0x21,0x43,0x95,0x32,0x68,0x36,0xd2,0xd7},
				   {0x70,0xfa,0x28,0x15,0x5c,0x47,0x88,0x70,0x72,0xaa,0xe1,0x2a,0x05,0xde,0x63,0x08}
	};

	vector<unsigned char> ciphertext_ref = { 0xc2,0x2f,0xee,0xb3,0xe2,0x7d,0xc3,0x29,0x93,0x45,0x03,0x01,0x39,0xee,0x81,0x67,
				  0x19,0xa8,0xa8,0x99,0x39,0x03,0x78,0x95,0xd7,0x49,0x65,0xfa,0x02,0x40,0xaf,0x5b,
				  0xe3,0x19,0x26,0x59,0xd5,0x66,0x39,0x8a,0x5d,0x95,0xf3,0xe0,0x4b,0xcd,0x53,0x57 };
	std::cout << ("!!!!!!!!!");
	/*	for (int i = 0; i < plaintext.capacity(); ++i) {
			std::cout << plaintext[i];
		}
		*/
	std::cout << ("!!!!!!!!!\n");
	/*vector<unsigned char> c(16);

	aes128e(c, plaintext, key);
	for (int i = 0; i < 16; ++i)
		printf("%#x ", c[i]); //1c34f0f5b87de7a3ba6598cc21fd3601 - result
	*/

	vector<unsigned char> ciphertext(3 * 16 * sizeof(unsigned char)); // 48 = plaintex.Length
	vector<unsigned char> tag(16 * sizeof(unsigned char));

	/* Test with 12 testvectors.
	   The lengths of the plaintexts are 0, 1, 2 or 3 blocks of  128 bits
	   The lengths of the additionnal data are 0, 1, 2, 3 blocks of  128 bits
	   The lenghts of the ciphertexts are 0, 1, 2 or 3 blocks of  128 bits
	   The lenght of the tags is 1 block of  128 bits
   */

   /*
   const unsigned char key2[16]={0};
   const unsigned char IV2[12] ={0};
   const unsigned char plaintext2[16] = {0};
   const unsigned char add_data2[16]={0};

   const unsigned char key3[16]={0xfe,0xff,0xe9,0x92,0x86,0x65,0x73,0x1c,0x6d,0x6a,0x8f,0x94,0x67,0x30,0x83,0x08};
   const unsigned char IV3[12] = {0xca,0xfe,0xba,0xbe,0xfa,0xce,0xdb,0xad,0xde,0xca,0xf8,0x88};
   const unsigned char plaintext3[4*16] = {0xd9,0x31,0x32,0x25,0xf8,0x84,0x06,0xe5,0xa5,0x59,0x09,0xc5,0xaf,0xf5,0x26,0x9a,
									   0x86,0xa7,0xa9,0x53,0x15,0x34,0xf7,0xda,0x2e,0x4c,0x30,0x3d,0x8a,0x31,0x8a,0x72,
									   0x1c,0x3c,0x0c,0x95,0x95,0x68,0x09,0x53,0x2f,0xcf,0x0e,0x24,0x49,0xa6,0xb5,0x25,
									   0xb1,0x6a,0xed,0xf5,0xaa,0x0d,0xe6,0x57,0xba,0x63,0x7b,0x39,0x1a,0xaf,0xd2,0x55};
   const unsigned char add_data3[16]={0};
   */

	unsigned int len_p; // = 4;
	unsigned int len_ad; // = 0;

	//aes128gcm(ciphertext,tag, key, IV, plaintext, len_p, add_data, len_ad);
	//aes128gcm(ciphertext,tag, key2, IV2, plaintext2, len_p, add_data2, len_ad);
	//aes128gcm(ciphertext,tag, key3, IV3, plaintext3, len_p, add_data3, len_ad);

	aes128gcm(ciphertext, tag, key, IV, plaintext, 3, add_data, 3);
	PrintVector(ciphertext);
	std::cout << "\n";

/*	for (len_p = 0; len_p <= 3; len_p++) {
		for (len_ad = 0; len_ad <= 3; len_ad++) {
			aes128gcm(ciphertext, tag, key, IV, plaintext, len_p, add_data, len_ad);
			PrintVector(ciphertext);
			std::cout << "\n";
			//printf("lenghts %d %d: ", len_p, len_ad);

			//printf("ciphertext %s ", ciphertext == ciphertext_ref ? "PASS" : "FAIL");
			//printf("tag %s\n\n", tag == tag_ref ? "PASS" : "FAIL");
*/	//	}
//	}/**/
	//free(ciphertext);
	//free(tag);



	return 0;
}