#include <caml/mlvalues.h>
#include <caml/memory.h>
#include "raylib.h"

#include <stdio.h>

int log_level_of_caml(value log_level)
{
    switch (Int_val(log_level))
    {
        case 0:
            return LOG_DEBUG;
        case 1:
            return LOG_INFO;
        case 2:
            return LOG_WARNING;
        case 3:
            return LOG_ERROR;
        default:
            return LOG_DEBUG;
    }
}

Color color_of_caml(value color)
{
      return (Color) { Int_val(Field(color, 0)), Int_val(Field(color, 1)), Int_val(Field(color, 2)), Int_val(Field(color, 3)) };
}

CAMLprim value caml_init_window(value width, value height, value title)
{
    CAMLparam3(width, height, title);
    InitWindow(Int_val(width), Int_val(height), String_val(title));
    CAMLreturn(Val_unit);
}

CAMLprim value caml_window_should_close(value unit)
{
    CAMLparam1(unit);
    if (WindowShouldClose()) {
        CAMLreturn(Val_true);
    }

    CAMLreturn(Val_false);
}

CAMLprim value caml_set_target_fps(value fps)
{
    CAMLparam1(fps);
    SetTargetFPS(Int_val(fps));
    CAMLreturn(Val_unit);
}

CAMLprim value caml_close_window(value unit)
{
    CAMLparam1(unit);
    CloseWindow();
    CAMLreturn(Val_unit);
}

CAMLprim value caml_begin_drawing(value unit)
{
    CAMLparam1(unit);
    BeginDrawing();
    CAMLreturn(Val_unit);
}

CAMLprim value caml_end_drawing(value unit)
{
    CAMLparam1(unit);
    EndDrawing();
    CAMLreturn(Val_unit);
}

CAMLprim value caml_clear_background(value color)
{
    CAMLparam1(color);
    ClearBackground(color_of_caml(color));
    CAMLreturn(Val_unit);
}

CAMLprim value caml_draw_text(value text, value pos_x, value pos_y, value font_size, value color)
{
    CAMLparam5(text, pos_x, pos_y, font_size, color);
    DrawText(String_val(text), Int_val(pos_x), Int_val(pos_y), Int_val(font_size), color_of_caml(color));
    CAMLreturn(Val_unit);
}

CAMLprim value caml_set_trace_log_level(value level)
{
    CAMLparam1(level);
    SetTraceLogLevel(log_level_of_caml(level));
    CAMLreturn(Val_unit);
}

