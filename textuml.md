Player and Monster are both subclasses of the Entity class which provides some general functions to get/set data. Player has more specifics on player guided actions and Monster has more specifics on when they are encountered.

Skills and Items are both subclasses of the Useable class which, similar to the Entity class has some utility functions, but the primary functions of both come from within their classes. Both Player and Monster can have Skill objects, and also vary with which Skill they have, but only Player objects can possess Item objects.

DungeonRoom is a class which randomly generates the contents within as well as passageways to other DungeonRoom 's. Due to memory constraints, each DungeonRoom will delete itself after the Player leaves/chooses another DungeonRoom (tentative). If a DungeonRoom generates a Monster, the Player and Monster are passed to a CombatHandler in the DungeonRoom. This CombatHandler will manage the turn based combat for the Player and Monster.

The main class handles the menu as well as generating and keeping track of DungeonRooms and the Player so that after beating a certain percentage of Monsters, certain special DungeonRoom will be generated.
