#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class Being {
public:
	bool exists = false;
	string name;
	int max_HP; //Added max Mp and Hp to serve as the base values that enemies and partymembers will return to after either new encounters or rest
	int max_MP; //So if a party member levels up, their max Hp and MP will change not their current. 
	int HP;
	int MP;
	int attackpower;

};

class partymembers: public Being{
public:
	bool shielded = false;
	bool has_abilities = false;
	bool carrying = false;
	bool powerup = false;
	int exp;
	string type;
	string ability1 = "None";
	string ability2 = "None";
	string ability3 = "None";
	int level = 1;
	void rest() {
		HP = max_HP;
		MP = max_MP;
	}
	void condition() {
		cout << endl << name << endl;
		cout << "HP:" << HP << "/" << max_HP << endl;
		cout << "MP:" << MP << "/" << max_MP << endl;
		cout << "Lvl:" << level << endl;
	}
};

class Healer : public partymembers {
public:
	void level_up() {
		if (exp >= (level * 100)) {
			level += 1;
			cout << name << " leveled up!" << endl;
			max_HP += (5 * level);
			max_MP += (15 * level);
			HP = max_HP;
			MP = max_MP;
			attackpower = (1 * level);
		}
	}
	template<class T> void healing(T target) {
		int heal = (10 * level);
		if (MP <= 0 || MP < 5) {
			cout << name << " can't heal they don't have enough mana!";
		}
		else {
			MP -= 5;
			target.HP = target.HP + heal;
			if (target.HP > target.max_HP) {
				target.HP = target.max_HP;
			}
			cout << name << " heals " << target.name << "for " << heal << " health." << endl;
		}
	}
	void group_healing(partymembers target, partymembers target2, partymembers target3) {
		if (MP <= 0 || MP < 10) {
			cout << name << " can't perform this ability they dont have enough mana!";
		}
		else {
			MP -= 10;
			int heal = 5 * level;
			target.HP += heal;
			target2.HP += heal;
			target3.HP += heal;
			cout << name << " healed everyone for " << heal << "health." << endl;
		}
	}
	template<class T> void revive(T target) {
		if (MP <= 0 || MP < 20) {
			cout << name << " can't revive without more mana!" << endl;
		}
		else {
			MP -= 20;
			target.HP = (target.max_HP / 2);
			cout << target.name << " has been revived from the grave!" << endl;
		}		
	}
};

class Knight : public partymembers {
public:
	void level_up() {
		if (exp >= (level * 100)) {
			level += 1;
			cout << name << " leveled up!" << endl;
			max_HP += (10 * level);
			max_MP += (2 * level);
			HP = max_HP;
			MP = max_MP;
			attackpower = 5 * level;
		}
	}
	void taunt(enemies enemy) {
		if ((MP <= 0) || (MP < 5)) {
			cout << name << " can't taunt they dont have enough mana!" << endl;
		}
		else {
			MP -= 5;
			enemy.taunted = true;
			cout << enemy.name << " has been taunted and can only focus on attacking " << name << "." << endl;
		}
	}
	template<class T> void shield_friend(T buddy, T buddy2, T buddy3) {
		if (MP <= 0 || MP < 5) {
			cout << name << " does not have enough mana for this move!" << endl;
		}
		else {
			if (buddy2.shielded == true || buddy3.shielded == true) {
				cout << name << " can only shield one person!" << endl;
			}
			MP -= 5;
			buddy.shielded = true;
			cout << buddy.name << " is shielded and " << name << "will take all incoming damage." << endl;
		}
	}
	void sacrifice(Hero hero) {
		if (HP < 10) {
			cout << name << " cant sacrifice they are too low on health!" << endl;
		}
		else {
			HP -= 10;
			hero.charged_up = true;
			cout << name << " charges up " << hero.name << "." << endl;
		}
	}
};

