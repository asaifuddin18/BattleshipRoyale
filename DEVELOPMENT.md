Log 1

Using the 3D graphics library, I was able to load and display a sphere with the earth texture on top of it. The experience I had with working with this library was
hard at first, but I was able to understand how to build and display a 3D object. I mainly followed tutorials online, which helped simplify the process and
let me better understand the methods' and classes' functions.
--------------------------------------------------------------------------------
Log 2

Changed project from 3D to 2D (see PROPOSAL.md).
Created player class and .h files to represent the player's actions. Implemented movement commands for both players, and set the background of the game.
I figured out how to draw shapes and move them fluidly across the screen.

Short Term Goals:
Implement Resize method that works when player changes size of graphic interface.
Implement rocket firing, rocket reflecting, and ammo spawn.
Draw flat ship and implement system which prevents player from leaving the ship.

Problems:
How to read 2 inputs at the same time (2 keys cannot be pressed at the same time).
How to implement a ship that can be modified over time (create a new class?).
--------------------------------------------------------------------------------
Log 3
Implemented Resize method that scales game size with the window size.
Successfully implemented rocket firing mechanism, reflecting, & acceleration.
Implemented map reader and implementer (not compiling).
Created block, map, rocket classes.

Short Term Goals:
Fix map reader and implementer bugs.
Add test cases for methods after fixing map.
Implement audio into game.
Add system which prevents player from leaving ship.

Long Term Goals:
Add pictures and possibly animations to players & rockets.

Problems:
Still need to figure out how to read 2 inputs at the same time.
-------------------------------------------------------------------------------------
Log 4
Fixed Map Loader to properly compile.
Map loader now uses key to determine block colors.
Added test cases for Block, Player, Map, and Rocket classes.
Added ammo system: ammo spawns randomly on players ships. Players can only hold 5 ammo at a time.
Changed the player tracking system to rely on map double array instead of OfRectangle class.
Removed magic numbers with constants.
Added sound effects to rocket fire, rocket hit, and game win.
Removed rocket acceleration and reflect:
Acceleration does not properly work with Map double array system.
Rocket reflect can cause a scenerio which players keep reflecting and game is in a stand still state.