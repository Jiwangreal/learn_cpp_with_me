#include "Integer.h"
#include <iostream>
using namespace std;


int main(void)
{
	Integer n(100);
	n.Display();

	Integer n2 = ++n;
	n.Display();
	n2.Display();

	Integer n3 = n++;
	n.Display();
	n3.Display();



	return 0;
}