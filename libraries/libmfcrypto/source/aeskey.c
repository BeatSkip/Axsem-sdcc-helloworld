/**
******************************************************************************
* @file aeskey.c
* @brief AES algorithm functions
* @internal
* @author   Thomas Sailer, Prakash Rajendran
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a "ON Semiconductor").
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software") and
* if applicable the software license agreement.  Do not use this software and/or
* documentation unless you have carefully read and you agree to the limited terms and
* conditions.  By using this software and/or documentation, you agree to the limited
* terms and conditions.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* ON SEMICONDUCTOR SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL,
* INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
* @endinternal
*
* @ingroup
*
* @details
*/

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0.h"
#endif
#ifdef __AXM0F2
#include "axm0f2.h"
#endif
#endif
#include "aes.h"
#include <string.h>

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#define INVALID_PARAMATER 1

#define AES_KEYSIZE_MASK	0x0F
#define AES_BLOCKMODE_MASK  0xF0

#define AXM0F2_AES_ROUND_ZERO   0
#define AES128_NUM_OF_ROUNDS	10
#define AES192_NUM_OF_ROUNDS	12
#define AES256_NUM_OF_ROUNDS	14

#define AES128_NUM_OF_BYTES 16
#define AES192_NUM_OF_BYTES 24
#define AES256_NUM_OF_BYTES 32

#define AES128_NUM_OF_WORDS 4
#define AES192_NUM_OF_WORDS 6
#define AES256_NUM_OF_WORDS 8

#define AES128_KEY 0 
#define AES192_KEY 1

#define AES_OFB_MODE 0x20
#define AES_CBC_MODE 0x30

/*
 * Description : Generates the Expanded key based on the given mode(AES128, AES192, AES256 bit key)
 * input : @param key AES cipher key
 * input : @param keyschedule address of the buffer to store expanded key
 * input : @param flag AES key size
 * output : None
 */
void aes_setup(const uint8_t *key, uint8_t __xdata *keyschedule, uint8_t flag)
{
	/* AES128 bit mode */
	if ((flag & AES_KEYSIZE_MASK) == AES128_KEY)
	{
		memcpy((void *)keyschedule, key, AES128_NUM_OF_BYTES);
		aes_keyexp(keyschedule, AES128_NUM_OF_WORDS, AES128_NUM_OF_ROUNDS);
	}
	/* AES192 bit mode */
	else if ((flag & AES_KEYSIZE_MASK) == AES192_KEY)
	{
		memcpy((void *)keyschedule, key, AES192_NUM_OF_BYTES);
		aes_keyexp(keyschedule, AES192_NUM_OF_WORDS, AES192_NUM_OF_ROUNDS);
	}
	/* AES256 bit mode */
	else
	{
		memcpy((void *)keyschedule, key, AES256_NUM_OF_BYTES);
		aes_keyexp(keyschedule, AES256_NUM_OF_WORDS, AES256_NUM_OF_ROUNDS);
	}
}

/*
 * Description : Performs AES Key Schedule Expansion to generate round key
 * input : @param keysched address of the buffer to store expanded key
 * input : @param Nk Number of 32 bit words in key (4,6,8)
 * input : @param Nr Number of rounds (10,12,14)
 * Output : None
 */
void aes_keyexp(uint8_t __xdata *keysched, uint8_t Nk, uint8_t Nr)
{
	uint8_t round;
	uint8_t w[4];
	uint8_t i, temp;

	round = 4 * (Nr + 1);
	keysched = keysched + Nk * 4 ;
	i = Nk;

	while (i < round)
	{
		keysched = keysched - 4;
		/* Storing previous 4 bytes */
		w[0] = *keysched++;
		w[1] = *keysched++;
		w[2] = *keysched++;
		w[3] = *keysched++;

		if (i % Nk == 0)
		{
			/* Rot word */
			temp = w[0];
			w[0] = w[1];
			w[1] = w[2];
			w[2] = w[3];
			w[3] = temp;

			/* Sub word */
			w[0] = aes_sbox[w[0]];
			w[1] = aes_sbox[w[1]];
			w[2] = aes_sbox[w[2]];
			w[3] = aes_sbox[w[3]];

			/* Rcon */
			w[0] ^= aes_rcon[(i / Nk) - 1];
		}

		/* Sub word for 32 byte key */
		else if (Nk > 6 && i % Nk == 4)
		{
			w[0] = aes_sbox[w[0]];
			w[1] = aes_sbox[w[1]];
			w[2] = aes_sbox[w[2]];
			w[3] = aes_sbox[w[3]];
		}

		keysched -= 4 * Nk;
		w[0] ^= *keysched++;
		w[1] ^= *keysched++;
		w[2] ^= *keysched++;
		w[3] ^= *keysched++;

		/* Update key schedule(4 bytes) */
		keysched += 4 * Nk - 4;
		*keysched++ = w[0];
		*keysched++ = w[1];
		*keysched++ = w[2];
		*keysched++ = w[3];

		i++;
	}
}

