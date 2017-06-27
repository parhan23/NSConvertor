#include "NSConv.h"
#include "menu.h"

int main()
{
	Number *num = newNumber();

	do
	{
		printMenu(num);
	} while (callCmd(num));
	deleteNumber(num);
	
	return 0;
}