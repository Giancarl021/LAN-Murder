enum {
	NULL_ROOM,
	BLOCK_ROOM,
	VCORRIDOR_ROOM,
	HCORRIDOR_ROOM
};

enum {
	MV_UP,
	MV_DOWN,
	MV_LEFT,
	MV_RIGHT
};

typedef struct {
	int width;
	int height;
	int *rooms;
} Map;

struct _room_structure {
	char combination[4];
	int result;
};

struct _room_structure rs[4] = {
	{{'#','#','#','\0'}, NULL_ROOM},
	{{'[',' ',']','\0'}, BLOCK_ROOM},
	{{'|',' ','|','\0'}, VCORRIDOR_ROOM},
	{{'=','=','=','\0'}, HCORRIDOR_ROOM}
};

const char PLAYER_CHAR = '~';

int _get_room_type(char a, char b, char c);

bool _is_accessible_room(Map map, int origin, int destination, int direction);

Map *parse_map(const char* string);

char *map_to_string(Map map);

void map_renderer(Map map, int position);

int map_move(Map map, int position, int direction);
