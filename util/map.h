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
	int color;
};

struct _room_structure rs[4] = {
	{{'#','#','#','\0'}, NULL_ROOM, BLACK},
	{{'[',' ',']','\0'}, BLOCK_ROOM, WHITE},
	{{'|',' ','|','\0'}, VCORRIDOR_ROOM, LIGHTGREEN},
	{{'=','=','=','\0'}, HCORRIDOR_ROOM, LIGHTGREEN}
};

int _get_room_type(char a, char b, char c);

Map *parse_map(const char* string);

char *map_to_string(Map map);
