#ifndef NSCONV_H
#define NSCONV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define INIT_NUM_BUFFER_SIZE 200
#define DIGITS               64
#define MIN_BASE             2
#define MAX_BASE             36

#define EATLINE\
	while (getchar() != '\n')\
		continue;

struct Number
{
	int initBase;
	int targetBase;
	char initNum[DIGITS + 1];
	char convNum[DIGITS + 1];
};

Number * newNumber();
int getInitBase(Number *);
int getTargetBase(Number *);
int getInitNumber(Number *);
bool convert(Number *);
void printInitBase(Number *);
void printTargetBase(Number *);
void printInitNumber(Number *);
void printConvertedNumber(Number *);

inline void deleteNumber(Number *num)
{
	free(num);
}

#endif // !NSCONV_H