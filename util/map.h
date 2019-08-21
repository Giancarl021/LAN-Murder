enum {
	NULL_ROOM,
	BLOCK_ROOM,
	VCORRIDOR_ROOM,
	HCORRIDOR_ROOM
};

typedef struct {
	unsigned int width;
	unsigned int height;
	int *rooms;
} Map;
