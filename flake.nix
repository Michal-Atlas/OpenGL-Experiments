{
  inputs = {
    nixpkgs.url = "github:NixOs/nixpkgs";
    parts.url = "github:hercules-ci/flake-parts";
    systems.url = "github:nix-systems/default";
  };
  outputs = {
    parts,
    systems,
    ...
  } @ inputs:
    parts.lib.mkFlake {inherit inputs;} {
      systems = import systems;
      perSystem = {pkgs, ...}: {
        packages.default = pkgs.stdenv.mkDerivation {
          name = "OpenGL-Experiments";
          src = ./.;
          nativeBuildInputs = [pkgs.cmake];
          buildInputs = with pkgs; [
            glew
            glfw
            glm
          ];
        };
      };
    };
}