/*
 * Description : Performs add round key operation
 * input : @param state	 base address of the buffer to store result
 * input : @param keysched  base address of the expanded key
 * input : @param n		 Round number in the algorithm
 * output : None
 */
static inline void axm0f2_aes_add_round_key(uint8_t *state, uint8_t *keysched, uint8_t n)
{
	uint8_t i;

	/*XOR state with round key*/
	for (i = 0; i < 16; i++)
	{
		state[i] ^= keysched[(n * 16) + i] ;
	}
}


/*
 * Description : Performs sub bytes and shift row operation
 * input : @param state Buffer to store result
 * output : None
 */
static inline void axm0f2_aes_subbytes_shift_row(uint8_t *state)
{
	uint8_t temp,temp1,temp2;

	state[0]  = aes_sbox[state[0]];
	state[4]  = aes_sbox[state[4]];
	state[8]  = aes_sbox[state[8]];
	state[12] = aes_sbox[state[12]];

	temp = aes_sbox[state[1]];
	state[1] = aes_sbox[state[5]];
	state[5] = aes_sbox[state[9]];
	state[9] = aes_sbox[state[13]];
	state[13]= temp;

	temp1 = aes_sbox[state[2]];
	temp2 = aes_sbox[state[6]];
	state[2] = aes_sbox[state[10]];
	state[6] = aes_sbox[state[14]];
	state[10] = temp1;
	state[14]= temp2;

	temp = aes_sbox[state[15]];
	state[15] = aes_sbox[state[11]];
	state[11] = aes_sbox[state[7]];
	state[7] = aes_sbox[state[3]];
	state[3] = temp ;
}


/*
 * Description : Performs GF multiplication by 2
 * input : @param value Input to be multiplied by 2
 * output : @param result of  the GF multiplication
 */
static inline uint8_t gf_multiply(uint8_t value)
{
	/*Check MSB and XOR*/
	if (value >> 7){
		value = value << 1 ;
		value = value ^ 0x1B ;
		return value;
	}
	else{
		value = value << 1;
		return value;
	}
}

/*
 * Description : Performs mix column operation
 * input : @param state Buffer to store result
 * output : None
 */
static inline void axm0f2_aes_mix_column(uint8_t *state)
{
	uint8_t s[16],res[16],i;

	/* Storing state initially for computation */
	memcpy(s, state, 16);

	/* GF Multiplication of each state */
	for (i = 0; i < 16; i++)
	{
		res[i] =  gf_multiply(state[i]);
	}

	for (i = 0; i < 13; i = i + 4)
	{
		state[i] = res[i] ^ res[i + 1] ^ s[i + 1] ^ (s[i + 2]) ^ (s[i + 3]) ;
	}

	for (i = 1; i < 14; i = i + 4)
	{
		state[i] = (s[i - 1]) ^ res[i] ^ res[i + 1] ^ s[i + 1] ^ (s[i + 2]) ;
	}

	for (i = 2; i < 15; i = i + 4)
	{
		state[i] = (s[i - 2]) ^ (s[i - 1]) ^ res[i] ^ res[i + 1] ^ s[i + 1] ;
	}

	for (i = 3; i < 16; i = i + 4)
	{
		state[i] = res[i - 3] ^ s[i - 3] ^ s[i - 2] ^ (s[i - 1]) ^ res[i] ;
	}
}

/*
 * Description : Performs Inverse sub bytes and inverse Shift row operation
 * input : @param state Buffer to store result
 * output : None
 */