class Hero : public partymembers {
public:
	bool charged_up = false;
	void level_up() {
		if (exp >= (level * 100)) {
			level += 1;
			cout << name << " leveled up!" << endl;
			max_HP += (7 * level);
			max_HP += (5 * level);
			HP = max_HP;
			MP = max_MP;
			attackpower = 5 * level;
		}
	}
	void big_slash(enemies enemy) {
		if (MP <= 0 || MP < 5) {
			cout << name << " does not have enough mana for this move!" << endl;
		}
		else {
			MP -= 5;
			int x = attackpower * 2;
			enemy.HP -= x;
			cout << name << " channels thier strength into a powerful slash! " << enemy.name << " takes " << x << " damage." << endl;
		}
	}
	void slime_toss(enemies enemy) {
		enemy.HP -= 1;
		enemy.slimy = true;
		cout << name << " tosses some slime at the " << enemy.name << "!" << endl;
	}
	void fireball(enemies enemy) {
		if (MP < 20) {
			cout << name << " does not have enough mana for this move!" << endl;
		}
		else {
			MP -= 20;
			int attack = attackpower * 10;
			enemy.HP -= attack;
			if (enemy.slimy == true) {
				enemy.burning = true;
			}
			cout << name << " launches a fireball dealing " << attack << " damage!" << endl;
		}
	}
};

class Hunter : public partymembers {
	void level_up() {
		if (exp >= (100 * level)) {
			cout << name << " has leveled up!" << endl;
			level += 1;
			max_HP += (5 * level);
			max_MP += (10 * level);
			HP = max_HP;
			MP = max_MP;
			attackpower = 10 * level;
		}
	}
};

class enemies : public Being {
public: 
	bool taunted = false;
	bool slimy = false;
	bool burning = false;
	string name;
	string abilities;
	// int upgradeLevel = partymembers.level;
	int HP = 20;
	int MP = 20;
	void update_level(Hero x) { //For use in the while loop to update the enemies stats from the original list of enemies which could be given default values
		level = x.level;
		HP = 20 * level;
		MP = 20 * level;
	}
private:
	int level = 1;

};

class Journey {
public:
	int length;
	int encounters;
	void reduce() {
		length -= 100;
		cout << length << " miles left to go.";
	}
	void enemy_defeated(enemies x) {
		encounters - 1;
		cout << "You defeated the " << x.name << "!";
	}
};

Knight knight;
Healer farmgirl;
partymembers hunter;
Hero maincharacter;
Journey theEnd;
enemies enemylist[5];
enemies enemy1;
enemies enemy2;
enemies enemy3;
enemies enemy4;
enemies enemy5;
Healer heal;

void options() {
	cout << endl << "What would you like to do: " << endl;
	cout << "1. Travel" << endl;
	cout << "2. Rest" << endl;
	cout << "3. Check on Party" << endl;
	cout << "4. Quit" << endl;
}

void begin() {
	system("cls");
	system("Color F5");
	cout << "*************************************************************************************" << endl;
	cout << "*************************************************************************************" << endl;
	cout << "*****************************/*********************\**********************************" << endl;
	cout << "****************************/***********************\*********************************" << endl;
	cout << "***************************/*************************\********************************" << endl;
	cout << "**************************/***************************\*******************************" << endl;
	cout << "*************************/*****************************\******************************" << endl;
	cout << "************************/*******************************\*****************************" << endl;
	cout << "********************           Welcome to NUBERA!!!         *************************" << endl;
	cout << "************************\*******************************/*****************************" << endl;
	cout << "*************************\*****************************/******************************" << endl;
	cout << "**************************\***************************/*******************************" << endl;
	cout << "***************************\*************************/********************************" << endl;
	cout << "****************************\***********************/*********************************" << endl;
	cout << "*****************************\*********************/**********************************" << endl;
	cout << "*************************************************************************************" << endl;
	cout << "*************************************************************************************" << endl;
	cout << endl;
	cout << "               Let us begin your journey...(Press ENTER to continue)" << endl;
	cin.ignore(); //https://stackoverflow.com/questions/903221/press-enter-to-continue
}

void gameWon() {
	cout << "**************************************************************************************" << endl;
	cout << endl;
	cout << "You have successfully completed the game. Thank you for playing!";
	cout << endl;
	cout << "**************************************************************************************" << endl;
	cout << "Press enter to continue...";
	cin.ignore();

}

