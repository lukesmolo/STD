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


#include<iostream>
#include <unistd.h>
#include "Wave.h"
#include "utils.h"
using namespace std;

static int counter = 0;
void
Wave::create_asteroids() {

	if((counter < number_asteroids) && freq==0) {
		float speed;
		point *pos = new point;
		// x position has to be at the grid border
		pos->x = 0.95;
		// y position has to be in an accetable range
			pos->y = return_random(0.8, -0.8);
			if(return_random(1.0, -1.0) > 0)
				speed = 1;	
			else
				speed = -1;

			Asteroids.push_back(new Asteroid(pos, 0, ASTEROID_SPEED*speed));
		delete pos;
		pos = NULL;
		number_asteroids--;
		freq = FREQ_ASTEROIDS_IN_WAVE;

	}
	else
		freq--;

}
