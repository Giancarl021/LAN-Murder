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
		switch(map.rooms[i]) {
			case BLOCK_ROOM:
				strcat(r, "[ ]");
				break;
			case VCORRIDOR_ROOM:
				strcat(r, "( )");
				break;
			case HCORRIDOR_ROOM:
				strcat(r, "{ }");
				break;
			case NULL_ROOM:
				strcat(r, "###");
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

void map_renderer(Map map, int size, int position) {
	if(!(size % 2)) size++;
	
	int i,
		l = map.height * map.width; // map.rooms size
		g = (int)floor((double)(size/2)), // max deslocation of map.rooms
		d = g * (size + 1); // center cell of map.rooms
	
	// TODO
	/*
		Render all white spaces in map before visible cells (out of bounds in map.rooms)
		Render visible map
		Render all white spaces in map after visible cells (out of bound in map.rooms)
	*/
};

int _get_room_type(char a, char b, char c) {
	int i;
	struct _room_structure rs[4];
	
	rs[0] = (struct _room_structure){{'[',' ',']'}, BLOCK_ROOM};
	rs[1] = (struct _room_structure){{'{',' ','}'}, HCORRIDOR_ROOM};
	rs[2] = (struct _room_structure){{'(',' ',')'}, VCORRIDOR_ROOM};
	rs[3] = (struct _room_structure){{'#','#','#'}, NULL_ROOM};
	
	for(i = 0; i < 4; i++) {
		if(a == rs[i].combination[0] && b == rs[i].combination[1] && c == rs[i].combination[2]) {
			return rs[i].result;
		}
	}
	return -1;
}
