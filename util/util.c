char *read_file(const char *path) {
	FILE *f = fopen(path, "r");
	if(f == NULL) return NULL;
	char *str = malloc(1), ch;
	while(!feof(f)) {
		ch = fgetc(f);
		str = realloc(str, strlen(str) + 1);
		str[strlen(str)] = ch;
	}
	fclose(f);
	return str;
}
