void print_all_chars(const char *string) {
	int i,
		l = strlen(string);
	for(i = 0; i < l; i++) {
		printf("[%d] {%c}\n", string[i], string[i]);
	}
	printf("\n\n");
}
