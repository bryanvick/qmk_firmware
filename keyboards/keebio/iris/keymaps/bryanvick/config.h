/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define EE_HANDS

#define NKRO_ENABLE

#define ONESHOT_TAP_TOGGLE 2
#define ONEHOT_TIMEOUT 5000

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY


// Mouse keys
// Not currently using, but these settings work well.
//#define MOUSEKEY_INTERVAL 16
//#define MOUSEKEY_DELAY 0
//#define MOUSEKEY_TIME_TO_MAX 60
//#define MOUSEKEY_MAX_SPEED 7
//#define MOUSEKEY_WHEEL_DELAY 0

// The number of key combinations defined in keymap.
#define COMBO_COUNT 25

// Keys in combo need to be input within this many milliseconds to register as a
// combination.
#define COMBO_TERM 20
