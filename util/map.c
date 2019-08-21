Map *parse_map(const char* string) {
	int i, w = -1, h = 0, l = strlen(string), size;
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
	printf("w:%d h:%d", w / 3, h);
	for(i = 0; i < size; i++) {
		// define rooms by string
	}
	return x;
}
