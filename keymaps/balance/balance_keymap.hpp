#ifndef BALANCE_KEYMAP_H
#define BALANCE_KEYMAP_H

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0  // Dvorak
#define SYMB 1  // Symbols
#define MDIA 2  // Media
#define UNU3 3  // 
#define IDSM 4  // IDs
#define CPPM 5  // C++ Macros
#define UE4M 6  // UE4 Macros
#define UNU7 7  // 
#define QWER 8  // QWERTY
#define LAYR 9  // Layout
#define EMTY 10 // Empty

// TODO: Looks like these are for extending functionality; remove unused ones
enum custom_keycodes
{
	PLACEHOLDER = SAFE_RANGE, // can always be here
	EPRM,
	VRSN,
	RGB_SLD,

	// Handles
	ID_YYF, // YinAndYangFang
	ID_YYFG, // YinAndYangFang@gmail.com
	ID_SFSF, // ScottF@ScottFries.com
	ID_SRFW, // Scott@RealFakeWorld.com
	ID_SFT, // sfries@tesla.com

	// C++
	CP_PO, // #pragma once
	CP_IDEF, // #pragma ifdef endif
    CP_INCL,
	CP_CLAS, // class
	CP_STRU, // struct
	CP_TEMP, // template<>
	CP_PUB, // public:
	CP_PRO, // protected:
	CP_PRV, // private:
	CP_NS, // namespace
	CP_NSB, // namespace Balance
	CP_NSTS, // namespace tesla::sim
	CP_FOR, // for () {}
	CP_FORI, // for (int i = 0; i < ; ++i) {}
	CP_FOEA, // for (auto& : ) {}
	CP_WHIL, // while () {}
	CP_IF, // if () {}
	CP_ELIF, // else if () {}
	CP_ELSE, // else {}
	CP_LAMB, // auto = [](){};
	CP_CTORS, // Declares each of the 6 special member functions
	CP_CTORSD, // Defines each of the 6 special member functions
	CP_STR, // std::string
	CP_ARRY, // std::array<>
	CP_VECT, // std::vector<>
	CP_UMAP, // std::unordered_map<>
	CP_MAP, // std::map<>
	CP_UNIQ, // std::unique_ptr<>
	CP_SHAR, // std::shared_ptr<>

	// UE4
	UE_UPROP, // UPROPERTY()
	UE_UFUNC, // UFUNCTION()
};

