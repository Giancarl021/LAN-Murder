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
		if(string[index + 3] == 10) index += 4; // Windows
		else if (string[index + 3] == 13) index += 5; // Linux
		else index += 3; // Normal
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
		switch(k) {
			case BLOCK_ROOM:
			case VCORRIDOR_ROOM:
			case HCORRIDOR_ROOM:
				if(position == i) {
					printf("%c%c%c", rs[k].combination[0], PLAYER_CHAR, rs[k].combination[2]);
				} else {
					printf("%s", rs[k].combination);
				}
				break;
			case NULL_ROOM:
				printf("   ");
				break;
			default:
				printf("ERR");
		}
		
		if(!((i + 1) % map.width)) {
			printf("\n");
		}
	}
};

int map_move(Map map, int position, int direction) {
	int destination;
	switch(direction) {
		case MV_UP:
			destination = position - map.width;
			break;
		case MV_DOWN:
			destination = position + map.width;
			break;
		case MV_LEFT:
			destination = position - 1;
			break;
		case MV_RIGHT:
			destination = position + 1;
			break;
		default:
			return position;
	}
	
	if(_is_accessible_room(map, position, destination, direction)) {
		return destination;
	}
	
	return position;
}

int map_warp(Map map, int position, int destination) {
	if(_can_warp(map, destination)) {
		return destination;
	}
	return position;
}

int random_map_warp(Map map, int position) {
	//
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

int _get_random_accessible_room(Map m) {
	int i, k,
		l = m.height * m.width,
		accessible_rooms[l],
		acc_rooms_size = 0;
		
	for(i = 0; i < l; i++) {
		k = m.rooms[i];
		if(k != BLOCK_ROOM && k != VCORRIDOR_ROOM && k != HCORRIDOR_ROOM) continue;
		accessible_rooms[acc_rooms_size++] = i;
	}
	return accessible_rooms[(int)(rand() % acc_rooms_size)];
}

bool _is_accessible_room(Map map, int origin, int destination, int direction) {
	// Null Destination
	
	if(destination < 0 || destination >= (map.width * map.height)) return false; // Null Pointer
	if(map.rooms[destination] == NULL_ROOM) return false; // Destination is a NULL BLOCK
	
	// Out off Bounds
	
	if(direction == MV_UP && origin <= map.width) return false; // Up in first line
	if(direction == MV_DOWN && origin >= (map.width * map.height - map.width)) return false; // Down in last line
	if(direction == MV_LEFT && origin % map.width == 0) return false; // Left in first column
	if(direction == MV_RIGHT && origin % map.width == (map.width - 1)) return false; // Right in last column
	
	// Constrains
	
	if(map.rooms[destination] == VCORRIDOR_ROOM && (direction == MV_LEFT || direction == MV_RIGHT)) return false; // Horizontal movement to VCORRIDOR ROOM
	if(map.rooms[destination] == HCORRIDOR_ROOM && (direction == MV_UP || direction == MV_DOWN)) return false; // Vertiacal movement to HCORRIDOR ROOM
	if(map.rooms[origin] == VCORRIDOR_ROOM && (direction == MV_LEFT || direction == MV_RIGHT)) return false; // Horizontal movement from VCORRIDOR ROOM
	if(map.rooms[origin] == HCORRIDOR_ROOM && (direction == MV_UP || direction == MV_DOWN)) return false; // Vertical movement from HCORRIDOR ROOM
	
	return true;
}

bool _can_warp(Map map, int destination) {
	// Null Destination
	if(destination < 0 || destination >= (map.width * map.height)) return false; // Null Pointer
	if(map.rooms[destination] == NULL_ROOM) return false; // Destination is a NULL BLOCK
	
	return true;
}
