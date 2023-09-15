module Color = struct
  type t = Color of int * int * int * int

  let lightgray = Color (200, 200, 200, 255)
  let gray = Color (130, 130, 130, 255)
  let darkgray = Color (80, 80, 80, 255)
  let yellow = Color (253, 249, 0, 255)
  let gold = Color (255, 203, 0, 255)
  let orange = Color (255, 161, 0, 255)
  let pink = Color (255, 109, 194, 255)
  let red = Color (230, 41, 55, 255)
  let maroon = Color (190, 33, 55, 255)
  let green = Color (0, 228, 48, 255)
  let lime = Color (0, 158, 47, 255)
  let darkgreen = Color (0, 117, 44, 255)
  let skyblue = Color (102, 191, 255, 255)
  let blue = Color (0, 121, 241, 255)
  let darkblue = Color (0, 82, 172, 255)
  let purple = Color (200, 122, 255, 255)
  let violet = Color (135, 60, 190, 255)
  let darkpurple = Color (112, 31, 126, 255)
  let beige = Color (211, 176, 131, 255)
  let brown = Color (127, 106, 79, 255)
  let darkbrown = Color (76, 63, 47, 255)
  let white = Color (255, 255, 255, 255)
  let black = Color (0, 0, 0, 255)
  let blank = Color (0, 0, 0, 0)
  let magenta = Color (255, 0, 255, 255)
  let raywhite = Color (245, 245, 245, 255)
end

type key =
  | Apostrophe
  | Comma
  | Minus
  | Period
  | Slash
  | Zero
  | One
  | Two
  | Three
  | Four
  | Five
  | Six
  | Seven
  | Eight
  | Nine
  | Semicolon
  | Equal
  | A
  | B
  | C
  | D
  | E
  | F
  | G
  | H
  | I
  | J
  | K
  | L
  | M
  | N
  | O
  | P
  | Q
  | R
  | S
  | T
  | U
  | V
  | W
  | X
  | Y
  | Z
  | LeftBracket
  | Backslash
  | RightBracket
  | Grave
  | Space
  | Escape
  | Enter
  | Tab
  | Backspace
  | Insert
  | Delete
  | Right
  | Left
  | Down
  | Up
  | PageUp
  | PageDown
  | Home
  | End
  | CapsLock
  | ScrollLock
  | NumLock
  | PrintScreen
  | Pause
  | F1
  | F2
  | F3
  | F4
  | F5
  | F6
  | F7
  | F8
  | F9
  | F10
  | F11
  | F12
  | LeftShift
  | LeftControl
  | LeftAlt
  | LeftSuper
  | RightShift
  | RightControl
  | RightAlt
  | RightSuper
  | KbMenu
  | Kp0
  | Kp1
  | Kp2
  | Kp3
  | Kp4
  | Kp5
  | Kp6
  | Kp7
  | Kp8
  | Kp9
  | KpDecimal
  | KpDivide
  | KpMultiply
  | KpSubtract
  | KpAdd
  | KpEnter
  | KpEqual
  | Back
  | Menu
  | VolumeUp
  | VolumeDown

type log_level =
  | Debug
  | Info
  | Warning
  | Error

type vector =
  | Vector2 of
      { mutable x : float
      ; mutable y : float
      }

(* NOTE: Alterar parâmetros para parâmetros nomeados? *)
external init_window : int -> int -> string -> unit = "caml_init_window"
external window_should_close : unit -> bool = "caml_window_should_close"
external set_target_fps : int -> unit = "caml_set_target_fps"
external close_window : unit -> unit = "caml_close_window"
external begin_drawing : unit -> unit = "caml_begin_drawing"
external end_drawing : unit -> unit = "caml_end_drawing"
external clear_background : Color.t -> unit = "caml_clear_background"
external draw_text : string -> int -> int -> int -> Color.t -> unit = "caml_draw_text"
external set_trace_log_level : log_level -> unit = "caml_set_trace_log_level"
