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


#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Config.h"
#include "utils.h"
#include "ctime"

using namespace std;


float
return_random(float x, float x1) {
	//return a random value between x and x1;	
	float tmp = x + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/((x1)-(x))));
	return tmp;
}



void
return_nBline(point *pos, float heigth) {
	int counter = 0;
	float line = -1;
	while((counter < N_LINES) && (line + heigth) < pos->y) {
		counter++;
		line += heigth;
	}
	pos->nLine = counter;
}

void
return_ncell(point *pos, float width) {
	int counter = 0;
	float line = -1;
	while((counter < N_CELLS) && (line + width) < pos->x) {
		counter++;
		line += width;
	}
	pos->ncell = counter;
}


void
return_o_lines(point *p, float rh_cell) {
	float tmp = -1.0f;

	while((tmp + rh_cell) < p->y) {
		tmp += rh_cell;
	}
	p->o_lines[0] = tmp;
	p->o_lines[1] = tmp + rh_cell;
}



void
return_v_lines(point *p, float rw_cell) {
	float tmp = -1.0f;

	while((tmp + rw_cell) < p->x) {
		tmp += rw_cell;
	}
	p->v_lines[0] = tmp;
	p->v_lines[1] = tmp + rw_cell;
}

void
print_pos(point *pos) {
	printf("x position is: %f\n", pos->x);
	printf("y position is: %f\n", pos->y);
	printf("nLine is: %d\n", pos->nLine);
	printf("ncell is: %d\n", pos->ncell);
	printf("vertical lines are: %f %f\n", pos->v_lines[0], pos->v_lines[1]);
	printf("orizontal lines are: %f %f\n", pos->o_lines[0], pos->o_lines[1]);
}


void
update_position(point *pos) {
	return_ncell(pos, RW_CELL);
	return_nBline(pos, RH_CELL);
	return_o_lines(pos, RH_CELL);
	return_v_lines(pos, RW_CELL);

}