char gameOver() {
	system("Color 04");
	cout << endl;
	cout << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**********************************||||Game over...|||*********************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << endl;
	cout << "Play again? (Y/N):";
	playAgain:
	char answer;
	cin >> answer;
	if ((answer == 'Y') || (answer == 'y')) {
		return answer;
	}
	else if ((answer == 'N') || (answer == 'n')) {
		return answer;
	}
	else {
		cout << "That is an invalid entry, please try again...: ";
		goto playAgain;
	}
	return answer;

}

int main() {

	srand((unsigned)time(0)); // unsigned means positive integers only including 0.
	// Having trouble with syntx issues...
	enemy1.name = "Wolf";
	enemy2.name = "Killer-Plant";
	enemy3.name = "Mr. Bear";
	enemy4.name = "THE Fungus Amongus";
	enemy5.name = "Bandit";
	enemylist[0] = enemy1;
	enemylist[1] = enemy2;
	enemylist[2] = enemy3;
	enemylist[3] = enemy4;
	enemylist[4] = enemy5;
	maincharacter.max_HP = 15;
	maincharacter.max_MP = 5;
	knight.max_HP = 20;
	knight.max_MP = 5;
	hunter.max_HP = 10;
	hunter.max_MP = 10;
	farmgirl.max_HP = 5;
	farmgirl.max_MP = 20;

theBeginning:
	begin();
	system("cls");
	system("Color B0"); //https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/ 
	cout << "The story begins in the small fishing village near the coast of Nubera." << endl;
	cout << "You open you eyes and find yourself laying in a bed" << endl;
	cout << "In your daze, you seek to recall your name." << endl << "What is your name?" << endl;
	//partymembers maincharacter;
	cin >> maincharacter.name;
	cout << "\"Ah thanks right, my name is " << maincharacter.name << "\"" << endl;
	cout << maincharacter.name << " awakens in a small cottage in a daze with no recollection of how they got there." << endl;
	cout << "Upon a quick glance around the room " << maincharacter.name << " realizes they are alone inside of what seems to be a cottage." << endl;

decision1:
	cout << "What will you do?" << endl;
	cout << "1. Get up and leave the cottage." << endl;
	cout << "2. Take a closer look at your surroundings." << endl;
	char decision;
	cin >> decision;
	/* Trouble figuring out how to embed this in...
	void randomEncounter() {
		int encounter = rand() % 2;
		if (encounter) {
		repeatCycle:
			int enemyArrNumber = 1 + rand() % 5;
			int hitDie = 1 + rand() % 6;
			int hitDie2 = 1 + rand() % 6;
			cout << maincharacter.name << " hits " << enemylist[enemyArrNumber].name << " for " << hitDie << " damage" << endl;
			cout << enemylist[enemyArrNumber].name << " loses " << hitDie << " HP" << endl;
			enemylist[enemyArrNumber].HP = enemylist[enemyArrNumber].HP - hitDie;
			if (enemylist[enemyArrNumber].HP <= 0) {
				cout << "You have defeated, " << enemylist[enemyArrNumber].name << endl;
				cout << "You earned 50 EXP!" << endl;
				maincharacter.exp += 50;
				knight.exp += 50;
				farmgirl.exp += 50;
				hunter.exp += 50;
			}
			cout << enemylist[enemyArrNumber].name << " hits you for " << hitDie2 << " damage" << endl;
			maincharacter.HP = maincharacter.HP - hitDie2;
			if (maincharacter.HP <= 0) {
				cout << "You have DIED..." << endl;
				gameOver();
				exit(0);
			}
		}
		goto repeatCycle;
	};
	*/
	
	if (decision == '1') {
		cout << "You walk outside of the small one room cottage and flinch at the smell around you." << endl;
	}
	else if (decision == '2') {
		cout << "You look around the room with a closer inspection and notice your room is dirty." << endl;
		cout << "\"I really should clean this place up\" you think to yourself and you head for the door" << endl;
	}
	else {
		cout << "That is not a valid entry, please enter a valid entry" << endl;
		goto decision1;

	}
	cout << "Scenery: As you look around you see the buildings destroyed and covered in a foul smelling viscous" << endl;
	cout << "substance.There is nothing to indicate that people still live here or may still be here." << endl;
	cout << " You look to the ocean and see something shining into your eyes on the beach." << endl;
	char decision2;
	decision2:
	cout << "What will you do?" << endl;
	cout << "1. Go to the beach and investigate the shining object" << endl;
	cout << "2. Ignore the object and make your way to the nearest city" << endl;
	cout << "3. Go into the nearby woods" << endl;
	cin >> decision2;

	if (decision2 == '2') {
		nearbycity:
		cout << "You decide to head on to the nearest city of Seamount in search of " << endl;
		cout << "answers for what is happening around you. On the way you discover a wagon that " << endl;
		cout << "has lost one of its wheels with someone crying for help inside." << endl;
		cout << "What will you do?" << endl;
		cout << "1. Go to the source of the crying." << endl;
		cout << "2. Continue on your way to the city" << endl;
		char decision2d1;
		cin >> decision2d1;
		system("cls");		
		if (decision2d1 == '1') {
			cout << "As you feel like it could be possible to abandon the cries for help you just can't " << endl;
			cout << "bring yourselves to do it.You and the knight look inside of the wagon and see a small farm girl crying " << endl;
			cout << "for help inside. The Farm Girl joins your party." << endl;
			farmgirl.exists = true;
			cout << "You have seen this farm girl before.... what was her name?" << endl;
			cin >> farmgirl.name;
			cout << "Ah thats right, her name was " << farmgirl.name << "." << endl;
			goto afterfarmgirl;
		}
		else if (decision2d1 == '2') {
			cout << "You ignore the blatant and loud cries for help and choose to not lose anytime " << endl;
			cout << "on your endeavor to reach the city." << endl;
				afterfarmgirl:
				cout << "Suddenly along the way you are ambushed by two plant-like creatures that appear similar in appearance to a venus flytrap." << endl;
				if (knight.exists) {
					cout << "The knight tries his hardest to hold them off but fails." << endl;
				}
				else {
					cout << "The plant-like creature raises his tenticle like arms and crushes you." << endl;
					cout << "if only there was a knight to save you..." << endl;
					goto gameover;
				}
				if (farmgirl.exists) {
					cout << "\"I'll take care of this!\" the farm girl exclaims and she walks toward the plant-like creatures." << endl;
					cout << "\"Poor things are just hungry\" the farm girl reaches into her pocket, pulls out some plant food" << endl;
					cout << "While the plant like creatures are distracted you are free to continue on your journey." << endl;
				}
				else {
					cout << "You fall prey to the plants. If only you had someone with you that knew " << endl;
					cout << "more about plants like a farmer." << endl;
					goto gameover;
				}
			
		}
		
	}
	else if (decision2 == '1') {
		knight.exists = true;
		cout << "You go to the beach to find the shine is actually a set of armor, and someone seems to still " << endl;
		cout << "be inside of it. \"its dangerous around!\" The knight yells. \"We should stick together!\"" << endl;
		cout << "The knight wants to join your party." << endl;
		cout << "What is his name?" << endl;
		cin >> knight.name;
		cout << knight.name << " joins the party" << endl;
		cout << "You and the knight must now decide where to go" << endl;
		subsubdecide:
		cout << "What will you do?" << endl;
		cout << "1. Go to the nearest city" << endl;
		cout << "2. Go into the nearby woods" << endl;
		char subdecide;
		cin >> subdecide;
		system("cls");
		if (subdecide == '1') {
			goto nearbycity;
		}
		else if (subdecide == '2') {
			cout << "Something compels you towards the forest. Wandering about into the forest you begin to walk deeper " << endl;
			cout << "and deeper.Until you realize that you are now lost. You try your hardest to recall the direction you" << endl;
			cout << "came from but to no avail. After an hour of walking aimlessly you spot someone in the forest and" << endl;
			cout << "call out to them. A hunter comes up to you and helps you out of the woods onto the main road." << endl;
			cout << "The hunter says that he can't find any animals in the entire forest and doesn't remember anything" << endl;
			cout << "about who he is. He decides to join your party." << endl;
			cout << "What is the hunter's name?" << endl;
			hunter.exists = true;
			cin >> hunter.name;
			cout << "You welcome " << hunter.name << " into your party and make your way out of the forest" << endl;
			cout << "Finally you decide to make your way to the nearest city"<< endl; 
			goto nearbycity;
		}
		else {
			cout << "That is not a valid entry, please enter a valid entry" << endl;
			goto subsubdecide;
		}
	}
	else if (decision2 == '3') {
		cout << "You wander around the woods for what seems like hours. You quickly lose your way." << endl;
		cout << "Suddenly you are attacked by a pack of wolves, you are never heard from again" << endl;
		goto gameover;

	} else {
		cout << "That is not a valid entry, please enter a valid entry" << endl;
		goto decision2;
	}

	cout << "You travel along the well worn road for what seems like hours. The night is approaching and your stomach begins to grumble" << endl;
	cout << "Now would be a good time to get some food" << endl;
	if (hunter.exists) {
		cout << "You send your new-found hunter friend out into the wilds to gather food" << endl;
		cout << "After a short stint of time he returns with a few captured rabbits. Your party will get to eat tonight and continue their journey" << endl;
	}
	else {
		cout << "After hours of searching for food you come up empty-handed. Your party becomes too hungry and weak to finish the journey" << endl;
		cout << "Unforunately you all starve. If only you had a hunter with you";
			goto gameover;
	}
	cout << "You continue on your journey and along the path you see a green wobbly blob laying in the middle of the road" << endl;
	cout << "Curious, you decide to poke it" << endl;
	cout << "\"Hey! Keep your hands to yourself there mate!\" you hear come from the slime" << endl;
	cout << "\"You don't see me intrupting you on you journey do ya? Where are you headed anyway?\"" << endl;
	cout << "You explain to the slime that you are headed to Seamont..." << endl;
	cout << "\"What a coincidence! So am I, how about you allow me to tag along?\" before you can even make up your mind" << endl;
	cout << "the slime jumps on your back. Exhausted, you decide not to pick a fight and you continue on your journey....."<< endl;
	cout << "You continue on your journey for another day. Suddenly you find yourself in a forest still following the same road" << endl;
	cout << "Hungry again, you ask " << farmgirl.name << " if there is anything she could " << endl;
	cout << "forage for in the woods along the path. " << farmgirl.name << " agrees to take a look. " << endl;
	cout << "Moment later she reemerges from the tree line carrying some strange mushrooms" << endl;
	decide3:
	cout << "What will you do?" << endl;
	cout << "1. Eat the mushrooms" << endl;
	cout << "2. Pass on the mushrooms" << endl;
	char decision3;
	cin >> decision3;
	cout << endl;
	system("cls");
	if (decision3 == '1') {
		cout << "You eat the mushroom and feel a strange tingle throughout your body.As this feeling goes through" << endl;
		cout << "your legs you drop to the floor instantly and " << knight.name << " and " << farmgirl.name << " go to help you up." << endl;
		cout << "You try to stand on your own but to no avail. There is no sensation or feeling in either of your legs." << endl;
		cout << "Luckily the knight offers to carry you the rest of the way to Seamont." << endl;
		knight.carrying = true;
	}
	else if (decision3 == '2') {
		cout << "You pass on the mushroom and decide that it is better if the party waits until they arrive in Seamont" << endl;
		cout << "to search for some kind of nourishment." << endl;
	}
	else {
		cout << "This is not a valid entry, please enter a valid entry";
		goto decide3;
	}

	cout << "The knight, slime, hunter, and farm girl make for a merry traveling party and the entire time you feel a" << endl;
	cout << "sort of elation about what might be in store for you all in Seamont. You suddenly feel famished and" << endl;
	cout << "somehow like it were reading your mind the slime splits a part of itself off. It emotes towards you and its" << endl;
	cout << "movements read as if it were beckoning you to eat the split piece. Although you are humbled by the offer" << endl;
	cout << "the goop reeks and is currently on the floor.";
	char decision4;
	dec4:
	cout << "What will you do?" << endl;
	cout << "1. Eat the slime" << endl;
	cout << "2. Don't eat the slime." << endl;
	cin >> decision4;
	system("cls");
	if (decision4 == '1') {
		cout << "Reluctantly you put the slime in your mouth and despite the putrid smell it actually tastes quite good." << endl;
		cout << "Suddenly you feel a tingle run through your body and you feel as if you have gotten stronger somehow." << endl;
			maincharacter.powerup = true;
			cout << endl;
			cout << "==========================" << endl;
			cout << maincharacter.name <<" has powered up!!!" << endl;
			cout << "==========================" << endl;
			cout << endl;
		



	}
	else if (decision4 == '2') {
		cout << "You choose to not eat the slime. Slime motions a somewhat sad face as best it can. The knight feels." << endl;
		cout << "sorry for the creature and eats the slime off the floor. The knight feels completely find and even goes as" << endl;
		cout << "far to say that slime tasted delicious";
			knight.powerup = true;
			cout << endl;
			cout << "==========================" << endl;
			cout << knight.name <<" has powered up!!!" << endl;
			cout << "==========================" << endl;
		
	}
	else {
		cout << "That is not a valid entry. Please enter a valid entry";
			goto dec4;
	}

	cout << "Arriving in Seamont: After the trial and tribulations of a simple walk to Seamont you and your party" << endl;
	cout << "finally arrive. Something is strange though the city gates are open and there isn't much noise coming from" << endl;
	cout << "the city. The building and sprawling castle seen from outside of the city walls seem to be in perfect" << endl;
	cout << "condition. After examining the outside of the city you and your party head on in and see if they can find anyone in the city." << endl;
	// insert new code here -- Last decision goes to gameWon but needs to have some time threshold
	// Beginning of Nick's section of code (feel free to add code to sections where it is needed)
	theEnd.length = 3000;
	theEnd.encounters = 0;
	cout << endl << "================================================================================" << endl;
	cout << "You made it inside the city but no one is there, but a note tells you to head west." << endl;
	cout << "Begin your journey to the west to find where everyone has gone." << endl;
	char journeyChoice;
	int encounterChance;
	maincharacter.HP = 15; // All of these values are initialized since I couldn't compile wihtout them, test values but I think its relatiely balanced for scaling up levels. 
	maincharacter.MP = 5;
	maincharacter.attackpower = 5;
	knight.HP = 20;
	knight.MP = 5;
	knight.attackpower = 5;
	hunter.HP = 10;
	hunter.MP = 10;
	hunter.attackpower = 10;
	farmgirl.HP = 5;
	farmgirl.MP = 20;
	farmgirl.attackpower = 1;
	maincharacter.exp = 0;
	knight.exp = 0;
	hunter.exp = 0;
	farmgirl.exp = 0;
	while (maincharacter.HP > 0) {
		options();
		cin >> journeyChoice;
		if (journeyChoice == '1') {
			theEnd.reduce();
			encounterChance = rand() % 10;
			if (encounterChance > 5) {
				// start an encounter between the party and an enemy, could use the other encounter fucntion here or try to work it into this option
				// all options are ok for other group members to add something to, if not I will write out the code for it
			}
		}
		else if (journeyChoice == '2') {
			cout << endl << "The party takes time to rest and refresh." << endl;
			knight.rest();
			hunter.rest();
			maincharacter.rest();
			farmgirl.rest();
		}
		else if (journeyChoice == '3') {
			maincharacter.condition();
			knight.condition();
			farmgirl.condition();
			hunter.condition();
		}
		else if (journeyChoice == '4') {
			goto gameover;
		}
	} 
	//End of Nicks poriton of code (with some functions and class changes at the top)
	gameWon();
	exit(0);
gameover:

	char choice = gameOver();
	if ((choice == 'Y') || (choice == 'y')) {
		begin();
		goto theBeginning;
	}
	
	return 0;
}