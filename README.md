# Simulator Description
The game “what time is it, big-bad wolf?” is a popular game played by children. One child, the “wolf”, stands at a fixed location. In our version, the wolf will always be at the origin, (0,0). The children are scattered around the wolf at their own (x,y) locations. The children ask “what time is it, big-bad wolf?” and the wolf states a time, for example, “3 o’clock”. The children then move 3 steps directly toward the wolf. If, instead, the wolf says “lunchtime!”, the wolf grabs the children closest to their location, and they are out of the game. In our version of the game, we are adding an additional rule: children may never leave the first quadrant (so their x and y coordinates must always be strictly positive). Any child who leaves the first quadrant during the course of the game is cheating, and is removed even if the wolf cannot catch them. Any child who attempts to start the game outside of the first quadrant is not allowed to play that round.
# Commands
## SPAWN
**Parameters: *x y***<br/>
**Description:** Spawn a new child to play the game at coordinates (x,y) if the position (x,y) lies within the first quadrant. If so, this child is added to the linked list. Note that the origin and the x or y axes do not belong to the first quadrant. Children may be added at any time until the OVER command is reached. worry about the case where two children have identical coordinates.<br/>
**Output**<br/>
***Success*** if the child's position lies within the first quadrant.<br/>
***Failure*** if the child's position lies outside the first quadrant
## TIME
**Parameters: *t***<br/>
**Description:** The children ask the wolf what time it is. The parameter t is guaranteed to be a double. If the parameter is non-negative, children move that many units toward the wolf, according to: Δ𝑥 = 𝑡 cos(𝑎𝑡𝑎𝑛2(𝑦, 𝑥)) Δ𝑦 = 𝑡 sin (𝑎𝑡𝑎𝑛2(𝑦, 𝑥)) If any child moves out of the first quadrant after applying the movement, the child is removed from the game (and the linked list). If t is strictly negative, all children within a distance of strictly less than 1m from the wolf are removed from the game. This command should still work as specified even if no children are left. Do not worry if, after moving, two children have the same coordinates.<br/>
**Output**<br/>
***number of children still playing: N*** where N is the number of children who are still in the game.
## NUM
**Description:** Output the number of children still playing the game.<br/>
**Output**<br/>
***number of children still playing: N*** where N is the number of children who are still in the game.
## PRT
**Parameters: *D***<br/>
**Description:** Prints the coordinates of all children with a distance strictly less than D from the wolf on a single line using spaces to separate the x and y coordinates. You do not need to worry about sorting the coordinates.<br/>
**Output**<br/>
***X1 Y2 X2 Y2...*** if there are any children within the given distance<br/>
***no children within distance*** if there are no children within the given distance
## OVER
**Description:** Indicates that this game is over. This command ends all input files.<br/>
**Output**<br/>
***the player wins*** if there is at least one child left playing<br/>
***the wolf wins*** if there are no children left playing
