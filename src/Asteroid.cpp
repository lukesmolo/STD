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
#include "Asteroid.h"

using namespace std;


void Asteroid::draw(){
	float r, g, b, a;
	r = 0.8;
	g = 0.8;
	b = 0.8;
	a = 1.0;
		GraphicPrimitives::drawLine2D(pos.x-ASTEROID_WIDTH/4, pos.y,pos.x+ASTEROID_WIDTH/4, pos.y, r, g, b, a);
		GraphicPrimitives::drawLine2D(pos.x-ASTEROID_WIDTH/4, pos.y+ASTEROID_HEIGHT/2,pos.x+ASTEROID_WIDTH/4, pos.y-ASTEROID_HEIGHT/2, r, g, b, a);
		GraphicPrimitives::drawLine2D(pos.x, pos.y+ASTEROID_HEIGHT/2,pos.x, pos.y-ASTEROID_HEIGHT/2, r, g, b, a);

		GraphicPrimitives::drawLine2D(pos.x+ASTEROID_WIDTH/4, pos.y+ASTEROID_HEIGHT/2,pos.x-ASTEROID_HEIGHT/4, pos.y-ASTEROID_HEIGHT/2, r, g, b, a);
		GraphicPrimitives::drawLine2D(pos.x+ASTEROID_WIDTH/4, pos.y+ASTEROID_HEIGHT/4,pos.x-ASTEROID_HEIGHT/4, pos.y-ASTEROID_HEIGHT/4, r, g, b, a);
		GraphicPrimitives::drawLine2D(pos.x-ASTEROID_WIDTH/4, pos.y+ASTEROID_HEIGHT/4,pos.x+ASTEROID_HEIGHT/4, pos.y-ASTEROID_HEIGHT/4, r, g, b, a);
}


void Asteroid::tick(){


	pos.x -= speedX; //change X speed
	if (pos.x - width/4 < -1.0f) {
		win = true;
		died = true;
	}
	if (pos.x + width/4 >= 1.0f) {
		speedX = -speedX;
		pos.x += speedX;

	}

	//vertical movement
	pos.y += speedY; //change Y speed
	if (pos.y + height/2 > 1.0f || pos.y - height/2 < -1.0f ) {
		speedY = -speedY;
		pos.y += speedY;
	}
	update_pos();
}

void Asteroid::update_pos() {
	update_position(&pos);
}
