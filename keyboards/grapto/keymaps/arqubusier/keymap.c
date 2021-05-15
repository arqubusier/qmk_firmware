/* Copyright 2020 Herman Lundkvist
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _SYM,
    _EXT
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    COPY = SAFE_RANGE,
    PASTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                          KC_F1,   KC_F2,    KC_F3,             KC_F4,   KC_F5,
                 KC_F11,  KC_LBRC, KC_QUOT,  KC_SCLN,           KC_P,    KC_Y,
                 KC_TAB,  KC_A,    KC_O,     KC_E,              KC_U,    KC_I,
                          KC_DOT,  KC_Q,     KC_J,              KC_K,    KC_X,
                                   KC_ENTER, LT(_EXT, KC_ESC),  KC_LSFT, MO(_SYM), KC_BSPC, KC_LALT,
               KC_LCTL,

                          KC_F6,   KC_F7,    KC_F8,   KC_F9,  KC_F10,
                          KC_F,    KC_G,     KC_C,    KC_R,    KC_L,   KC_F12,
                          KC_D,    KC_H,     KC_T,    KC_N,    KC_S,   KC_ENTER,
                          KC_B,    KC_M,     KC_W,    KC_V,    KC_Z,
        KC_RALT, KC_RSFT, KC_SPC,  MO(_SYM),  KC_DEL,  KC_RCTL,
                                                              KC_RGUI
    ),
    [_SYM] = LAYOUT(
                          KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS,
               KC_TRNS,   KC_NUHS, KC_COMM, KC_NUBS, KC_SLSH, KC_MINS,
               KC_TRNS,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
                                   RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS,

                          KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                          KC_EQL,  KC_RBRC, KC_GRV,  KC_PGUP, KC_PGDN, KC_TRNS,
                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
                          KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,   KC_F7,
                                                              KC_TRNS
    ),
    [_EXT] = LAYOUT(
                          KC_HOME, KC_END,  KC_PGUP, KC_PGDN,  KC_INS,
               KC_TRNS,   KC_NUHS, KC_COMM, KC_NUBS, KC_SLSH,  KC_MINS,
               KC_TRNS,   KC_1,    KC_2,    COPY,    KC_PASTE, KC_5,
                          KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
                                   RESET,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS,

                          KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                          KC_EQL,  KC_RBRC, KC_GRV,  KC_PGUP, KC_PGDN, KC_TRNS,
                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
                          KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,   KC_F7,
                                                              KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COPY:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_LCTL("c"));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case PASTE:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING(SS_LCTL("v"));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
