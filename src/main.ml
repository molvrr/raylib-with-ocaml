let rec loop () =
  if Raylib.window_should_close ()
  then ()
  else (
    let () = Raylib.begin_drawing () in
    let () = Raylib.clear_background @@ Raylib.Color.(RGBA (100, 100, 255, 255)) in
    let () = Raylib.end_drawing () in
    loop ())
;;

let () =
  let () = Raylib.init_window 600 480 "Joguinho" in
  let () = Raylib.set_target_fps 60 in
  let () = loop () in
  Raylib.close_window ()
;;
