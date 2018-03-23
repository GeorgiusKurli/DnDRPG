#ifndef VIEW_H // header guard
#define VIEW_H
#include<iostream>
#include<windows.h>
#include<conio.h>
#include"Controller.h"
#include"Models.h"
using namespace std;

Player IntroductionPhase()
{
	string input,name;
	cout << "Welcome" << endl;
	Sleep(1000);
	cout << "Please tell us your name." << endl;
	cin >> input;
	if(input == "no" || input == "No"){
		name = "Pinocchio";
		cout << "Not much into names are we? Well then, I will call you Pinocchio." << endl;
	}
	else
	{
		name = input;
		cout << "Welcome to the world " + name << endl;
		Sleep(1000);
		cout << "Lets get started." << endl;
	}
	Player player(name,1,20,100,3,3, 3);
	return player;
}

void Story(Player player)
{
	cout << "Long time ago, in Markarth, there lived an alchemist named Geppetto." << endl;
	cout << "One of his best creations was a living puppet, named " << player.getName() << "." << endl;
	Sleep(1500);
	cout << "One day, " << player.getName() << " had this question which was bugging him." << endl;
	Sleep(1000);
	cout << "Why was he different from Geppetto?" << endl;
	Sleep(3000);
	cout << "He didn't want to be different; he wanted to be same as his Father." << endl;
	Sleep(1000);
	cout << "Geppetto said that he could change " << player.getName() << " into human but the condition was difficult." << endl;
	Sleep(1000);
	cout << player.getName() << " accepted it and began his journey." << endl;
}

void BeforeBattle(Player player)
{
	cout << player.getName() << " did his job. Geppetto asked him to hand over the Sword." << endl;
	Sleep(1000);
	cout << "He gave the Sword";
	Sleep(1500);
	cout << " and the moment he wanted to give the Armor," << endl;
	Sleep(1000);
	cout << "Geppetto attacked " << player.getName() << "!" << endl;
	Sleep(3500);
	cout << "Fortunately, the Armor reacted to it and saved " << player.getName() << "." << endl;
	Sleep(1000);
	cout << player.getName() << " was shocked and felt betrayed over the sudden attack from Geppetto." << endl;
	Sleep(1000);
	cout << "Why? Why would he do this?" << endl;
	Sleep(3000);
	cout << "It turned out " << player.getName() << " was only just a pawn for Geppetto in order to obtain The Legendary Items." << endl;
	cout << "Geppetto lied about turning into human in order to make it easier to manipulate him." << endl;
	Sleep(1000);
	cout << player.getName() << " was felt despair and sadness over the betrayal of his most beloved Father." << endl;
	cout << "But no matter what, he should fight back in order to survive." << endl;
}

void AfterBattle(int boss, Player player)
{
	if (boss == -1)
	{
		cout << player.getName() << " got Gut Render, Glory of Illuminated Dreams!" << endl;
		Sleep(1500);
		cout << "But is this necessary? To kill Garland?" << endl;
		Sleep(1500);
		cout << player.getName() << " decided to keep his own doubt." << endl;
	}
	if (boss == -2)
	{
		cout << player.getName() << " paused, thinking, should Pinocchio kill him?" << endl;
		Sleep(3000);
		cout << "Geppetto assured him because Lahabrea was keeping Bastion of Hope," << endl;
		Sleep(1000);
		cout << "a thing that will fulfill " << player.getName() << "'s purpose" << endl;
		Sleep(2000);
		cout << "There's no point on doubting yourself, Geppetto said." << endl;
	}
	if (boss == -3)
	{
		cout << "Even " << player.getName() << " won the fight, he felt inches away from death." << endl;
		Sleep(4000);
		cout << "There was a thing that " << player.getName() << " still didn't know..." << endl;
		Sleep(4000);
		cout << "Since he was Geppetto's puppet, Geppetto's creation..." << endl;
		Sleep(4000);
		cout << "Geppetto revealed that " << player.getName();
		Sleep(3000);
		cout << " had his life tied to him." << endl;
		Sleep(5000);
		cout << "\nIn the end, " << player.getName() << " died along with Geppetto." << endl;
	}
}

void BattlePhase(int tier, Player player)
{
	Monster enemy(tier);
	if(tier == -3)
	{
		BeforeBattle(player);
	}
	int randint;
	if(tier > 0)
	{
		cout << "A " << enemy.getName() << " appeared! " << endl;
	}
	
	else
	{
		cout << enemy.getName() << endl;
	}
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
	
	int counter = 0;
	
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
					cout << "You have " << to_string(player.getHealthPotion()) << " health potion and " << to_string(player.getManaPotion()) << " mana potion." << endl;
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
			
			if(counter == 0 && enemy.getTier() == -1 && player.getCurrentHealth() <= 0)
			{
				cout << player.getName() << " Resisted Death!" << endl;
				player.setCurrentHealth(1);
				counter += 1;
			}
			
			if(enemy.getCurrentHealth() <= 0)
			{
				cout << enemy.getName() << " has been killed." << endl;
				if(tier < 0)
				{
					AfterBattle(tier,player)
				}
				battleflag = false;
				
				cout << "You get " << to_string(enemy.getGoldDrop()) << " gold and " << to_string(enemy.getExpDrop()) << " exp." << endl;
				player.setGold(player.getGold() + enemy.getGoldDrop());
				player.setExp(player.getExp() + enemy.getExpDrop());
				player.checklevelUp();
				
				randint = rand()%100+1;
				
				if(enemy.getTier() == -1)
				{
					Weapon tempweapon(-1,999999,"Gut Render");
					player.setWeapon(tempweapon);
					cout << player.getName() << " found " << tempweapon.getName() << endl;
					tempweapon.printStats();
					randint = 0;
				}

				if(enemy.getTier() == -2)
				{
					Armor temparmor(-1,999999,"Bastion of Hope");
					player.setArmor(temparmor);
					cout << player.getName() << " found " << temparmor.getName() << endl;
					temparmor.printStats();
					randint = 0;
				}
				
				
				if(randint > 40)
				{
					if((player.getWeapon()).getName() == "Gut Render")
					{
						randint = 1;
					}
					
					else if((player.getArmor()).getName() == "Bastion of Hope")
					{
						randint = 2;
					}
					
					else
					{
						randint = rand()%2;
					}
					
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
					player.setCurrentMana(player.getMaxMana());
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
					player.setCurrentMana(player.getMaxMana());
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
				if(player.getWeapon().getName() == "Gut Render" && choice1 == 1)
				{
					cout << "You do not need to replace " << player.getWeapon().getName() << endl;
					choice1 = 3;
				}
				
				if(player.getArmor().getName() == "Bastion of Hope" && choice1 == 2)
				{
					cout << "You do not need to replace " << player.getArmor().getName() << endl;
					choice1 = 3;
				}
				
				if(choice1 == 1){
					bool looping1 = true;
					int armor;
					char decision;
					cout << "Your armor:" << endl;
					player.getArmor().printStats();
					cout << endl;
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
					cout << "Your weapon:" << endl;
					player.getWeapon().printStats();
					cout << endl;
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
