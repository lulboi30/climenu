/*
 * Copyright (c) 2026 lulboi30.
 * SPDX-License-Identifier: MIT
 */

#include "climenu.h"

uint16_t menuselect(climenu_t* menu) {
  for (uint16_t i = 0; i < menu->count; i++) {
    printf("%" PRIu16 ") %s\n", i, menu->items[i]);
  }
  putchar('\n');

  uint16_t selection = 0;
  printf(") ");
  scanf("%i", &selection);

  while (selection > menu->count) {
    puts("Selection Too High!");
    printf(") ");
    scanf("%i", &selection);
  }

  return selection;
}