int key_of_ocaml(value key)
{
    switch (Int_val(key)) {
        case 0:
            return KEY_APOSTROPHE;
        case 1:
            return KEY_COMMA;
        case 2:
            return KEY_MINUS;
        case 3:
            return KEY_PERIOD;
        case 4:
            return KEY_SLASH;
        case 5:
            return KEY_ZERO;
        case 6:
            return KEY_ONE;
        case 7:
            return KEY_TWO;
        case 8:
            return KEY_THREE;
        case 9:
            return KEY_FOUR;
        case 10:
            return KEY_FIVE;
        case 11:
            return KEY_SIX;
        case 12:
            return KEY_SEVEN;
        case 13:
            return KEY_EIGHT;
        case 14:
            return KEY_NINE;
        case 15:
            return KEY_SEMICOLON;
        case 16:
            return KEY_EQUAL;
        case 17:
            return KEY_A;
        case 18:
            return KEY_B;
        case 19:
            return KEY_C;
        case 20:
            return KEY_D;
        case 21:
            return KEY_E;
        case 22:
            return KEY_F;
        case 23:
            return KEY_G;
        case 24:
            return KEY_H;
        case 25:
            return KEY_I;
        case 26:
            return KEY_J;
        case 27:
            return KEY_K;
        case 28:
            return KEY_L;
        case 29:
            return KEY_M;
        case 30:
            return KEY_N;
        case 31:
            return KEY_O;
        case 32:
            return KEY_P;
        case 33:
            return KEY_Q;
        case 34:
            return KEY_R;
        case 35:
            return KEY_S;
        case 36:
            return KEY_T;
        case 37:
            return KEY_U;
        case 38:
            return KEY_V;
        case 39:
            return KEY_W;
        case 40:
            return KEY_X;
        case 41:
            return KEY_Y;
        case 42:
            return KEY_Z;
        case 43:
            return KEY_LEFT_BRACKET;
        case 44:
            return KEY_BACKSLASH;
        case 45:
            return KEY_RIGHT_BRACKET;
        case 46:
            return KEY_GRAVE;
        case 47:
            return KEY_SPACE;
        case 48:
            return KEY_ESCAPE;
        case 49:
            return KEY_ENTER;
        case 50:
            return KEY_TAB;
        case 51:
            return KEY_BACKSPACE;
        case 52:
            return KEY_INSERT;
        case 53:
            return KEY_DELETE;
        case 54:
            return KEY_RIGHT;
        case 55:
            return KEY_LEFT;
        case 56:
            return KEY_DOWN;
        case 57:
           return KEY_UP;
        case 58:
           return KEY_PAGE_UP;
        case 59:
           return KEY_PAGE_DOWN;
        case 60:
           return KEY_HOME;
        case 61:
           return KEY_END;
        case 62:
           return KEY_CAPS_LOCK;
        case 63:
           return KEY_SCROLL_LOCK;
        case 64:
           return KEY_NUM_LOCK;
        case 65:
           return KEY_PRINT_SCREEN;
        case 66:
           return KEY_PAUSE;
        case 67:
           return KEY_F1;
        case 68:
           return KEY_F2;
        case 69:
           return KEY_F3;
        case 70:
           return KEY_F4;
        case 71:
           return KEY_F5;
        case 72:
           return KEY_F6;
        case 73:
           return KEY_F7;
        case 74:
           return KEY_F8;
        case 75:
           return KEY_F9;
        case 76:
           return KEY_F10;
        case 77:
           return KEY_F11;
        case 78:
           return KEY_F12;
        case 79:
           return KEY_LEFT_SHIFT;
        case 80:
           return KEY_LEFT_CONTROL;
        case 81:
           return KEY_LEFT_ALT;
        case 82:
           return KEY_LEFT_SUPER;
        case 83:
           return KEY_RIGHT_SHIFT;
        case 84:
           return KEY_RIGHT_CONTROL;
        case 85:
           return KEY_RIGHT_ALT;
        case 86:
           return KEY_RIGHT_SUPER;
        case 87:
           return KEY_KB_MENU;
        case 88:
           return KEY_KP_0;
        case 89:
           return KEY_KP_1;
        case 90:
           return KEY_KP_2;
        case 91:
           return KEY_KP_3;
        case 92:
           return KEY_KP_4;
        case 93:
           return KEY_KP_5;
        case 94:
           return KEY_KP_6;
        case 95:
           return KEY_KP_7;
        case 96:
           return KEY_KP_8;
        case 97:
           return KEY_KP_9;
        case 98:
           return KEY_KP_DECIMAL;
        case 99:
           return KEY_KP_DIVIDE;
        case 100:
           return KEY_KP_MULTIPLY;
        case 101:
           return KEY_KP_SUBTRACT;
        case 102:
           return KEY_KP_ADD;
        case 103:
           return KEY_KP_ENTER;
        case 104:
           return KEY_KP_EQUAL;
        case 105:
           return KEY_BACK;
        case 106:
           return KEY_MENU;
        case 107:
           return KEY_VOLUME_UP;
        case 108:
           return KEY_VOLUME_DOWN;
    }
}

Vector2 vector2_of_caml(value vector)
{
    float x = Double_val(Field(vector, 0));
    float y = Double_val(Field(vector, 1));
    return (Vector2) { x, y };
}

CAMLprim value caml_draw_circle_v(value center, value radius, value color)
{
    CAMLparam3(center, radius, color);
    Vector2 vec = vector2_of_caml(center);
    double rad = Double_val(radius);
    Color cor = color_of_caml(color);
    DrawCircleV(vec, rad, cor);
    CAMLreturn(Val_unit);
}

CAMLprim value caml_is_key_down(value key)
{
    CAMLparam1(key);
    if (IsKeyDown(key_of_ocaml(key)))
        {
            CAMLreturn(Val_true);
        } else {
        CAMLreturn(Val_false);
    }
}
