enum planck_keycodes {
    DYNAMIC_MACRO_RANGE,
};

#include "dz60.h"
#include "secret.h"
#include "dynamic_macro.h"

// layers
#define _BL 0 // base layer
#define _FL 1 // function layer
#define _LL 2 // lighting layer
#define _ML 3 // macro layer

// macros
#define M_FX 0 // firefox master

// readability
#define _______ KC_TRNS
#define ___X___ KC_NO
#define FN_CAPS LT(_FL, KC_CAPS)
#define RGB_SWL RGB_M_SW
#define RGB_SNK RGB_M_SN
#define RGB_PLN RGB_M_P
#define RGB_BTH RGB_M_B
#define RGB_RNB RGB_M_R
#define MAC_RC1 DYN_REC_START1
#define MAC_RC2 DYN_REC_START2
#define MAC_PL1 DYN_MACRO_PLAY1
#define MAC_PL2 DYN_MACRO_PLAY2
#define MAC_STP DYN_REC_STOP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = KEYMAP(
        KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC ,
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_NUHS ,
        FN_CAPS , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  ,
        KC_LSFT , KC_NUBS , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
        KC_LCTL , KC_LGUI , KC_LALT , KC_SPC  , MO(_FL) , MO(_ML) , KC_RALT , KC_RGUI , MO(_LL) , KC_RCTL
    ),
    [_FL] = KEYMAP(
        KC_GRV  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_DEL  ,
        _______ , RESET   , KC_UP   , _______ , KC_BTN1 , KC_MS_U , KC_BTN2 , _______ , KC_UP   , _______ , KC_PSCR , _______ , _______ , _______ ,
        _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_MS_L , KC_MS_D , KC_MS_R , KC_LEFT , KC_DOWN , KC_RGHT , _______ , _______ , _______ ,
        _______ , M(M_FX) , MAC_PL1 , MAC_PL2 , _______ , _______ , KC_VOLD , KC_VOLU , KC_MUTE , KC_MPRV , KC_MNXT , KC_MPLY , _______ ,
        _______ , _______ , _______ , KC_PGDN , _______ , KC_PGUP , _______ , _______ , _______ , _______
    ),
    [_LL] = KEYMAP(
        RGB_TOG , RGB_PLN , RGB_BTH , RGB_RNB , RGB_SWL , RGB_SNK , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , RGB_HUD , RGB_SAD , RGB_VAD , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),
    [_ML] = KEYMAP(
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , MAC_RC1 , MAC_RC2 , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    )
};

const macro_t *action_get_macro(keyrecord_t *record , uint8_t id , uint8_t opt) {
    keyevent_t event = record->event;
    if (event.pressed) {
        switch (id) {
            case M_FX:
                SEND_STRING(SEC_FF_MASTER);
                return false;
        }
    }
    return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode , keyrecord_t *record) {
    uint16_t macro_kc = (keycode == MO(_ML) ? DYN_REC_STOP : keycode);
    if (!process_record_dynamic_macro(macro_kc, record)) {
		return false;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {
}