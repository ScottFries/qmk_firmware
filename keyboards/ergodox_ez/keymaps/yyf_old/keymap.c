#include QMK_KEYBOARD_H
#include "version.h"

#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

#define L_DVORAK    0
#define L_QWERTY    1
#define L_SYMBOLS   2
#define L_SYS_CTRL  3
#define L_IDS       4
#define L_CPP       5
#define L_UE4       6
#define L_PYTHON    7
#define L_NAVIGATE  8

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,

  #define YYF_INJECT_KEYCODES
  #include "custom_keys/id.inl"
  #include "custom_keys/cpp.inl"
  #include "custom_keys/ue4.inl"
  #include "custom_keys/python.inl"
  #undef YYF_INJECT_KEYCODES
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |  L8    |   1  |   2  |   3  |   4  |   5  |   [  |           |  ]   |   6  |   7  |   8  |   9  |   0  |   \    |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |  ~L2   |  '"  |   ,  |   .  |   P  |   Y  |   _  |           |  ;   |   F  |   G  |   C  |   R  |   L  |   /    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * | Caps   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
  * |--------+------+------+------+------+------|Macro1|           |Macro2|------+------+------+------+------+--------|
  * |LShift (|   ;  |   Q  |   J  |   K  |   X  | Play |           | Play |   B  |   M  |   W  |   V  |   Z  |=/RShift|
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   | M1r  |Cp/~L4|Pt/~L7|Scr/Gui|SysReq/Alt|                                   |  Up  | Down | Left |Right |  M2r |
  *   `----------------------------------'                                       `-----------------------------------'
  *                                      ,---------------.       ,--------------.
  *                                      |Esc/Meh|  Gui  |       | MStop | Del  |
  *                               ,------|-------|-------|       |------+--------+------.
  *                               |      |       |Hom/Alt|       |PgU/~L5|      |      |
  *                               |  Tab | Space |-------|       |-------|BackSp|Enter |
  *                               |      |       |End/Ctr|       |PgD/~L6|      |      |
  *                               `----------------------'       `----------------------'
  */
  [0] = LAYOUT_ergodox_pretty(
    TO(8),          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LBRACKET,                                    KC_RBRACKET,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLASH,
    MO(2),          KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_UNDS,                                        KC_SCOLON,      KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,
    KC_CAPSLOCK,    KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                                                           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,
    KC_LSPO,        KC_GRAVE,       KC_Q,           KC_J,           KC_K,           KC_X,           DYN_MACRO_PLAY1,                                DYN_MACRO_PLAY2,KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           RSFT_T(KC_EQUAL),
    DYN_REC_START1, LT(L_IDS, LCTL(KC_C)),LT(L_PYTHON, LCTL(KC_V)),LGUI_T(KC_SCROLLLOCK),LALT_T(KC_PSCREEN),                                                                        KC_UP,          KC_DOWN,        KC_LEFT,        KC_RIGHT,       DYN_REC_START2,
                                                                                                    MT(MOD_MEH, KC_ESCAPE),KC_LGUI,         DYN_REC_STOP,           KC_DELETE,
                                                                                                                    LALT_T(KC_HOME),        LT(L_CPP, KC_PGUP),
                                                                                    KC_TAB,         KC_SPACE,       LCTL_T(KC_END),         LT(L_UE4, KC_PGDOWN),   KC_BSPACE,      KC_ENTER
  ),
  /* Keymap 1: QWERTY
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |        +------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
  * |        +------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
  * |        +------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |Z/LCtl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//RCtl|        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |        |        |        |       |                                       |      |      |      |      |       |
  *   `----------------------------------'                                       `-----------------------------------'
  *                                      ,---------------.       ,--------------.
  *                                      |       |       |       |       |      |
  *                               ,------|-------|-------|       |       --------+------.
  *                               |      |       |       |       |       |      |      |
  *                               |      |       |-------|       |       |      |      |
  *                               |      |       |       |       |       |      |      |
  *                               `----------------------'       `----------------------'
  */
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keymap 2: Symbols
  *
  * ,---------------------------------------------------.           ,--------------------------------------------------.
  * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
  * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
  * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   F12  |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |    -   |
  * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
  * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |       |      |      |      |      |                                       |      |   .  |   0  |   =  |      |
  *   `-----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |Animat| Red  |       |Toggle|Solid |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |Bright|Bright| Green|       |      |Hue-  |Hue+  |
  *                                 |ness- |ness+ |------|       |------|      |      |
  *                                 |      |      | Blue |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    RGB_MOD,        HSV_0_255_255,  RGB_TOG,        RGB_SLD,
                                                                                                                    HSV_86_255_128, KC_TRANSPARENT,
                                                                                    RGB_VAD,        RGB_VAI,        HSV_172_255_255,KC_TRANSPARENT, RGB_HUD,        RGB_HUI
  ),
  /* Keymap 3: System Control
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  Power |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |      |      | MsUp |      |      |Bright|           |Bright|      |      |      |      |      |  Sleep |
  * |--------+------+------+------+------+------|  Up  |           |  Dn  |------+------+------+------+------+--------|
  * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      | NKRO |      |  Wake  |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   | Oryx |      |      |      |      |                                       |Pause | Play | Prev | Next |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |WhlLef|       |WhlRgh| Mclk |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |WhlUp |      |      |
  *                                 | VolUp| VolDn|------|       |------| Lclk | Rclk |
  *                                 |      |      | Mute |       |WhlDn |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SYSTEM_POWER,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_UP,                                KC_BRIGHTNESS_DOWN,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SYSTEM_SLEEP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MAGIC_TOGGLE_NKRO,KC_TRANSPARENT, KC_SYSTEM_WAKE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    WEBUSB_PAIR,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_PAUSE,       KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_MS_BTN3,
                                                                                                                    KC_TRANSPARENT, KC_MS_WH_UP,
                                                                                    KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_MS_WH_DOWN,  KC_MS_BTN1,     KC_MS_BTN2
  ),
  /* Keymap 4: IDs
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        | YYF  | YYFG | SRFW |  SFT | SFSF |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, ID_YYF,         ID_YYFG,        ID_SRFW,        ID_SFT,         ID_SFSF,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keymap 5: C++
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        | Class|Struct|public|protec|privat|      |           |      |  for |while |  if  | ifel | else |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * | # once |ctors |ctorsd|      |      | templ| name |           |      | fori |forea |lambda|      |      |        |
  * |--------+------+------+------+------+------| space|           |      |------+------+------+------+------+--------|
  * | #ifdef |string|      |      |      |      |------|           |------|      |      |      |      |      |        |
  * |--------+------+------+------+------+------|  ns  |           |  ns  |------+------+------+------+------+--------|
  * |#include|array |vector| umap | map  |      |  bal |           | t sim|unique|shared|      |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [5] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, CPP_CLASS,      CPP_STRUCT,     CPP_PUBLIC,     CPP_PROTECTED,  CPP_PRIVATE,    KC_TRANSPARENT,                                 KC_TRANSPARENT, CPP_FOR,        CPP_WHILE,      CPP_IF,         CPP_ELIF,       CPP_ELSE,       KC_TRANSPARENT,
    CPP_PO,         CPP_CTORS,      CPP_CTORDEFS,   KC_TRANSPARENT, KC_TRANSPARENT, CPP_TEMPLATE,   CPP_NS,                                         KC_TRANSPARENT, CPP_FORI,       CPP_FOREACH,    CPP_LAMBDA,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    CPP_IFDEF,      CPP_STRING,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    CPP_INCLUDE,    CPP_ARRAY,      CPP_VECTOR,     CPP_UMAP,       CPP_MAP,        KC_TRANSPARENT, CPP_NSB,                                        CPP_NSTS,       CPP_UNIQUE,     CPP_SHARED,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keymap 6: UE4
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        | PROP | FUNC |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [6] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, UE4_UPROP,       UE4_UFUNC,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keymap 7: Python
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [7] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keymap 8: Navigate
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |   L0   |  L1  |  L2  |  L3  |  L4  |  L5  |      |           |      |  L6  |  L7  |  L8  |  L9  |  L0  |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [8] = LAYOUT_ergodox_pretty(
    TO(0),          TO(1),          TO(2),          TO(3),          TO(4),          TO(5),          KC_TRANSPARENT,                                 KC_TRANSPARENT, TO(6),          TO(7),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(0,255,255);
        #endif
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(86,255,128);
        #endif
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(172,255,255);
        #endif
      }
      return false;

    #define YYF_INJECT_KEYCODE_HANDLERS
    #include "custom_keys/id.inl"
    #include "custom_keys/cpp.inl"
    #include "custom_keys/ue4.inl"
    #include "custom_keys/python.inl"
    #undef YYF_INJECT_KEYCODE_HANDLERS
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case 0:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0,255,197);
        }
        break;
      case 1:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(209,255,197);
        }
        break;
      case 2:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(12,255,105);
        }
        break;
      case 3:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0,0,255);
        }
        break;
      case 4:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(83,255,255);
        }
        break;
      case 5:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(149,255,130);
        }
        break;
      case 6:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(0,0,192);
        }
        break;
      case 7:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(32,176,255);
        }
        break;
      case 8:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(131,246,237);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;

};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}
