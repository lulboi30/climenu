/*
 * Copyright (c) 2026 lulboi30.
 * SPDX-License-Identifier: MIT
 */

#ifndef CLIMENU_H
#define CLIMENU_H 1

#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char **items;
  uint16_t count;
} climenu_t;

extern uint16_t menuselect(climenu_t* menu);
extern climenu_t *newmenu();
extern void additem(climenu_t* menu, char *item);
extern void freemenu(climenu_t *menu);

#endif
