/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
 * Copyright 2023 @Ex3c4Def
 * Copyright 2023 @Residuum
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "keymap_hungarian.h"

enum layers {
    _QWERTZ,
    _LOWER,
    _RAISE,
    _ADJUST,
    _WASD,
};

#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)

#define LAY_BAS TO(_QWERTZ)
#define LAY_ASD TO(_WASD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,--------------------------------------------.                                         ,----------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                                         |   6  |   7  |   8  |   9  |   0  |  `        |
 * |---------+------+------+------+------+------|                                         |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                                         |   Y  |   U  |   I  |   O  |   P  |  CapsLock |
 * |---------+------+------+------+------+------|                                         |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |---------------.         ,---------------|   H  |   J  |   K  |   L  |   ;  |  RShift   |
 * |---------+------+------+------+------+------| None |   (    |         |   )   | None  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |------|--------|         |-------|-------|   N  |   M  |   ,  |  .  |   -   |  RCTRL    |
 * `--------------------------------------------|               /          \              |----------------------------------------------'
 *                         | LGUI | LALT | DEL  |LOWER | Space /            \Enter| RAISE |BackSP| RGUI | RALT |
 *                         `----------------------------------'              '---------------------------------'
 */
[_QWERTZ] = LAYOUT(
    KC_ESC,  HU_1,  HU_2,   HU_3,    HU_4,    HU_5,                                          HU_6,    HU_7,    HU_8,    HU_9,    HU_0,    HU_GRV,
    KC_TAB,  HU_Q,  HU_W,   HU_E,    HU_R,    HU_T,                                          HU_Z,    HU_U,    HU_I,    HU_O,    HU_P,    KC_CAPS,
    KC_LSFT, HU_A,  HU_S,   HU_D,    HU_F,    HU_G,                                          HU_H,    HU_J,    HU_K,    HU_L,    HU_SCLN, KC_RSFT,
    KC_LCTL, HU_Y,  HU_X,   HU_C,    HU_V,    HU_B,   XXXXXXX,  HU_LPRN,  HU_RPRN,  XXXXXXX, HU_N,    HU_M,    HU_COMM, HU_DOT,  HU_MINS, KC_RCTL,
                            KC_LGUI, KC_LALT, KC_DEL, LOWER,    KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, KC_RALT, KC_RGUI
),
/* LOWER
* QWERTY
 * ,--------------------------------------------.                                           ,----------------------------------------------.
 * |   F12   |  F1  |  F2  |  F3  |  F4  |  F5  |                                           |  F6  |  F7  |  F8  |  F9  | F10  |  F11      |
 * |---------+------+------+------+------+------|                                           |------+------+------+------+------+-----------|
 * |   Tab   | None | None | None | None | None |                                           | None |   Ü  | None |   Ü  |   ?  | CapsLock  |
 * |---------+------+------+------+------+------|                                           |------+------+------+------+------+-----------|
 * | LShift  |   !  |   @  |   #  |   $  |   %  |---------------.           ,---------------|   ^  |   &  |   *  | None |   :  |  RShift   |
 * |---------+------+------+------+------+------| None |    [   |           |   ]   | None  |------+------+------+------+------+-----------|
 * | LCTRL   | None | None | None | None | None |------|--------|           |-------|-------|   °  | None |   <  |   >  |   _  |  RCTRL    |
 * `--------------------------------------------|               /            \              |----------------------------------------------'
 *                         | LGUI | LALT | DEL  |LOWER | Space /              \Enter| RAISE |BackSP| RGUI | RALT |
 *                         `----------------------------------'                '---------------------------------'
 */
