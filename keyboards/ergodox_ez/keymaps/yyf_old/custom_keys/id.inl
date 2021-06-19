#include "common.inl"

#ifdef YYF_INJECT_KEYCODES
ID_YYF, // YinAndYangFang
ID_YYFG, // YinAndYangFang@gmail.com
ID_SFSF, // ScottF@ScottFries.com
ID_SRFW, // Scott@RealFakeWorld.com
ID_SFT, // sfries@tesla.com
#endif  // YYF_INJECT_KEYCODES

#ifdef YYF_INJECT_KEYCODE_HANDLERS
case ID_YYF: // YinAndYangFang
    YYF_MACRO("YinAndYangFang");
    return false;
case ID_YYFG: // YinAndYangFang@gmail.com
    YYF_MACRO("YinAndYangFang@gmail.com");
    return false;
case ID_SFSF: // ScottF@ScottFries.com
    YYF_MACRO("ScottF@ScottFries.com");
    return false;
case ID_SRFW: // Scott@RealFakeWorld.com
    YYF_MACRO("Scott@RealFakeWorld.com");
    return false;
case ID_SFT: // sfries@tesla.com
    YYF_MACRO("sfries@tesla.com");
    return false;
#endif  // YYF_INJECT_KEYCODE_HANDLERS