char *read_file(const char *path) {
	FILE *f = fopen(path, "r");
	if(f == NULL) return NULL;
	
	fseek(f, 0, SEEK_END);
	int l = ftell(f);
	fseek(f, 0, SEEK_SET);
	char *str = malloc(l + 1);
	if(str) {
    	fread(str, 1, l, f);
	}
	fclose(f);
	str[l] = '\0';
	return str;
}

void write_file(const char *path, const char *string) {
	FILE *f = fopen(path, "w");
	fprintf(f, "%s", string);
	fclose(f);
}

bool check_file(const char *path) {
	FILE *f = fopen(path, "r");
	if(f == NULL) {
		return false;
	}
	fclose(f);
	return true;
}

void init(void) {
	srand(time(NULL));
}

void surround_text(const char *text, char surround_char) {
	int i,n;
	n = strlen(text) + 4;
	for (i=0;i<n;i++) {
		printf("%c", surround_char);
	}
	printf("\n");
	printf("%c %s %c\n", surround_char, text, surround_char);
	for (i=0;i<n;i++) {
		printf("%c", surround_char);
	}
}

void input(char *var, int var_size) {
	int i;
	bool complete = false;
	fgets(var, var_size, stdin);
	fflush(stdin);
	for(i = 0; i < var_size; i++) {
		if(var[i] == 10 || var[i] == 13 || complete) {
			var[i] = '\0';
			complete = true;
		}
	}
}
