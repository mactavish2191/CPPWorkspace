#include <stdio.h>
#include <string>
#define ln "\n"


void show_bytes( unsigned char *start, auto len ) {
	for (auto i = 0; i < len; i++) {
		printf(" %2.2x", start[i]);
	}
	printf(ln);
}

auto main() -> int {

	int i = 0x01020304;
	float f = 123.456;
	int *ip = &i;
	char *s = (char *)"ABCDEFX";

	show_bytes((unsigned char *)&i, sizeof(int));
	show_bytes((unsigned char *)&f, sizeof(float));
	show_bytes((unsigned char *)&ip, sizeof(char *));
	show_bytes((unsigned char *)s, strlen(s));


	return 0;
}