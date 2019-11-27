Environment *create_environment(Map m) {
	Environment *e = malloc(sizeof(Environment));
	e->map = m;
	e->items_size = 0;
	return e;
}

void generate_item(Environment *env) {
	if(env->items_size == _ENVIROMENT_ITEM_LIMIT) {
		return;
	}
	
	Item it;
	it.location = _get_random_accessible_room(env->map);
	it.tag = "Item gerado";
	it.type = rand() % _IT_COUNT;
	env->items[env->items_size++] = it;
}
