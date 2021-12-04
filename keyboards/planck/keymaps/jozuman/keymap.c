/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"
#include "jozuman.h"
#include "print.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  MY_MACRO,
  WIN_1,
  WIN_2,
  WIN_3,
  WIN_4
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define CTRL_ALT_DEL LALT(LCTL(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 0. Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Shift'|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  |  Fn  |Lower |    Space    |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_UP,   RSFT_T(KC_QUOT),
    KC_LCTL, KC_LGUI, KC_LALT, TT(3), LOWER, KC_SPC, KC_SPC, RAISE, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* 1. Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ^^  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,          KC_8,          KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,       KC_PLUS,       KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  LSFT(KC_NUHS), LSFT(KC_NUBS), KC_HOME, KC_END,  KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______,       KC_MNXT,       KC_VOLD, KC_VOLU, KC_MPLY
),

/* 2. Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ^^  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |LOCK_W|ISO / |Pg Up |Pg Dn |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS,    KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RGUI(KC_L), KC_NUBS, KC_PGUP, KC_PGDN, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* 3. Function layer
 *                                                         v----------NUM PAD----------v
 * ,-----------------------------------------------------------------------------------.
 * |   1  | Win1 | Win2 | Win3 | Win4 | Win5 |   6  |   7  |   7  |   8  |   9  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MailAr|      |      |      |   *  |   *  |   F  |   4  |   5  |   6  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   K  |   W  |TRM_PS|   *  |   *  |   R  |   1  |   2  |   3  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlAlD|      |      |   A  |   O  |             |   E  |   0  |   .  |   .  |   +  |
 * `-----------------------------------------------------------------------------------'
 * MailAr = Outlook Mail Archive shortcut
 * TRM_PS = Terminal Paste = Shift + Insert to paste into terminals so function + v instead of ctrl + v
 * CtlAlD = Ctrl + Alt + D + Custom Macro + More
 */
[_FUNCTION] = LAYOUT_planck_grid(
    KC_1,     WIN_1,            WIN_2,   WIN_3,   WIN_4,        KC_5,  KC_6,  KC_7, KC_7, KC_8,   KC_9,    KC_PSLS,
    KC_NO,    LCTL(LSFT(KC_1)), _______, _______, _______,      KC_T,  KC_Y,  KC_U, KC_4, KC_5,   KC_6,    KC_PAST,
    KC_NO,    _______,          KC_S,    KC_D,    LSFT(KC_INS), KC_G,  KC_H,  KC_J, KC_1, KC_2,   KC_3,    KC_PMNS,
    MY_MACRO, _______,          KC_NO,   KC_TRNS, KC_V,         KC_NO, KC_NO, KC_N, KC_0, KC_DOT, KC_DOT,  KC_PPLS
),

/* 4. Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |  ^^  | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ^^  |  ^^  |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|DM_REC|DM_PLY|DM_STP|  ^^  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |keyloc|Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|BL_TOG|BL_STE|BL_BRT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ^^  |  ^^  |  ^^  |  ^^  |  ^^  |             |  ^^  |BL_ON |BL_OFF|BL_INC|BL_DEC|
 * `-----------------------------------------------------------------------------------'
 * DM* = Dynamic Macros. tried putting these on the Function layer but I was encountering issues
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_TRNS, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
    KC_TRNS, KC_TRNS, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  DM_REC1,  DM_PLY1, DM_RSTP, KC_TRNS,
    KC_LOCK, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, BL_TOGG, BL_STEP, BL_BRTG,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_ON,    BL_OFF,  BL_INC,  BL_DEC
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static bool win_pressed;

void crazy_win_magic(uint16_t number_code){
    // if we aren't pressing the win key already, press and hold win key and record that we're holding it
    if (!win_pressed) {
        #ifdef CONSOLE_ENABLE
            print("register win\n");
        #endif
        register_code(KC_LGUI);
        win_pressed = true;
    }
    #ifdef CONSOLE_ENABLE
        print("tapping number\n");
    #endif
    tap_code(number_code);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed

  #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  #endif
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case MY_MACRO:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_DEL) SS_UP(X_LALT) SS_UP(X_LCTRL) SS_DELAY(1000) MACRO_VALUE SS_TAP(X_ENTER));
      }
      return false;
      break;
    case WIN_1:
      if (record->event.pressed) {
          crazy_win_magic(KC_1);
      }
      return false;
      break;
    case WIN_2:
      if (record->event.pressed) {
          crazy_win_magic(KC_2);
      }
      return false;
      break;
    case WIN_3:
      if (record->event.pressed) {
          crazy_win_magic(KC_3);
      }
      return false;
      break;
    case WIN_4:
      if (record->event.pressed) {
          crazy_win_magic(KC_4);
      }
      return false;
      break;
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TT(3):
      if (!record->event.pressed) {
        if (win_pressed) {
            #ifdef CONSOLE_ENABLE
                print("letting off win\n");
            #endif
            // since we're still holding the win key but we've just let go of the layer 3 key, let's let go of the win key
            unregister_code(KC_LGUI);
            win_pressed = false;
        }
      }
      break;
  }
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour

  // debug_enable=true;
  // debug_matrix=true;

  //debug_keyboard=true;
  //debug_mouse=true;
}
