The Project that I am proposing to do is a battle-ship minigame where a player on a boat has to sink the opposing boat. The first person to sink the opposing boat is the winners.
The game will be a two player game with both players using controls on the keyboard (WASDF, Arrow Keys + Enter).
In depth, the game will consist of a player who will be able to move in a 2D environment (a ship). The camera view will be a birds eye view of the scene.
To simplify things, instead of the player firing cannons like in real ships, the player will have a rocket launcher that they will be able to fire with. 
The player will have to collect ammo around the ship in order to keep firing rockets. The ammo will be spawned in set locations in the ship, with random spawn timers. 
The rocket will be fired with F as Player 1 or enter as Player 2. The rocket will eliminate any part of the enemy ship it makes contact with.
If there player is standing in front of an incoming rocket, they will reflect it back. The ship will consist of many different squares, rectangles, and potentially other geometries. 
The game will include a timer that will end the match in a draw if neither person can win. Initially, the players and other objects will be represented by squares, although
I do plan on changing that (see below).

One of the libraries I will be using is the 2D graphics library provided by openframeworks. This will allow me to draw different 2D shapes to represent the ship, players, and other objects.
Since this library does not count toward the "significant library" (used in ofSnake), I will also be using the openFrameworks sound library (https://openframeworks.cc/documentation/sound/)
to create sound when a player lands a hit, or does some other action. If I have enough time, I also plan on using the 2D graphics library to use images and animations to make the game
more visually appealing (https://openframeworks.cc/ofBook/chapters/animation.html).

The only background that I have in building this project is my C++ knowledge and experience I have from the MP's this semester. In terms of the game design, I have a clear
visualization of the game I am planning on building, which is advantageous when building a large project.