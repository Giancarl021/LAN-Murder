enum {
	IT_SCRAP,
	IT_GUN,
	IT_WARPER
};

typedef struct {
	int location;
	char *name;
} Corpse;

typedef struct {
	Map map;
	int *scrap;
	int *gun;
	int *warper;
	Corpse *corpse;
} Environment;
