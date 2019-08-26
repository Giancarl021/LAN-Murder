enum {
	NULL_ROOM,
	BLOCK_ROOM,
	VCORRIDOR_ROOM,
	HCORRIDOR_ROOM
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
	{{'(',' ',')','\0'}, VCORRIDOR_ROOM},
	{{'{',' ','}','\0'}, HCORRIDOR_ROOM}
};

int _get_room_type(char a, char b, char c);

Map *parse_map(const char* string);

char *map_to_string(Map map);
