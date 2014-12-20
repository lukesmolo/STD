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


#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "BLine.h"
#include "Config.h"
#include "Observer.h"
#include "Asteroid.h"
#include "Game.h"


int
main(int argc, char * argv[]) {
	
	int i = 0;
	Game game;
	std::vector<Spaceship*> ships;
	std::vector<BLine *> Blines;
	//create the number of Bline objects according to Config.h file
	for(i = 0; i< N_LINES; i++) {
		Blines.push_back(new BLine(N_CELLS, game.window_width/(Blines.size()+1), game.window_height/N_CELLS, Blines.size()));
	}
	Observer* obs = new Observer(&game, &ships, &Blines);
	GraphicEngine * ge = new MyGraphicEngine(&game, &ships, &Blines);
	GameEngine * gme = new MyGameEngine(&game, &ships, &Blines, obs);
	ControlEngine * ce = new MyControlEngine(&game, &ships, &Blines);


	Engine e(argc,argv, game.window_width, game.window_height);
	e.setGraphicEngine(ge);
	e.setGameEngine(gme);
	e.setControlEngine(ce);

	e.start();
	return 0;
}
