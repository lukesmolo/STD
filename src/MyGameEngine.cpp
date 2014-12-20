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


#include "MyGameEngine.h"
#include "Observer.h"
#include <unistd.h>

void MyGameEngine::idle(){

	if(!game->pause) {
		observer->detect_problems();	
		observer->manage_deaths();	
		for (int i = 0; i < (int)ships->size(); i++) {
			(*ships)[i]->tick();
			for(int y = 0; y < (int)((*ships)[i])->shots.size(); y++)
				((*ships)[i])->shots[y]->tick();
		}
		if(game->wave!=NULL) {
			game->wave->create_asteroids();
			for (int i = 0; i < (int)game->wave->Asteroids.size(); i++) {
				game->wave->Asteroids[i]->tick();
			}
		}
	}
}
