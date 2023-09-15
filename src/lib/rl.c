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
