# Problem Link

[STRWN](https://www.codechef.com/COMR2019/problems/STRWN)



# Description

This is a fight between weapons. There are 3 type of weapons - Dragonglass, Valyrian Steel and Wild Fire. Now, the result of a fight between any 2 weapons is known to be as below:

Dragonglass defeats Valyrian Steel
Valyrian Steel defeats Wild Fire
Wild Fire defeats Dragonglass
Here, note that match between 2 weapons of same type results in draw.

Now, there are D number of dragonglasses, V number of swords of Valyrian Steel and W number of containers of Wild Fire. At a time you can choose any 2 weapons (possibly same weapons) from remaining and make them fight.

If weapon x and weapon y fight, and suppose x defeats y , then y is out of the game and x returns to the respective group of the remaining weapons.

If weapon x and weapon y fight, and suppose the match is draw, then both of them return to their respective groups.

Your task is to minimize the total number of remaining weapons of all 3 types if the game can go on forever.

**Note:** After a weapon wins and return to the group of weapons, you can again choose any 2 weapons, that you want, from all the remaining ones.