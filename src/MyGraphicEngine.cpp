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


#include "MyGraphicEngine.h"

using namespace std;

void MyGraphicEngine::Draw(){
	if(!game->pause && ! game->game_over) {
		int shot_counter = 0;
		for (int i = 0; i < (int)Blines->size(); i++) {
			(*Blines)[i]->draw();
		}
		for (int i = 0; i < (int)ships->size(); i++) {
			(*ships)[i]->draw();

			for(int y = 0; y < (int)((*ships)[i])->shots.size(); y++) {
				((*ships)[i])->shots[y]->draw();
				shot_counter += ((*ships)[i])->shots.size();
			}


		}

		if(game->wave!=NULL)
			for (int i = 0; i < (int)game->wave->Asteroids.size(); i++) {
				game->wave->Asteroids[i]->draw();
			}

		game->draw();
		//since the ship can create a shot only in its draw, we need to update n_shot from here
		game->update_n_ships(ships->size());
		game->update_n_shots(shot_counter);
		if(game->wave != NULL)
			game->update_n_asteroids(game->wave->number_asteroids);

	} else if(game->pause) {
		game->pause_draw();
	} else if(game->game_over) {
		game->game_over_draw();
	}
}


void
MyGraphicEngine::reshape(int width, int height) {
	game->window_width = width;
	game->window_height = height;
}

