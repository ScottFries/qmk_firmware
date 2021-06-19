#include "common.inl"

#ifdef YYF_INJECT_KEYCODES
CPP_PO, // #pragma once
CPP_IFDEF, // #pragma ifdef endif
CPP_INCLUDE,
CPP_CLASS, // class
CPP_STRUCT, // struct
CPP_TEMPLATE, // template<>
CPP_PUBLIC, // public:
CPP_PROTECTED, // protected:
CPP_PRIVATE, // private:
CPP_NS, // namespace
CPP_NSB, // namespace Balance
CPP_NSTS, // namespace tesla::sim
CPP_FOR, // for () {}
CPP_FORI, // for (int i = 0; i < ; ++i) {}
CPP_FOREACH, // for (auto& : ) {}
CPP_WHILE, // while () {}
CPP_IF, // if () {}
CPP_ELIF, // else if () {}
CPP_ELSE, // else {}
CPP_LAMBDA, // auto = [](){};
CPP_CTORS, // Declares each of the 6 special member functions
CPP_CTORDEFS, // Defines each of the 6 special member functions
CPP_STRING, // std::string
CPP_ARRAY, // std::array<>
CPP_VECTOR, // std::vector<>
CPP_UMAP, // std::unordered_map<>
CPP_MAP, // std::map<>
CPP_UNIQUE, // std::unique_ptr<>
CPP_SHARED, // std::shared_ptr<>
#endif  // YYF_INJECT_KEYCODES

#ifdef YYF_INJECT_KEYCODE_HANDLERS
case CPP_PO: // #pragma once
    YYF_MACRO
    (
        "#pragma once"
        SS_TAP(X_ENTER)
        SS_TAP(X_ENTER)
    );
    return false;
case CPP_IFDEF: // #pragma ifdef endif
    YYF_MACRO
    (
        "#ifdef "
        SS_TAP(X_ENTER)
        "#define "
        SS_TAP(X_ENTER)
        SS_TAP(X_ENTER)
        SS_TAP(X_ENTER)
        SS_TAP(X_ENTER)
        "#endif // "
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
    );
    return false;
case CPP_INCLUDE: // #include 
    YYF_MACRO("#include ");
    return false;
case CPP_CLASS: // class
    YYF_MACRO
    (
        "class "
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_DOWN)
        ";"
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
    );
    return false;
case CPP_STRUCT: // struct
    YYF_MACRO
    (
        "struct "
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_DOWN)
        ";"
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
    );
    return false;
case CPP_TEMPLATE: // template<>
    YYF_MACRO
    (
        "template<>"
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_PUBLIC: // public:
    YYF_MACRO
    (
        SS_LSFT(SS_TAP(X_TAB))
        "public:"
        SS_TAP(X_ENTER)
        SS_TAP(X_TAB)
    );
    return false;
case CPP_PROTECTED: // protected:
    YYF_MACRO
    (
        SS_LSFT(SS_TAP(X_TAB))
        "protected:"
        SS_TAP(X_ENTER)
        SS_TAP(X_TAB)
    );
    return false;
case CPP_PRIVATE: // private:
    YYF_MACRO
    (
        SS_LSFT(SS_TAP(X_TAB))
        "private:"
        SS_TAP(X_ENTER)
        SS_TAP(X_TAB)
    );
    return false;
case CPP_NS: // namespace
    YYF_MACRO
    (
        "namespace "
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_DOWN)
        "  // "
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
    );
    return false;
case CPP_NSB: // namespace Balance
    YYF_MACRO
    (
        "namespace Balance"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_DOWN)
        "  // namespace Balance"
        SS_TAP(X_UP)
        SS_TAP(X_END)
    );
    return false;
case CPP_NSTS: // namespace tesla::sim
    YYF_MACRO
    (
        "namespace tesla"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_LSFT(SS_TAP(X_TAB))
        "namespace sim"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_DOWN)
        " // namespace sim"
        SS_TAP(X_DOWN)
        " // namespace tesla"
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
    );
    return false;
case CPP_FOR: // for () {}
    YYF_MACRO
    (
        "for ()"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_FORI: // for (int i = 0; i < ; ++i) {}
    YYF_MACRO
    (
        "for (int i = 0; i < ; ++i)"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_FOREACH: // for (auto& : ) {}
    YYF_MACRO
    (
        "for (auto&  : )"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_WHILE: // while () {}
    YYF_MACRO
    (
        "while ()"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_IF: // if () {}
    YYF_MACRO
    (
        "if ()"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_ELIF: // else if () {}
    YYF_MACRO
    (
        "else if ()"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_ELSE: // else {}
    YYF_MACRO
    (
        "else"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
    );
    return false;
case CPP_LAMBDA: // auto = [](){};
    YYF_MACRO
    (
        "auto  = []()"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_ENTER)
        SS_TAP(X_DOWN)
        ";"
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_UP)
        SS_TAP(X_END)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_CTORS: // Declares each of the 6 special member functions
    YYF_MACRO
    (
        SS_LCTRL("v")"();"
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"(const "SS_LCTRL("v")"& other);"
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"("SS_LCTRL("v")"&& other);"
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"& operator=(const "SS_LCTRL("v")"& other);"
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"& operator=("SS_LCTRL("v")"&& other);"
        SS_TAP(X_ENTER)
        "~"SS_LCTRL("v")"();"
    );
    return false;
case CPP_CTORDEFS: // Defines each of the 6 special member functions
    YYF_MACRO
    (
        SS_LCTRL("v")"::"SS_LCTRL("v")"()"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_DOWN)
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"::"SS_LCTRL("v")"(const "SS_LCTRL("v")"& other)"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_DOWN)
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"::"SS_LCTRL("v")"("SS_LCTRL("v")"&& other)"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_DOWN)
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"& "SS_LCTRL("v")"::operator=(const "SS_LCTRL("v")"& other)"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_DOWN)
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"& "SS_LCTRL("v")"::operator=("SS_LCTRL("v")"&& other)"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_DOWN)
        SS_TAP(X_ENTER)
        SS_LCTRL("v")"::~"SS_LCTRL("v")"()"
        SS_TAP(X_ENTER)
        "{"
        SS_TAP(X_DOWN)
        SS_TAP(X_ENTER)
    );
    return false;
case CPP_STRING: // std::string
    YYF_MACRO("std::string ");
    return false;
case CPP_ARRAY: // std::array<>
    YYF_MACRO
    (
        "std::array<> "
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_VECTOR: // std::vector<>
    YYF_MACRO
    (
        "std::vector<> "
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_UMAP: // std::unordered_map<>
    YYF_MACRO
    (
        "std::unordered_map<> "
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_MAP: // std::map<>
    YYF_MACRO
    (
        "std::map<> "
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_UNIQUE: // std::unique_ptr<>
    YYF_MACRO
    (
        "std::unique_ptr<> "
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
case CPP_SHARED: // std::shared_ptr<>
    YYF_MACRO
    (
        "std::shared_ptr<> "
        SS_TAP(X_LEFT)
        SS_TAP(X_LEFT)
    );
    return false;
#endif  // YYF_INJECT_KEYCODE_HANDLERS