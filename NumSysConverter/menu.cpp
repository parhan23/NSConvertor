#include "menu.h"

void handleInputError(const char *msg)
{
	system("cls");
	printf("%s\n\n", msg);
	printf("Press any key to repeat...");
	_getch();
}

void setInitBase(Number *num)
{
	system("cls");
	printf("Enter initial base (%d..%d)\n", MIN_BASE, MAX_BASE);
	printf("> ");
	
	if (!getInitBase(num))
		handleInputError("Incorrect value");
}

void setInitNum(Number *num)
{
	system("cls");
	printf("Enter initial number\n");
	printf("> ");

	switch (getInitNumber(num))
	{
	case -1:
		handleInputError("Set initial base at first");
		break;
	case -2:
		handleInputError("Incorrect value");
		break;
	}
}

void setTargetBase(Number *num)
{
	system("cls");
	printf("Enter target base (%d..%d)\n", MIN_BASE, MAX_BASE);
	printf("> ");

	if (!getTargetBase(num))
		handleInputError("Incorrect value");
}

//Public:

void printMenu(Number *num)
{
	system("cls");

	printf("Initial base: ");
	printInitBase(num);
	printf("\n");

	printf("Initial number: ");
	printInitNumber(num);
	printf("\n\n");

	printf("Target base: ");
	printTargetBase(num);
	printf("\n");

	printf("Converted number: ");
	printConvertedNumber(num);
	printf("\n-----\n");

	printf("1. Set initial base\n");
	printf("2. Enter initial number\n");
	printf("3. Set target base\n");
	printf("4. Convert\n");
	printf("5. Exit\n");
}

bool callCmd(Number *num)
{
	char cmd = _getch();

	switch (cmd)
	{
	case '1':
		setInitBase(num);
		break;
	case '2':
		setInitNum(num);
		break;
	case '3':
		setTargetBase(num);
		break;
	case '4':
		if (!convert(num))
			handleInputError("Unable to convert. Check parameters");
		break;
	case '5':
		return false;
	}

	return true;
}