typedef int bool;
enum {
	false,
	true
};

char *read_file(const char *path);

void write_file(const char *path, const char *string);

bool check_file(const char *path);

void surround_text(const char *text, char surround_char);

void input(char *var, int var_size);

void init(void);
