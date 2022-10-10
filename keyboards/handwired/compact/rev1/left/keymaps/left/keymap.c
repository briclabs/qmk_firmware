#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_dvorak.h"
#include "sendstring_dvorak.h"

#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define LAYER_BASE   0
#define LAYER_NUMROW 1
#define LAYER_FNROW  2

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    TOP_ROW_CHANGE,
    TOP_ROW_DEFAULT,
    HYPHEN,
    PARENS_OPEN,
    PARENS_CLOSE,
    AT_SIGN,
    POUND_SIGN,
    DOLLAR_SIGN,
    TILDE,
    APOSTROPHE,
    COMMA,
    PERIOD,
    P,
    Y,
    AMPERSAND,
    A,
    O,
    E,
    U,
    I,
    SEMICOLON,
    Q,
    J,
    K,
    X,
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
 *        |TR_CHG|   -  |   (  |   )  |   @  |   #  |   $  |   ~  |
 *        `------+------+------+------+------+------+------+------|
 *        |     TAB     |   '  |   ,  |   .  |   P  |   Y  |   &  |
 * ,------+------+------+------+------+------+------+------+------|
 * |  OS  |  ALT | CTRL |   A  |   O  |   E  |   U  |   I  | "END"|
 * `------+------+------+------+------+------+------+------+------|
 *        |    SHIFT    |   ;  |   Q  |   J  |   K  |   X  | BACK |
 * ,------+------+------+------+------+------+------+------+      |
 * | PGDN |  UP  | PGUP |                                  | SPC  |
 * |------+------+------'                                  `------'
 * | LEFT |  DN  | RIGHT|
 * `--------------------'
 *
 */
[LAYER_BASE] = LAYOUT(
          TOP_ROW_CHANGE,         HYPHEN,     PARENS_OPEN,     PARENS_CLOSE,     AT_SIGN,     POUND_SIGN,     DOLLAR_SIGN,         TILDE,
                                  KC_TAB,      APOSTROPHE,            COMMA,      PERIOD,           DV_P,            DV_Y,     AMPERSAND,
   KC_LGUI,      KC_LALT,       KC_LCTRL,            DV_A,             DV_O,        DV_E,           DV_U,            DV_I,        KC_END,
                                 KC_LSFT,       SEMICOLON,             DV_Q,        DV_J,           DV_K,            DV_X,       KC_BSPC,
 KC_PGDOWN,        KC_UP,        KC_PGUP,
   KC_LEFT,      KC_DOWN,       KC_RIGHT
),
/* Keymap 1: Number layer
  *
 *        ,-------------------------------------------------------.
 *        |TR_DEF|      |   0  |   1  |   2  |   3  |   4  |   5  |
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
           TOP_ROW_DEFAULT,     KC_TRNS,       ZERO,        ONE,        TWO,      THREE,       FOUR,       FIVE,
                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS,
   KC_TRNS,        KC_TRNS,     KC_TRNS
),
/* Keymap 2: Function layer
 *
 *        ,-------------------------------------------------------.
 *        |TR_DEF|      |      |  F1  |  F2  |  F3  |  F4  |  F5  |
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
    case HYPHEN:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("_");
              dprint("Sent string: _\n");
          } else {
              SEND_STRING("-");
              dprint("Sent string: -\n");
          }
      }
      break;
    case PARENS_OPEN:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              unregister_code(KC_LSHIFT);
              SEND_STRING ("[");
              dprint("Sent string: [\n");
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              unregister_code(KC_RSHIFT);
              SEND_STRING ("[");
              dprint("Sent string: [\n");
          } else {
              SEND_STRING ("(");
              dprint("Sent string: (\n");
          }
      }
      return false;
      break;
    case PARENS_CLOSE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              unregister_code(KC_LSHIFT);
              SEND_STRING ("]");
              dprint("Sent string: ]\n");
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              unregister_code(KC_RSHIFT);
              SEND_STRING ("]");
              dprint("Sent string: ]\n");
          } else {
              SEND_STRING (")");
              dprint("Sent string: )\n");
          }
      }
      return false;
      break;
    case AT_SIGN:
      if (record->event.pressed) {
        SEND_STRING ("@");
        dprint("Sent string: @\n");
      }
      return false;
      break;
    case POUND_SIGN:
      if (record->event.pressed) {
        SEND_STRING ("#");
        dprint("Sent string: #\n");
      }
      return false;
      break;
    case DOLLAR_SIGN:
      if (record->event.pressed) {
        SEND_STRING ("$");
        dprint("Sent string: $\n");
      }
      return false;
      break;
    case TILDE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
              del_mods(MOD_BIT(KC_LSHIFT));
              register_code(KC_GRAVE);
              unregister_code(KC_GRAVE);
              add_mods(MOD_BIT(KC_LSHIFT));
              dprint("Sent string: `\n");
          } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
              del_mods(MOD_BIT(KC_RSHIFT));
              register_code(KC_GRAVE);
              unregister_code(KC_GRAVE);
              add_mods(MOD_BIT(KC_RSHIFT))
              dprint("Sent string: `\n");
          } else {
              SEND_STRING("~");
              dprint("Sent string: ~\n");
          }
      }
      return false;
      break;
    case APOSTROPHE:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("\"");
              dprint("Sent string: \"\n");
          } else {
              SEND_STRING ("'");
              dprint("Sent string: '\n");
          }
      }
      return false;
      break;
    case COMMA:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("?");
              dprint("Sent string: ?\n");
          } else {
              SEND_STRING (",");
              dprint("Sent string: ,\n");
          }
      }
      return false;
      break;
    case PERIOD:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING ("!");
              dprint("Sent string: !\n");
          } else {
              SEND_STRING (".");
              dprint("Sent string: .\n");
          }
      }
      return false;
      break;
    case AMPERSAND:
      if (record->event.pressed) {
        SEND_STRING ("&");
        dprint("Sent string: &\n");
      }
      return false;
      break;
    case SEMICOLON:
      if (record->event.pressed) {
          if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {
              SEND_STRING (":");
              dprint("Sent string: :\n");
          } else {
              SEND_STRING (";");
              dprint("Sent string: ;\n");
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
    if (IS_LAYER_ON(LAYER_BASE) && !IS_LAYER_ON(LAYER_NUMROW) && !IS_LAYER_ON(LAYER_FNROW)) {
        set_led_theme();
    } else if (IS_LAYER_ON(LAYER_NUMROW)) {
        set_top_row_led(200, 0, 255);   // VIOLET
    } else if (IS_LAYER_ON(LAYER_FNROW)) {
        set_top_row_led(200, 255, 0);   // YELLOW
    }
}
