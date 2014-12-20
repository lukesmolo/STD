/*
 * Copyright (C) 2014 Luca Sciullo
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#pragma once
typedef struct point {
	float x;
	float y;
	int nLine;
	int ncell;
	float v_lines[2];
	float o_lines[2];
} point;

float return_random(float x, float x1);
void return_nBline(point *pos, float rh_cell);
void return_ncell(point *pos, float rw_cell);
void return_v_lines(point *pos, float rw_cell);
void return_o_lines(point *pos, float rh_cell);
void update_position(point *pos);
void print_pos(point *pos);

