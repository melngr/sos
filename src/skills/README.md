All Skill classes inhert from Skill and have similar traits</br>
Each Skill does different damage and Monster objects learn a different set of Skill objects than the player</br>

More Skill_s will be added to make the game more interseting over time.</br>

All Skill subclasses follow the same general structure:</br>
+ a constructor that take a String name and int maxuses
+ a destructor because of subclassing
+ a use function that takes a int statvalue

The damage retured from the Skill.use(int) varyies by Skill
