/*
 * Copyright (c) 2026 lulboi30.
 * SPDX-License-Identifier: MIT
 */

#include "climenu.h"

uint16_t menuselect(climenu_t* menu) {
	for (uint16_t i = 0; i < menu->count; i++) {
		printf("%" PRIu16 ") %s\n", i + 1, menu->items[i]);
	}
	putchar('\n');

	uint16_t selection = 1;
	printf(") ");
	scanf("%i", &selection);

	while (selection > menu->count || selection < 1) {
		puts("Invalid Selection");
		printf(") ");
		scanf("%i", &selection);
	}

	return selection - 1;
}

climenu_t *newmenu() {
	climenu_t *menu = malloc(sizeof(climenu_t));
	menu->count = 0;
	menu->items = NULL;
}

void additem(climenu_t* menu, char *item) {
	menu->count++;
	char **temp = realloc(menu->items, menu->count * sizeof(char *));
	if (temp != NULL) {
		menu->items = temp;
		menu->items[menu->count - 1] = malloc(strlen(item));
		strcpy(menu->items[menu->count - 1], item);
	} else {
		menu->count--;
	}
}

void freemenu(climenu_t *menu) {
	if (menu->items != NULL) {
		for (uint16_t i = 0; i < menu->count; i++) {
			free(menu->items[i]);
		}
		free(menu->items);
	}
	free(menu);
}
