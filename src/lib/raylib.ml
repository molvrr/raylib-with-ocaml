module Color = struct
  type palette =
    | Lightgray
    | Gray
    | Darkgray
    | Yellow
    | Gold
    | Orange
    | Pink
    | Red
    | Maroon
    | Green
    | Lime
    | Darkgreen
    | Skyblue
    | Blue
    | Darkblue
    | Purple
    | Violet
    | Darkpurple
    | Beige
    | Brown
    | Darkbrown
    | White
    | Black
    | Blank
    | Magenta
    | Raywhite

  type t =
    | Default of palette
    | RGBA of int * int * int * int
end

external init_window : int -> int -> string -> unit = "caml_init_window"
external window_should_close : unit -> bool = "caml_window_should_close"
external set_target_fps : int -> unit = "caml_set_target_fps"
external close_window : unit -> unit = "caml_close_window"
external begin_drawing : unit -> unit = "caml_begin_drawing"
external end_drawing : unit -> unit = "caml_end_drawing"
external clear_background : Color.t -> unit = "caml_clear_background"
external draw_text : string -> int -> int -> int -> Color.t -> unit = "caml_draw_text"
