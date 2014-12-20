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


class Spaceship{

	public:
		Spaceship(float posX_ = 0.0f,float posY_ = 0.0f, struct point *pos_ = NULL , int id_number_ = 0, int type_ = SNOW_SHIP, float fire_rate_ = SNOW_SHIP_FIRE_RATE, float speed_ = SNOW_SHIP_SPEED, float life_ = SNOW_SHIP_LIFE):
			posX(posX_),
			posY(posY_),
			width(SHIP_WIDTH),
			height(SHIP_HEIGHT),
			id_number(id_number_),
			type(type_),
			fire_rate(fire_rate_),
			freq(0),
			speed(speed_),
			life(life_),
			died(false),	
			toleft(false) {	
				if(pos_ != NULL)
					memcpy(&pos, pos_, sizeof(struct point));
				properties_assign();
			}

		float posX,posY; //positions of vertex for drawing
		float width,height;
		float rgba[4];	//color of ship
		int id_number;	//number of ship in the game
		int type;
		struct point pos; //information about the center of the ship
		int fire_rate;
		int freq;	//counter for fire_rate
		float speed; //speed of movement
		float life; //counter for spaceship life
		float died; //flag for spaceship dead
		float toleft; //flag for shooting on the left

		std::vector<Shot*> shots;

		void draw();
		void properties_assign();
		void tick();
		void change_shot_direction(int counter);
};