static inline void axm0f2_aes_inv_subbytes_shift_row(uint8_t *state)
{
	uint8_t temp,temp1,temp2;

	state[0]  = inv_sbox[state[0]];
	state[4]  = inv_sbox[state[4]];
	state[8]  = inv_sbox[state[8]];
	state[12] = inv_sbox[state[12]];

	temp = inv_sbox[state[13]];
	state[13] = inv_sbox[state[9]];
	state[9] = inv_sbox[state[5]];
	state[5] = inv_sbox[state[1]];
	state[1] = temp;

	temp1 = inv_sbox[state[10]];
	temp2 = inv_sbox[state[14]];
	state[14] = inv_sbox[state[6]];
	state[10] = inv_sbox[state[2]];
	state[6] = temp2;
	state[2] = temp1;

	temp = inv_sbox[state[3]];
	state[3] = inv_sbox[state[7]];
	state[7] = inv_sbox[state[11]];
	state[11] = inv_sbox[state[15]];
	state[15] = temp;
}



/*
 * Description : Performs Inverse mix column operation
 * input : @param state Buffer to store result
 * output : None
 */
static inline void axm0f2_aes_inv_mix_column(uint8_t *state)
{
	uint8_t s1[16], s2[16], s3[16], s4[16];
	uint8_t s[16], i;

	/* Storing state initially for computation */
	memcpy(s, state, 16);

	/* Multiply by 0x09 */
	for (i = 0; i < 16; i++)
	{
		s1[i] = (gf_multiply(gf_multiply(gf_multiply(s[i])))) ^ (s[i]) ;
	}

	/* Multiply by 0x0B */
	for (i = 0; i < 16; i++)
	{
		s2[i] = gf_multiply((gf_multiply(gf_multiply(s[i])) ^ s[i])) ^ (s[i])  ;
	}

	/* Multiply by 0x0D */
	for (i = 0; i < 16; i++)
	{
		s3[i] = gf_multiply(gf_multiply((gf_multiply(s[i]) ^ s[i]))) ^ (s[i]) ;
	}

	/* Multiply by 0x0E */
	for (i = 0; i < 16; i++)
	{
		s4[i] = gf_multiply((gf_multiply(gf_multiply(s[i]) ^ s[i])) ^ (s[i])) ;
	}

	for (i = 0; i < 13; i = i + 4)
	{
		state[i] = s4[i] ^ s2[i + 1] ^ (s3[i + 2]) ^ (s1[i + 3]) ;
	}

	for (i = 1; i < 14; i = i + 4)
	{
		state[i] = (s1[i - 1]) ^ s4[i] ^ s2[i + 1] ^ (s3[i + 2]) ;
	}

	for (i = 2; i < 15; i = i + 4)
	{
		state[i] = (s3[i - 2]) ^ (s1[i - 1]) ^ s4[i] ^ s2[i + 1]  ;
	}

	for (i = 3; i < 16; i = i + 4)
	{
		state[i] = s2[i - 3] ^ s3[i - 2] ^ s1[i - 1] ^ (s4[i]) ;
	}
}

/*
 * Description : Performs AES Encryption
 * input : @param ptext Base address of Input text block
 * input : @param ctext Base address of cipher text
 * input : @param keyschedule   Base address of the Expanded key
 * input : @param Nr Number of rounds in AES algorithm (10,12,14)
 * output : None
 */
void axm0f2_aes_cipher(uint8_t *ptext, uint8_t *ctext, uint8_t *keyschedule, uint8_t Nr)
{
	uint8_t round;

	/* Copy input buffer to cipher text */
	memcpy((void *)ctext, ptext, 16) ;

	/* Initial Add round key */
	axm0f2_aes_add_round_key(ctext, keyschedule, AXM0F2_AES_ROUND_ZERO);

	/* Round 1 to Nr-1 */
	for (round = 1; round < Nr; round++)
	{
		axm0f2_aes_subbytes_shift_row(ctext);
		axm0f2_aes_mix_column(ctext);
		axm0f2_aes_add_round_key(ctext, keyschedule, round);
	}

	/* Last round */
	axm0f2_aes_subbytes_shift_row(ctext);
	axm0f2_aes_add_round_key(ctext, keyschedule, Nr);
}

/*
 * Description : Performs AES Decryption
 * input : @param ctext Base address of cipher text
 * input : @param ptext Base address of output text
 * input : @param keyschedule Base address of the Expanded key
 * input : @param Nr Number of rounds in AES algorithm (10,12,14)
 * output : None
 */
