#include <iostream>
using namespace std;

class Being {
public:
	string name;
	int HP;
	int MP;

};

class partymembers: public Being{

};

int main() {
	cout << "The story begins in the small fishing village near the coast of Nubera." << endl;
	cout << "You open you eyes and find yourself laying in a bed" << endl;
	cout << "In your daze, you seek to recall your name." << endl << "What is your name?" << endl;
	partymembers maincharacter;
	cin >> maincharacter.name;
	cout << "\"Ah thanks right, my name is " << maincharacter.name << "\"" << endl;
	cout << maincharacter.name << " awakens in a small cottage in a daze with no recollection of how they got there." << endl;
	cout << "Upon a quick glance around the room" << maincharacter.name << " realizes they are alone inside of what seems to be a cottage." << endl;

	decision1:
	cout << "What will you do?" << endl;
	cout << "1. Get up and leave the cottage." << endl;
	cout << "2.Take a closer look at your surroundings." << endl;
	int decision;
	cin >> decision;
	if (decision == 1) {
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
	if (decision2 == 2) {
		nearbycity:
		cout << "You decide to head on to the nearest city of Seamount in search of " << endl;
		cout << "answers for what is happening around you. On the way you discover a wagon that " << endl;
		cout << "has lost one of its wheels with someone crying for help inside." << endl;
		cout << "What will you do?" << endl;
		cout << "1. Go to the source of the crying." << endl;
		cout << "2. Continue on your way to the city" << endl;
		int decision2d1;
		cin >> decision2d1;
		if (decision2d1 == 1) {
			cout << "As you feel like it could be possible to abandon the cries for help you just can’t " << endl;
			cout << "bring yourselves to do it.You and the knight look inside of the wagon and see a small farm girl crying " << endl;
			cout << "for help inside. The Farm Girl joins your party.";
			partymembers farmgirl;
			cout << "You have seen this farm girl before.... what was her name?";
			cin >> farmgirl.name;
			cout << "Ah thats right, her name was " << farmgirl.name << ".";
		}
		else if (decision2d1 == 2) {
			cout << "You and the knight ignore the blatant and loud cries for help and choose to not lose anytime " << endl;
			cout << "on your endeavor to reach the city. Suddenly along the way you and the knight are ambushed by two " << endl;
			cout << "plant - like creatures that appear similar in appearance to a venus flytrap. The knight tries his hardest " << endl;
			cout << "to hold them off but fails and you as well fall prey to the plants. If only you had someone with you that knew " << endl;
			cout << "more about plants like a farmer.";
			goto gameover;
		}
		
	}
	else if (decision2 == 1) {
		partymembers knight;
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
		if (subdecide == 1) {
			goto nearbycity;
		}
		else if (subdecide == 2) {

		}
		else {
			cout << "That is not a valid entry, please enter a valid entry" << endl;
			goto subsubdecide;
		}
	}
	else {
		cout << "That is not a valid entry, please enter a valid entry" << endl;
		goto decision2;
	}
gameover:
	cout << "Game over.";
	return 0;
}