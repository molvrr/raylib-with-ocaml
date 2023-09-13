open Raylib

let rec loop () =
  if window_should_close ()
  then close_window ()
  else (
    let () = begin_drawing () in
    let () = clear_background Color.(Default White) in
    let () =
      draw_text
        "Congrats! You created your first window!"
        190
        200
        20
        Color.(Default Lightgray)
    in
    let () = end_drawing () in
    loop ())
;;

let () =
  let screen_width = 800 in
  let screen_height = 450 in
  let title = "raylib [core] example - basic window" in
  let () = init_window screen_width screen_height title in
  let () = set_target_fps 60 in
  loop ()
;;
