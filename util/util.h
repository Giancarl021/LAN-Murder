typedef int bool;
enum {
	false,
	true
};

const int DEFAULT_COLOR = LIGHTGRAY;
const int DEFAULT_BG = BLACK;
const int HIGHLIGHT_BG = RED;

const int MV_UP = 0;
const int MV_DOWN = 1;
const int MV_LEFT = 2;
const int MV_RIGHT = 3;

char *read_file(const char *path);
