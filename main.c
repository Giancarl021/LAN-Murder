#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <conio.c>
#include <locale.h>
#include "util/util.c"
#include "util/map.h"
#include "util/map.c"

int main(int argc, char *argv[]) {
	char *map_path = "map/2.map";
	
	printf("%s", // Prints string
		map_to_string( // Convert map structure into string
			*parse_map( // Convert string into map structure
				read_file(map_path) // read file dynamic allocating memory to string
			)
		)
	);
	Map m = *parse_map(read_file(map_path));
	map_renderer(m, 18);
//	textbackground(RED);
//	map_renderer(m, 3, 2);
//	textbackground(BLACK);
	return 0;
}
