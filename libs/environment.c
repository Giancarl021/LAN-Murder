Environment *create_environment(Map m) {
	Environment *e = malloc(sizeof(Environment));
	e->map = m;
	e->items_size = 0;
	return e;
}

void generate_item(Environment *env) {
//	printf("%d", env->map.width);
	if(env->items_size == _ENVIROMENT_ITEM_LIMIT) {
		return;
	}
	
	env->items[env->items_size++] = (Item){0, "TEST", IT_CORPSE};
	env->items[env->items_size++] = (Item){0, "TEST2", IT_CORPSE};
	int i;
	for(i = 0; i < env->items_size; i++) {
		printf(env->items[i].tag);
	}
}
