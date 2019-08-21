#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/util.c"
#include "util/map.c"

int main(int argc, char *argv[]) {
	printf(read_file(argv[1]));
	return 0;
}
