char *read_file(const char *path) {
	FILE *f = fopen(path, "r");
	if(f == NULL) return NULL;
	
	int index = 0;
	char *str = malloc(sizeof(char)), ch;
	
	while(!feof(f)) {
		ch = fgetc(f);
		if(ch == '%') {
			str = realloc(str, (sizeof(char) * (index + 2)));
			str[index++] = ch;
			str[index++] = ch;
		} else {
			str = realloc(str, (sizeof(char) * (index + 1)));
			str[index++] = ch;
		}
	}
	str[index] = NULL;
	fclose(f);
	return str;
}
