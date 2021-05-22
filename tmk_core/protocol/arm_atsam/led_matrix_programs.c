/*
Copyright 2018 Massdrop Inc.

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

#ifdef USE_MASSDROP_CONFIGURATOR

#include "led_matrix.h"

//Teal <-> Salmon
led_setup_t leds_teal_salmon[] = {
    { .hs = 0,  .he = 33,  .rs = 24,  .re = 24,  .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_NONE },
    { .hs = 33, .he = 66,  .rs = 24,  .re = 255, .gs = 215, .ge = 114, .bs = 204, .be = 118, .ef = EF_NONE },
    { .hs = 66, .he = 100, .rs = 255, .re = 255, .gs = 114, .ge = 114, .bs = 118, .be = 118, .ef = EF_NONE },
    { .end = 1 },
};

//Yellow
led_setup_t leds_yellow[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Off
led_setup_t leds_off[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Red
led_setup_t leds_red[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Green
led_setup_t leds_green[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Blue
led_setup_t leds_blue[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 255, .be = 255, .ef = EF_NONE },
    { .end = 1 },
};

//White
led_setup_t leds_white[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE },
    { .end = 1 },
};

//White with moving red stripe
led_setup_t leds_white_with_red_stripe[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE },
    { .hs = 0, .he = 15, .rs = 0, .re = 0, .gs = 0, .ge = 255, .bs = 0, .be = 255, .ef = EF_SCR_R | EF_SUBTRACT },
    { .hs = 15, .he = 30, .rs = 0, .re = 0, .gs = 255, .ge = 0, .bs = 255, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT },
    { .end = 1 },
};

//Black with moving red stripe
led_setup_t leds_black_with_red_stripe[] = {
    { .hs = 0, .he = 15, .rs = 0, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R },
    { .hs = 15, .he = 30, .rs = 255, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R },
    { .end = 1 },
};

//Rainbow no scrolling
led_setup_t leds_rainbow_ns[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER },
    { .end = 1 },
};

//Rainbow scrolling
led_setup_t leds_rainbow_s[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

// Teal Salmon Scroll

led_setup_t leds_teal_salmon_s3[] = {
    { .hs = 0,  .he = 50,  .rs = 24,  .re = 24,  .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_SCR_R },
    { .hs = 25, .he = 50,  .rs = 24,  .re = 255, .gs = 215, .ge = 114, .bs = 204, .be = 118, .ef = EF_SUBTRACT | EF_SCR_R },
    { .hs = 50, .he = 100,  .rs = 255, .re = 255, .gs = 114, .ge = 114, .bs = 118, .be = 118, .ef = EF_SCR_R },
    { .hs = 75, .he = 100, .rs = 255, .re = 24,  .gs = 114, .ge = 214, .bs = 118, .be = 204, .ef = EF_SUBTRACT | EF_SCR_R },
    { .end = 1 },
};


led_setup_t leds_subt_ex_s[] = {
    { .hs = 0,  .he = 100,  .rs = 128,  .re = 128,  .gs = 128, .ge = 128, .bs = 128, .be = 128},
    { .hs = 25, .he = 50,   .rs = 0,    .re = 0,    .gs = 128, .ge = 0,   .bs = 128, .be = 0, .ef = EF_SUBTRACT | EF_SCR_R },
    { .hs = 75, .he = 100,  .rs = 128,  .re = 0,    .gs = 0,   .ge = 0,   .bs = 0,   .be = 0, .ef = EF_SUBTRACT | EF_SCR_R }
};
// TS Scroll 2
led_setup_t leds_teal_salmon_s2[] = {
    { .hs = 0, .he = 8,	    .rs = 255, 	.re = 255, 	.gs = 92, 	.ge = 92, 	.bs = 96, 	.be = 96, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 8, .he = 13,	.rs = 255, 	.re = 226, 	.gs = 92, 	.ge = 106, 	.bs = 96, 	.be = 110, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 13, .he = 18,	.rs = 226, 	.re = 197, 	.gs = 106, 	.ge = 120, 	.bs = 110, 	.be = 124, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 18, .he = 24,	.rs = 197, 	.re = 168, 	.gs = 120, 	.ge = 134, 	.bs = 124, 	.be = 138, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 24, .he = 30,	.rs = 168, 	.re = 139, 	.gs = 134, 	.ge = 148, 	.bs = 138, 	.be = 152, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 30, .he = 35,	.rs = 139, 	.re = 110, 	.gs = 148, 	.ge = 162, 	.bs = 152, 	.be = 166, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 35, .he = 40,	.rs = 110, 	.re = 81, 	.gs = 162, 	.ge = 176, 	.bs = 166, 	.be = 180, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 40, .he = 45,	.rs = 81, 	.re = 52, 	.gs = 176, 	.ge = 190, 	.bs = 180, 	.be = 194, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 45, .he = 50,	.rs = 52, 	.re = 24, 	.gs = 190, 	.ge = 210, 	.bs = 194, 	.be = 210, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 50, .he = 55,	.rs = 24, 	.re = 24, 	.gs = 210, 	.ge = 210, 	.bs = 210, 	.be = 210, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 55, .he = 63,	.rs = 24, 	.re = 52, 	.gs = 210, 	.ge = 190, 	.bs = 210, 	.be = 194, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 63, .he = 68,	.rs = 52, 	.re = 81, 	.gs = 190, 	.ge = 176, 	.bs = 194, 	.be = 180, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 68, .he = 73,	.rs = 81, 	.re = 110, 	.gs = 176, 	.ge = 162, 	.bs = 180, 	.be = 166, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 73, .he = 78,	.rs = 110, 	.re = 139, 	.gs = 162, 	.ge = 148, 	.bs = 166, 	.be = 152, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 78, .he = 84,	.rs = 139, 	.re = 168, 	.gs = 148, 	.ge = 134, 	.bs = 152, 	.be = 138, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 84, .he = 90,	.rs = 168, 	.re = 197, 	.gs = 134, 	.ge = 120, 	.bs = 138, 	.be = 124, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 90, .he = 95,	.rs = 197, 	.re = 226, 	.gs = 120, 	.ge = 106, 	.bs = 124, 	.be = 110, 	 .ef = EF_OVER | EF_SCR_R },
    { .hs = 95, .he = 100,	.rs = 226, 	.re = 255, 	.gs = 106, 	.ge = 92, 	.bs = 110, 	.be = 96, 	 .ef = EF_OVER | EF_SCR_R },

    { .end = 1 },
};

//Rainbow scrolling
led_setup_t leds_rainbow_s2[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};


//Purple
led_setup_t leds_purple[] = {
    { .hs = 0, .he = 100, .rs = 125, .re = 125, .gs = 0, .ge = 0, .bs = 100, .be = 100, .ef = EF_NONE },
    { .end = 1 },
};

led_setup_t leds_purples_s[] = {
    { .hs = 0,  .he = 20,  .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 20, .he = 40,  .rs = 255, .re = 0,   .gs = 0,   .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 40, .he = 60,  .rs = 0,   .re = 255, .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 60, .he = 80,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 255, .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 80, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 0,   .bs = 0,   .be = 255,   .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

//Add new LED animations here using one from above as example
//The last entry must be { .end = 1 }
//Add the new animation name to the list below following its format

void *led_setups[] = {
    leds_teal_salmon_s2,
    leds_rainbow_s2,
    //leds_subt_ex_s2,
    leds_rainbow_s,
    leds_yellow,
    leds_red,
    leds_green,
    leds_white,
    leds_purple,
    leds_white_with_red_stripe,
//    leds_black_with_red_stripe,
//    leds_teal_salmon_s,
//    leds_purples_s,
//    leds_blue,
//    leds_rainbow_ns,
//    leds_teal_salmon,
    //leds_subt_ex_s,
    leds_off
};

const uint8_t led_setups_count = sizeof(led_setups) / sizeof(led_setups[0]);

#endif
