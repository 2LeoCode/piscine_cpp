#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void) {
	time_t	seed = time(NULL);
	char	buf[20] = { 0 };

	initstate(seed, buf, 20);
	for (int i = 0; i < 20; ++i)
		printf("%d\n", buf[i]);
	for (int i = 0; i < 20; ++i)
		random();	
	for (int i = 0; i < 20; ++i)
		printf("%d\n", buf[i]);
	return 0;
}
