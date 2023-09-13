module C = Configurator.V1

let () =
C.main ~name:"foo" (fun _ ->
let default : C.Pkg_config.package_conf =
  { libs   = ["-lraylib"]
  ; cflags = ["-lraylib"]
  }
in
let conf = default
in


C.Flags.write_sexp "c_flags.sexp"         conf.cflags;
C.Flags.write_sexp "c_library_flags.sexp" conf.libs)
