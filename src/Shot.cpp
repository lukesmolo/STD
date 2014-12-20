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


#include<string>
#include<cstring>
#include<sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Shot.h"
#include "Config.h"
#include "utils.h"


using namespace std;

void Shot::draw(){
    GraphicPrimitives::drawLine2D(pos.x, pos.y, pos.x + SHOT_WIDTH, pos.y, 1.0f, 1.0f, 1.0f, 0.0);
}


void Shot::tick(){
	pos.x += speed;
	if (pos.x > 1.0f || pos.x < -1.0f) {
		died = true;
	}
	update_pos();
}

void Shot::update_pos() {
	//no need to update line and orizonatal information
	return_ncell(&pos, RW_CELL);
	return_v_lines(&pos, RW_CELL);
}
