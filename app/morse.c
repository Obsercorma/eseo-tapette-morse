/*
 * morse.c
 *
 *  Created on: 22 mai 2026
 *      Author: thomasstrong
 */

#include "morse.h"
#include <string.h>

const char* morse_table[36] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
	".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
	"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // S-Z
	"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};

// as lower
const char* char_table = "abcdefghijklmnopqrstuvwxyz0123456789";

void morse_decode(const char* input, char* output){

}

void morse_encode(const char* input, char* output){
	for(int i = 0; input[i] != '\0'; i++){
		char c = input[i];
		// concatène le code Morse correspondant au caractère c dans output
		const char* morse_code = NULL;
		morse_code = morse_table[c - 'a'];
		if(morse_code != NULL){
			strncat(output, morse_code, strlen(morse_code));
		}
	}
}
