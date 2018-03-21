#include<iostream>
#include"Controller.cpp"
#include"Models.cpp"
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
		cout << "Welcome to the world " + name;
	}
	Player player(name,1,20,100,3,3, 3);
	return player;
}

void BattlePhase(int tier, Player player)
{
	Monster enemy(tier);
	int randint;
	cout << ("A " + enemy.getName() + " appeared!") << endl;
	bool battleflag = true;
	string input;
	bool chooseoption = true;
	Skill tempskill = (0,0,"Use potion");
	bool tempbool;
	string input;
	
	while (battleflag)
	{
		tempskill = NULL;
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
					
					if(stoi(input) != 0)
					{
						tempskill = player.getSkill(stoi(input));
						chooseoption = false;
					}
					break;
				}
				
				case 2:
				{
					cout << "1.Health Potion 2. Mana Potion 3. Back";
					cin >> input;
					
					if(stoi(input) == 1)
					{
						tempbool = player.useHealthPotion();
						if(tempbool == true)
						{
							chooseoption = false;
						}
						
					}
					
					if(stoi(input) == 2)
					{
						tempbool = player.useManaPotion();
						if(tempbool == true)
						{
							tempskill = (0,0,"Use potion");
							chooseoption = false;
						}
					}
					
					break;
				}
				
				case 3:
				{
					chooseoption = false;
					battleflag = false;
					break;
				}
				
				default:
				{
					cout << ("Please input [1..3]!") << endl;
					break;
				}
			}
		}
		
		
		
	}
}
