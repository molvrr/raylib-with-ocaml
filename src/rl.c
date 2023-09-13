#include <caml/mlvalues.h>
#include <caml/memory.h>
#include "raylib.h"

CAMLprim void caml_init_window(value width, value height, value title)
{
    InitWindow(Int_val(width), Int_val(height), String_val(title));
}
