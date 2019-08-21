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
