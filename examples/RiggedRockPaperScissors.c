/*
 * Copyright (c) 2026 lulboi30
 * SPDX-License-Identifier: MIT
 */

#include <climenu.h>

/*
 * climenu.h already includes what we need
 * the only example in the examples directory? deal with it
 */

int main() {
	climenu_t *menu = newmenu();

	additem(menu, "Rock");
	additem(menu, "Paper");
	additem(menu, "Scissors");

	puts("Make Your Choice");
	puts("----------------");
	uint16_t choice = menuselect(menu);
	printf("\nYou Chose %s\n", menu->items[choice]);

	switch (choice) {
		case 0:
			puts("I Chose Paper\nI Win!");
			break;
		case 1:
			puts("I Chose Scissors\nI Win!");
			break;
		case 2:
			puts("I Chose Rock\nI win!");
			break;
	}

	freemenu(menu);
}
