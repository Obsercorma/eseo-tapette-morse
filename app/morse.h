/*
 * morse.h
 *
 *  Created on: 22 mai 2026
 *      Author: thomasstrong
 */

#ifndef MORSE_H_
#define MORSE_H_

/**
 * @brief Encode une chaine de caracteres en Morse
 * @param input La chaine de caracteres a encoder
 * @param output Le buffer ou stocker la chaine Morse resultante
 * @param output_size La taille du buffer de sortie
 */
void morse_decode(char* input, char* output);

/**
 * @brief Decode une chaine de Morse en caracteres
 * @param input La chaine de Morse a decoder
 * @param output Le buffer ou stocker la chaine de caracteres resultante
 * @param output_size La taille du buffer de sortie
 */
void morse_encode(char* input, char* output);

#endif /* MORSE_H_ */
