#define _ENVIROMENT_ITEM_LIMIT 8

const _IT_COUNT = 4;

enum {
	IT_CORPSE,
	IT_SCRAP,
	IT_GUN,
	IT_WARPER
};

typedef struct {
	int location;
	char *tag;
	int type;
} Item;

typedef struct {
	Map map;
	Item items[_ENVIROMENT_ITEM_LIMIT];
	int items_size;
} Environment;

Environment *create_environment(Map m);

void generate_item(Environment *env);
