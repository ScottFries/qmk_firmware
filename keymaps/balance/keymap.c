#include "balance_keymap.hpp"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	/* Keymap 0: Basic layer
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |  L9    |   1  |   2  |   3  |   4  |   5  |   [  |           |  ]   |   6  |   7  |   8  |   9  |   0  |   \    |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* | Tab/~L1|  '"  |   ,  |   .  |   P  |   Y  |   _  |           |  ;   |   F  |   G  |   C  |   R  |   L  |   /    |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* | Caps   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
	* |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
	* | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |=/RShift|
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   |`/Ctr |ShfCmd|CtlAlt|CtlShf|AltShf|                                       |  Up  | Down | Left |Right | `/Ctr |
	*   `----------------------------------'                                       `-----------------------------------'
	*                                      ,---------------.       ,--------------.
	*                                      |  Esc  |  Gui  |       |  ~L4  | Del  |
	*                               ,------|-------|-------|       |------+--------+------.
	*                               |      |       |Hom/Alt|       |PgU/~L5|      |      |
	*                               |  Tab | Space |-------|       |-------|BackSp|Enter |
	*                               |      |       |End/Ctr|       |PgD/~L6|      |      |
	*                               `----------------------'       `----------------------'
	*/
	// If it accepts an argument (i.e, is a function), it doesn't need KC_.
	// Otherwise, it needs KC_*
	[BASE] = LAYOUT_ergodox(
		// left hand
		TO(LAYR),        KC_1,          KC_2,          KC_3,    KC_4,    KC_5,              KC_LBRC,
		LT(SYMB,KC_TAB), KC_QUOT,       KC_COMM,       KC_DOT,  KC_P,    KC_Y,              KC_UNDS,
		KC_CAPSLOCK,     KC_A,          KC_O,          KC_E,    KC_U,    KC_I,    
		KC_LSFT,         KC_SCOLON,     KC_Q,          KC_J,    KC_K,    KC_X,              KC_LCBR,
		CTL_T(KC_GRV),   LSFT(KC_LGUI), LCTL(KC_LALT), LCTL(KC_LSFT), LALT(KC_LSFT),
		                                                                 KC_ESC,            KC_LGUI,
		                                                                                    ALT_T(KC_HOME),
		                                                        KC_TAB,  KC_SPC,            CTL_T(KC_END),
		// right hand
		KC_RBRC,         KC_6,          KC_7,          KC_8,    KC_9,    KC_0,              KC_BSLS,
		KC_SCOLON,       KC_F,          KC_G,          KC_C,    KC_R,    KC_L,              KC_SLSH,
		                 KC_D,          KC_H,          KC_T,    KC_N,    KC_S,              KC_MINS,
		KC_RCBR,         KC_B,          KC_M,          KC_W,    KC_V,    KC_Z,              SFT_T(KC_EQL),
		                                KC_UP,         KC_DOWN, KC_LEFT, KC_RGHT,           CTL_T(KC_GRV),
		MO(IDSM),	       KC_DELT,
		LT(CPPM,KC_PGUP),
		LT(UE4M,KC_PGDN),  KC_BSPC, KC_ENT
	),
	/* Keymap 1: Symbol Layer
	*
	* ,---------------------------------------------------.           ,--------------------------------------------------.
	* |         |  F1  |  F2  |  F3  |  F4  |  F5  | VolDn|           |VolUp |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
	* |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
	* |         |   !  |   @  |   {  |   }  |   |  |      |           | Mute |  Up  |   7  |   8  |   9  |   *  |   F12  |
	* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |    -   |
	* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
	* `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   | Redo  | Cut  |Paste | Copy | Undo |                                       | Find |   0  |   .  |   =  |      |
	*   `-----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        |Animat|      |       |Toggle|Solid |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
	*                                 |ness- |ness+ |------|       |------|      |      |
	*                                 |      |      |      |       |      |      |      |
	*                                 `--------------------'       `--------------------'
	*/
	// SYMBOLS
	[SYMB] = LAYOUT_ergodox(
		// left hand
		KC_TRNS,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,   KC__VOLDOWN,
		KC_TRNS,    KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE, KC_TRNS,
		KC_TRNS,    KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRV,
		KC_TRNS,    KC_PERC,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD, KC_TRNS,
		LCTL(KC_Y), LCTL(KC_X), LCTL(KC_V), LCTL(KC_C), LCTL(KC_Z),
		                                                            RGB_MOD, KC_TRNS,
		                                                                     KC_TRNS,
		                                                RGB_VAD,    RGB_VAI, KC_TRNS,
		// right hand
		KC__VOLUP,  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,  KC_F11,
		KC__MUTE,   KC_UP,      KC_7,       KC_8,       KC_9,       KC_ASTR, KC_F12,
		            KC_DOWN,    KC_4,       KC_5,       KC_6,       KC_PLUS, KC_MINUS,
		KC_TRNS,    KC_AMPR,    KC_1,       KC_2,       KC_3,       KC_BSLS, KC_TRNS,
	                LCTL(KC_F), KC_0,       KC_DOT,     KC_EQL,     KC_TRNS,
		RGB_TOG,    RGB_SLD,
		KC_TRNS,    
		KC_TRNS,    RGB_HUD,    RGB_HUI
	),
	/* Keymap 2: Media and mouse keys
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
	*   `----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        |      |      |       |      |      |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |      |      |      |       |      |      |Brwser|
	*                                 |      |      |------|       |------|      |Back  |
	*                                 |      |      |      |       |      |      |      |
	*                                 `--------------------'       `--------------------'
	*/
	// MEDIA AND MOUSE
	[MDIA] = LAYOUT_ergodox(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U,   KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D,   KC_MS_R, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1,   KC_BTN2,
		                                               KC_TRNS, KC_TRNS,
		                                                        KC_TRNS,
		                                      KC_TRNS, KC_TRNS, KC_TRNS,
		// right hand
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
		          KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
		KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV,  KC_MNXT, KC_TRNS, KC_TRNS,
		                   KC_VOLU, KC_VOLD,  KC_MUTE, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_WBAK
	),
	/* Keymap 3:
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
	// 
	[UNU3] = LAYOUT_ergodox(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		// right hand
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS
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
	// 
	[IDSM] = LAYOUT_ergodox(
		KC_TRNS, ID_YYF,  ID_YYFG, ID_SRFW, ID_SFT,  ID_SFSF, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		// right hand
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS
	),
	/* Keymap 5: C++ Macros
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |   L9   | Class|Struct|public|protec|privat|      |           |      |  for |while |  if  | ifel | else |        |
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
	// 
	[CPPM] = LAYOUT_ergodox(
		TO(9),   CP_CLAS,  CP_STRU,   CP_PUB,  CP_PRO,   CP_PRV,  KC_TRNS,
		CP_PO,   CP_CTORS, CP_CTORSD, KC_TRNS, KC_TRNS,  CP_TEMP, CP_NS,
		CP_IDEF, CP_STR,   KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,
		CP_INCL, CP_ARRY,  CP_VECT,   CP_UMAP, CP_MAP,   KC_TRNS, CP_NSB,
		KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		// right hand
		KC_TRNS, CP_FOR,   CP_WHIL,   CP_IF,   CP_ELIF,  CP_ELSE, KC_TRNS,
		KC_TRNS, CP_FORI,  CP_FOEA,   CP_LAMB, KC_TRNS,  KC_TRNS, KC_TRNS,
		         KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
		CP_NSTS, CP_UNIQ,  CP_SHAR,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
		                   KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS
	),
	/* Keymap 6: UE4 Macros
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
	// 
	[UE4M] = LAYOUT_ergodox(
		KC_TRNS, UE_UPROP, UE_UFUNC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS,
		// right hand
		KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		         KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS
	),
	/* Keymap 7:
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
	// 
	[UNU7] = LAYOUT_ergodox(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		// right hand
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS
	),
	/* Keymap 8: QWERTY
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |  L9    |   1  |   2  |   3  |   4  |   5  |   [  |           |  ]   |   6  |   7  |   8  |   9  |   0  |   -    |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* | Tab/~L1|   Q  |   W  |   E  |   R  |   T  |   _  |           |  ;   |   Y  |   U  |   I  |   O  |   P  |   \    |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
	* |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
	* | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   |`/Ctr |ShfCmd|CtlAlt|CtlShf|AltShf|                                       |  Up  | Down | Left |Right | `/Ctr |
	*   `----------------------------------'                                       `-----------------------------------'
	*                                      ,---------------.       ,--------------.
	*                                      |  Esc  |  Gui  |       |Gui/~L4| Del  |
	*                               ,------|-------|-------|       |------+--------+------.
	*                               |      |       |Hom/Alt|       |PgU/~L5|      |      |
	*                               |  Tab | Space |-------|       |-------|BackSp|Enter |
	*                               |      |       |End/Ctr|       |PgD/~L6|      |      |
	*                               `----------------------'       `----------------------'
	*/
	[QWER] = LAYOUT_ergodox(
		// left hand
		TO(LAYR),        KC_1,    KC_2,    KC_3,          KC_4,    KC_5,      KC_LBRC,
		LT(SYMB, KC_TAB),KC_Q,    KC_W,    KC_E,          KC_R,    KC_T,      KC_UNDS,
		KC_CAPSLOCK,     KC_A,    KC_S,    KC_D,          KC_F,    KC_G,
		KC_LSFT,         KC_Z,    KC_X,    KC_C,          KC_V,    KC_B,      KC_LCBR,
		CTL_T(KC_GRV),   LSFT(KC_LGUI), LCTL(KC_LALT), LCTL(KC_LSFT), LALT(KC_LSFT),
		                                                           KC_ESC,    KC_LGUI,
		                                                                      ALT_T(KC_HOME),
		                                                  KC_TAB,  KC_SPC,    CTL_T(KC_END),
		// right hand
		KC_RBRC,         KC_6,    KC_7,     KC_8,         KC_9,    KC_0,      KC_MINS,
		KC_SCOLON,       KC_Y,    KC_U,     KC_I,         KC_O,    KC_P,      KC_BSLS,
		                 KC_H,    KC_J,     KC_K,         KC_L,    KC_SCOLON, KC_QUOT,
		KC_RCBR,         KC_N,    KC_M,     KC_COMMA,     KC_DOT,  KC_SLSH,   KC_EQL,
		                          KC_UP,    KC_DOWN,      KC_LEFT, KC_RGHT,   CTL_T(KC_GRV),
		                                                  LT(IDSM, KC_LGUI),  KC_DELT,
		                                                           LT(CPPM,   KC_PGUP),
		                                              LT(UE4M, KC_PGDN),KC_BSPC,KC_ENT
	),
	/* Keymap 9: Layers
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
	// 
	[LAYR] = LAYOUT_ergodox(
		TO(0),   TO(1),   TO(2),   TO(9),   TO(4),   TO(5),   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		// right hand
		KC_TRNS, TO(6),   TO(9),   TO(8),   TO(9),   TO(0),   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS
	),
	/* Keymap Empty:
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
	// 
	[EMTY] = LAYOUT_ergodox(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		// right hand
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS
	)
};
