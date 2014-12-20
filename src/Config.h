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
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define N_LINES 4
#define N_CELLS 10
#define RW_CELL (float) 2.0/N_CELLS
#define RH_CELL (float) 2.0/N_LINES
#define SHIP_WIDTH	0.1f
#define SHIP_HEIGHT	SHIP_WIDTH*(WINDOW_WIDTH/WINDOW_HEIGHT)
#define SNOW_SHIP 0
#define GRASS_SHIP 1
#define BLOOD_SHIP 2
#define SNOW_SHIP_LIFE 1
#define SNOW_SHIP_FIRE_RATE 70
#define SNOW_SHIP_SPEED 0.05
#define SNOW_SHIP_COST 30
#define GRASS_SHIP_LIFE 2
#define GRASS_SHIP_FIRE_RATE 30
#define GRASS_SHIP_SPEED 0.03
#define GRASS_SHIP_COST 50
#define BLOOD_SHIP_LIFE 3
#define BLOOD_SHIP_FIRE_RATE 90
#define BLOOD_SHIP_SPEED 0.02
#define BLOOD_SHIP_COST 70


#define SHOT_WIDTH 0.02f
#define SHOT_HEIGHT 0.02f
#define SHOT_SPEED 0.02f

#define ASTEROID_WIDTH 0.18f
#define ASTEROID_HEIGHT 0.18f
#define ASTEROID_SPEED 0.008f

#define START_SCORE 150
#define START_LEVEL 1
#define SCORE_HIT 30
#define SCORE_COLLISION -50
#define SCORE_ASTEROIDS -250

#define ASTEROIDS_IN_WAVE 4
#define FREQ_ASTEROIDS_IN_WAVE 10

#define NUM_ASTEROIDS_BEHIND 2
#define SEC_ASTEROIDS_BEHIND 2
