Console project using Visual Studio 2017 or 2019 for a simple battle simulation game between a knight and an orc.

Knight Characteristics:
- 20 health points and a 50-point shield.
- A sword that deals 5 damage per turn.
- A "charge" ability that deals double damage every 3 turns with a 60% success rate. Failure still incurs the 3-turn cooldown.
- Damage first reduces the shield before affecting health.

Orc Characteristics:
- 60 health points, no shield.
- An axe that deals 8 damage per turn.
- A "stun" ability that stuns the enemy for one turn every 5 turns with a 20% success rate. Failure still incurs the 5-turn cooldown.

Game Mechanics:
- Each turn includes special abilities activation followed by combat.
- The game continues until one unit is defeated.
- Each unit directly inflicts damage on the enemy, considering any special ability effects.
