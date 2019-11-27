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
	str[index] = '\0';
	fclose(f);
	return str;
}

void write_file(const char *path, const char *string) {
	FILE *f = fopen(path, "w");
	fprintf(f, "%s", string);
	fclose(f);
}
