Map *parse_map(const char* string) {
	int i, size,
		w = -1,
		h = 0,
		l = strlen(string),
		index = 0;
	
	for(i = 0; i < l; i++) {
		if(string[i] == '\n') {
			if(w == -1) w = i;
			h++;
		}
	}
	Map *x = malloc(sizeof(Map));
	x->height = h;
	x->width = (int)w / 3;
	
	size = (w / 3) * h;
	
	x->rooms = malloc(sizeof(int) * size);
	for(i = 0; i < size; i++) {
		x->rooms[i] = _get_room_type(string[index], string[index + 1], string[index + 2]);
		if(string[index + 3] == '\n') index += 4;
		else index += 3;
	}
	return x;
}

char *map_to_string(Map map) {
	int i, j, 
		h = map.height,
		w = map.width,
		size = w * h;
	
	char *r = malloc((sizeof(char) * size * 3) + (sizeof(char) * h));
	
	r[0] = '\0';
	
	for(i = 0; i < size; i++) {
		int k = map.rooms[i];
		switch(k) {
			case NULL_ROOM:
			case BLOCK_ROOM:
			case VCORRIDOR_ROOM:
			case HCORRIDOR_ROOM:
				strcat(r, rs[k].combination);
				break;
			default:
				strcat(r, "!!!");
		}
		
		if(!((i + 1) % w)) {
			strcat(r, "\n");
		}
	}
	return r;
}

void map_renderer(Map map, int position) {
	int i, k,
		l = map.height * map.width;
		
	for(i = 0; i < l; i++) {
		k = map.rooms[i];
		if(position == i) textbackground(HIGHLIGHT_BG);
		else textbackground(DEFAULT_BG);
		switch(k) {
			case BLOCK_ROOM:
			case VCORRIDOR_ROOM:
			case HCORRIDOR_ROOM:
				textcolor(rs[k].color);
				printf("%s", rs[k].combination);
				break;
			case NULL_ROOM:
				printf("   ");
				break;
			default:
				textcolor(DARKGRAY);
				printf("ERR");
		}
		
		if(!((i + 1) % map.width)) {
			printf("\n");
		}
		textcolor(DEFAULT_COLOR);
	}
};

int map_move(Map map, int position, int direction) {
	int destination;
	if(direction == MV_UP) {
		destination = position - map.width;
	} else if (direction == MV_DOWN) {
		destination = position + map.width;
	} else if (direction == MV_LEFT) {
		destination = position - 1;
	} else if (direction == MV_RIGHT) {
		destination = position + 1 ;
	} else {
		return position;
	}
	
	if(_is_accessible_room(map, position, destination)) {
		return destination;
	}
}

int _get_room_type(char a, char b, char c) {
	int i;
	
	for(i = 0; i < 4; i++) {
		if(a == rs[i].combination[0] && b == rs[i].combination[1] && c == rs[i].combination[2]) {
			return rs[i].result;
		}
	}
	return -1;
}

bool _is_accessible_room(Map map, int origin, int destination) {
	if(destination < 0 || destination > (map.width * map.height)) return false;
	
	if(map.rooms[destination] == NULL_ROOM) return false;
}
