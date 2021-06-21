#include "common.inl"

#ifdef YYF_INJECT_KEYCODES
UE4_UPROPERTY, // UPROPERTY()
UE4_UFUNCTION, // UFUNCTION()
UE4_UCLASS, // UCLASS()
UE4_USTRUCT, // USTRUCT()
UE4_UENUM, // UENUM()
#endif  // YYF_INJECT_KEYCODES

#ifdef YYF_INJECT_KEYCODE_HANDLERS
case UE4_UPROPERTY: // UPROPERTY()
    YYF_MACRO
    (
        "UPROPERTY()"
        SS_TAP(X_LEFT)
    );
    return false;
case UE4_UFUNCTION: // UFUNCTION()
    YYF_MACRO
    (
        "UFUNCTION()"
        SS_TAP(X_LEFT)
    );
    return false;
case UE4_UCLASS: // UCLASS()
    YYF_MACRO
    (
        "UCLASS()"
        SS_TAP(X_LEFT)
    );
    return false;
case UE4_USTRUCT: // USTRUCT()
    YYF_MACRO
    (
        "USTRUCT()"
        SS_TAP(X_LEFT)
    );
    return false;
case UE4_UENUM: // UENUM()
    YYF_MACRO
    (
        "UENUM()"
        SS_TAP(X_LEFT)
    );
    return false;
#endif  // YYF_INJECT_KEYCODE_HANDLERS