// TOOD: May need to change TO commands to this; remove otherwise
const uint16_t PROGMEM fn_actions[] =
{
	[1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
	if (record->event.pressed)
	{
		switch (keycode)
		{
			// dynamically generate these.
		case EPRM:
			eeconfig_init();
			return false;
			break;
		case VRSN:
			//SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
			return false;
			break;
		case RGB_SLD:
#ifdef RGBLIGHT_ENABLE
			rgblight_mode(1);
#endif
			return false;
			break;

			// Handles
		case ID_YYF: // YinAndYangFang
			SEND_STRING("YinAndYangFang");
			return false;
			break;
		case ID_YYFG: // YinAndYangFang@gmail.com
			SEND_STRING("YinAndYangFang@gmail.com");
			return false;
			break;
		case ID_SFSF: // ScottF@ScottFries.com
			SEND_STRING("ScottF@ScottFries.com");
			return false;
			break;
		case ID_SRFW: // Scott@RealFakeWorld.com
			SEND_STRING("Scott@RealFakeWorld.com");
			return false;
			break;
		case ID_SFT: // sfries@tesla.com
			SEND_STRING("sfries@tesla.com");
			return false;
			break;

			// C++
		case CP_PO: // #pragma once
			SEND_STRING("#pragma once\n\n");
			return false;
			break;
		case CP_IDEF: // #pragma ifdef endif
			SEND_STRING("#ifdef \n#define \n\n\n\n#endif // "SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END));
			return false;
			break;
		case CP_INCL: // #include 
			SEND_STRING("#include ");
			return false;
			break;
		case CP_CLAS: // class
			SEND_STRING("class \n{\n\n};"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END));
			return false;
			break;
		case CP_STRU: // struct
			SEND_STRING("struct \n{\n\n};"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END));
			return false;
			break;
		case CP_TEMP: // template<>
			SEND_STRING("template<>"SS_TAP(X_LEFT));
			return false;
			break;
		case CP_PUB: // public:
			SEND_STRING("public:\n");
			return false;
			break;
		case CP_PRO: // protected:
			SEND_STRING("protected:\n");
			return false;
			break;
		case CP_PRV: // private:
			SEND_STRING("private:\n");
			return false;
			break;
		case CP_NS: // namespace
			SEND_STRING("namespace \n{\n\n} // "SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END));
			return false;
			break;
		case CP_NSB: // namespace Balance
			SEND_STRING("namespace Balance\n{\n\n} // namespace Balance"SS_TAP(X_UP)SS_TAP(X_END));
			return false;
			break;
		case CP_NSTS: // namespace tesla::sim
			SEND_STRING("namespace tesla\n{\nnamespace sim\n{\n\n} // namespace sim\n} // namespace tesla"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END));
			return false;
			break;
		case CP_FOR: // for () {}
			SEND_STRING("for ()\n{\n\n}"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_FORI: // for (int i = 0; i < ; ++i) {}
			SEND_STRING("for (int i = 0; i < ; ++i)\n{\n\n}"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_FOEA: // for (auto& : ) {}
			SEND_STRING("for (auto&  : )\n{\n\n}"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_WHIL: // while () {}
			SEND_STRING("while ()\n{\n\n}"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_IF: // if () {}
			SEND_STRING("if ()\n{\n\n}"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_ELIF: // else if () {}
			SEND_STRING("else if ()\n{\n\n}"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_ELSE: // else {}
			SEND_STRING("else\n{\n\n}"SS_TAP(X_UP));
			return false;
			break;
		case CP_LAMB: // auto = [](){};
			SEND_STRING("auto  = []()\n{\n\n};"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_END)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_CTORS: // Declares each of the 6 special member functions
			SEND_STRING(SS_LCTRL("v")"();\n"SS_LCTRL("v")"(const "SS_LCTRL("v")"& other);\n"SS_LCTRL("v")"("SS_LCTRL("v")"&& other);\n"SS_LCTRL("v")"& operator=(const "SS_LCTRL("v")"& other);\n"SS_LCTRL("v")"& operator=("SS_LCTRL("v")"&& other);\n~"SS_LCTRL("v")"();");
			return false;
			break;
		case CP_CTORSD: // Defines each of the 6 special member functions
			SEND_STRING(SS_LCTRL("v")"::"SS_LCTRL("v")"()\n{\n}\n"SS_LCTRL("v")"::"SS_LCTRL("v")"(const "SS_LCTRL("v")"& other)\n{\n}\n"SS_LCTRL("v")"::"SS_LCTRL("v")"("SS_LCTRL("v")"&& other)\n{\n}\n"SS_LCTRL("v")"& "SS_LCTRL("v")"::operator=(const "SS_LCTRL("v")"& other)\n{\n}\n"SS_LCTRL("v")"& "SS_LCTRL("v")"::operator=("SS_LCTRL("v")"&& other)\n{\n}\n"SS_LCTRL("v")"::~"SS_LCTRL("v")"()\n{\n}");
			return false;
			break;
		case CP_STR: // std::string
			SEND_STRING("std::string ");
			return false;
			break;
		case CP_ARRY: // std::array<>
			SEND_STRING("std::array<> "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_VECT: // std::vector<>
			SEND_STRING("std::vector<> "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_UMAP: // std::unordered_map<>
			SEND_STRING("std::unordered_map<> "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_MAP: // std::map<>
			SEND_STRING("std::map<> "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_UNIQ: // std::unique_ptr<>
			SEND_STRING("std::unique_ptr<> "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;
		case CP_SHAR: // std::shared_ptr<>
			SEND_STRING("std::shared_ptr<> "SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			return false;
			break;

			// UE4
		case UE_UPROP: // UPROPERTY()
			SEND_STRING("UPROPERTY()"SS_TAP(X_LEFT));
			return false;
			break;
		case UE_UFUNC: // UFUNCTION()
			SEND_STRING("UFUNCTION()"SS_TAP(X_LEFT));
			return false;
			break;
		}
	}
	return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void)
{
	ergodox_led_all_on();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{
	uint8_t layer = biton32(layer_state);
	ergodox_led_all_off();
	switch (layer)
	{
	case BASE:
		ergodox_right_led_1_on();
		break;
	case SYMB:
		ergodox_right_led_2_on();
		break;
	case MDIA:
		ergodox_right_led_3_on();
		break;
	case UNU3:
		break;
	case IDSM:
		ergodox_right_led_1_on();
		ergodox_right_led_2_on();
		break;
	case CPPM:
		ergodox_right_led_1_on();
		ergodox_right_led_3_on();
		break;
	case UE4M:
		ergodox_right_led_2_on();
		ergodox_right_led_3_on();
		break;
	case UNU7:
		break;
	case QWER:
		ergodox_right_led_1_on();
		ergodox_right_led_2_on();
		ergodox_right_led_3_on();
		break;
	case LAYR:
		ergodox_right_led_2_on();
		ergodox_right_led_3_on();
		break;
	default:
		break;
	}
};

#endif // BALANCE_KEYMAP_H 
