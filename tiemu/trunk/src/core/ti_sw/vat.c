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
    Variable Allocation Table access routines
*/

#include <stdio.h>

#include "ti68k_def.h"
#include "ti68k_int.h"

#include "handles.h"
#include "vat.h"

typedef struct 
{
	char name[8]; 
	uint16_t compat; 
	union { 
		uint16_t flags_n; 
		struct { 
			uint16_t busy : 1, local : 1, flag1_5 : 1, flag1_4 : 1, collapsed : 1, twin : 1, archived : 1, in_view : 1; 
			uint16_t folder : 1, overwritten : 1, checked : 1, hidden : 1, locked : 1, statvar : 1, graph_ref_1 : 1, graph_ref_0 : 1; 
		} bits; 
	} flags; 
	uint16_t handle; 
} TI89_SYM_ENTRY;

typedef struct 
{ 
	uint16_t folder; 
	uint16_t offset; 
} TI89_HSym;


// AMS 1 only
int parse_vat_89(GNode *node_top)
{
	uint32_t fa, va, pa;
	uint16_t fs, vs, ps;
	int nfolders, nvars;
	int i, j;
	VatSymEntry *vse;
	GNode *node_fol, *node_var;

	if(tihw.calc_type == TI92)
		return -1;

	if(strcmp(img_infos.version, "2.00") >= 0)
		return -1;

	// handle: names and handles of all folders (including "main")
	heap_get_block_addr_and_size(0x8, &fa, &fs);

	// skip maximum number of folders before handle #$B needs to be resized
	// and actual number of folders 
	printf("# folder: %i\n", nfolders = mem_rd_word(fa+2));	
	fa += 4;

	// now, we read a list of SYM_ENTRY structs (list of folders)
	for(i=0; i<nfolders; i++)
	{
		TI89_SYM_ENTRY se;
		
		// read struct
		memcpy(&se, ti68k_get_real_address(fa + i * sizeof(TI89_SYM_ENTRY)), sizeof(TI89_SYM_ENTRY));
		se.handle = GUINT16_FROM_BE(se.handle);
		printf("folder name: <%s>\n", se.name);

		// add node
		vse = g_malloc0(sizeof(VatSymEntry));
		strcpy(vse->name, se.name);	vse->handle = se.handle;
		g_node_append(node_top, node_fol = g_node_new(vse));

		// handle xxxx: names and handles of all variables
		heap_get_block_addr_and_size(se.handle, &va, &vs);

		// skip max num and actual num of vars
		printf("# vars: %i\n", nvars = mem_rd_word(va+2));	
		va += 4;

		for(j=0; j<nvars; j++)
		{
			TI89_SYM_ENTRY se;

			// read struct
			memcpy(&se, ti68k_get_real_address(va + j * sizeof(TI89_SYM_ENTRY)), sizeof(TI89_SYM_ENTRY));
			se.handle = GUINT16_FROM_BE(se.handle);
			printf("var name: <%s>\n", se.name);

			// add node
			vse = g_malloc0(sizeof(VatSymEntry));
			strcpy(vse->name, se.name);	vse->handle = se.handle;
			g_node_append(node_fol, node_var = g_node_new(vse));

			// handle: variable content
			heap_get_block_addr_and_size(se.handle, &pa, &ps);
			{
				uint16_t varsize = mem_rd_word(pa);
				uint8_t vartype = mem_rd_byte(pa + varsize + 1);

				printf("var size = %i, var type = %02x\n", varsize, vartype);
			}		
		}
	}

	return 0;
}

/*
	An excellent doc on VAT: http://doors.ticalc.org/tips.htm#VAT
*/

typedef struct 
{
	char name[9]; 
	uint8_t state;
	uint16_t handle; 
} TI92_SYM_ENTRY;

// tested: OK.
int parse_vat_92(GNode *node_top)
{
	uint32_t fa, va, pa;
	uint16_t fs, vs, ps;
	int nfolders, nvars;
	int i, j;
	VatSymEntry *vse;
	GNode *node_fol, *node_var;

	if(tihw.calc_type != TI92)
		return -1;

	// handle 000B:	names and handles of all folders (including "main")
	heap_get_block_addr_and_size(0xb, &fa, &fs);

	// skip maximum number of folders before handle #$B needs to be resized
	// and actual number of folders 
	printf("# folder: %i\n", nfolders = mem_rd_word(fa+2));	
	fa += 4;

	// now, we read a list of SYM_ENTRY structs (list of folders)
	for(i=0; i<nfolders; i++)
	{
		TI92_SYM_ENTRY se;
		
		// read struct
		memcpy(&se, ti68k_get_real_address(fa + i * sizeof(TI92_SYM_ENTRY)), sizeof(TI92_SYM_ENTRY));
		se.handle = GUINT16_FROM_BE(se.handle);
		printf("folder name: <%s>\n", se.name);

		// add node
		vse = g_malloc0(sizeof(VatSymEntry));
		strcpy(vse->name, se.name);	vse->handle = se.handle;
		g_node_append(node_top, node_fol = g_node_new(vse));

		// handle xxxx: names and handles of all variables
		heap_get_block_addr_and_size(se.handle, &va, &vs);

		// skip max num and actual num of vars
		printf("# vars: %i\n", nvars = mem_rd_word(va+2));	
		va += 4;

		for(j=0; j<nvars; j++)
		{
			TI92_SYM_ENTRY se;

			// read struct
			memcpy(&se, ti68k_get_real_address(va + j * sizeof(TI92_SYM_ENTRY)), sizeof(TI92_SYM_ENTRY));
			se.handle = GUINT16_FROM_BE(se.handle);
			printf("var name: <%s>\n", se.name);

			// add node
			vse = g_malloc0(sizeof(VatSymEntry));
			strcpy(vse->name, se.name);	vse->handle = se.handle;
			g_node_append(node_fol, node_var = g_node_new(vse));

			// handle: variable content
			heap_get_block_addr_and_size(se.handle, &pa, &ps);
			{
				uint16_t varsize = mem_rd_word(pa);
				uint8_t vartype = mem_rd_byte(pa + varsize + 1);

				printf("var size = %i, var type = %02x\n", varsize, vartype);
			}		
		}
	}

	return 0;
}

/*
	Allocate and create a tree
*/
int vat_parse(GNode **tree)
{
	VatSymEntry *vse;

	if(tree == NULL)
		return -1;

	vse = g_malloc0(sizeof(VatSymEntry));
	strcpy(vse->name, "home");
	*tree = g_node_new(vse);
	printf("vse: %p\n", vse);

	if(tihw.calc_type == TI92)
		parse_vat_92(*tree);
	else
		parse_vat_89(*tree);

	return 0;
}

static gboolean free_vse(GNode *node, gpointer data)
{
	if (node) 
		g_free(node->data);
	return FALSE;
}

/*
	Free a previously allocated tree
*/
int vat_free(GNode **tree)
{
	if (*tree != NULL) 
	{
	    g_node_traverse(*tree, G_IN_ORDER, G_TRAVERSE_ALL, -1, free_vse, NULL);
		g_node_destroy(*tree);
		*tree = NULL;
	}

	return 0;
}