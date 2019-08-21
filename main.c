#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "util/util.c"
#include "util/map.h"
#include "util/map.c"

int main(int argc, char *argv[]) {
	printf(read_file("map/1.map"));
	parse_map(read_file("map/1.map"));
	return 0;
}
