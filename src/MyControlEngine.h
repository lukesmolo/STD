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
#include "Engine.h"
#include "Spaceship.h"
#include "BLine.h"
#include "Asteroid.h"
#include "Game.h"

class MyControlEngine:public ControlEngine {

	Game *game;
	std::vector<Spaceship * > *ships;
	std::vector<BLine *> *Blines;
	public:
	MyControlEngine(Game *game_, std::vector<Spaceship * > * ships_, std::vector<BLine * > * Blines_):
		game(game_),
		ships(ships_),
		Blines(Blines_){}

	virtual void MouseCallback(int button, int state, int x, int y) ;
	virtual void KeyboardCallback(unsigned char key, int x, int y) ;
};
