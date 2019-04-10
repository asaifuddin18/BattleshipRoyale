The Project that I am proposting to do is a battle-ship minigame where a player on a boat has to sink the opposing boat. The first person to sink the opposing boat is the winners.
In depth, the game will consist of a player who will be able to move in a 3D environment (a ship). The player will be locked into first person point of view.
To simplify things, instead of the player firing cannons like in real ships, the player will have a rocket launcher that they will be able to fire with. 
The player will have to collect ammo around the ship in order to keep firing rockets. The ammo will be spawned in set locations in the ship, with random spawn timers. 
The rocket will be aimed with right click and fired with left click. The rocket will create an explosion, and damage will scale with distance from the epicenter of the blast.
In addition, if the player is in the blast radius of an enemy attack, the player will lose health. I am planning on having the ship be composed of multiple geometries, 
each having its own health. Once the health of that part of the ship reaches zero, it will break. In addition, each part of the ship is valued differently. 
For example the destroying the top of the ship will hinder player movement, while destroying the bottom of the ship will partially sink it. The game will also 
include a timer, so long drawn out games will not occur.

The main library I will be using is the 3D library provided by openFrameworks (https://openframeworks.cc/documentation/3d/). This will allow me to render the world in a 3D setting,
which allows for more player movement. In addition, I may be planning on using a fluid library (https://github.com/moostrik/ofxFlowTools) to represent the ocean, which will
create the game much more asthetically appealing, and the Sound library provided by openFrameworks (https://openframeworks.cc/documentation/sound/) to create sound when something is
hit or when a player fires. Although the flluid library is recommended for live camera feed, it should still be possible to apply it to my project. The 3D library provides me with
the ability to provide the player with a camera angle and geometries to represent the ship.
f

The only background that I have in building this project is my C++ knowledge and experience I have from the MP's this semester. In terms of the game design, I have a clear
visualization of the game I am planning on building, which is advantagous when building a large project.