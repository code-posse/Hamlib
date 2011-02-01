/*
 *  Hamlib Elecraft backend--support extensions to Kenwood commands
 *  Copyright (C) 2010 by Nate Bargmann, n0nb@n0nb.us
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 */

#ifndef _ELECRAFT_H
#define _ELECRAFT_H 1

#include "hamlib/rig.h"

/* The Elecraft Programmer's Reference details the extension level that
 * a K2 or K3 may have in effect which modify certain commands.
 */

#define EXT_LEVEL_NONE -1

enum elec_ext_id_e {
	K20 = 0,	/* K2 Normal mode */
	K21,		/* K2 Normal/rtty_off */
	K22,		/* K2 Extended mode */
	K23,		/* K2 Extended mode/rtty_off */
	K30,		/* K3 Normal mode */
	K31			/* K3 Extended mode */
};

struct elec_ext_id_str {
	enum elec_ext_id_e level;
	const char *id;
};

/* Data sub-modes are provided from the K3 via the DT command */
enum k3_data_submodes_e {
	K3_MODE_DATA_A = 0,		/* DT0; */
	K3_MODE_AFSK_A,			/* DT1; */
	K3_MODE_FSK_D,			/* DT2; */
	K3_MODE_PSK_D			/* DT3; */
};


/* Private tokens used for ext_lvl function in Elecraft backends.  
 * Extra levels which are rig specific should be coded in
 * the individual rig files and token #s >= 101.
 */
#define TOK_IF_FREQ TOKEN_BACKEND(101)    /* K3 FI command */
#define TOK_TX_STAT TOKEN_BACKEND(102)    /* K3 TQ command */

/* Token structure assigned to .cfgparams in rig_caps */
extern const struct confparams elecraft_ext_levels[];


/* Elecraft extension function declarations */
int elecraft_open(RIG *rig);


#endif /* _ELECRAFT_H */