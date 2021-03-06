/* 
Copyright (C) 2018 Microsoft Corporation

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <string.h>
#include "frotz.h"
#include "games.h"
#include "frotz_interface.h"

// Trinity: http://ifdb.tads.org/viewgame?id=j18kjz80hxjtyayw

const char *trinity_intro[] = { "\n" };

char** trinity_intro_actions(int *n) {
  *n = 1;
  return trinity_intro;
}

char* trinity_clean_observation(char* obs) {
  return obs+2;
}

int trinity_victory() {
  char *death_text = "****  You have won  ****";
  if (strstr(world, death_text)) {
    return 1;
  }
  return 0;
}

int trinity_game_over() {
  char *death_text = "[Type RESTART, RESTORE or QUIT.]";
  if (strstr(world, death_text)) {
    return 1;
  }
  return 0;
}

int trinity_get_self_object_num() {
  return 103;
}

int trinity_get_moves() {
  return (((short) zmp[34172]) << 8) | zmp[34173];
}

int trinity_get_score() {
  return zmp[34215];
}

int trinity_max_score() {
  return 60;
}

int trinity_get_num_world_objs() {
  return 593;
}

int trinity_ignore_moved_obj(zword obj_num, zword dest_num) {
  if (dest_num == 483)
    return 1;
  return 0;
}

int trinity_ignore_attr_diff(zword obj_num, zword attr_idx) {
  return 0;
}

int trinity_ignore_attr_clr(zword obj_num, zword attr_idx) {
  return 0;
}
