typedef int bool;
enum {
	false,
	true
};

char *read_file(const char *path);

void write_file(const char *path, const char *string);
