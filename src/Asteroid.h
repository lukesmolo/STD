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
#include <vector>
#include "GraphicPrimitives.h"
#include "Config.h"
#include "utils.h"
#include "Shot.h"


class Asteroid{

	public:

		Asteroid( struct point *pos_ = NULL , int id_number_ = 0, float speed_ = ASTEROID_SPEED):
			id_number(id_number_),
			speedX(ASTEROID_SPEED),
			speedY(speed_),
			width(ASTEROID_WIDTH),
			height(ASTEROID_HEIGHT),
			freq(0),
			died(false),
			win(false) {
			if(pos_ != NULL)
			memcpy(&pos, pos_, sizeof(struct point));
		}



		struct point pos;
		int id_number;
		float speedX;
		float speedY;
		
		float width,height;
		float rgba[4];
		int fire_rate;
		int freq;

		float power;
		bool died;
		bool win;


		void draw();
		void tick();
		void update_pos();


};
