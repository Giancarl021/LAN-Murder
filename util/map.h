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

int _get_room_type(char a, char b, char c);
