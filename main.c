#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "lib/conio.h"
#include "lib/conio.c"
#include "util/util.h"
#include "util/util.c"
#include "util/map.h"
#include "util/map.c"

int main(int argc, char *argv[]) {
	char *map_path = "map/3-type.map";
	
//	printf("%s", // Prints string
//		map_to_string( // Convert map structure into string
//			*parse_map( // Convert string into map structure
//				read_file(map_path) // read file dynamic allocating memory to string
//			)
//		)
//	);
	Map m = *parse_map(read_file(map_path));
	char ch;
	int position = 0,
		w = m.width,
		h = m.height;
	map_renderer(m, position);
	do {
		ch = toupper(getch());
		position = map_move(m, position, (ch == 'W' ? 0 : (ch == 'S' ? 1 : (ch == 'A' ? 2 : 3))));
		gotoxy(1, 1);
		map_renderer(m, position);
	} while(ch != ' ');
	
	return 0;
}
