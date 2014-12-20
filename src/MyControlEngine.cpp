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


#include <stdio.h>
#include "MyControlEngine.h"
#include "Config.h"
#include "utils.h"

using namespace std;

/*return if it is possible put a ship into a cell*/
bool
check_cell(point *p,std::vector<BLine*> *Blines ) {
	bool *check = (*Blines)[p->nLine]->ships_in_cells;
	if(check[p->ncell])
		return false;
	else {
		return true;
	}
}


/*check if it's possible drawing where there was the click.
  All calculations are made by using the relative measures*/
void
check_point(point *p, float width, float heigth) {
	float epsilon = 0.01;	//small value to divide ships from lines
	float v_line;
	float o_line;

	//check x

	float m_board = p->x + width;
	v_line = -1;
	while((v_line < p->x || v_line >= m_board) && v_line <= m_board) { /*for each o_line drawn, check if there exits an intersection with the point*/
		v_line+=RW_CELL;
	}

	if( v_line > p->x && v_line <= m_board) {
		float mid = (p->x +(width/2));
		if(mid > v_line) { //choose which half has to be used
			p->x = v_line+epsilon+(width/2);
		} else {

			p->x = v_line-epsilon-(width/2);
		}
	} else
		p->x = p->x +(SHIP_WIDTH/2); //return the original x

	float rh_cell = RH_CELL;

	//check y
	m_board = p->y + (heigth);

	o_line = -1;
	while((o_line < p->y || o_line >= m_board) && o_line <= m_board) { /*for each o_line drawn, check if there exits an intersection with the point*/
		o_line+=rh_cell;
	}

	if(o_line <= m_board) {
		float mid = (p->y +(heigth/2));
		if(mid > o_line) { //choose which half has to be used
			p->y = o_line+epsilon+(heigth/2);
		} else {
			p->y = o_line-epsilon-(heigth/2);
		}
	} else
		p->y = p->y +(SHIP_HEIGHT/2); //return the original y


	//put the number of line and cell inside p
	return_nBline(p, RH_CELL);
	return_ncell(p, RW_CELL);
}

void MyControlEngine::MouseCallback(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		point *p = new point;
		//turn absolute coordinates into board coordinates
		p->x = (float)(x-(game->window_width/2)) / (game->window_width/2);
		p->y = (float)(y-(game->window_height/2))/ - (game->window_height/2);

		//turn coordinates of center into coordinates of a vertex
		p->x -= (SHIP_WIDTH/2);
		p->y -= (SHIP_HEIGHT/2);


		//prepare coordinates to be checked. Return the new coordinates of centre
		check_point(p, SHIP_WIDTH, SHIP_HEIGHT);
		if(check_cell(p, Blines) && game->check_enough_score(game->ship_type)) {
			//return the lines and the cell values in which the ship is
			return_v_lines(p, RW_CELL);
			return_o_lines(p, RH_CELL);
			//set the cell busy
			(*Blines)[p->nLine]->ships_in_cells[p->ncell] = true;
			//need to pass the coordinates of vertex, not of center
				//print_pos(p);
			ships->push_back(new Spaceship(p->x - (SHIP_WIDTH/2), p->y - (SHIP_HEIGHT/2), p, 0, game->ship_type)); //draw the ships starting from the middle
			game->update_n_ships(ships->size());
			delete p;
		}

	}
}


void MyControlEngine::KeyboardCallback(unsigned char key, int x, int y){
	if(key == 'a'  && game->wave == NULL) {
		point *p = new point;
		//turn absolute coordinates into board coordinates
		p->x = (float)(x-(game->window_width/2)) / (game->window_width/2);
		p->y = (float)(y-(game->window_height/2))/ - (game->window_height/2);
		game->wave = new Wave(game->level);
		game->n_asteroids = game->wave->number_asteroids;
		printf("Level: %d\n", game->level);

	} else if(key == 'p') {
		game->pause = ! game->pause;

	} else if(key == 'h') {
		game->pause = true;

	} else if(key == 'q') {
		game->ship_type = SNOW_SHIP;
	} else if(key == 'w') {
		game->ship_type = GRASS_SHIP;
	} else if(key == 'e') {
		game->ship_type = BLOOD_SHIP;
	} else if(key == 'r' && game->game_over) {
		game->reset();	
	}

}


