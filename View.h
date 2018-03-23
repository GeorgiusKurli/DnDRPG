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
			cout << player.getName() << "'s Health: " << player.getCurrentHealth() << "/" << player.getMaxHealth() << endl;
			cout << player.getName() << "'s mana: " << player.getCurrentMana() << "/" << player.getMaxMana() << endl;
			cout << enemy.getName() << "'s Health: " << enemy.getCurrentHealth() << "/" << enemy.getMaxHealth() << endl;
			
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
					tempbool = false;
					cout << "You have " << to_string(player.getHealthPotion()) << " health potion and " << to_string(player.getManaPotion()) << "mana potion." << endl;
					cout << "1.Health Potion 2. Mana Potion 3. Back" << endl;
					cin >> input;
					
					if(stoi(input) == 1)
					{
						tempbool = player.useHealthPotion();
						if(tempbool == true)
						{
							tempskill.damage = 0;
							tempskill.name = " Heath Potion";
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
							tempskill.name = " Mana Potion";
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
			if(player.getCombinedSpeed() > enemy.getSpeed())
			{
				cout << player.getName() << " uses " + tempskill.name << endl;
				if(tempskill.name != "Potion")
				{
					player.setCurrentMana(player.getCurrentMana() - tempskill.manacost);
					damage = tempskill.damage *  player.getCombinedStrength() - enemy.getDefense()/3;
					if(damage < 0)
					{
						damage = 0;
					}
					cout << player.getName() << " deals " + to_string(damage) << " damage." << endl;
					enemy.setCurrentHealth(enemy.getCurrentHealth() - damage);
					
				}
				
				if(enemy.getCurrentHealth() > 0)
				{
					damage =  enemy.getStrength() - player.getCombinedDefense()/3;
					if(damage < 0)
					{
						damage = 0;
					}
					cout << enemy.getName() << " deals " + to_string(damage) << " damage." << endl;
					player.setCurrentHealth(player.getCurrentHealth() - damage);
				}
				
			}
			
			else if(player.getCombinedSpeed() < enemy.getSpeed())
			{
				damage =  enemy.getStrength() - player.getCombinedDefense()/3;
				if(damage < 0)
				{
					damage = 0;
				}
				cout << enemy.getName() << " deals " << damage << " damage." << endl;
				player.setCurrentHealth(player.getCurrentHealth() - damage);
				
				if(player.getCurrentHealth() > 0)
				{
					cout << player.getName() << " uses " << tempskill.name << endl;
					if(tempskill.name != "Potion")
					{
						player.setCurrentMana(player.getCurrentMana() - tempskill.manacost);
						damage = tempskill.damage *  player.getCombinedStrength() - enemy.getDefense()/3;
						if(damage < 0)
						{
							damage = 0;
						}
						cout << player.getName() << " deals " << damage << " damage." << endl;
						enemy.setCurrentHealth(enemy.getCurrentHealth() - damage);
						
					}
				}
				
			}
			
			if(enemy.getCurrentHealth() <= 0)
			{
				cout << enemy.getName() << " has been slain!" << endl;
				battleflag = false;
				
				cout << "You get " << to_string(enemy.getGoldDrop()) << " gold and " << to_string(enemy.getExpDrop()) << " exp." << endl;
				player.setGold(player.getGold() + enemy.getGoldDrop());
				player.setExp(player.getExp() + enemy.getExpDrop());
				player.checklevelUp();
				
				randint = rand()%100+1;
				
				if(randint > 40)
				{
					randint = rand()%2;
					if(randint == 0)
					{
						Weapon tempweapon(enemy.getTier(),enemy.getLevel());
						cout << player.getName() << " found " << tempweapon.getName() << endl;
						tempweapon.printStats();
						cout << "Do you want to replace your current weapon?(y/n)" << endl;
						cout << "Current Weapon: " << player.getWeapon().getName() << endl;
						player.getWeapon().printStats();
						
						cin >> input;
						if(input == "y")
						{
							player.setWeapon(tempweapon);
						}
						
					}
					
					else
					{
						Armor temparmor(enemy.getTier(),enemy.getLevel());
						cout << player.getName() << " found " << temparmor.getName() << endl;
						temparmor.printStats();
						cout << "Do you want to replace your current armor?(y/n)" << endl;
						cout << "Current Armor: " << player.getArmor().getName() << endl;
						player.getArmor().printStats();
						
						cin >> input;
						if(input == "y")
						{
							player.setArmor(temparmor);
						}
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

void dungeon(int tier, Player player){
	bool running = true;
	int choice;
	while(running){
		int chance = rand()%10+1;
		cout << "What do you want to do?" << endl;
		cout << "1. Battle\n2. Camp\n3. Back to city" << endl;
		cin >> choice;
		switch(choice){
			case 1:
				BattlePhase(tier,player);
				break;
			case 2:
				cout << "Resting...." << endl;
				if(chance <= 2){
					BattlePhase(tier, player);
				}
				else{
					player.setCurrentHealth(player.getMaxHealth());
				}
				break;
			case 3:
				running = false;
				break;
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

void shop(Player player){
	bool running = true;
	int choice;
	cout << "Welcome to Adventurer's shop!'" << endl;
	while(running){
		cout << "What do you wanna do?" << endl;
		cout << "1. Buy\n2. Back to city" << endl;
		cin >> choice;
		if(choice == 1){
			bool buying = true;
			int choice1;
			while(buying){
				cout << "What do you wanna buy?" << endl;
				cout << "1. Armor\n2. Weapon\n3. Back" << endl;
				cin >> choice1;
				if(choice1 == 1){
					bool looping1 = true;
					int armor;
					char decision;
					Armor armor1(1,player.getLevel(),"Blackwing Coat");
					Armor armor2(1,player.getLevel(),"Rosarium Vest");
					Armor armor3(1,player.getLevel(),"Imperial Breastplate");
					while(looping1){
						cout << "Which armor do you wanna buy?" << endl;
						cout << "1. " << armor1.getName() << endl;
						armor1.printStats();
						cout << "2. " << armor2.getName() << endl;
						armor2.printStats();
						cout << "3. " << armor3.getName() << endl;
						armor3.printStats();
						cout << "4. Back" << endl;
						cin >> armor;
						if(armor == 1){
							cout << "Are you sure you want to buy this?" << endl;
							cin >> decision;
							if(decision == 'y' || decision == 'Y'){
								if(player.getGold() >= 50){
									cout << "Thank you for your purchase!" << endl;
									player.setGold(player.getGold() - 50);
									player.setArmor(armor1);
								}
								else{
									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
								}
							}
						}
						else if(armor == 2){
							cout << "Are you sure you want to buy this?" << endl;
							cin >> decision;
							if(decision == 'y' || decision == 'Y'){
								if(player.getGold() >= 50){
									cout << "Thank you for your purchase!" << endl;
									player.setGold(player.getGold() - 50);
									player.setArmor(armor2);
								}
								else{
									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
								}
							}
						}
						else if(armor == 3){
							cout << "Are you sure you want to buy this?" << endl;
							cin >> decision;
							if(decision == 'y' || decision == 'Y'){
								if(player.getGold() >= 50){
									cout << "Thank you for your purchase!" << endl;
									player.setGold(player.getGold() - 50);
									player.setArmor(armor3);
								}
								else{
									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
								}
							}
						}
						else if(armor == 4){
							looping1 = false;
						}
					}
				}
				else if(choice1 == 2){
					bool looping2 = true;
					int weapon;
					char decision;
					Weapon weapon1(1,player.getLevel(),"Elucidator");
					Weapon weapon2(1,player.getLevel(),"Dark Repulser");
					Weapon weapon3(1,player.getLevel(),"Excalibur");
					while(looping2){
						cout << "Which weapon do you wanna buy?" << endl;
						cout << "1. " << weapon1.getName() << endl;
						weapon1.printStats();
						cout << "2. " << weapon2.getName() << endl;
						weapon2.printStats();
						cout << "3. " << weapon3.getName() << endl;
						weapon3.printStats();
						cout << "4. Back" << endl;
						cin >> weapon;
						if(weapon == 1){
							cout << "Are you sure you want to buy this?" << endl;
							cin >> decision;
							if(decision == 'y' || decision == 'Y'){
								if(player.getGold() >= 50){
									cout << "Thank you for your purchase!" << endl;
									player.setGold(player.getGold() - 50);
									player.setWeapon(weapon1);
								}
								else{
									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
								}
							}
						}
						else if(weapon == 2){
							cout << "Are you sure you want to buy this?" << endl;
							cin >> decision;
							if(decision == 'y' || decision == 'Y'){
								if(player.getGold() >= 50){
									cout << "Thank you for your purchase!" << endl;
									player.setGold(player.getGold() - 50);
									player.setWeapon(weapon2);
								}
								else{
									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
								}
							}
						}
						else if(weapon == 3){
							cout << "Are you sure you want to buy this?" << endl;
							cin >> decision;
							if(decision == 'y' || decision == 'Y'){
								if(player.getGold() >= 50){
									cout << "Thank you for your purchase!" << endl;
									player.setGold(player.getGold() - 50);
									player.setWeapon(weapon3);
								}
								else{
									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
								}
							}
						}
						else if(weapon == 4){
							looping2 = false;
						}
					}
				}
				else if(choice1 == 3){
					buying = false;
				}
			}
		}
//		else if(choice == 2){
//			bool upgrading = true;
//			int choice2;
//			while(upgrading){
//				cout << "What do you wanna upgrade?" << endl;
//				cout << "1. Armor\n2. Weapon\n3. Back" << endl;
//				cin >> choice2;
//				if(choice2 == 1){
//					bool looping1 = true;
//					int armor;
//					char decision;
//					while(looping1){
//						cout << "Which armor do you wanna buy?" << endl;
//						cin >> armor;
//						if(armor == 1){
//							cout << "Are you sure you want to buy this?" << endl;
//							cin >> decision;
//							if(decision == 'y' || decision == 'Y'){
//								if(player.getGold() >= 50){
//									cout << "Thank you for your purchase!" << endl;
//									player.setGold(player.getGold() - 50);
//									player.setArmor(armor1);
//								}
//								else{
//									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
//								}
//							}
//						}
//						else if(armor == 2){
//							cout << "Are you sure you want to buy this?" << endl;
//							cin >> decision;
//							if(decision == 'y' || decision == 'Y'){
//								if(player.getGold() >= 50){
//									cout << "Thank you for your purchase!" << endl;
//									player.setGold(player.getGold() - 50);
//									player.setArmor(armor2);
//								}
//								else{
//									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
//								}
//							}
//						}
//						else if(armor == 3){
//							cout << "Are you sure you want to buy this?" << endl;
//							cin >> decision;
//							if(decision == 'y' || decision == 'Y'){
//								if(player.getGold() >= 50){
//									cout << "Thank you for your purchase!" << endl;
//									player.setGold(player.getGold() - 50);
//									player.setArmor(armor3);
//								}
//								else{
//									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
//								}
//							}
//						}
//						else if(armor == 4){
//							looping1 = false;
//						}
//					}
//				}
//				else if(choice1 == 2){
//					bool looping2 = true;
//					int weapon;
//					char decision;
//					Weapon weapon1(1,player.getLevel(),"Elucidator");
//					Weapon weapon2(1,player.getLevel(),"Dark Repulser");
//					Weapon weapon3(1,player.getLevel(),"Excalibur");
//					while(looping2){
//						cout << "Which weapon do you wanna buy?" << endl;
//						cout << "1. " << weapon1.getName() << endl;
//						weapon1.printStats();
//						cout << "2. " << weapon2.getName() << endl;
//						weapon2.printStats();
//						cout << "3. " << weapon3.getName() << endl;
//						weapon3.printStats();
//						cout << "4. Back" << endl;
//						cin >> weapon;
//						if(weapon == 1){
//							cout << "Are you sure you want to buy this?" << endl;
//							cin >> decision;
//							if(decision == 'y' || decision == 'Y'){
//								if(player.getGold() >= 50){
//									cout << "Thank you for your purchase!" << endl;
//									player.setGold(player.getGold() - 50);
//									player.setWeapon(weapon1);
//								}
//								else{
//									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
//								}
//							}
//						}
//						else if(weapon == 2){
//							cout << "Are you sure you want to buy this?" << endl;
//							cin >> decision;
//							if(decision == 'y' || decision == 'Y'){
//								if(player.getGold() >= 50){
//									cout << "Thank you for your purchase!" << endl;
//									player.setGold(player.getGold() - 50);
//									player.setWeapon(weapon2);
//								}
//								else{
//									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
//								}
//							}
//						}
//						else if(weapon == 3){
//							cout << "Are you sure you want to buy this?" << endl;
//							cin >> decision;
//							if(decision == 'y' || decision == 'Y'){
//								if(player.getGold() >= 50){
//									cout << "Thank you for your purchase!" << endl;
//									player.setGold(player.getGold() - 50);
//									player.setWeapon(weapon3);
//								}
//								else{
//									cout << "Pardon us, but you don't have enough gold at the moment" << endl;
//								}
//							}
//						}
//						else if(weapon == 4){
//							looping2 = false;
//						}
//					}
//				}
//				else if(choice1 == 3){
//					upgrading = false;
//				}
//			}
//		}
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
					dungeon(dungeon_tier, player);
					looping = false;
				}
				else if(dungeon_tier == 2){
					cout << "Are you sure you wanna go? this dungeon is recommended for lvl. 10+" << endl;
					cout << "Y/N? ";
					cin >> choice1;
					if(choice1 == 'y' || choice1 == 'Y'){
						dungeon(dungeon_tier, player);
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
			shop(player);
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
