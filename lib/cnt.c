int define_host_folder(char *path) {
	DIR *d = opendir(path);
	if(d) {
		closedir(d);
		return -1;
	}
	mkdir(path);
}
