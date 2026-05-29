/*
 * morse.c
 *
 *  Created on: 22 mai 2026
 *      Author: thomasstrong
 */

#include "morse.h"
#include <string.h>
#include <ctype.h>

const char* morse_table[36] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
	".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
	"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // S-Z
	"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};

// as lower
const char* char_table = "abcdefghijklmnopqrstuvwxyz0123456789";

void morse_decode(char* input, char* output){
	int out_index = 0;
	char morse_char[10];
	int morse_index = 0;
	int space_count = 0;

	output[0] = '\0';

	for(int i = 0; ; i++){
		char c = input[i];

		if(c == '.' || c == '-'){
			morse_char[morse_index++] = c;
			space_count = 0;
		}

		else if(c == ' '){
			space_count++;

			// fin d'une lettre
			if(morse_index > 0){
				morse_char[morse_index] = '\0';

				for(int j = 0; j < 36; j++){
					if(strcmp(morse_char, morse_table[j]) == 0){
						output[out_index++] =
							tolower((unsigned char)char_table[j]);
						break;
					}
				}

				morse_index = 0;
			}
		}
		else if(c == '|'){
			output[out_index++] = '|';
		}

		else if(c == '\0'){
			if(morse_index > 0){
				morse_char[morse_index] = '\0';

				for(int j = 0; j < 36; j++){
					if(strcmp(morse_char, morse_table[j]) == 0){
						output[out_index++] =
							tolower((unsigned char)char_table[j]);
						break;
					}
				}
			}
			break;
		}
	}

	output[out_index] = '\0';
}


void morse_encode(char* input, char* output){
	output[0] = '\0';   // initialise proprement

	for(int i = 0; input[i] != '\0'; i++){
		char c = tolower(input[i]);

		const char* morse_code = NULL;

		if(c == '\r' || c == '\n'){
			strcat(output, "\n");
			continue;
		}

		if(c == ' '){
			strcat(output, "  ");
			continue;
		}

		if(c >= 'a' && c <= 'z'){
			morse_code = morse_table[c - 'a'];
		}
		else if(c >= '0' && c <= '9'){
			morse_code = morse_table[26 + (c - '0')];
		}

		if(morse_code != NULL){
			strcat(output, morse_code);
		}
	}
}
