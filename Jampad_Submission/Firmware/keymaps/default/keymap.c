#include QMK_KEYBOARD_H

enum layer_names {
    _BASE
};

/*
 * ┌──────────┬──────────┬──────────┐
 * │ Undo     │ Copy     │ Paste    │
 * ├──────────┼──────────┼──────────┤
 * │ Previous │ Play     │ Next     │
 * ├──────────┼──────────┼──────────┤
 * │ Escape   │ Screenshot│ Delete  │
 * └──────────┴──────────┴──────────┘
 *
 * Encoder: counter-clockwise = volume down; clockwise = volume up.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_3x3(
        C(KC_Z),    C(KC_C),    C(KC_V),
        KC_MPRV,    KC_MPLY,    KC_MNXT,
        KC_ESC,     G(S(KC_S)), KC_DEL
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_ln_P(PSTR("JAMPAD"), false);
    oled_write_ln_P(PSTR("XIAO RP2040"), false);
    oled_write_ln_P(PSTR("Knob: Volume"), false);

    led_t host_leds = host_keyboard_led_state();
    oled_write_P(PSTR("Caps: "), false);
    oled_write_ln_P(host_leds.caps_lock ? PSTR("ON") : PSTR("off"), false);

    return false;
}
#endif

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(128, 255, 48);
#endif
}
