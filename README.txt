# cub3d
int this projer we will make game like "Wolfenstein 3D" ,you don't know "Wolfenstein" really ,
its parent of fps games , you need try to play it.

# informations

-----------------------------------------------------------------------------------------------------------------------------------------------------
|  -> your program must be smooth !   																												|
|  -> your porgram must be working with any resulution and any "valid" map	!						    											|
|  -> you must have diferent texture evry direction	{North, South, East, West} !																	|
|  -> you need to to aet diferent colors for "floor" and "celing" (it can be changed) !																|
|  -> right and left arrow key let let lock right and left !																						|
|  -> "W,S,A,D" keys let ou mouve !	    																											|
|  -> ESC must close the window and quit the program cleanly !																						|
|  -> Clicking on the red cross on the window’s frame must close the window and quit the program cleanly											|
|  -> The use of images of the minilibX is strongly recommended 																					|
|  -> your program must take first argument that have map file name and her extension ".cub" !														|
|  -> The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s					|
|  		start position and spawning orientation !																									|
|  -> the map must be close by walls ! (if not the program must be return an error) .																|
|  -> you can separated by one or more empty line(s) for element type but map can't !																|
|  -> in file ".cub" you must write the element types (path of W,N,S,E texture) then write the map !												|
|  -> Except for the map, each type of information from an element can be separated by one or more space(s) !										|
|  -> The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be					|
|  		able to parse any kind of map, as long as it respects the rules of the map !																|
|  -> if map not valid you program must be exit and print "Error\n" followed by your error message !												|
-----------------------------------------------------------------------------------------------------------------------------------------------------

#ExMapFile

 ---------------
| ExMapFile.cub |
----------------------------------------
|	NO ./path_to_the_north_texture		|
|	SO ./path_to_the_south_texture		|
|	WE ./path_to_the_west_texture		|
|	EA ./path_to_the_east_texture		|
|										|
|	F 220,100,0							|
|	C 225,30,0							|
|										|
|			1111111111111111111111111	|
|			1000000000110000000000001	|
|			1011000001110000000000001	|
|			1001000000000000000000001	|
|	111111111011000001110000000000001	|
|	100000000011000001110111111111111	|
|	11110111111111011100000010001		|
|	11110111111111011101010010001		|
|	11000000110101011100000010001		|
|	10000000000000001100000010001		|
|	10000000000000001101010010001		|
|	11000001110101011111011110N0111		|
|	11110111 1110101 101111010001		|
|	11111111 1111111 111111111111		|
-----------------------------------------
