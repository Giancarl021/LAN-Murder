#include "lib"

int main(int argc, char *argv[]) {
	init();
//	char *map_path = "map/3-type.map";
//	Map m = *parse_map(read_file(map_path));
//	char ch;
//	int position = 0,
//		w = m.width,
//		h = m.height;
//	map_renderer(m, 0);
//	do {
//		ch = toupper(getch());
//      if(ch != 'W' && ch != 'A' && ch != 'S' && ch != 'D') continue;
//		system("cls");
//		position = map_move(m, position, (ch == 'W' ? MV_UP : (ch == 'S' ? MV_DOWN : (ch == 'A' ? MV_LEFT : MV_RIGHT))));
//		map_renderer(m, position);
//	} while(ch != ' ');
//	
//	Environment *e = create_environment(m);
//	
//	generate_item(e);
//	generate_item(e);
//	generate_item(e);
//	generate_item(e);
//	generate_item(e);
//	
//	int i;
//	for(i = 0; i < e->items_size; i++) {
//		printf("\ntype: %d\ntag: %s\nlocation: %d", e->items[i].type, e->items[i].tag, e->items[i].location);
//	}
	if(!check_file("config.txt")) {
		char address[256];
		surround_text("BEM-VINDO AO LAN-MURDER!!!", '*');
		printf("\n\nAntes de iniciar, poderia informar o endereco da pasta de salas?\n\n > ");
		input(address, 255);
		printf("[%s]", address);
		write_file("config.txt", address);
	}
//	printf("%d\n", check_file("config.json"));
//	write_file("config.json", "{\n  \"a\": 1\n  \"b\":2\n}");
//	const char *a = read_file("config.txt");
//	printf("%s", a);
//	printf("\n\n%s", read_file(a));
	print_all_chars(read_file("map/1.map"));
	printf("\n\n");
	return 0;
}
