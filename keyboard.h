#ifndef DARKEST_DUNGEON_LITE_KEYBOARD_H
#define DARKEST_DUNGEON_LITE_KEYBOARD_H
enum class KeyboardKey : int {
    // Специальные клавиши
    ESC = 27,
    ENTER = 10,
    BACKSPACE = 8,
    TAB = 9,
    SPACE = 32,
    // Буквы верхнего регистра
    A = 65, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    // Буквы нижнего регистра
    a = 97, b, c, d, e, f, g, h, i, j, k, l, m,
    n, o, p, q, r, s, t, u, v, w, x, y, z,
    // Цифры
    NUM_0 = 48, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5,
    NUM_6, NUM_7, NUM_8, NUM_9,
    // Символы
    EXCLAMATION = 33, DOUBLE_QUOTE, NUMBER_SIGN, DOLLAR_SIGN, PERCENT, AMPERSAND, SINGLE_QUOTE, OPEN_PAREN,
    CLOSE_PAREN, ASTERISK, PLUS, COMMA, MINUS, PERIOD, SLASH,
    COLON = 58, SEMICOLON, LESS_THAN, EQUALS, GREATER_THAN, QUESTION_MARK, AT_SYMBOL,
    OPEN_BRACKET = 91, BACKSLASH, CLOSE_BRACKET, CARET, UNDERSCORE, BACKQUOTE = 96,
    OPEN_CURLY_BRACE = 123, VERTICAL_BAR, CLOSE_CURLY_BRACE, TILDE = 126,
    // Функциональные клавиши
    F1 = 112, F2, F3, F4, F5, F6, F7, F8, F9, F10,
    F11, F12,
    // Стрелки
  //  ARROW_UP = 30, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT
};

class Keyboard {
public:
    // Запрещаем копирование и присваивание
    Keyboard(const Keyboard &) = delete;

    Keyboard &operator=(const Keyboard &) = delete;

    static Keyboard &getInstance() {
        static Keyboard instance;
        return instance;
    }

    void change_key(KeyboardKey _key) { key = _key; }

    // getters
    KeyboardKey get_key() { return key; }

private:
    KeyboardKey key;

    Keyboard() {}

    ~Keyboard() {}
};

#endif //DARKEST_DUNGEON_LITE_KEYBOARD_H