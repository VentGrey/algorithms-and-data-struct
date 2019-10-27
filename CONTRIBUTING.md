# First of all...

Thanks a lot for your will to contribute to this repository! :rocket:

This contribution guide will try to help you in your way.

# Programming Languages

> *FOR C-LIKE LANGUAGES! DO NOT GO OVER COLUMN 80, PLEASE :D*

If you make an algorithm please make sure to place it in the correct folder
:happy: such folders are:

* C-C++/ for C and C++ projects
* Kotlin/ for Kotlin projects
* Python/ for Python projects
* Rust/ for Rust projects
* SortingEnv/ for any sorting algorithm made in any language

> You can create a new folder if you introduce a new language :heart:

## C-C++

C and C++ files have their guidelines, this is a learning repository and
consistency is important for begginers :wink: so I'd like to ask you to make a
few modifications to your C code so it looks as awesome as you!

### For C files:

* Must follow the Linux Kernel Code Style
* Do not violate ANSI / ISO conventions. (This means no "#include <conio.h>" or
  similar stuff).
  
### For C++ files:

* Must follow Google Code Style
* Do not violate ANSI / ISO conventions.

Make sure to add your project to the Makefile so it compiles and lets
the CI/CD checks to merge your PR!

## Kotlin

Just place the root directory of your project in there.

> If you are making it with IntelliJ please make sure to exclude the `.idea`
> folder.

## Python

This folder is a mess, I'd be happy to take a PR if you want to propose a way to
order it. I don't have much experience with python so I don't know much.


## Rust

Place the whole cargo project inside. Make sure to exclude the `.git` directory
or try to merge your commits without making it a submodule.

Also please make sure to run `cargo fmt` to format rust code properly.
`cargo clippy` also makes some bonus points :happy:

## Sorting Environment

This repository is also a mess, so please open a PR if you want to propose an
ordering structure :smile:

# I want to fix things

GREAT! This helps me a lot and I thank you for that!

If you'd like to help me squashing some bugs please take a look at the [issues
tab](https://github.com/VentGrey/algorithms-and-data-struct/issues) or the [projects tab](https://github.com/VentGrey/algorithms-and-data-struct/projects) to help me out :rocket: :+1:
