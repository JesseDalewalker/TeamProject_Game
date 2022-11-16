#include <iostream>
#include <Windows.h>

using namespace std;

class Being {
public:
	bool exists = false;
	string name;
	int HP;
	int MP;

};

class partymembers: public Being{
public:
	bool carrying = false;
	bool powerup = false;
};

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

int main() {
	partymembers knight;
	partymembers farmgirl;
	partymembers hunter;
	begin();
	system("cls");
	system("Color B0"); //https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/ 
	cout << "The story begins in the small fishing village near the coast of Nubera." << endl;
	cout << "You open you eyes and find yourself laying in a bed" << endl;
	cout << "In your daze, you seek to recall your name." << endl << "What is your name?" << endl;
	partymembers maincharacter;
	cin >> maincharacter.name;
	cout << "\"Ah thanks right, my name is " << maincharacter.name << "\"" << endl;
	system("cls");	cout << maincharacter.name << " awakens in a small cottage in a daze with no recollection of how they got there." << endl;
	cout << "Upon a quick glance around the room " << maincharacter.name << " realizes they are alone inside of what seems to be a cottage." << endl;

	decision1:
	cout << "What will you do?" << endl;
	cout << "1. Get up and leave the cottage." << endl;
	cout << "2. Take a closer look at your surroundings." << endl;
	int decision;
	cin >> decision;
	system("cls");	if (decision == 1) {
		cout << "You walk outside of the small one room cottage and flinch at the smell around you." << endl;
	}
	else if (decision == 2) {
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
	int decision2;
	decision2:
	cout << "What will you do?" << endl;
	cout << "1. Go to the beach and investigate the shining object" << endl;
	cout << "2. Ignore the object and make your way to the nearest city" << endl;
	cout << "3. Go into the nearby woods" << endl;
	cin >> decision2;
	system("cls");	if (decision2 == 2) {
		nearbycity:
		cout << "You decide to head on to the nearest city of Seamount in search of " << endl;
		cout << "answers for what is happening around you. On the way you discover a wagon that " << endl;
		cout << "has lost one of its wheels with someone crying for help inside." << endl;
		cout << "What will you do?" << endl;
		cout << "1. Go to the source of the crying." << endl;
		cout << "2. Continue on your way to the city" << endl;
		int decision2d1;
		cin >> decision2d1;
		system("cls");		
		if (decision2d1 == 1) {
			cout << "As you feel like it could be possible to abandon the cries for help you just can't " << endl;
			cout << "bring yourselves to do it.You and the knight look inside of the wagon and see a small farm girl crying " << endl;
			cout << "for help inside. The Farm Girl joins your party." << endl;
			farmgirl.exists = true;
			cout << "You have seen this farm girl before.... what was her name?" << endl;
			cin >> farmgirl.name;
			cout << "Ah thats right, her name was " << farmgirl.name << "." << endl;
			goto afterfarmgirl;
		}
		else if (decision2d1 == 2) {
			cout << "You ignore the blatant and loud cries for help and choose to not lose anytime " << endl;
			cout << "on your endeavor to reach the city." << endl;
				afterfarmgirl:
				cout << "Suddenly along the way you are ambushed by two plant-like creatures that appear similar in appearance to a venus flytrap." << endl;
				if (knight.exists) {
					cout << "The knight tries his hardest to hold them off but fails." << endl;
				}
				else {
					cout << "The plant-like creature raises his tenticle like arms and crushes you." << endl;
					cout << "if only there was a knight to save you" << endl;
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
	else if (decision2 == 1) {
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
		int subdecide;
		cin >> subdecide;
		system("cls");
		if (subdecide == 1) {
			goto nearbycity;
		}
		else if (subdecide == 2) {
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
	else if (decision2 == 3) {
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
	int decision3;
	cin >> decision3;
	cout << endl;
	system("cls");
	if (decision3 == 1) {
		cout << "You eat the mushroom and feel a strange tingle throughout your body.As this feeling goes through" << endl;
		cout << "your legs you drop to the floor instantly and " << knight.name << " and " << farmgirl.name << " go to help you up." << endl;
		cout << "You try to stand on your own but to no avail. There is no sensation or feeling in either of your legs." << endl;
		cout << "Luckily the knight offers to carry you the rest of the way to Seamont." << endl;
		knight.carrying = true;
	}
	else if (decision3 == 2) {
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
	int decision4;
	dec4:
	cout << "What will you do?" << endl;
	cout << "1. Eat the slime" << endl;
	cout << "2. Don't eat the slime." << endl;
	cin >> decision4;
	system("cls");
	if (decision4 == 1) {
		cout << "Reluctantly you put the slime in your mouth and despite the putrid smell it actually tastes quite good." << endl;
		cout << "Suddenly you feel a tingle run through your body and you feel as if you have gotten stronger somehow." << endl;
			maincharacter.powerup = true;
			cout << endl;
			cout << "==========================" << endl;
			cout << maincharacter.name <<" has powered up!!!" << endl;
			cout << "==========================" << endl;
			cout << endl;


	}
	else if (decision4 == 2) {
		cout << "You choose to not eat the slime. Slime motions a somewhat sad face as best it can. The knight feels." << endl;
		cout << "sorry for the creature and eats the slime off the floor. The knight feels completely find and even goes as" << endl;
		cout << "far to say that slime tasted delicious";
			knight.powerup = true;
			cout << endl;
			cout << "==========================" << endl;
			cout << knight.name <<" has powered up!!!" << endl;
			cout << "==========================" << endl;
			cout << endl;
	}
	else {
		cout << "That is not a valid entry. Please enter a valid entry";
			goto dec4;
	}

	cout << "Arriving in Seamont: After the trial and tribulations of a simple walk to Seamont you and your party" << endl;
	cout << "finally arrive. Something is strange though the city gates are open and there isn't much noise coming from" << endl;
	cout << "the city. The building and sprawling castle seen from outside of the city walls seem to be in perfect" << endl;
	cout << "condition. After examining the outside of the city you and your party head on in and see if they can find anyone in the city." << endl;
	// insert new code here
gameover:

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
	
	return 0;
}