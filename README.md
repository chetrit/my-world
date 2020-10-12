# my-world

## What is my-world ?

My world is a finite terraformer program created with CSFML library (in C). It's a software that allows you to edit and create a world on an arbitrary-sized map in "god mode", with plenty of feature. It aims to show the capabilites of CSFML lib (an adaptation of SFML in C) and a lot of mathematical "cool" effects !

![](.github/ressources/highlight/basic-editing.gif)
![](.github/ressources/highlight/tools.gif)
![](.github/ressources/highlight/menu.gif)
![](.github/ressources/highlight/colors.gif)
![](.github/ressources/highlight/rectangular_map.png)
![](.github/ressources/highlight/3dshape.png)
![](.github/ressources/highlight/animations.gif)

# Installation and compilation
#### Installation
After cloning the repository, you have to install the CSFML library (if you don't already have it !).
If you'r on Fedora (tested on version 29 or higher), you can just execute the ``build_csfml.sh`` script at the root of the project, and It will be installed. Otherwise you can download it on the official website [here](https://www.sfml-dev.org/download/csfml/index-fr.php).

#### Compilation
Compilation using makefile:
```
make
```

# Usage
```
Finite terraformer program created with CSFML.

USAGE
    ./my_world [map_path]*
               ./my_world --convert map_path [map_path]*

OPTIONS
    -h print the usage and quit.
    ```

Check ``map_example`` file for an example of the format for the map to convert (doing a ``./my_world --conver map_example``).

## Features
- Multiple tools (corners only, leveling, brush, reset ...)
- Multiple colors (realistic to mathematical patterns)
- Saves of multiple maps
- Conversion of map from file
- Basic Animations (Basic wave, leveling ...)
- Advanced Animation (3d mathematical functions)
- UX: Helpboxes, settings, burger menus (some are empty)
- Rectangular maps

## Authors
  - [Theo Hinsinger](https://github.com/TheoHertz)
  - [Alexandre Chetrit](https://github.com/chetrit)
  