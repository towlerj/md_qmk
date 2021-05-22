#include QMK_KEYBOARD_H

enum shift_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_EDG_I,            //LED Edge Brightness Increase
    L_EDG_D,            //LED Edge Brightness Decrease
    L_EDG_M,            //LED Edge lighting mode
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction and effect
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    DBG_FAC,            //DEBUG Factory light testing (All on white)
    MD_BOOT,            //Restart into bootloader after hold timeout
	L_RATIOI,			// Increase Key to Underglow LED brightness Ratio
	L_RATIOD			// Decrease Key to Underglow LED brightness Ratio
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

// JT additions
//#define JT_SP1 LT(_MEDIA, KC_SPC)     // Media layer while held, otherwise space
//#define JT_SP2 LT(_NUMPAD, KC_SPC)    // NumPad layer while held, otherwise space
//#define JT_SP3 LT(_RAISE, KC_SPC)     // Raise while held, space on tap
#define JT_SP1 LT(1, KC_SPC)            // Raise while held, space on tap

//#define JT_EN1 LT(_LOWER, KC_ENT)     // Lower while held, enter on tap
//#define JT_EN2 LT(_MEDIA, KC_ENT)     // Lower while held, enter on tap

//#define JT_AP1 LT(_ADJUST, KC_APP)    // Adjust while held, app/menu on tap
#define JT_AP2 LT(2, KC_APP)            // Layer 2 while held,app/menu on tap
#define JT_AP3 LT(3, KC_APP)            // Layer 2 while held,app/menu on tap

#define JT_DL2 LT(2, KC_DEL)            // Layer 2 while held, delete on tap
#define JT_DL3 LT(3, KC_DEL)            // Layer 3 while held, delete on tap

#define JT_CAD C(A(KC_DEL))             // Control Alt Delete
#define JT_CSL C(S(KC_LEFT))            // Control Shift Left
#define JT_CSR C(S(KC_RIGHT))           // Control Shift Right
#define JT_CLF C(KC_LEFT)               // Control Left
#define JT_CRT C(KC_RIGHT)              // Control Right
#define JT_CHM C(KC_HOME)               // Control Home
#define JT_CND C(KC_END)                // Control End
#define JT_SUP S(KC_UP)                 // Shift Up
#define JT_SDN S(KC_DOWN)               // Shift Down
#define JT_CUP C(KC_UP)                 // Shift Down
#define JT_CDW C(KC_DOWN)               // Shift Down
//#define JT_ES1 LT(_MEDIA, KC_ESC)       // Escape when tapped, otherwise switch to numpad
//#define JT_ES2 LT(_NUMPAD, KC_ESC)      // Escape when tapped, otherwise switch to numpad



#define JT_MN1 LT(_MEDIA, KC_MINUS)     // Minus when tapped, otherwise media
#define JT_MN2 LT(_NUMPAD, KC_MINUS)    // Minus when tapped, otherwise numpad

//#define JT_SVU C(S(A(KC_F23)))          // Control, shift, alt F23 - triggers vol up on sonos script
//#define JT_SVD C(S(A(KC_F22)))          // Control, shift, alt F22 - triggers vol up on sonos script

#define JT_SVU MEH(KC_F23)              // Control, shift, alt F23 - triggers vol up on sonos script
#define JT_SVD MEH(KC_F22)              // Control, shift, alt F22 - triggers vol up on sonos script

//#define JT_GBP RALT(RSFT(KC_4))          // Should send £ symbol for us int keyboard


enum {
	TD_CPY,
    TD_CPJ,
    TD_UP,
    TD_DN,
    TD_LF,
    TD_RG,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CPY]    = ACTION_TAP_DANCE_DOUBLE(KC_Y,    KC_CAPSLOCK),
    [TD_CPJ]    = ACTION_TAP_DANCE_DOUBLE(KC_J,    KC_CAPSLOCK),
    [TD_UP]     = ACTION_TAP_DANCE_DOUBLE(KC_UP,   KC_PGUP),
    [TD_DN]     = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
    [TD_LF]     = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
    [TD_RG]     = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END),

};


keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F2,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_HOME, KC_END,  KC_PGUP, KC_PGDN, \
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          TG(2),   KC_PSLS, KC_PAST, KC_PSCR, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TD(TD_CPY), KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_7,    KC_8,    KC_9,    KC_PMNS, \
        JT_DL2,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_4,    KC_5,    KC_6,    KC_PPLS, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                            KC_1,    KC_2,    KC_3,             \
                                                                                                                                KC_UP,                                       KC_PENT, \
        KC_LCTL, KC_LGUI, KC_LALT,                   JT_SP1,                                KC_RALT, JT_AP3,                                               KC_0,    KC_DOT,          \
                                                                                                                        KC_LEFT, KC_DOWN, KC_RGHT                                     \
    ),
    [1] = LAYOUT(
        KC_GRV,  MEH(KC_1),MEH(KC_2),MEH(KC_3),MEH(KC_4),MEH(KC_5),MEH(KC_6),MEH(KC_7),MEH(KC_8),MEH(KC_9),MEH(KC_0),_______, _______, KC_INS,     KC_MPLY, KC_MSTP, KC_VOLU, KC_MUTE, \
        KC_TILD, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,  _______,    KC_HOME, KC_END,  KC_PGUP, KC_PGDN, \
        KC_TILD, _______,  C(KC_W),  _______,  C(KC_R),  C(KC_T),  _______,  _______,  U_T_AGCR, _______,  _______,  _______, _______, KC_SLEP,    KC_MPRV, KC_MNXT, KC_VOLD, KC_SLCK, \
        _______, C(KC_A),  C(KC_S),  _______,  C(KC_F),  _______,  _______,  KC_LALT,  KC_TAB,   KC_LCTL,  _______,  _______, _______,             _______, _______, _______, _______, \
        _______, C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______, _______, _______,          \
                                                                                                                              KC_PGUP,                                        _______, \
        _______, _______, _______,                   _______,                            KC_APP,  _______,                                                  _______, _______,          \
                                                                                                                     KC_HOME, KC_PGDN, KC_END                                         \
    ),
    [2] = LAYOUT(
        _______,  KC_F1,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______, _______, _______,    KC_HOME, KC_END,  KC_PGUP, KC_PGDN, \
        KC_TILD,  _______, _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______, _______, _______,    _______, KC_PSLS, KC_PAST, KC_PSCR, \
        _______,  _______, _______,  _______,  _______,  _______,  KC_Y,     _______,   _______,  _______,  _______,  _______, _______, _______,    KC_P7,   KC_P8,   KC_P9,   KC_PMNS, \
        KC_SPACE, _______, _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______, _______,             KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
        _______,  _______, _______,  _______,  _______,  S(KC_B),  _______,  _______,   _______,  _______,  _______,  _______,                      KC_P1,   KC_P2,   KC_P3,            \
                                                                                                                             _______,                                         KC_PENT, \
        _______,  _______, _______,                   KC_SPACE,                            _______, _______,                                                  KC_P0,   KC_DOT,          \
                                                                                                                    _______, _______, _______                                          \
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_HOME, KC_END,  KC_PGUP, KC_PGDN, \
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,           KC_NLCK, KC_PSLS, KC_PAST, KC_PSCR, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   L_EDG_I, _______, _______, _______, U_T_AGCR, _______, _______, KC_SLCK, KC_PAUS,_______,           KC_P7,   KC_P8,   KC_P9,   KC_PMNS, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   L_EDG_D, _______, _______, _______, _______,  _______, _______, _______, _______,                   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
        _______, L_T_MD,  L_T_ONF, _______, L_EDG_M, MD_BOOT, TG_NKRO, _______, _______,  _______, _______, _______,                            KC_P1,   KC_P2,   KC_P3,            \
                                                                                                                             _______,                                     KC_PENT, \
        _______, _______, _______,                   DBG_FAC,                            _______, _______,                                              KC_P0,   KC_DOT,          \
                                                                                                                    _______, _______, _______                                      \
    ),

    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,           _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______,          \
                                                                                                                             _______,                                     _______, \
        _______, _______, _______,                   _______,                            _______, _______,                                     _______, _______,                   \
                                                                                                                    _______, _______, _______                                      \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    gcr_desired         = 32;
    led_edge_brightness = 0.10;
    led_animation_speed = 1;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    static uint8_t scroll_effect = 0;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_EDG_M:
            if (record->event.pressed) {
                led_edge_mode++;
                if (led_edge_mode > LED_EDGE_MODE_MAX) {
                    led_edge_mode = LED_EDGE_MODE_ALL;
                }
            }
            return false;
        case L_EDG_I:
            if (record->event.pressed) {
                led_edge_brightness += 0.1;
                if (led_edge_brightness > 1) { led_edge_brightness = 1; }
            }
            return false;
        case L_EDG_D:
            if (record->event.pressed) {
                led_edge_brightness -= 0.1;
                if (led_edge_brightness < 0) { led_edge_brightness = 0; }
            }
            return false;
        case L_RATIOI:
            if (record->event.pressed) {
                led_ratio_brightness += 0.2;
                if (led_ratio_brightness > 2.0) { led_ratio_brightness = 2.0; }
            }
            return false;
        case L_RATIOD:
            if (record->event.pressed) {
                led_ratio_brightness -= 0.2;
                if (led_ratio_brightness < 0.0) { led_ratio_brightness = 0.0; }
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
            	led_mfg_test_mode = LED_MFG_TEST_MODE_OFF;
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
            	led_mfg_test_mode = LED_MFG_TEST_MODE_OFF;
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                //I2C3733_Control_Set(!I2C3733_Control_Get());
            	led_lighting_mode = ((led_lighting_mode == LED_MODE_INDICATORS_ONLY)? LED_MODE_NORMAL : LED_MODE_INDICATORS_ONLY);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                I2C3733_Control_Set(1);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                I2C3733_Control_Set(0);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                scroll_effect++;
                if (scroll_effect == 1) {               //Patterns with scroll move horizontal (Right to left)
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                } else if (scroll_effect == 2) {        //Patterns with scroll move vertical (Top to bottom)
                    led_animation_direction = 1;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 3) {        //Patterns with scroll move vertical (Bottom to top)
                    led_animation_direction = 0;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 4) {        //Patterns with scroll explode from center
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else if (scroll_effect == 5) {        //Patterns with scroll implode on center
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else {                                //Patterns with scroll move horizontal (Left to right)
                    scroll_effect = 0;
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                }
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_FAC:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
            	led_mfg_test_mode = LED_MFG_TEST_MODE_ON;
            	led_lighting_mode = LED_MODE_NORMAL;
                led_edge_brightness = 1;
                led_edge_mode = LED_EDGE_MODE_ALL;
                led_animation_breathing = 0;
                led_animation_id = 7; //led_programs.c led_setups leds_white index
                gcr_desired = LED_GCR_MAX;
                I2C3733_Control_Set(1);
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions[] = {
    //LEDs are normally inactive, no processing is performed on them
    //Flags are used in matching criteria for an LED to be active and indicate how to color it
    //Flags can be found in tmk_core/protocol/arm_atsam/led_matrix.h (prefixed with LED_FLAG_)
    //LED IDs can be found in config_led.h in the keyboard's directory
    //Examples are below

    //All LEDs use the user's selected pattern (this is the factory default)
     { .flags = LED_FLAG_USE_ROTATE_PATTERN },

    //Specific LEDs use the user's selected pattern while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 0xFFFFFFFF, .id1 = 0xAAAAAAAA, .id2 = 0x55555555, .id3 = 0x11111111 },

    //Specific LEDs use specified RGB values while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFF, .id1 = 0x00FF, .id2 = 0x0000FF00, .id3 = 0xFF000000, .r = 75, .g = 150, .b = 225 },

    //All LEDs use the user's selected pattern
    //On layer 1, all key LEDs (except the top row which keeps active pattern) are red while all edge LEDs are green
    //When layer 1 is active, key LEDs use red    (id0  32 -  17: 1111 1111 1111 1111 0000 0000 0000 0000 = 0xFFFF0000) (except top row 16 - 1)
    //When layer 1 is active, key LEDs use red    (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //When layer 1 is active, key LEDs use red    (id2  87 -  65: 0000 0000 0111 1111 1111 1111 1111 1111 = 0x007FFFFF)
    //When layer 1 is active, edge LEDs use green (id2  95 -  88: 1111 1111 1000 0000 0000 0000 0000 0000 = 0xFF800000)
    //When layer 1 is active, edge LEDs use green (id3 119 -  96: 0000 0000 1111 1111 1111 1111 1111 1111 = 0x00FFFFFF)
    // { .flags = LED_FLAG_USE_ROTATE_PATTERN },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0xFFFF0000, .id1 = 0xFFFFFFFF, .id2 = 0x007FFFFF, .r = 255, .layer = 1 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id2 = 0xFF800000, .id3 = 0x00FFFFFF, .g = 127, .layer = 1 },

    //All key LEDs use red while edge LEDs use the active pattern
    //All key LEDs use red     (id0  32 -   1: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id2  87 -  65: 0000 0000 0111 1111 1111 1111 1111 1111 = 0x007FFFFF)
    //Edge uses active pattern (id2  95 -  88: 1111 1111 1000 0000 0000 0000 0000 0000 = 0xFF800000)
    //Edge uses active pattern (id3 119 -  96: 0000 0000 1111 1111 1111 1111 1111 1111 = 0x00FFFFFF)
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFFFFFFFF, .id1 = 0xFFFFFFFF, .id2 = 0x007FFFFF, .r = 255 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN , .id2 = 0xFF800000, .id3 = 0x00FFFFFF },


    // JT TEST id0 = 262143
    /*
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 4294967295, .id1 = 4294967295, .id2 = 4294967295, .id3 = 6, .r = 255, .g = 0,   .b = 255, .layer = 1 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 4294967295, .id1 = 4294967295, .id2 = 4294967295, .id3 = 6, .r = 0,   .g = 255, .b = 255, .layer = 2 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 4294967295, .id1 = 4294967295, .id2 = 4294967295, .id3 = 6, .r = 255, .g = 120, .b = 60,  .layer = 3 },
    */
   /*
   { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 1048574, .id5 = 4080,  .r = 255, .g = 0,   .b = 255, .layer = 1 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 1048574, .id5 = 4080,  .r = 0,   .g = 255, .b = 255, .layer = 2 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 1048574, .id5 = 4080,  .r = 255, .g = 0,   .b = 0,   .layer = 3 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_RGB, .id3 = 4294967232, .id4 = 4294967295, .id5 = 15, .r = 0, .g = 0,   .b = 0},
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                    .id3 = 4294967232, .id4 = 4294967295, .id5 = 15, .pattern_id = 1},
    */

   // JT NOTE - these are in qmk_firmware\tmk_core\protocol\arm_atsam\led_matrix_programs.c
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 4294967295, .id1 = 4294967295, .id2 = 4294967295,.id3 = 4294967232, .id4 = 4294967295, .id5 = 4080,  .r = 255, .g = 0,   .b = 255, .layer = 1 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 4294967295, .id1 = 4294967295, .id2 = 4294967295,.id3 = 4294967232, .id4 = 4294967295, .id5 = 4080,  .r = 0  , .g = 125, .b = 125, .layer = 2 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 4294967295, .id4 = 4294967295, .id5 = 4080,  .r = 0,   .g = 255, .b = 0,   .layer = 3 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_RGB, .id3 = 4294967232, .id4 = 4294967295, .id5 = 15, .r = 0, .g = 0,   .b = 0},
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                    .id3 = 4294967232, .id4 = 4294967295, .id5 = 15, .pattern_id = 1},

    //end must be set to 1 to indicate end of instruction set
     { .end = 1 }
};
