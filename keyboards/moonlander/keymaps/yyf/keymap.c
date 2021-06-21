#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
};


enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Dvorak
  *
  * ,------------------------------------------------.           ,------------------------------------------------.
  * |  L8  |  1   |  2   |  3   |  4   |  5   |  [   |           |   ]  |   6  |   7  |   8  |   9  |   0  |   \  |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * | ~L2  |  '   |  ,   |  .   |  P   |  Y   |  (   |           |   )  |   F  |   G  |   C  |   R  |   L  |   /  |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * | Caps |  A   |  O   |  E   |  U   |  I   |  _   |           |   ;  |   D  |   H  |   T  |   N  |   S  |   -  |
  * |------+------+------+------+------+------+------`           |------+------+------+------+------+------+------|
  * |LShift|  `   |  Q   |  J   |  K   |  X   |                         |   B  |   M  |   W  |   V  |   Z  |=/RShf|
  * `------+------+------+------+------+------'                         `------+------+------+------+------+------|
  * |LCtrl | LAlt |SS/Mod| Left |Right |      /---\                 /---\      |  Up  | Down | Page | ~L4  | ~L5  |
  * `----------------------------------'    /  Esc  \             /       \    `----------------------------------'
  *                                      ,/     /     \.       ,/    Del    \.
  *                                      | LeftCmd/Win |       |             |
  *                               ,------|------|------|       |------|------|------.
  *                               |      |      | Home |       |  End |      |      |
  *                               | Tab  |Space |  /   |       |   /  | Back | Enter|
  *                               |      |      |LCtrl |       |  LAlt| Space|      |
  *                               `--------------------'       `--------------------'
  */
  [0] = LAYOUT_moonlander(
    TO(6),          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LBRACKET,                                    KC_RBRACKET,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLASH,      
    MO(2),          KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_LPRN,                                        KC_RPRN,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,       
    KC_CAPSLOCK,    KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_UNDS,                                                                        KC_SCOLON,      KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,       
    KC_LSHIFT,      KC_GRAVE,       KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           RSFT_T(KC_EQUAL),
    KC_LCTRL,       KC_LALT,        SCMD_T(KC_PSCREEN),KC_LEFT,        KC_RIGHT,       LGUI_T(KC_ESCAPE),                                                                                                KC_DELETE,      KC_UP,          KC_DOWN,        TD(DANCE_0),    MO(4),          MO(5),          
    KC_TAB,         KC_SPACE,       LCTL_T(KC_HOME),                LALT_T(KC_END), KC_BSPACE,      KC_ENTER
  ),
  /* Keymap 1: Qwerty
  *
  * ,------------------------------------------------.           ,------------------------------------------------.
  * |      |      |      |      |      |      |      |           |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |  Q   |  W   |  E   |  R   |  T   |      |           |      |   Y  |   U  |   I  |   O  |   P  |      |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |  A   |  S   |  D   |  F   |  G   |      |           |      |   H  |   J  |   K  |   L  |   ;  |      |
  * |------+------+------+------+------+------+------`           |------+------+------+------+------+------+------|
  * |      |  Z   |  X   |  C   |  V   |  B   |                         |   N  |   M  |   ,  |   .  |   '  |      |
  * `------+------+------+------+------+------'                         `------+------+------+------+------+------|
  * |      |      |      |      |      |      /---\                 /---\      |      |      |      |      |      |
  * `----------------------------------'    /       \             /       \    `----------------------------------'
  *                                      ,/           \.       ,/           \.
  *                                      |             |       |             |
  *                               ,------|------|------|       |------|------|------.
  *                               |      |      |      |       |      |      |      |
  *                               |      |      |      |       |      |      |      |
  *                               |      |      |      |       |      |      |      |
  *                               `--------------------'       `--------------------'
  */
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_QUOTE,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keymap 2: Symbols
  *
  * ,------------------------------------------------.           ,------------------------------------------------.
  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |  !   |  @   |  {   |  }   |  |   |      |           |      |  Up  |   7  |   8  |   9  |   *  |  F12 |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |  #   |  $   |  (   |  )   |  `   |      |           |      | Down |   4  |   5  |   6  |   -  |   /  |
  * |------+------+------+------+------+------+------`           |------+------+------+------+------+------+------|
  * |      |  %   |  ^   |  [   |  ]   |  ~   |                         |   &  |   1  |   2  |   3  |   +  |      |
  * `------+------+------+------+------+------'                         `------+------+------+------+------+------|
  * |      |  ,   |      |      |      |      /---\                 /---\      |BackSp|   .  |   0  |   =  |      |
  * `----------------------------------'    /       \             /       \    `----------------------------------'
  *                                      ,/  Toggle   \.       ,/           \.
  *                                      |  Animation  |       |             |
  *                               ,------|------|------|       |------|------|------.
  *                               |      |      |Toggle|       |      |      |      |
  *                               |Bright|Bright|Layer |       |      | Hue- | Hue+ |
  *                               |  Up  | Down |Color |       |      |      |      |
  *                               `--------------------'       `--------------------'
  */
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,         
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_MINUS,    KC_SLASH,       
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        KC_BSPACE,      KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  /* Keymap 3: System Control
  *
  * ,------------------------------------------------.           ,------------------------------------------------.
  * |      |      |      |      |      |      |      |           |      |      |      |      |      |      | Power|
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |      |      | MsUp |      |      |      |           |      |      |      |      |      |      | Sleep|
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |      |MsLeft|MsDown|MsRght|      |      |           |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------`           |------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |                         |      | Pause| Prev | Next |      |ScrlLk|
  * `------+------+------+------+------+------'                         `------+------+------+------+------+------|
  * | Oryx |      |      |      |      |      /---\                 /---\      | VolUp|VolDwn| Mute |      |      |
  * `----------------------------------'    /       \             /       \    `----------------------------------'
  *                                      ,/           \.       ,/           \.
  *                                      |             |       |             |
  *                               ,------|------|------|       |------|------|------.
  *                               |      |      |      |       |      |      |      |
  *                               | Left |Middle|Right |       | Wheel| Wheel|  WWW |
  *                               |Click |Click |Click |       | Down |  Up  | Back |
  *                               `--------------------'       `--------------------'
  */
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SYSTEM_POWER,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SYSTEM_SLEEP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_SCROLLLOCK,  
    WEBUSB_PAIR,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,                     KC_MS_WH_DOWN,  KC_MS_WH_DOWN,  KC_WWW_BACK
  ),
  /* Keymap 4: IDs
  *
  * ,------------------------------------------------.           ,------------------------------------------------.
  * |      | YYF  |S@rfw | sf@t |      |      |      |           |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |YYF@g | S@sf |      |      |      |      |           |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |           |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------`           |------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |                         |      |      |      |      |      |      |
  * `------+------+------+------+------+------'                         `------+------+------+------+------+------|
  * |      |      |      |      |      |      /---\                 /---\      |      |      |      |      |      |
  * `----------------------------------'    /       \             /       \    `----------------------------------'
  *                                      ,/           \.       ,/           \.
  *                                      |             |       |             |
  *                               ,------|------|------|       |------|------|------.
  *                               |      |      |      |       |      |      |      |
  *                               |      |      |      |       |      |      |      |
  *                               |      |      |      |       |      |      |      |
  *                               `--------------------'       `--------------------'
  */
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keymap 5: C++
  *
  * ,------------------------------------------------.           ,------------------------------------------------.
  * |      |class |struct|templ |public|protec|privat|           |  ns  |  for |  if  | while|      |      | UPROP|
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |# once|ctors |ctorsd|typena|      |      |lambda|           | ns ts| fori | ifel |dowhil|      |      | UFUNC|
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |#ifdef|string|      |      |      |      |      |           |ns bal| forea| else |      |      |      |UCLASS|
  * |------+------+------+------+------+------+------`           |------+------+------+------+------+------+------|
  * | #if  |array |vector| umap | map  |      |                         |unique|shared| weak |      |      |USTRUC|
  * `------+------+------+------+------+------'                         `------+------+------+------+------+------|
  * |#incl"|#incl<|      |      |      |      /---\                 /---\      |      |      |      |      | UENUM|
  * `----------------------------------'    /       \             /       \    `----------------------------------'
  *                                      ,/           \.       ,/           \.
  *                                      |             |       |             |
  *                               ,------|------|------|       |------|------|------.
  *                               |      |      |      |       |      |      |      |
  *                               |      |      |      |       |      |      |      |
  *                               |      |      |      |       |      |      |      |
  *                               `--------------------'       `--------------------'
  */
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keymap 6: Navigation
  *
  * ,------------------------------------------------.           ,------------------------------------------------.
  * |  L0  |  L1  |  L2  |  L3  |  L4  |  L5  |      |           |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |           |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |           |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------`           |------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |                         |      |      |      |      |      |      |
  * `------+------+------+------+------+------'                         `------+------+------+------+------+------|
  * |      |      |      |      |      |      /---\                 /---\      |      |      |      |      |      |
  * `----------------------------------'    /       \             /       \    `----------------------------------'
  *                                      ,/           \.       ,/           \.
  *                                      |             |       |             |
  *                               ,------|------|------|       |------|------|------.
  *                               |      |      |      |       |      |      |      |
  *                               |      |      |      |       |      |      |      |
  *                               |      |      |      |       |      |      |      |
  *                               `--------------------'       `--------------------'
  */
  [6] = LAYOUT_moonlander(
    TO(0),          TO(1),          TO(2),          TO(3),          TO(4),          TO(5),          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202}, {0,255,202} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,255}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,204,255}, {134,255,213}, {0,0,0}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {0,204,255}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {154,86,255}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {180,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,145}, {0,0,145}, {0,0,145}, {0,0,145}, {154,255,255}, {252,119,255}, {50,246,240}, {50,246,240}, {0,0,0}, {154,255,255}, {252,119,255}, {0,0,0}, {50,246,240}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {50,246,240}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {50,246,240}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,86,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,145}, {0,0,145}, {0,0,145}, {0,0,145}, {0,0,145}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,86,255}, {154,86,255}, {0,0,0}, {0,183,238}, {0,0,0}, {154,86,255}, {154,86,255}, {154,86,255}, {0,183,238}, {0,0,0}, {154,86,255}, {154,86,255}, {154,86,255}, {0,183,238}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,86,255}, {154,86,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,202}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
    }
    if(state->count > 3) {
        tap_code16(KC_PGUP);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_PGUP); break;
        case DOUBLE_TAP: register_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGUP); register_code16(KC_PGUP);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_PGUP); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGUP); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
