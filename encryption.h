#ifndef ENCRPYTION_H
#define ENCRYPTION_H

#include <stdio.h>
#include <stdlib.h>

int8_t M_IMAG = 0x001;
int8_t M_FILE = 0x002;
int8_t M_QIET = 0x004;
int8_t M_STRN = 0x008;

int encrypt_file(char **files);

#endif