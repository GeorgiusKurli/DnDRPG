#ifndef VIEW_H // header guard
#define VIEW_H
#include<iostream>
#include"Controller.h"
#include"Models.h"
using namespace std;

Player IntroductionPhase()
{
	string input,name;
	cout << "Welcome" << endl;
	cout << "Please tell us your name." << endl;
	cin >> input;
	if(input == "no" || input == "No"){
		name = "Noctis";
		cout << "Not much into names are we? Well then, I will call you Noctis." << endl;
	}
	else
	{
		name = input;
		cout << "Welcome to the world " + name << endl;
		cout << "Lets get started." << endl;
	}
	Player player(name,1,20,100,3,3, 3);
	return player;
}


//need to include armor and weapon to dmg calculation!
void BattlePhase(int tier, Player player)
{
	Monster enemy(tier);
	int randint;
	cout << "A " << enemy.getName() << " appeared! " << endl;
	cout << "Level: " << enemy.getLevel() << endl;
	string input;
	
	//main flag
	bool battleflag = true;
	
	//flag for player choosing
	bool chooseoption = true;
	
	//flag for if player use potion successfully
	bool tempbool;
	
	//flag for if player flees
	bool exitflag = false;
	int damage;
	Skill tempskill;
	
	while (battleflag){
		
		chooseoption = true;
		while(chooseoption)
		{
			cout << ("1.Fight\n2.Potion\n3.Run") << endl;
			cin >> input;
			
			
			switch(stoi(input)){
				case 1:
				{
					cout << "0.Back" << endl;
					player.printSkills();
					cin >> input;
					
					if(stoi(input) != 0 && player.getCurrentMana() >= (player.getSkill(stoi(input)).manacost))
					{
						tempskill = player.getSkill(stoi(input));
						chooseoption = false;
					}
					break;
				}
				
				case 2:
				{
					cout << "You have " << to_string(player.getHealthPotion()) << " health potion and " << to_string(player.getManaPotion()) << "mana potion." << endl;
					cout << "1.Health Potion 2. Mana Potion 3. Back" << endl;
					cin >> input;
					
					if(stoi(input) == 1)
					{
						tempbool = player.useHealthPotion();
						if(tempbool == true)
						{
							tempskill.damage = 0;
							tempskill.name = "Potion";
							tempskill.manacost = 0;
							chooseoption = false;
						}
						
					}
					
					if(stoi(input) == 2)
					{
						tempbool = player.useManaPotion();
						if(tempbool == true)
						{
							tempskill.damage = 0;
							tempskill.name = "Potion";
							tempskill.manacost = 0;
							chooseoption = false;
						}
					}
					
					break;
				}
				
				case 3:
				{
					chooseoption = false;
					battleflag = false;
					exitflag = true;
					continue;
					break;
				}
				
				default:
				{
					cout << ("Please input [1..3]!") << endl;
					break;
				}
			}
		}
		if(exitflag != true)
		{
			if(player.getSpeed() > enemy.getSpeed())
			{
				cout << player.getName() << " uses " + tempskill.name << endl;
				if(tempskill.name != "Potion")
				{
					player.setCurrentMana(player.getCurrentMana() - tempskill.manacost);
					damage = tempskill.damage * player.getStrength() - enemy.getDefense()/3;
					cout << player.getName() << " deals " + to_string(damage) << " damage.";
					enemy.setCurrentHealth(enemy.getCurrentHealth() - damage);
					
				}
				
				if(enemy.getCurrentHealth() > 0)
				{
					damage =  enemy.getStrength() - player.getDefense()/3;
					cout << enemy.getName() << " deals " + to_string(damage) << " damage.";
					player.setCurrentHealth(player.getCurrentHealth() - damage);
				}
				
			}
			
			else if(player.getSpeed() < enemy.getSpeed())
			{
				damage =  enemy.getStrength() - player.getDefense()/3;
				cout << enemy.getName() << " deals " << to_string(damage) << " damage.";
				player.setCurrentHealth(player.getCurrentHealth() - damage);
				
				if(player.getCurrentHealth() > 0)
				{
					cout << player.getName() << " uses " << tempskill.name << endl;
					if(tempskill.name != "Potion")
					{
						player.setCurrentMana(player.getCurrentMana() - tempskill.manacost);
						damage = tempskill.damage * player.getStrength() - enemy.getDefense()/3;
						cout << player.getName() << " deals " << to_string(damage) << " damage.";
						enemy.setCurrentHealth(enemy.getCurrentHealth() - damage);
						
					}
				}
				
			}
			
			if(enemy.getCurrentHealth() <= 0)
			{
				cout << enemy.getName() << " has been slain!" << endl;
				battleflag = false;
				
				cout << "You get " << to_string(enemy.getGoldDrop()) << " gold and " << to_string(enemy.getExpDrop()) << " exp.";
		
				randint = rand()%100+1;
				
				if(randint > 40)
				{
					randint = rand()%2;
					if(randint == 0)
					{
						//get new weapon
					}
					else
					{
						//get new armor
					}
				}
			}
			
			else if(player.getCurrentHealth() <= 0)
			{
				cout << player.getName() << " died" << endl;
				battleflag = false;
			}
		}
		
	}	
}

void inn(Player player){
	bool running = true;
	int choice;
	char staying;
	int inn_cost = 10;
	cout << "Welcome to Low-Cost INN" << endl;
	while(running){
		cout << "What do you wanna do?" << endl;
		cout << "1. Stay\n2. Back to city" << endl;
		cin >> choice;
		if(choice == 1){
			cout << "Staying in here would cost 10 gold. Are you sure? Y/N" << endl;
			cin >> staying;
			if(staying == 'y' || staying == 'Y'){
				if(player.getGold() >= inn_cost){
					cout << "Thank you for your staying!" << endl;
					player.setGold(player.getGold() - inn_cost);
					player.setCurrentHealth(player.getMaxHealth());
				}
				else{
					cout << "Pardon us, but you don't have enough gold at the moment" << endl;
				}
			}
		}
		else if(choice == 2){
			cout << "Thank you for your patronage!" << endl;
			running = false;
		}
	}
}

void city(Player player){
	bool running = true;
	int choice;
	cout << "WELCOME TO JAPARI CITY!" << endl;
	while(running){
		cout << "Where do you wanna go to?" << endl;
		cout << "1. Dungeon\n2. Inn\n3. Adventurer's shop\n4. Castle\n5. Exit" << endl;
		cin >> choice;
		if(choice == 1){
			bool looping = true;
			int dungeon_tier;
			char choice1;
			while(looping){
				cout << "Which dungeon do you wanna go to?" << endl;
				cout << "1. Ainground\n2. Aincrad\n3. Back" << endl;
				cin >> dungeon_tier;
				if(dungeon_tier == 1){
					//dungeon(dungeon_tier, player);
					looping = false;
				}
				else if(dungeon_tier == 2){
					cout << "Are you sure you wanna go? this dungeon is recommended for lvl. 10+" << endl;
					cout << "Y/N? ";
					cin >> choice1;
					if(choice1 == 'y' || choice1 == 'Y'){
						//dungeon(dungeon_tier, player);
						looping = false;
					}
				}
				else if(dungeon_tier == 3){
					looping = false;
				}
			}
		}
		else if(choice == 2){
			inn(player);
		}
		else if(choice == 3){
			//shop(player);
		}
		else if(choice == 4){
			//castle(player);
		}
		else if(choice == 5){
			running = false;
		}
	}
}
#endif
