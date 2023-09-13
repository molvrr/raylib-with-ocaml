{
  inputs.nixpkgs.url = "github:nix-ocaml/nix-overlays";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = import nixpkgs { inherit system; };
      in {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs;
            with ocamlPackages; [
              dune_3
              findlib
              ocaml
              ocaml-lsp
              ocamlformat
              ocamlformat-rpc-lib

              raylib
              pkg-config

              xorg.libXcursor
              xorg.libXrandr
              xorg.libXinerama
              xorg.libXi

              dune-configurator
            ];

        };
      });
}
