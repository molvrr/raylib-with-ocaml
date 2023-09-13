#include <caml/mlvalues.h>
#include <caml/memory.h>
#include "raylib.h"

#include <stdio.h>

Color color_of_caml(value color)
{
    // TAG 0: DEFAULT * palette
    if (Tag_val(color) == 0)
    {
        switch (Int_val(Field(color, 0)))
        {
            case 0:
                return LIGHTGRAY;
            case 1:
                return GRAY;
            case 2:
                return DARKGRAY;
            case 3:
                return YELLOW;
            case 4:
                return GOLD;
            case 5:
                return ORANGE;
            case 6:
                return PINK;
            case 7:
                return RED;
            case 8:
                return MAROON;
            case 9:
                return GREEN;
            case 10:
                return LIME;
            case 11:
                return DARKGREEN;
            case 12:
                return SKYBLUE;
            case 13:
                return BLUE;
            case 14:
                return DARKBLUE;
            case 15:
                return PURPLE;
            case 16:
                return VIOLET;
            case 17:
                return DARKPURPLE;
            case 18:
                return BEIGE;
            case 19:
                return BROWN;
            case 20:
                return DARKBROWN;
            case 21:
                return WHITE;
            case 22:
                return BLACK;
            case 23:
                return BLANK;
            case 24:
                return MAGENTA;
            case 25:
                return RAYWHITE;
            default:
                return WHITE;
        }
    }
    else
    {
        int r = Int_val(Field(color, 0));
        int g = Int_val(Field(color, 1));
        int b = Int_val(Field(color, 2));
        int a = Int_val(Field(color, 3));

        Color cor = { r, g, b, a };
        return cor;
    }
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

    // if (Tag_val(color) == 0)
    // {
    //
    // } else
    // {
    //
    // }
    ClearBackground(color_of_caml(color));
    CAMLreturn(Val_unit);
}
