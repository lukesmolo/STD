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
#include "Config.h"
#include "GraphicPrimitives.h"
#include "utils.h"
#include <vector>

using namespace std;

class Shot {

	public:

		Shot(point *pos_ = NULL, float speed_ = SHOT_SPEED):
			width(SHOT_WIDTH),
			height(SHOT_HEIGHT),
			died(false) {
				if(pos_ != NULL) {
					memcpy(&pos, pos_, sizeof(struct point));
				speed = speed_;
				if(speed == -SHOT_SPEED)
				pos.x -= SHIP_WIDTH/2;  //start the shot from the right of its ships
				else
				pos.x += SHIP_WIDTH/2;  //start the shot from the right of its ships
				}
			}

		float width, height;
		float rgba[4];
		int id_number;
		bool died;
		struct point pos;
		float fire_rate;
		float speed;
		float power;

		void draw();
		void tick();
		void update_pos();

};
