#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "util/util.c"
#include "util/map.h"
#include "util/map.c"

int main(int argc, char *argv[]) {
	printf("%s", // Prints string
		map_to_string( // Convert map structure into string
			*parse_map( // Convert string into map structure
				read_file("map/3.map") // read file dynamic allocating memory to string
			)
		)
	);
	Map m = *parse_map(read_file("map/3.map"));
	map_renderer(m, 3, 4);
	return 0;
}
