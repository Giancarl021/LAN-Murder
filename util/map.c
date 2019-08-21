char* read_map_as_string(const char *path) {
	FILE *map = fopen(path, "r");
	if(map == NULL) return NULL;
	
	fclose(map);
}
