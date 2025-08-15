# Turtledove-RC

Turtledove- RC is a lightweight ray-casting engine that renders 3D enviroments from 2D text based-maps, similar to [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D#Development)'s.

## Overview

The program renders a real-time 3D representation of a 2D map defined in a text-based input file. You can move freely through the environment, with solid walls and basic collision detection.

</br>
</br>

<img width="900" height="auto" alt="image" src="https://github.com/user-attachments/assets/ce92b1c4-86c7-4001-96d4-3bd3ba11f43d" />

</br>
</br>

<img width="900" height=auto alt="image" src="https://github.com/user-attachments/assets/db4e2017-62f8-49c5-8a8b-4d6a28ae7c4a" />

</br>
</br>

Map info is contained in .cub files which contains texture paths for each wall orientation, RGB colors for floor and ceiling and a 2D map layout using ASCII characters.

## Building

To compile the project yourself simply clone the repository and run make inside the root directory of the repository.

```
git clone https://github.com/luna7111/turtledove-RC
cd cub3d
make
```

> [!NOTE]
> This project depends on [MiniLibX](https://github.com/42paris/minilibx-linux), which requires the following system requirements:
>
> - MinilibX only supports TrueColor visual type (8,15,16,24 or 32 bits depth)
> - gcc
> - make
> - X11 include files (package xorg)
> - XShm extension must be present (package libxext-dev)
> - Utility functions from BSD systems - development files (package libbsd-dev)
> - **e.g. sudo apt-get install gcc make xorg libxext-dev libbsd-dev (Debian/Ubuntu)**

## Running

To run the program execute the binary and use a valid .cub map as an argument, some test maps are listed on the maps/valid/ directory, but feel free to create your own, be creative!

```
./cub3D maps/valid/example.cub
```
> [!TIP]
> Use the WASD keys to move around the map. Use the left and right arrow keys to rotate the camera.


## The ray-casting algorithm

For each frame, walls are scanned from left to right across the player's field of view by casting one ray per vertical screen column.

<img width="512" height="512" alt="sweep image" src="https://github.com/user-attachments/assets/c4be51ca-ac70-4d21-b5cf-f62d1e5ceed3" />

![raycast-ray](https://github.com/user-attachments/assets/4eb032f4-02ab-4c94-9c68-c4f387014c34)


---

<img width="1600" height="739" alt="image" src="https://github.com/user-attachments/assets/4589fd88-b4a0-45fa-8062-69dd165ec574" />

Made with love by [caroldmg](https://github.com/caroldmg) and [luna7111](https://github.com/luna7111) <3
