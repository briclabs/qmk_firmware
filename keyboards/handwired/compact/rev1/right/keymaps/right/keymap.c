#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_dvorak.h"
#include "sendstring_dvorak.h"

#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define LAYER_BASE   0
#define LAYER_NUMROW 1
#define LAYER_FNROW  2
#define LAYER_NUMPAD 3

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    TOP_ROW_CHANGE,
    TOP_ROW_DEFAULT,
    NUMPAD,
    PRINT,
    COPY,
    SLASH,
    CURLY_OPEN,
    CURLY_CLOSE,
    EQUALS,
    CARET,
    PERCENT,
    PLUS,
    L,
    R,
    C,
    G,
    F,
    PIPE,
    S,
    N,
    T,
    H,
    D,
    Z,
    V,
    W,
    M,
    B,
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 *    0       1      2      3      4      5      6      7      8
 *        ,-------------------------------------------------------.
 *        |TR_CHG|   /  |   }  |   {  |   =  |   ^  |   %  |   +  |
 *        `------+------+------+------+------+------+------+------|
 *        |    ENTER    |   L  |   R  |   C  |   G  |   F  |   |  |
 * ,------+------+------+------+------+------+------+------+------|
 * |  OS  |  ALT | CTRL |   S  |   N  |   T  |   H  |   D  | HOME |
 * `------+------+------+------+------+------+------+------+------|
 *        |    SHIFT    |   Z  |   V  |   W  |   M  |   B  |      |
 * ,------+------+------+------+------+------+------+------+ SPC  |
 * | NUM  | COPY |  ESC |                                  |      |
 * |------+------+------'                                  `------'
 * | PSTE |  DN  |  DEL |
 * `--------------------'
 *
 */
[LAYER_BASE] = LAYOUT(
          TOP_ROW_CHANGE,          SLASH,     CURLY_CLOSE,       CURLY_OPEN,      EQUALS,          CARET,         PERCENT,          PLUS,
                                KC_ENTER,            DV_L,             DV_R,        DV_C,           DV_G,            DV_F,          PIPE,
   KC_RGUI,      KC_RALT,       KC_RCTRL,            DV_S,             DV_N,        DV_T,           DV_H,            DV_D,       KC_HOME,
                                 KC_RSFT,            DV_Z,             DV_V,        DV_W,           DV_M,            DV_B,        KC_SPC,
    NUMPAD,         COPY,         KC_ESC,
     PRINT,       KC_INS,         KC_DEL
),
/* Keymap 1: Number layer
  *
 *        ,-------------------------------------------------------.
 *        |TR_DEF|      |      |   0  |   9  |   8  |   7  |   6  |
 *        `------+------+------+------+------+------+------+------|
 *        |             |      |      |      |      |      |      |
 * ,------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------+------|
 *        |             |      |      |      |      |      |      |
 * ,------+------+------+------+------+------+------+------+      |
 * |      |      |      |                                  |      |
 * |------+------+------'                                  `------'
 * |      |      |      |
 * `--------------------'
 *
 */
// NUMBER KEY ROW
[LAYER_NUMROW] = LAYOUT(
           TOP_ROW_DEFAULT,     KC_TRNS,    KC_TRNS,       ZERO,       NINE,      EIGHT,      SEVEN,        SIX,
                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS
),
/* Keymap 2: Function layer
 *
 *        ,-------------------------------------------------------.
 *        |TR_DEF| F12  | F11  | F10  |  F9  |  F8  |  F7  |  F6  |
 *        `------+------+------+------+------+------+------+------|
 *        |             |      |      |      |      |      |      |
 * ,------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------+------|
 *        |             |      |      |      |      |      |      |
 * ,------+------+------+------+------+------+------+------+      |
 * |      |      |      |                                  |      |
 * |------+------+------'                                  `------'
 * |      |      |      |
 * `--------------------'
 *
 */
// FUNCTION KEY ROW
[LAYER_FNROW] = LAYOUT(
           TOP_ROW_DEFAULT,       KC_NO,      KC_NO,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,
                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS
),
/* Keymap 3: Numpad layer
 *
 *        ,-------------------------------------------------------.
 *        |      |      |      |      |      |      |      |      |
 *        `------+------+------+------+------+------+------+------|
 *        |             |   /  |   9  |   8  |   7  |   -  |      |
 * ,------+------+------+------+------+------+------+------+------|
 * |      |      |      |   *  |   6  |   5  |   4  |   +  |      |
 * `------+------+------+------+------+------+------+------+------|
 *        |             |   .  |   3  |   2  |   1  |   0  |      |
 * ,------+------+------+------+------+------+------+------+      |
 * |      |      |      |                                  |      |
 * |------+------+------'                                  `------'
 * |      |      |      |
 * `--------------------'
 *
 */
// NUMPAD
[LAYER_NUMPAD] = LAYOUT(
                   KC_TRNS,     KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_KP_SLASH,    KC_KP_9,    KC_KP_8,    KC_KP_7, KC_KP_MINUS,    KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS, KC_KP_ASTERISK,    KC_KP_6,    KC_KP_5,    KC_KP_4,  KC_KP_PLUS,    KC_TRNS,
                                KC_TRNS,      KC_KP_DOT,    KC_KP_3,    KC_KP_2,    KC_KP_1,     KC_KP_0,    KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
  #ifdef CONSOLE_ENABLE
    dprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  #endif
  switch (keycode) {
    case TOP_ROW_CHANGE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              layer_invert(LAYER_FNROW);
              dprint("Layer toggled: function row.\n");
          } else {
              layer_invert(LAYER_NUMROW);
              dprintf("Layer toggled: number row.\n");
          }
      }
      return false;
      break;
    case TOP_ROW_DEFAULT:
      if (record->event.pressed) {
          layer_move(LAYER_BASE);
          dprint("Layer reset to base.\n");
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
          layer_invert(LAYER_NUMPAD);
          if ((host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
              dprint("Numlock already on.\n");
          } else {
              SEND_STRING (SS_TAP(X_NUMLOCK));
              dprint("Enabled numlock.\n");
          }
          dprint("Layer toggled: numpad.\n");
      }
      return false;
      break;
    case PRINT:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING (SS_TAP(X_PAUSE));
              dprint("Sent string: <pause>\n");
          } else {
              SEND_STRING (SS_TAP(X_PSCREEN));
              dprint("Sent string: <print>\n");
          }
      }
      return false;
      break;
    case COPY:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              SEND_STRING (SS_UP(X_LSHIFT) SS_DOWN(X_LCTRL) SS_LCTL("v") SS_UP(X_LCTRL) SS_DOWN(X_LSHIFT));
              dprint("Sent string: LCTRL + v\n");
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING (SS_UP(X_RSHIFT) SS_DOWN(X_RCTRL) SS_RCTL("v") SS_UP(X_RCTRL) SS_DOWN(X_RSHIFT));
              dprint("Sent string: RCTRL + v\n");
          } else {
              SEND_STRING (SS_RCTL("c"));
              dprint("Sent string: <copy>\n");
          }
      }
      return false;
      break;
    case SLASH:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(KC_BSLASH);
              unregister_code(KC_BSLASH);
              add_mods(MOD_BIT(KC_LSHIFT));
              dprint("Sent string: \\ \n");
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(KC_BSLASH);
              unregister_code(KC_BSLASH);
              add_mods(MOD_BIT(KC_RSHIFT))
              dprint("Sent string: \\ \n");
          } else {
              SEND_STRING ("/");
              dprint("Sent string: / \n");
          }
      }
      return false;
      break;
    case CURLY_CLOSE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              register_code(DV_DOT);
              unregister_code(DV_DOT);
              dprint("Sent string: > \n");
          } else {
              SEND_STRING ("}");
              dprint("Sent string: } \n");
          }
      }
      return false;
      break;
    case CURLY_OPEN:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("<");
              dprint("Sent string: < \n");
          } else {
              SEND_STRING ("{");
              dprint("Sent string: { \n");
          }
      }
      return false;
      break;
    case EQUALS:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_EQL);
              unregister_code(DV_EQL);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_EQL);
              unregister_code(DV_EQL);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("=");
          }
          dprint("Sent string: = \n");
      }
      return false;
      break;
    case CARET:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              register_code(DV_6);
              unregister_code(DV_6);
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              register_code(DV_6);
              unregister_code(DV_6);
          } else {
              SEND_STRING ("^");
          }
          dprint("Sent string: ^ \n");
      }
      return false;
      break;
    case PERCENT:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              register_code(DV_5);
              unregister_code(DV_5);
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              register_code(DV_5);
              unregister_code(DV_5);
          } else {
              SEND_STRING ("%");
          }
          dprint("Sent string: % \n");
      }
      return false;
      break;
    case PLUS:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              register_code(KC_8);
              unregister_code(KC_8);
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              register_code(KC_8);
              unregister_code(KC_8);
          } else {
              SEND_STRING ("+");
          }
          dprint("Sent string: +\n");
      }
      return false;
      break;
    case L:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("L");
              dprint("Sent string: L\n");
          } else {
              SEND_STRING ("l");
              dprint("Sent string: l\n");
          }      }
      return false;
      break;
    case R:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("R");
              dprint("Sent string: R\n");
          } else {
              SEND_STRING ("r");
              dprint("Sent string: r\n");
          }
      }
      return false;
      break;
    case C:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("C");
              dprint("Sent string: C\n");
          } else {
              SEND_STRING ("c");
              dprint("Sent string: c\n");
          }
      }
      return false;
      break;
    case G:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("G");
              dprint("Sent string: G\n");
          } else {
              SEND_STRING ("g");
              dprint("Sent string: g\n");
          }
      }
      return false;
      break;
    case F:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("F");
              dprint("Sent string: F\n");
          } else {
              SEND_STRING ("f");
              dprint("Sent string: f\n");
          }
      }
      return false;
      break;
    case PIPE:
      if (record->event.pressed) {
        SEND_STRING ("|");
        dprint("Sent string: |\n");
      }
      return false;
      break;
    case S:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("S");
              dprint("Sent string: S\n");
          } else {
              SEND_STRING ("s");
              dprint("Sent string: s\n");
          }
      }
      return false;
      break;
    case N:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("N");
              dprint("Sent string: N\n");
          } else {
              SEND_STRING ("n");
              dprint("Sent string: n\n");
          }
      }
      return false;
      break;
    case T:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("T");
              dprint("Sent string: T\n");
          } else {
              SEND_STRING ("t");
              dprint("Sent string: t\n");
          }
      }
      return false;
      break;
    case H:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("H");
              dprint("Sent string: H\n");
          } else {
              SEND_STRING ("h");
              dprint("Sent string: h\n");
          }
      }
      return false;
      break;
    case D:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("D");
              dprint("Sent string: D\n");
          } else {
              SEND_STRING ("d");
              dprint("Sent string: d\n");
          }
      }
      return false;
      break;
    case Z:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("Z");
              dprint("Sent string: Z\n");
          } else {
              SEND_STRING ("z");
              dprint("Sent string: z\n");
          }
      }
      return false;
      break;
    case V:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("V");
              dprint("Sent string: V\n");
          } else {
              SEND_STRING ("v");
              dprint("Sent string: v\n");
          }
      }
      return false;
      break;
    case W:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("W");
              dprint("Sent string: W\n");
          } else {
              SEND_STRING ("w");
              dprint("Sent string: w\n");
          }
      }
      return false;
      break;
    case M:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("M");
              dprint("Sent string: M\n");
          } else {
              SEND_STRING ("m");
              dprint("Sent string: m\n");
          }
      }
      return false;
      break;
    case B:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("B");
              dprint("Sent string: B\n");
          } else {
              SEND_STRING ("b");
              dprint("Sent string: b\n");
          }
      }
      return false;
      break;
    case ZERO:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_0);
              unregister_code(DV_0);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_0);
              unregister_code(DV_0);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("0");
          }
        dprint("Sent string: 0\n");
      }
      return false;
      break;
    case ONE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_1);
              unregister_code(DV_1);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_1);
              unregister_code(DV_1);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("1");
          }
        dprint("Sent string: 1\n");
      }
      return false;
      break;
    case TWO:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_2);
              unregister_code(DV_2);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_2);
              unregister_code(DV_2);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("2");
          }
        dprint("Sent string: 2\n");
      }
      return false;
      break;
    case THREE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_3);
              unregister_code(DV_3);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_3);
              unregister_code(DV_3);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("3");
          }
        dprint("Sent string: 3\n");
      }
      return false;
      break;
    case FOUR:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_4);
              unregister_code(DV_4);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_4);
              unregister_code(DV_4);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("4");
          }
        dprint("Sent string: 4\n");
      }
      return false;
      break;
    case FIVE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_5);
              unregister_code(DV_5);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_5);
              unregister_code(DV_5);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("5");
          }
        dprint("Sent string: 5\n");
      }
      return false;
      break;
    case SIX:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_6);
              unregister_code(DV_6);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_6);
              unregister_code(DV_6);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("6");
          }
        dprint("Sent string: 6\n");
      }
      return false;
      break;
    case SEVEN:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_7);
              unregister_code(DV_7);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_7);
              unregister_code(DV_7);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("7");
          }
        dprint("Sent string: 7\n");
      }
      return false;
      break;
    case EIGHT:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_8);
              unregister_code(DV_8);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_8);
              unregister_code(DV_8);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("8");
          }
        dprint("Sent string: 8\n");
      }
      return false;
      break;
    case NINE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(DV_9);
              unregister_code(DV_9);
              add_mods(MOD_BIT(KC_LSHIFT));
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(DV_9);
              unregister_code(DV_9);
              add_mods(MOD_BIT(KC_RSHIFT));
          } else {
              SEND_STRING ("9");
          }
        dprint("Sent string: 9\n");
      }
      return false;
      break;
  }
  return true;
}

void led_matrix_indicators_user(void) {
    set_led_theme();

    if (IS_LAYER_ON(LAYER_BASE) & !IS_LAYER_ON(LAYER_NUMROW) & !IS_LAYER_ON(LAYER_FNROW) & !IS_LAYER_ON(LAYER_NUMPAD)) {
        set_led_theme();
    }

    if (IS_LAYER_ON(LAYER_NUMROW)) {
        set_top_row_led(200, 0, 255);   // VIOLET
    }

    if (IS_LAYER_ON(LAYER_NUMPAD)) {
        set_numpad_keys(200, 0, 255);   // VIOLET
    }

    if (IS_LAYER_ON(LAYER_FNROW)){
        set_top_row_led(255, 255, 0);   // YELLOW
    }
}
