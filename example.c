#include <stdio.h>

#define print(fmt, ...)		__builtin_print(fmt, printf __VA_OPT__(,) __VA_ARGS__)

int main(void)
{
	int a = 10;
	int b = 20;

	print("{a} + {b} = {}\n", a + b);
	print("{a} + {b} = {0}\n", a + b);
	print("{1} + {0} = {2}\n", a, b, a + b);
	print("a = {a:03x}\n", a);
	print("a = {a:-3} hello\n", a);
	print("a = {a:3} hello\n", a);
}
