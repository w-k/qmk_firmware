#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3

enum custom_keycodes {
  RAIS = SAFE_RANGE,
  LOWE,
  ADJU,
  KC_LPLT, 
  KC_RPGT,
  KC_GRV_SP,
  KC_GRV_LE,
  KC_GRV_RI,
  KC_GRV_DN,
  KC_GRV_UP,
  KC_GRV_U,
  KC_GRV_N,
  KC_GRV_E,
  KC_GRV_I,
  KC_GRV_C,
  KC_GRV_X,
};


#define ____ KC_TRNS
#define CTL_BSPC CTL_T(KC_BSPC)
#define ESC_CTL MT(MOD_LCTL, KC_ESC)
#define ENT_SFT MT(MOD_LSFT, KC_ENT)
#define LPLT KC_LPLT // ( or < with shift 
#define RPGT KC_RPGT // ) or > with shift
#define GRV_SP KC_GRV_SP // `+space 
#define GRV_LE KC_GRV_LE // `+left
#define GRV_RI KC_GRV_RI // `+right
#define GRV_DN KC_GRV_DN // `+down
#define GRV_UP KC_GRV_UP // `+up
#define GRV_U KC_GRV_U // `+U
#define GRV_N KC_GRV_N // `+N
#define GRV_E KC_GRV_E // `+E
#define GRV_I KC_GRV_I // `+I
#define GRV_C KC_GRV_C // `+C
#define GRV_X KC_GRV_X // `+X
#define SLSHA MT(MOD_LALT, KC_SLSH)
#define LS_E MT(MOD_LSFT, OSM(MOD_LSFT))
#define CMD_BSP MT(MOD_LGUI, KC_BSPC)

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Base (colemak dh)
 * ,----------------------------------,              ,----------------------------------,
 * |   q  |   f  |   p  |   r  |   b  |              |   j  |   l  |   u  |   y  |   ;  |
 * |------+------+------+------+------|              |-------------+------+------+------|
 * |   a  |   r  |   s  |   t  |   g  |              |   m  |   n  |   e  |   i  |   o  |
 * |------+------+------+------+------|              |------|------+------+------+------|
 * |   z  |   x  |   c  |   d  |   v  |              |   k  |   h  |   ,  |   .  |   /  |
 * |------+------+------+-------------,              ,-------------+------+------+------,
 *        |  TAB |   `  |                                          |   =  |   "  |
 *        '------+------'-------------'              '-------------'------+------'
 *                      |CMD_BSP| SPACE|              | RAISE| ENTS |
 *                      |  +   |   +  |              |  +   |  +   |
 *                      |      | ESCC |              | LOWER|      |
 *                      '------+------'              '------+------'
 */

#define EQL_CMD MT(MOD_LGUI, KC_EQL)
#define QUOT_SFT MT(MOD_LSFT, KC_QUOT)
#define TAB_CTL MT(MOD_LCTL, KC_TAB)
#define GRV_ALT MT(MOD_LALT, KC_GRV)
#define GRV_ADJ LT(_ADJUST, KC_GRV)

[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_F,    KC_P,    KC_B,                                       KC_J, KC_L,    KC_U,    KC_Y,   KC_SCLN, \
  KC_A, KC_R, KC_S,    KC_T,    KC_G,                                       KC_M, KC_N,    KC_E,    KC_I,   KC_O,    \
  KC_Z, KC_X, KC_C,    KC_D,    KC_V,                                       KC_K, KC_H,    KC_COMM, KC_DOT, SLSHA   ,\
              TAB_CTL, GRV_ADJ,                                                     EQL_CMD, QUOT_SFT,                   \
                                     CMD_BSP,KC_SPC,    RAISE  ,    LOWER ,                                           \
                                     ENT_SFT, ____ ,    ESC_CTL  ,  ____  ,                                           \
                                      ____,  ____,      ____   , ____
),

/* Raise
 * ,----------------------------------,              ,----------------------------------,
 * |  !   |  @   |  #   |  $   |  %   |              | `UP  |  (   |  UP  |  )   |      |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |  1   |  2   |  3   |   4  |   5  |              |  -   | LEFT | DOWN | RIGHT|  \   |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |  6   |  7   |  8   |  9   |  0   |              |  &   |  [   |   *  |  ]   |  |   |
 * |------+------+------+-------------,              ,-------------+------+------+------,
 *        |      |      |                                          |      |      |
 *        '------+------'-------------'              '-------------'------+------'
 *                      |      |      |              |      |      |
 *                      |  +   |   +  |              |  +   |  +   |
 *                      |      |      |              |      |ADJUST|
 *                      '------+------'              '------+------'
 */