void axm0f2_aes_inv_cipher(uint8_t *ctext, uint8_t *ptext, uint8_t *keyschedule, uint8_t Nr)
{
	uint8_t round;

	/* Copy cipher text to plain text */
	memcpy((void *)ptext, ctext, 16);

	/* Initial add round key */
	axm0f2_aes_add_round_key(ptext, keyschedule, Nr);

	for (round = (Nr - 1); round > AXM0F2_AES_ROUND_ZERO; round--)
	{
		axm0f2_aes_inv_subbytes_shift_row(ptext);
		axm0f2_aes_add_round_key(ptext, keyschedule, round);
		axm0f2_aes_inv_mix_column(ptext);
	}

	/* Final round */
	axm0f2_aes_inv_subbytes_shift_row(ptext);
	axm0f2_aes_add_round_key(ptext, keyschedule, AXM0F2_AES_ROUND_ZERO);
}


/*
 * Description : Performs AES Encryption in CBC or OFB mode
 * input : @param pdata Base address of plain text block with first block as Initialization vector
 * input : @param cdata Base address of Cipher text block
 * input : @param block_len number of blocks in plain text excluding Initialization vector
 * input : @param keyschedule Base address of AES cipher key schedule
 * input : @param flag mode of encryption
 * output : @return returns status INVALID_PARAMETER or encrypted block length
 */
uint32_t aes_encrypt(uint8_t __xdata *pdata, uint8_t __xdata *cdata, uint32_t block_len, uint8_t __xdata *keyschedule, uint8_t flag)
{
	uint8_t i, init_vector[16], input_block[16], output_block[16], block, num_of_rounds;

	/* Check the size of the plain text */
	if (!block_len)
		return INVALID_PARAMATER ;

	/* Configuring number of rounds based on mode */
	if ((flag & AES_KEYSIZE_MASK) == AES128_KEY) {
		/* 128 bit */
		num_of_rounds = AES128_NUM_OF_ROUNDS;
	} else if ((flag & AES_KEYSIZE_MASK) == AES192_KEY) {
		/*  192 bit */
		num_of_rounds = AES192_NUM_OF_ROUNDS;
	} else {
		/*  256 bit */
		num_of_rounds = AES256_NUM_OF_ROUNDS;
	}

	/*Copy first block of plain text to initialization vector*/
	memcpy(init_vector, pdata, 16);

	/* Perform encryption in cipher block chaining(CBC) mode */
	if ((flag & AES_BLOCKMODE_MASK) == AES_CBC_MODE)
	{
		/* XOR plain text with initialization vector to get input block */
		for (i = 0; i < 16; i++)
		{
			input_block[i] = pdata[i + 16] ^ init_vector[i] ;
		}

		/* Perform encryption of every block */
		for (block = 1; block <= block_len; block++)
		{
			/* Encryption with initialization vector */
			axm0f2_aes_cipher(&input_block[0], &output_block[0], &keyschedule[0], num_of_rounds);

			/* Copy output block to cipher text*/
			memcpy(&cdata[(block - 1) * 16], output_block, 16);

			/* XOR output block with plain text for next block */
			if (block != block_len)
			{
				for (i = 0; i < 16; i++)
				{
					input_block[i] = pdata[((block + 1) * 16) + i] ^ output_block[i] ;
				}
			}
		}
	}

	/* Perform encryption in Output Feedback(OFB) mode*/
	else if ((flag & AES_BLOCKMODE_MASK) == AES_OFB_MODE)
	{
		 /* Copy initialization vector to input block */
		memcpy(input_block, init_vector, 16);

		/* Perform encryption for every block */
		for (block = 1; block <= block_len; block++)
		{
			/* Encryption with input block */
			axm0f2_aes_cipher(&input_block[0], &output_block[0], &keyschedule[0], num_of_rounds);

			/* Store output block for next block */
			memcpy(input_block, output_block, 16);

			/* Output XOR with plain text to get cipher text */
			for (i = 0; i < 16; i++)
			{
				cdata[((block - 1) * 16) + i] = output_block[i] ^ pdata[(block * 16) + i];
			}
		}
	}
	return block_len;
}


/*
 * Description : Performs AES Decryption in CBC or OFB mode
 * input : @param cdata Base address of Cipher text block with first block as Initialization vector
 * input : @param pdata Base address of Output plain text block
 * input : @param block_len number of blocks in cipher text excluding Initialization vector
 * input : @param keyschedule Base address of AES key schedule
 * input : @param flag mode of encryption
 * output : @return returns status INVALID_PARAMETER or decrypted block length
 */
