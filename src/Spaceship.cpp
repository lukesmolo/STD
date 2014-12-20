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
#include "Spaceship.h"
#include "Shot.h"

using namespace std;


float white[4] = {1, 1, 1, 0};
float green[4] = {0, 1, 0, 1};
float red[4] = {1, 0, 0, 1};

void Spaceship::draw(){
	GraphicPrimitives::drawFillRect2D(posX,posY,width,height,rgba[0],rgba[1],rgba[2], rgba[3]);
	Shot *tmp = NULL;
	if(toleft) {
		tmp = new Shot(&pos,-SHOT_SPEED);
	} else {
		tmp = new Shot(&pos);
	}
	if(freq%fire_rate == 0) {
		shots.push_back(tmp);
		freq = 0;
	}
	freq++;
}

void Spaceship::properties_assign() {
int i = 0;
	switch(type) {
		case SNOW_SHIP:
			life = SNOW_SHIP_LIFE;
			speed = SNOW_SHIP_SPEED;
			for(i = 0; i < 4; i++) {
				rgba[i] = white[i];
			}
			fire_rate = SNOW_SHIP_FIRE_RATE;
			break;
		case GRASS_SHIP:
			life = GRASS_SHIP_LIFE;
			speed = GRASS_SHIP_SPEED;
			for(i = 0; i < 4; i++) {
				rgba[i] = green[i];
			}
			fire_rate = GRASS_SHIP_FIRE_RATE;
			break;
		case BLOOD_SHIP:
			life = BLOOD_SHIP_LIFE;

			speed = BLOOD_SHIP_SPEED;
			for(i = 0; i < 4; i++) {
				rgba[i] = red[i];
			}
			fire_rate = BLOOD_SHIP_FIRE_RATE;
			break;
		default:
			break;
	}

}


void Spaceship::tick(){

	//vertical movement
	posY += speed; //change speed
	pos.y += speed;	

	if (posY + height > pos.o_lines[1] || posY < pos.o_lines[0] ) {
		speed = -speed;
		posY += speed;
	}
}


void
Spaceship::change_shot_direction(int counter){
	if(counter >= NUM_ASTEROIDS_BEHIND)
		toleft = true;
	else
		toleft = false;
}