[_RAISE] = LAYOUT( \
  KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC ,                       KC_CIRC,  LPLT  ,  KC_UP,   RPGT    , ____,  \
  KC_1,    KC_2, KC_3,   KC_4,  KC_5,                          KC_MINS, KC_LEFT,  KC_DOWN, KC_RIGHT,KC_BSLS,\
  KC_6,    KC_7, KC_8,   KC_9,  KC_0,                          KC_AMPR, KC_LBRC,  KC_ASTR, KC_RBRC, KC_PIPE,\
           ____, ____,                                                        ____,    ____,                \
                                       ____, ____,  ____, ADJUST,                                             \
                                       ____, ____,  ____, ____,                                            \
                                       ____, ____,  ____, ____                                              \
),


/* Lower
 * ,----------------------------------,              ,----------------------------------,
 * |  F1  |  F2  |  F3  |  F4  |  F5  |              | `UP  | `LEFT|  `U  |`RIGHT| PGDN |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |WHL_UP|              | `DOWN|  `N  |  `E  |  `I  | PGUP |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |  F10 |  `X  |  `C  |      |WHL_DN|              |      |      |      |      |      |
 * |------+------+------+-------------,              ,-------------+------+------+------,
 *        |  F11 |  F12 |                                          |      |      |
 *        '------+------'-------------'              '-------------'------+------'
 *                      |      |`SPACE|              |ADJUST|      |
 *                      |  +   |   +  |              |  +   |  +   |
 *                      |      |      |              |      |      |
 *                      '------+------'              '------+------'
 */

[_LOWER] = LAYOUT( \
  KC_F1, KC_F2,KC_F3, KC_F4, KC_F5,                           GRV_UP , GRV_LE,  GRV_U,  GRV_RI,  KC_PGUP, \
  KC_F6, KC_F7,KC_F8, KC_F9,KC_MS_WH_UP,                      GRV_DN , GRV_N ,  GRV_E,  GRV_I ,  KC_PGDN, \
  KC_F10,GRV_X,GRV_C,____,KC_MS_WH_DOWN,                   ____  ,    ____,   ____ ,    ____,     ____, \
        KC_F11,  KC_F12,                                                         ____,  ____,               \
                                   ____, GRV_SP,  ADJUST,____,                                              \
                                   ____, ____  ,   ____,____,                                              \
                                   ____, ____  ,  ____  ,____                                               \
),


/* Adjust 
 * ,----------------------------------,              ,----------------------------------,
 * | RESET|      |      |      |      |              |WHL_UP|      | MS_UP|      |      |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |      |      |      |      |      |              |WHL_DN|MS_LFT| MS_DN|MS_RGT|      |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |      |      |      |      |      |              |      |ACCL_0|ACCL_1|ACCL_2|      |
 * |------+------+------+-------------,              ,-------------+------+------+------,
 *        |      |      |                                          |      |      |
 *        '------+------'-------------'              '-------------'------+------'
 *                      |MS_LFT|MS_RGT|              |      |      |
 *                      |  +   |   +  |              |  +   |  +   |
 *                      |      |MS_MDL|              |      |      |
 *                      '------+------'              '------+------'
 */
[_ADJUST] = LAYOUT( \
  RESET, ____, ____, ____, ____,         KC_MS_WH_UP,    ____,       KC_MS_UP,       ____,     ____,   \
  ____,  ____, ____, ____, ____,         KC_MS_WH_DOWN,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,  ____,   \
  ____,  ____, ____, ____, ____,         ____,           KC_ACL0   , KC_ACL1   , KC_ACL2    ,         ____,   \
         KC_ACL2, ____,                                                 ____,       ____,                 \
                     ____, ____,         KC_MS_BTN1,     KC_MS_BTN2,                                   \
                     ____, ____,         KC_MS_BTN3,     ____,                                         \
                     ____, ____,         ____,           ____                                          \
),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GRV_SP: // `+space 
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_SPACE);
      }
      return false;
    case GRV_LE: // `+left
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_LEFT);
      }
      return false;
    case GRV_RI: // `+right
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_RIGHT);
      }
      return false;
    case GRV_DN: // `+down
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_DOWN);
      }
      return false;
    case GRV_UP: // `+up
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_UP);
      }
      return false;
    case GRV_U: // `+U
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_U);
      }
      return false;
    case GRV_N: // `+N
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_N);
      }
      return false;
    case GRV_E: // `+E
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_E);
      }
      return false;
    case GRV_I: // `+I
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_I);
      }
      return false;
    case GRV_C: // `+C
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_C);
      }
      return false;
    case GRV_X: // `+X
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        tap_code(KC_X);
      }
      return false;
  case LPLT: // ( or < with shift
    if (record->event.pressed) {
      if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
        // <
        tap_code(KC_COMM); // shift is already registered
      } else {
        // (
        register_mods(MOD_BIT(KC_LSFT));
        tap_code(KC_9);
        unregister_mods(MOD_BIT(KC_LSFT));
      }
    }
    return false;
  case RPGT: // ) or > with shift
    if (record->event.pressed) {
      if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
        // <
        tap_code(KC_DOT); // shift is already registered
      } else {
        // )
        register_mods(MOD_BIT(KC_LSFT));
        tap_code(KC_0);
        unregister_mods(MOD_BIT(KC_LSFT));
      }
    }
    return false;
  }
  return true;
}
