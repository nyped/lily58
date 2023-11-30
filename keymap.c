#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    SCROLL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC~ |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | REP  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |BackSP|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LCTRL |LOWER | LAlt | /Space  /       \Enter \  | RGUI |RAISE | MENU |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_QWERTY] = LAYOUT(
          QK_GESC,  KC_1, KC_2,       KC_3,    KC_4,    KC_5,                     KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    QK_REP,
          KC_TAB,   KC_Q, KC_W,       KC_E,    KC_R,    KC_T,                     KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
          KC_BSPC,  KC_A, KC_S,       KC_D,    KC_F,    KC_G,                     KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     OSM(MOD_LSFT), KC_Z, KC_X,       KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),
                       KC_LCTL, MO(_LOWER), KC_LALT,  KC_SPC,  KC_ENT,  KC_RGUI,  MO(_RAISE), KC_APP
    ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | BTN1 | BTN3 | BTN2 |SCROLL|      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | Prev |PPause| Next | WFWD |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      | Mute | VolD | VolU |      | WBAK |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |RCTRL |LOWER | LAlt | /Space  /       \Enter \  | RGUI |RAISE | MENU |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LOWER] = LAYOUT(
      KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
      XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2,  SCROLL, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_WFWD, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_WBAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                  KC_RCTL,_______, _______,     _______, _______,  _______, _______, _______
    ),

    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      | Home |  End |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|   +  |   -  |   =  |   |  |   \  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LCTRL |LOWER | LAlt | /Space  /       \Enter \  | RGUI |RAISE | MENU |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_RAISE] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_HOME,  KC_END, XXXXXXX, XXXXXXX,

      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  KC_PLUS, KC_PMNS, KC_PEQL, KC_PIPE, KC_BSLS, _______,
                                 _______, _______, _______,  _______, _______,  _______, _______, _______
    ),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LCTRL |LOWER | LAlt | /Space  /       \Enter \  | RGUI |RAISE | MENU |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ADJUST] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, _______,  _______, _______, _______
    ),
    // clang-format on
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Process macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCROLL: /* Scroll toggle on ploopy */
            if (record->event.pressed) {
                register_code(KC_NUM);
                unregister_code(KC_NUM);
                register_code(KC_NUM);
                unregister_code(KC_NUM);
            }
            break;

        default: /* FALLTHROUGH */
            break;
    }
    return true;
};
