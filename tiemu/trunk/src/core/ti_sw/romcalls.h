/* Hey EMACS -*- linux-c -*- */
/* $Id$ */

/*  TiEmu - an TI emulator
 *
 *  Copyright (c) 2000, Thomas Corvazier, Romain Lievin
 *  Copyright (c) 2001-2002, Romain Lievin, Julien Blache
 *  Copyright (c) 2003-2004, Romain Li�vin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
  Breakpoint definitions
*/

#ifndef __ROMCALLS__
#define __ROMCALLS__

#include <stdio.h>
#include <stdint.h>

#include "romcalls.h"

#define NMAX_ROMCALLS	0x800

/* Types */

typedef struct
{
	int			id;
    uint32_t    addr;
    char*       name;
} ROM_CALL;

/* Functions */

int romcalls_load_from_file(const char* filename);
int romcalls_unload(void);
int romcalls_is_loaded(void);

int romcalls_is_address(uint32_t addr);
int romcalls_is_name(const char *name);

int romcalls_get_id(int i);
const char* romcalls_get_name(int i);
uint32_t romcalls_get_addr(int i);
const char* romcalls_get_addr_name(uint32_t addr);

ROM_CALL *romcalls_sort_by_id(void);
ROM_CALL *romcalls_sort_by_addr(void);
ROM_CALL *romcalls_sort_by_name(void);

int romcalls_get_size(void);

void romcalls_get_table_infos(uint32_t *addr, uint32_t *size);

#endif