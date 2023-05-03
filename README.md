# cub3D
 
<p align="center">
<img src="https://github.com/yarutiun/Cub3D/blob/main/screenshots/42%20logo.jpeg?raw=true" alt="42 Wolfsburg Logo" width="150" height="150">
</p>
 
Cub3D is a 42 Wolfsburg raycasting project where a pseudo-3D maze is to be rendered and where the user can traverse in.

For this project it was key to implement a parser that processes custom .cub files and to connect it with a graphics rendering module. 
The latter has a raycaster with a Digital Differential Analysis (DDA) algorithm at its core.

This project was done as a team by:
<ul>
<li> Yurii Arutiunov - <a href="https://github.com/yarutiun">Github</a></li>
<li> Santiago Tena - <a href="https://github.com/santiagotena">Github</a> </li>
</ul>
 
## Rules

### Map:

The program is to parse a .cub file.

This file contains 6 elements and a map.

The elements `NO` `SO` `WE` `EA` are to be paired with paths for.xpm texture files.

Elements`C` and `F` match with RGB values to render the colors of the ceiling and floor respectively.

The map is to have characters `1` for walls and `0` for empty spaces.

The use of space characters is allowed when not used adjacent to a `0` character.

Finally, the map is also to have `N` `S` `W` or `E` character for the player's staring position and spatial orientation.

An example of a valid map looks like this:
<p align="center">
<img src="https://github.com/yarutiun/Cub3D/blob/main/screenshots/test_map.png?raw=true" alt="Map.cub example image">
</p>

### Movement:

The user can use the following keys for movement of the player and the camera:

`W` - Forward movement.<br>
`S` - Backward movement.<br>
`A` - Movement to the left.<br>
`D` - Movement to the right.<br>
`LEFT_ARROW` - Rotate the camera to the left.<br>
`RIGHT_ARROW` - Rotate the camera to the right.

### Available parameters:
 
The only parameter that is needed for this program to run is `path_to_cub_file`.
 
In case of providing an invalid path to a .cub file or by feeding a .cub file with erroneous elements or map,
the program displays an appropriate error message.

Errors include for example: Providing a non-closed map, not providing a player starting position and not 
providing a valid texture file for the walls.
 
# Usage
 
Use `make` to compile the program.
 
Add the required parameter:
 
```
./cub3D <path_to_cub_file>
```
 
# Example
 
Input:
 
```
./cub3D maps/test.cub
```
 
# Screenshots

<p align="center">
<img src="https://github.com/yarutiun/Cub3D/blob/main/screenshots/cube01.png?raw=true" alt="Cub3d example image">
</p>
<p align="center">
<img src="https://github.com/yarutiun/Cub3D/blob/main/screenshots/cube02.png?raw=true" alt="Cub3d example image">
</p>
<p align="center">
<img src="https://github.com/yarutiun/Cub3D/blob/main/screenshots/cube03.png?raw=true" alt="Cub3d example image">
</p>
