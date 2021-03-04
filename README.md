# Bomberman 2.0
Bomberman game in c++ using SFML. This version of game provides multiplayer gameplay on a single computer as well as LAN gameplay. Version 1.0 available [here](https://github.com/kamildlugajczyk/Bomberman).

## Controls
<b>Player 1:</b>
<ul>
  <li> Movement: W, S, A, D
  <li> Planting bomb: Space
</ul>

<b>Player 2:</b>
<ul>
  <li> Movement: UP, DOWN, LEFT, RIGHT
  <li> Planting bomb: Right Shift
</ul>

## Map
Map as .txt file is loaded from <i>res/map/Map.txt</i> (if you want to modify game map, feel free to change this file).
<ul>
  <li> <b>2</b> - solid block
  <li> <b>1</b> - breakable block
  <li> <b>0</b> - background block
</ul>

## Statistics
Statistics of all played games are saved in .txt file in <i>res/stats/statistics.txt</i>, including date, time, winner and amount of bombs planted by each player.

## LAN
In order to play LAN, one of the players have to host the game. After that, second player has to type in host's IP address and join the game.

## Scrennshots
<img src="Screenshots/main_menu.png">
<img src="Screenshots/lan_menu.png">
<img src="Screenshots/start.png">
<img src="Screenshots/bomb.png">
<img src="Screenshots/explosion.png">
<img src="Screenshots/win.png">
