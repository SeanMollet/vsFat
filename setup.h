/*
 * vsfat - virtual synthetic FAT filesystem on network block device from local folder
 * Copyright (C) 2017 Sean Mollet
 *
 * This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "vsfat.h"

//These two settings adjust the size of the syn-disk
// SecPerClus	Disk Size (G)
// 1		0.5
// 2		2
// 4		8
// 8		32
// 16		128
// 32		512
// 64		2048

#define Fat32_Sectors_per_Cluster 32

//8192 = 2Tb with 64 Sec/Clus
//Subtract 3 for the reserved area and space taken by fats
//Practical maximum is 8189

#define FAT32_FAT_Table_Length 8189

void build_root_dir();
void build_mbr();
uint32_t build_boot_sector(BootEntry *bootentry, int xmpl_debug);
static const uint32_t part1_base = 1048576;
void build_fats();