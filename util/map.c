Map parse_map(const char* string) {
	int i, w = -1, h = 0, l = strlen(string);
	for(i = 0; i < l; i++) {
		if(string[i] == '\n') {
			if(w == -1) w = i;
			h++;
		}
	}
	Map x;
	printf("%d %d", w, h);
	return x;
}