uint32_t aes_decrypt(uint8_t __xdata *cdata, uint8_t __xdata *pdata, uint32_t block_len, uint8_t __xdata *keyschedule, uint8_t flag)
{
	uint8_t i, input_block[16], output_block[16], block, num_of_rounds;

	/* Check the size of the cipher text */
	if (!block_len)
		return INVALID_PARAMATER ;

	/* Configuring number of rounds based on mode */
	if ((flag & AES_KEYSIZE_MASK) == AES128_KEY) {
		/* 128 bit */
		num_of_rounds = AES128_NUM_OF_ROUNDS;
	} else if ((flag & AES_KEYSIZE_MASK) == AES192_KEY) {
		/*  192 bit */
		num_of_rounds = AES192_NUM_OF_ROUNDS;
	} else {
		/* 256 bit */
		num_of_rounds = AES256_NUM_OF_ROUNDS;
	}

	/* Perform decryption in cipher block chaining(CBC) mode */
	if ((flag & AES_BLOCKMODE_MASK) == AES_CBC_MODE)
	{
		for (block = 1; block <= block_len; block++)
		{
			/* Copy cipher text to input block */
			memcpy(input_block, &cdata[block * 16], 16);

			/* Perform decryption of input block */
			axm0f2_aes_inv_cipher(&input_block[0], &output_block[0], &keyschedule[0], num_of_rounds);

			/* XOR output block with cipher text */
			for (i = 0; i < 16; i++)
			{
					pdata[((block - 1) * 16) + i] = output_block[i] ^ cdata[((block - 1) * 16) + i];
			}
		}
	}

	/* Perform decryption in Output Feedback(OFB) mode*/
	else if ((flag & AES_BLOCKMODE_MASK) == AES_OFB_MODE)
	{
		/* Copy initialization vector to input block */
		memcpy(input_block, cdata, 16);

		/* Perform decryption for every block */
		for (block = 1; block <= block_len; block++)
		{
			/* Encryption with initialization vector */
			axm0f2_aes_cipher(&input_block[0], &output_block[0], &keyschedule[0], num_of_rounds);

			/* Store output block for next block */
			memcpy(input_block, output_block, 16);

			for (i = 0; i < 16; i++)
			{
				pdata[((block - 1) * 16) + i] = output_block[i] ^ cdata[(block * 16) + i];
			}

		}
	}
	return block_len ;
}

#endif /* __AXM0F2 */


#else /* Other than ARM */

/*
 * Nb=4
 * Nk=4,6,8
 * Nr=10,12,14
 */
void aes_keyexp(uint8_t __xdata *keysched, uint8_t Nk, uint8_t Nr)
{
	uint8_t __autodata wcnt;
	uint8_t __autodata w[4];
	uint8_t __autodata bnum;
	uint8_t __autodata rcon;

	wcnt = 4 * (Nr+1);
	if (wcnt <= Nk)
		return;
	wcnt -= Nk;
	keysched += Nk * 4;
	bnum = 0;
	rcon = 1;
	do {
		keysched -= 4;
		w[0] = *keysched++;
		w[1] = *keysched++;
		w[2] = *keysched++;
		w[3] = *keysched++;
		if (!bnum) {
			/* RotWord */
			bnum = w[0];
			w[0] = w[1];
			w[1] = w[2];
			w[2] = w[3];
			w[3] = bnum;
			/* SubWord */
			w[0] = aes_sbox[w[0]];
			w[1] = aes_sbox[w[1]];
			w[2] = aes_sbox[w[2]];
			w[3] = aes_sbox[w[3]];
			/* xor rcon */
			w[0] ^= rcon;
			/* update rcon */
			bnum = (rcon & 0x80);
			rcon <<= 1;
			if (bnum)
				rcon ^= 0x1b;
			bnum = 0;
		} else if (Nk > 6 && bnum == 4) {
			/* SubWord */
			w[0] = aes_sbox[w[0]];
			w[1] = aes_sbox[w[1]];
			w[2] = aes_sbox[w[2]];
			w[3] = aes_sbox[w[3]];
		}
		keysched -= 4 * Nk;
		w[0] ^= *keysched++;
		w[1] ^= *keysched++;
		w[2] ^= *keysched++;
		w[3] ^= *keysched++;
		keysched += 4 * Nk - 4;
		*keysched++ = w[0];
		*keysched++ = w[1];
		*keysched++ = w[2];
		*keysched++ = w[3];
		++bnum;
		if (bnum >= Nk)
			bnum = 0;
	} while (--wcnt);
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */
