#include "common.inl"

#ifdef YYF_INJECT_KEYCODES
UE4_UPROP, // UPROPERTY()
UE4_UFUNC, // UFUNCTION()
#endif  // YYF_INJECT_KEYCODES

#ifdef YYF_INJECT_KEYCODE_HANDLERS
case UE4_UPROP: // UPROPERTY()
    YYF_MACRO
    (
        "UPROPERTY()"
        SS_TAP(X_LEFT)
    );
    return false;
case UE4_UFUNC: // UFUNCTION()
    YYF_MACRO
    (
        "UFUNCTION()"
        SS_TAP(X_LEFT)
    );
    return false;
#endif  // YYF_INJECT_KEYCODE_HANDLERS