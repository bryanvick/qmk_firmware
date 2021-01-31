/*

== todo ==
. Checkout fork that allows overlapping combos: https://github.com/sevanteri/qmk_firmware


== Notes ==

. mod-tap timing is no good for fast typing.  Use mod keys, not mod-tap.
.. I've tried many variations of timings, permissive hold, retro tapping etc.
The tinkering isn't worth the effort.  Lots of edge-cases.
. Combos can't be used for keys that need to be paired with a modifier, because
when the modifier is held down, the combo won't trigger.  Therefore, combos are
good for punctuation like ()[]{} or other keys that won't need to be pressed
while a modifier is held down.
.. The following thread has some hints on getting modifiers to work w/ comobs:
https://www.reddit.com/r/ErgoMechKeyboards/comments/ifenwa/thoughts_on_layout_2_combos_are_a_game_changer/
*/




#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _MOUSE 2
#define _NAV 3
#define _NUM 4
#define _MEDIA 5
#define _GAME 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MOUSE,
  NAV,
  NUM,
  MEDIA,
  GAME,
};


// Aliases for prettier layouts below.
#define MONUM MO(_NUM)
#define LALTENT LALT_T(KC_ENT)


// Ctrl when held, Esc when tapped.
#define CTLESC MT(MOD_LCTL, KC_ESC)

// Layer 3 when held, semicolon when tapped.
#define NAVSLN LT(_NAV,KC_SCLN)


