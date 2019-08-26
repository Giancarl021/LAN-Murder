#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "util/util.c"
#include "util/map.h"
#include "util/map.c"

int main(int argc, char *argv[]) {
	printf("%s\n",read_file("map/3.map"));
	printf("%s", 
	map_to_string(*parse_map(read_file("map/3.map")))
	)
	;
	return 0;
}