[_LOWER] = LAYOUT(
    KC_F12 , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, HU_UDIA, XXXXXXX, HU_ODIA, HU_QUES, _______,
    _______, HU_EXLM, HU_AT,   HU_HASH, HU_DLR,  HU_PERC,                                     HU_CIRC, HU_AMPR, HU_ASTR, XXXXXXX, HU_COLN, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HU_LBRC, HU_RBRC, XXXXXXX, HU_RNGA, XXXXXXX, HU_LABK, HU_RABK, HU_UNDS, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* RAISE
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * |   None  |  !   |  @   |  #   |   $  |   %  |                                   |  ^   |   &  |   *  |   (  |   )  |     ~     |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |   None  |   \  |   |  |  É   |   /  |  ~   |                                   | Home |   Ú  |   Í  |   Ó  | None |    None   |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |  LShift |   Á  |   '  |   "  |   (  |   )  |---------------.   ,---------------| End  | Left | Down |  Up  |Right |  RShift   |
 * |---------+------+------+------+------+------| None |   {    |   |   }   | None  |------+------+------+------+------+-----------|
 * |  LCTRL  | None | None | None |   [  |   ]  |------|--------|   |-------|-------|   {  |   }  |   +  |   -  |   =  |  RCTRL    |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                         | LCTRL| LGUI |LALT  |LOWER | Space /      \Enter| RAISE |BackSP| RGUI | RALT |
 *                         `----------------------------------'        '---------------------------------'
 */
 [_RAISE] = LAYOUT(
    XXXXXXX, HU_EXLM, HU_AT,   HU_HASH, HU_DLR,  HU_PERC,                                       HU_CIRC, HU_AMPR, HU_ASTR, HU_LPRN, HU_RPRN, HU_TILD,
    XXXXXXX, HU_BSLS, HU_PIPE, HU_EACU, HU_SLSH, HU_TILD,                                       KC_HOME, HU_UACU, HU_IACU, HU_OACU, XXXXXXX, XXXXXXX,
    _______, HU_AACU, HU_QUOT, HU_DQUO, HU_LPRN, HU_RPRN,                                       KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, HU_LBRC, HU_RBRC,  XXXXXXX, HU_LCBR,  HU_RCBR, XXXXXXX, HU_LCBR, HU_RCBR, HU_PLUS, HU_MINS, HU_EQL,  _______,
                               _______, _______, _______,  _______, _______,  _______, _______,  _______, _______, _______
),

/* ADJUST (Press LOWER and RAISE together)
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * | QK_BOOT |      |      |      |      | WASD  |                                   |      |      |      |      |      |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * | RGB ON  | HUE+ | SAT+ | VAL+ |      |      |                                   | None |  Ű   | Play |   Ő  |      |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * | MODE    | HUE- | SAT- | VAL- |      |      |---------------.   ,---------------| None | Prev | Vol- | Vol+ | Next |           |
 * |---------+------+------+------+------+------|      |        |   |       |       |------+------+------+------+------+-----------|
 * |         |      |      |      |      |      |------|--------|   |-------|-------|      | Rwnd | Mute | Stop | Ffwd |           |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                         | LCTRL| LGUI |LALT  |LOWER | Space /      \Enter| RAISE |BackSP| RGUI | RALT |
 *                         `----------------------------------'        '---------------------------------'
 */
[_ADJUST] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAY_ASD,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU, XXXXXXX,                                     XXXXXXX, HU_UDAC, KC_MPLY, HU_ODAC, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID, XXXXXXX,                                     XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_WAKE, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MRWD, KC_MUTE, KC_MSTP, KC_MFFD, XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* WASD
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * |   None  | None | None | None | None | BASE |                                   | None | None | None | None | None |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |   None  | None |   Q  |   W  |   E  | None |                                   | None | None | None | None | None |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |  LShift |LShift|   A  |  S  |   D   | None |---------------.   ,---------------| Left | Down |  Up  |Right |   ;  |           |
 * |---------+------+------+------+------+------| None |   {    |   |   }   | None  |------+------+------+------+------+-----------|
 * |  LCNTRL | None | None | None | None |  C   |------|--------|   |-------|-------|   +  |   -  |   =  |  [  |   ]   |   \       |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                         |  None| None | None | Space|  None /      \Enter| RAISE |BackSP| RGUI | RALT |
 *                         `----------------------------------'        '---------------------------------'
 */
[_WASD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAY_BAS,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, HU_Q,    HU_W,    HU_E,    XXXXXXX,                                     XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, KC_LSFT, HU_A,    HU_S,    HU_D,    XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HU_C,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
)

};



layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTZ] = { ENCODER_CCW_CW(KC_DOWN, KC_UP),          ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUI, KC_TAB),         ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),        ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),       ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [_WASD  ] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),       ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    //                  Encoder 1                                     Encoder 2
};
#endif // ENCODER_MAP_ENABLE
