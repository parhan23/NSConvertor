#include "NSConv.h"

int getBase(int *base)
{
	int buffer;
	
	if (scanf("%d", &buffer) && buffer >= MIN_BASE && buffer <= MAX_BASE)
	{
		*base = buffer;
		EATLINE
		return *base;
	}
	else
	{
		EATLINE
		return false;
	}
}

void strToUpper(char *str)
{
	for (int i = 0; i < strlen(str); ++i)
		if (islower(str[i]))
			str[i] = toupper(str[i]);
}

bool isValidNum(char *num, int base)
{
	for (int i = 0; i != strlen(num); ++i)
	{
		if (base <= 10 && num[i] - '0' >= base ||
			base > 10 && num[i] - 'A' + 10 >= base)
			return false;
	}

	return true;
}

char intToChar(int digit)
{
	if (digit <= 9)
		return ('0' + digit);
	else
		return ('A' + digit - 10);
}

int charToInt(char digit)
{
	if (digit <= '9')
		return (digit - '0');
	else
		return (digit - 'A' + 10);
}

unsigned long long aTo10LL(char *numStr, int base)
{
	unsigned long long LL10Num = 0;
	char *digit = numStr;
	int power = strlen(numStr) - 1;

	while (*digit)
	{
		LL10Num += charToInt(*digit) * pow(base, power);
		--power;

		++digit;
	}

	return LL10Num;
}

void printBase(const int base)
{
	if (base)
		printf("%d", base);
	else
		printf("%s", "n/a");
}

void printNumber(const char *num)
{
	if (*num)
		printf("%s", num);
	else
		printf("%s", "n/a");
}

//Public:

Number * newNumber()
{
	Number *newNumPtr = (Number *)malloc(sizeof(Number));
	
	newNumPtr->initBase = 0;
	newNumPtr->targetBase = 0;
	newNumPtr->initNum[0] = '\0';
	newNumPtr->convNum[0] = '\0';
	
	return newNumPtr;
}

int getInitBase(Number *num)
{	
	bool isSuccess = getBase(&num->initBase);

	num->initNum[0] = '\0';
	num->convNum[0] = '\0';
	
	return isSuccess;
}

int getTargetBase(Number *num)
{
	bool isSuccess = getBase(&num->targetBase);
	
	num->convNum[0] = '\0';
	
	return isSuccess;
}

int getInitNumber(Number *num)
{
	char buffer[INIT_NUM_BUFFER_SIZE];

	if (num->initBase)
	{
		scanf("%s", buffer);
		buffer[DIGITS] = '\0';
		EATLINE
	}
	else
		return -1;
	
	if (num->initBase > 10)
		strToUpper(buffer);
	
	if (isValidNum(buffer, num->initBase))
	{
		strcpy(num->initNum, buffer);
		return 0;
	}
	else
		return -2;
}

bool convert(Number *num)
{
	unsigned long long initNum;
	static char convertedNum[DIGITS + 1];
	char *digit = convertedNum + DIGITS;

	if (!num->initBase || !num->targetBase ||
		!num->initNum[0])
		return false;
	
	if (num->initBase == 10)
		initNum = atoll(num->initNum);
	else
		initNum = aTo10LL(num->initNum, num->initBase);

	while (initNum)
	{
		--digit;
		*digit = intToChar(initNum % num->targetBase);
		initNum /= num->targetBase;
	}

	strcpy(num->convNum, digit);

	return true;
}

void printInitBase(Number *num)
{
	printBase(num->initBase);
}

void printTargetBase(Number *num)
{
	printBase(num->targetBase);
}

void printInitNumber(Number *num)
{
	printNumber(num->initNum);
}

void printConvertedNumber(Number *num)
{
	printNumber(num->convNum);
}