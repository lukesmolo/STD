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
#include "Asteroid.h"
#include "utils.h"
#include "Config.h"
#include "GraphicPrimitives.h"
#include <vector>


using namespace std;

class Wave {

	public:
		Wave(int number_asteroids_):
			number_asteroids(number_asteroids_*ASTEROIDS_IN_WAVE),
			freq(FREQ_ASTEROIDS_IN_WAVE) {
			create_asteroids();	
			}

		int number_asteroids;
		int freq;
		std::vector<Asteroid*> Asteroids;

		void create_asteroids();	

};
