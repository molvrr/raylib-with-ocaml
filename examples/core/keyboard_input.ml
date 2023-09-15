open Raylib

let incr_x ball = ball.x <- ball.x +. 2.0
let incr_y ball = ball.y <- ball.y +. 2.0
let decr_y ball = ball.y <- ball.y -. 2.0
let decr_x ball = ball.x <- ball.x -. 2.0
let move_right () = is_key_down Right
let move_up () = is_key_down Up
let move_left () = is_key_down Left
let move_down () = is_key_down Down

let move ball () =
  match move_left (), move_up (), move_right (), move_down () with
  | false, false, false, true -> incr_y ball
  | false, false, true, false -> incr_x ball
  | false, false, true, true ->
    incr_x ball;
    incr_y ball
  | false, true, false, false -> decr_y ball
  | false, true, true, true ->
    decr_y ball;
    incr_x ball
  | false, true, true, false ->
    decr_y ball;
    incr_x ball
  | true, false, false, false -> decr_x ball
  | true, false, false, true ->
    decr_x ball;
    incr_y ball
  | true, false, true, true -> incr_y ball
  | true, true, false, false ->
    decr_x ball;
    decr_y ball
  | true, true, false, true -> decr_x ball
  | true, true, true, false -> decr_y ball
  | false, false, false, false
  | false, true, false, true
  | true, true, true, true
  | true, false, true, false -> ()
;;

let rec loop ball () =
  if window_should_close ()
  then close_window ()
  else (
    let () = move ball () in
    let () = begin_drawing () in
    let () = clear_background Color.white in
    let () = draw_text "move the ball with arrow keys" 10 10 20 Color.lightgray in
    let () = draw_circle_v ball 50.0 Color.maroon in
    let () = end_drawing () in
    loop ball ())
;;

let () =
  let screen_width = 800 in
  let screen_height = 450 in
  let title = "raylib [core] example - keyboard input" in
  let ball =
    { x = Float.of_int screen_width /. 2.0; y = Float.of_int screen_height /. 2.0 }
  in
  let () = init_window screen_width screen_height title in
  let () = set_target_fps 60 in
  loop ball ()
;;
