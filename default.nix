{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  # buildInputs is for dependencies you'd need "at run time",
  # were you to to use nix-build not nix-shell and build whatever you were working on
  buildInputs = [
    pkgs.cmake
  ];

  shellHook = ''
    export PS1="\e[0;31m[\u@\h \W]\$ \e[m "
  '';
}
