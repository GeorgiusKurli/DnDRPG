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
	if(input.length()<0){
		name = "Noctis";
		cout << "Not much into names are we? Well then, I will call you Noctis.";
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
	cout << "A " + enemy.getName() + " appeared! ";
	cout << "Level: " + enemy.getLevel() << endl;
	bool battleflag = true;
	string input;
	bool chooseoption = true;
	bool tempbool;
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
					cout << "You have " + to_string(player.getHealthPotion()) + " health potion and " + to_string(player.getManaPotion()) + "mana potion." << endl;
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
		
		if(player.getSpeed() > enemy.getSpeed())
		{
			cout << player.getName() + " uses " + tempskill.name << endl;
			if(tempskill.name != "Potion")
			{
				player.setCurrentMana(player.getCurrentMana() - tempskill.manacost);
				damage = tempskill.damage * player.getStrength() - enemy.getDefense()/3;
				cout << player.getName() + " deals " + to_string(damage) + " damage.";
				enemy.setCurrentHealth(enemy.getCurrentHealth() - damage);
				
			}
			
			if(enemy.getCurrentHealth() > 0)
			{
				damage =  enemy.getStrength() - player.getDefense()/3;
				cout << enemy.getName() + " deals " + to_string(damage) + " damage.";
				player.setCurrentHealth(player.getCurrentHealth() - damage);
			}
			
		}
		
		else if(player.getSpeed() < enemy.getSpeed())
		{
			damage =  enemy.getStrength() - player.getDefense()/3;
			cout << enemy.getName() + " deals " + to_string(damage) + " damage.";
			player.setCurrentHealth(player.getCurrentHealth() - damage);
			
			if(player.getCurrentHealth() > 0)
			{
				cout << player.getName() + " uses " + tempskill.name << endl;
				if(tempskill.name != "Potion")
				{
					player.setCurrentMana(player.getCurrentMana() - tempskill.manacost);
					damage = tempskill.damage * player.getStrength() - enemy.getDefense()/3;
					cout << player.getName() + " deals " + to_string(damage) + " damage.";
					enemy.setCurrentHealth(enemy.getCurrentHealth() - damage);
					
				}
			}
			
		}
		
		if(enemy.getCurrentHealth() <= 0)
		{
			cout << enemy.getName() + " has been slain!" << endl;
			battleflag = false;
			
			cout << "You get " + to_string(enemy.getGoldDrop()) + " gold and " + to_string(enemy.getExpDrop()) + " exp.";
	
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
			cout << player.getName() + " died" << endl;
			battleflag = false;
		}
		
	}
	
	
	
	
}
