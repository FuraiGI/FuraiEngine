#ifndef KEY_CODES_HPP
#define KEY_CODES_HPP

#include <stdint.h>

namespace FuraiEngine {
    
    // =========================================
    // キーボード (Keyboard)
    // =========================================
    enum class Key : uint16_t {
        // --- アルファベット ---
        A = 65,
        B = 66,
        C = 67,
        D = 68,
        E = 69,
        F = 70,
        G = 71,
        H = 72,
        I = 73,
        J = 74,
        K = 75,
        L = 76,
        M = 77,
        N = 78,
        O = 79,
        P = 80,
        Q = 81,
        R = 82,
        S = 83,
        T = 84,
        U = 85,
        V = 86,
        W = 87,
        X = 88,
        Y = 89,
        Z = 90,

        // --- 数字キー（メイン） ---
        Num0 = 48,
        Num1 = 49,
        Num2 = 50,
        Num3 = 51,
        Num4 = 52,
        Num5 = 53,
        Num6 = 54,
        Num7 = 55,
        Num8 = 56,
        Num9 = 57,

        // --- コントロール＆ナビゲーション ---
        Space       = 32,
        Escape      = 256,
        Enter       = 257,
        Tab         = 258,
        Backspace   = 259,
        Insert      = 260,
        Delete      = 261,
        Right       = 262,
        Left        = 263,
        Down        = 264,
        Up          = 265,
        PageUp      = 266,
        PageDown    = 267,
        Home        = 268,
        End         = 269,
        CapsLock    = 280,
        ScrollLock  = 281,
        NumLock     = 282,
        PrintScreen = 283,
        Pause       = 284,

        // --- ファンクションキー ---
        F1  = 290,
        F2  = 291,
        F3  = 292,
        F4  = 293,
        F5  = 294,
        F6  = 295,
        F7  = 296,
        F8  = 297,
        F9  = 298,
        F10 = 299,
        F11 = 300,
        F12 = 301,

        // --- テンキー (Numpad) ---
        Kp0        = 320,
        Kp1        = 321,
        Kp2        = 322,
        Kp3        = 323,
        Kp4        = 324,
        Kp5        = 325,
        Kp6        = 326,
        Kp7        = 327,
        Kp8        = 328,
        Kp9        = 329,
        KpDecimal  = 330,
        KpDivide   = 331,
        KpMultiply = 332,
        KpSubtract = 333,
        KpAdd      = 334,
        KpEnter    = 335,
        KpEqual    = 336,

        // --- 修飾キー (Modifiers) ---
        LeftShift   = 340,
        LeftControl = 341,
        LeftAlt     = 342,
        LeftSuper   = 343,
        RightShift  = 344,
        RightControl= 345,
        RightAlt    = 346,
        RightSuper  = 347,
        Menu        = 348
    };

    // =========================================
    // マウス (Mouse)
    // =========================================
    enum class MouseButton : uint16_t {
        Button0 = 0,
        Button1 = 1,
        Button2 = 2,
        Button3 = 3,
        Button4 = 4,
        Button5 = 5,
        Button6 = 6,
        Button7 = 7,

        Left   = Button0,
        Right  = Button1,
        Middle = Button2
    };

    // =========================================
    // コントローラー (Gamepad)
    // =========================================
    enum class GamepadButton : uint16_t {
        A           = 0,
        B           = 1,
        X           = 2,
        Y           = 3,
        LeftBumper  = 4,
        RightBumper = 5,
        Back        = 6,
        Start       = 7,
        Guide       = 8,
        LeftThumb   = 9,
        RightThumb  = 10,
        DpadUp      = 11,
        DpadRight   = 12,
        DpadDown    = 13,
        DpadLeft    = 14,
    };

    enum class GamepadAxis : uint16_t {
        LeftX        = 0,
        LeftY        = 1,
        RightX       = 2,
        RightY       = 3,
        LeftTrigger  = 4,
        RightTrigger = 5,
    };
}

#endif // KEY_CODES_HPP