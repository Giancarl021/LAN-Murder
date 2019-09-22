#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "util/util.h"
#include "util/util.c"
#include "util/map.h"
#include "util/map.c"
#include "util/player.h"
#include "util/player.c"

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
	map_renderer(m, 0);
	do {
		ch = toupper(getch());
		system("cls");
		position = map_move(m, position, (ch == 'W' ? MV_UP : (ch == 'S' ? MV_DOWN : (ch == 'A' ? MV_LEFT : MV_RIGHT))));
		map_renderer(m, position);
	} while(ch != ' ');
	
	return 0;
}