// Homerow combinations
// --------------------
const uint16_t PROGMEM combo_d_f[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_j_k[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_s_f[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_j_l[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_s_d[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_k_l[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_f_g[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo_h_j[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_l_semic[] = {KC_L, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM combo_semic_quote[] = {KC_SCOLON, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo_right_thumb_bash[] = {KC_SPACE, KC_INS, COMBO_END};
const uint16_t PROGMEM combo_j_thumb[] = {KC_RCTL, KC_J, COMBO_END};
const uint16_t PROGMEM combo_f_thumb[] = {KC_LCTL, KC_F, COMBO_END};


// GT/LT
const uint16_t PROGMEM combo_t_g[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_y_h[] = {KC_Y, KC_H, COMBO_END};


// Upper row combos
// ----------------
// These are hard to hit quickly
const uint16_t PROGMEM combo_y_u[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_r_t[] = {KC_R, KC_T, COMBO_END};

const uint16_t PROGMEM combo_e_r[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_u_i[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_u_o[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo_w_e[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_w_r[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM combo_i_o[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_o_p[] = {KC_O, KC_P, COMBO_END};


// Lower row combos
// ----------------
const uint16_t PROGMEM combo_l_and_r_shift[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM combo_m_and_comma[] = {KC_M, KC_COMMA, COMBO_END};

#define COMMA_SPACE 24

combo_t key_combos[COMBO_COUNT] = {
    // Homerow combos: Brackets and braces.
    [0] = COMBO(combo_d_f, KC_LEFT_PAREN),
    [1] = COMBO(combo_j_k, KC_RIGHT_PAREN),
    [2] = COMBO(combo_s_f, KC_LBRACKET),
    [3] = COMBO(combo_j_l, KC_RBRACKET),
    [4] = COMBO(combo_s_d, KC_LEFT_CURLY_BRACE),
    [5] = COMBO(combo_k_l, KC_RIGHT_CURLY_BRACE),

    [6] = COMBO(combo_l_semic, KC_COLN),
    [7] = COMBO(combo_semic_quote, KC_DOUBLE_QUOTE),


    [8] = COMBO(combo_f_g, KC_EQUAL),
    [9] = COMBO(combo_h_j, KC_ENTER),

    // Upper row of combos
    //[10] = COMBO(combo_e_r, KC_MINUS), // er is a common fast entry, was triggering this, disabl;ing. 
    [10] = COMBO(combo_u_i, KC_MINUS),
    [11] = COMBO(combo_u_o, KC_COLON),
    [12] = COMBO(combo_w_r, KC_QUESTION), 

    [13] = COMBO(combo_r_t, KC_PLUS),
    [14] = COMBO(combo_y_u, KC_DOUBLE_QUOTE),
    [15] = COMBO(combo_o_p, KC_BSLASH),

    // Symmetry in dash/minus.
    [16] = COMBO(combo_w_e, KC_UNDERSCORE),
    [17] = COMBO(combo_i_o, KC_UNDERSCORE),

        
    // Lower row of combos
    // -------------------
    [18] = COMBO(combo_l_and_r_shift, KC_CAPS),
    [19] = COMBO(combo_right_thumb_bash, KC_DELETE),

    // Symmetry in <>
    [20] = COMBO(combo_t_g, KC_LEFT_ANGLE_BRACKET),
    [21] = COMBO(combo_y_h, KC_RIGHT_ANGLE_BRACKET),

    [22] = COMBO(combo_j_thumb, KC_LALT),
    [23] = COMBO(combo_f_thumb, KC_LALT),
    [COMMA_SPACE] = COMBO_ACTION(combo_m_and_comma),

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRAVE,KC_EXLM , KC_AT  ,KC_HASH ,KC_DLR  ,KC_PERC ,                KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_BSPACE,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_PIPE ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   CTLESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                KC_H    ,KC_J    ,KC_K    ,KC_L    , NAVSLN , KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼───────┬───────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,TG(_GAME),KC_INS ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬───┴──┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_LGUI,MONUM,LALTENT ,            KC_SPC,KC_RCTL,KC_LALT
),


[_NAV] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END  , _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, _______, _______,                   _______, _______, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),


  [_NUM] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┬────────┐
   DEBUG   , KC_9    , KC_7    ,KC_5    ,KC_3    ,KC_1    ,                KC_0    ,KC_2    ,KC_4    ,KC_6    ,KC_8    ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, XXXXXXX, KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,                KC_MINUS,KC_7    ,KC_8    ,KC_9    ,KC_ASTR ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, XXXXXXX, KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,                KC_PLUS ,KC_4    ,KC_5    ,KC_6    ,KC_ASTR ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┼───────┬───────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, XXXXXXX, KC_F1   ,KC_F2   ,KC_F3   ,KC_F10  ,RESET  ,_______,KC_0    ,KC_1    ,KC_2    ,KC_3    ,_______ ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬───┴──┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  XXXXXXX ,XXXXXXX ,XXXXXXX ,       KC_0    ,KC_0    , _______
//                               └────────┴────────┴────────┘      └────────┴────────┴────────┘
),


  [_MEDIA] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                KC_MPRV ,KC_VOLD ,KC_VOLU ,KC_MNXT ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┼───────┬───────┼────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,XXXXXXX,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬───┴──┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  XXXXXXX ,XXXXXXX ,XXXXXXX ,       KC_MPLY ,KC_MUTE , XXXXXXX
//                               └────────┴────────┴────────┘      └────────┴────────┴────────┘
),

  [_GAME] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_ESC  , KC_1    , KC_2   ,KC_3    ,KC_4    ,KC_5    ,                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,TG(_GAME) ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TAB  , KC_Q   , KC_W   ,KC_E    ,KC_R    ,KC_T    ,                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LCTRL, KC_A   ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,               XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┼───────┬───────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSFT, KC_Z    , KC_X   ,KC_C    ,KC_V    ,KC_B    ,TG(_GAME),XXXXXXX,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬───┴──┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  KC_LALT ,KC_SPC  ,KC_H    ,       XXXXXXX ,XXXXXXX , XXXXXXX
//                               └────────┴────────┴────────┘      └────────┴────────┴────────┘
),



/*
PURPOSE: Mouse, RGB
[_MOUSE] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   RGB_TOG, _______, _______, _______, _______, _______,                            _______,KC_WH_U, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   RGB_MOD, _______, _______, _______, _______, _______,                            KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, RGB_VAI, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   BL_STEP, _______, _______, _______, _______, _______, KC_SLEP,          KC_WAKE, _______, KC_WH_D,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  _______, KC_BTN1, KC_BTN2,                   _______, _______, _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),
*/

/* Left-hand numpad
  [_LNUM] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, KC_9    , KC_7    ,KC_5    ,KC_3    ,KC_1    ,                KC_0    ,KC_2    ,KC_4    ,KC_6    ,KC_8    ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, XXXXXXX, KC_7    ,KC_8    ,KC_9    ,XXXXXXX ,                KC_MINUS,KC_7    ,KC_8    ,KC_9    ,KC_ASTR ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, XXXXXXX, KC_4     ,KC_5   ,KC_6    ,XXXXXXX ,                KC_PLUS ,KC_4    ,KC_5    ,KC_6    ,KC_ASTR ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┼───────┬───────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, XXXXXXX, KC_1    ,KC_2    ,KC_3    ,XXXXXXX ,RESET  ,_______,KC_0    ,KC_1    ,KC_2    ,KC_3    ,_______ ,_______ ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬───┴──┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  XXXXXXX ,KC_0    ,XXXXXXX ,       KC_0    ,KC_0    , _______
//                               └────────┴────────┴────────┘      └────────┴────────┴────────┘
),
*/



/*
Purpose: TEMPLATE LAYER

  [TODO_TEMPLATE_NAME] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┼───────┬───────┼────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,XXXXXXX,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬───┴──┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                  XXXXXXX ,XXXXXXX ,XXXXXXX ,       XXXXXXX ,XXXXXXX , XXXXXXX
//                               └────────┴────────┴────────┘      └────────┴────────┴────────┘
),
*/

};


void process_combo_event(uint16_t combo_index, bool pressed){
    switch(combo_index) {
        case COMMA_SPACE:
            if (pressed){
                SEND_STRING(", ");
                break;
            }
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
