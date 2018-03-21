#include<iostream>
using namespace std;

struct Skill
{
	int damage;
	int manacost;
	string name;
};

class Monster
{
	private:
		string name;
		int tier;
		int level;
		int health;
		int strength;
		int speed;
		int defense;
		int expdrop;
		int moneydrop;
	
	public:
		Monster(int tier){
			if(tier == 1)
			{
				int enemyname = rand()%2;
				
				if(enemyname == 0)
				{
					this->name = "Goblin";
				}
				
				else if(enemyname == 1)
				{
					this->name = "Slime";
				}
				
				this->tier = 1;
				this->level = rand()%9 + 1;
				this->health = level * rand()%3 + 20;
				this->strength = level + rand()%3 + 1;
				this->speed = level + rand()%4 +1;
				this->defense = level + rand()%3;
				this->expdrop = level * 2 + rand()%10;
				this->moneydrop = level + rand()%10 + 100;
			}
			
		}
		
		string getName()
		{
			return this->name;
		}
		
		int getTier()
		{
			return this->tier;
		}
		
		int getLevel()
		{
			return this->level;
		}
		
		int getHealth()
		{
			return this->health;
		}
		
		int getStrength()
		{
			return this->strength;
		}
		
		int getSpeed()
		{
			return this->speed;
		}
		
		int getDefense()
		{
			return this->defense;
		}
};

class Weapon
{
	private:
		string name;
		int tier;
		int level;
		int strength;
		int value;
	
	public:
		
		Weapon(int tier,int level){
			if(tier == 1)
			{
				
				int name = rand()%3;
				
				if(name == 0)
				{
					this->name = "Iron Scimitar";
				}
				
				else if(name == 1)
				{
					this->name = "Iron Broadsword";
				}
				
				else if(name == 3)
				{
					this->name = "Iron Rapier";
				}
				
				this->tier = tier;
				this->level = level;
				this->strength = level + rand()%5;
				this->value = level * 25 + strength * 50;
			}
		}
		
		string getName()
		{
			return this->name;
		}
		
		int getTier()
		{
			return this->tier;
		}
		
		int getLevel()
		{
			return this->level;
		}
		
		int getStrength()
		{
			return this->strength;
		}
		
		int getValue()
		{
			return this->value;
		}
};

class Armor
{
	private:
		string name;
		int tier;
		int level;
		int health;
		int speed;
		int defense;
		int value;
	
	public:
		
		Armor(int tier, int level){
			if(tier == 1)
			{
				
				int name = rand()%2;
				
				if(name == 0)
				{
					this->name = "Iron Chainmail";
				}
				
				else if(name == 1)
				{
					this->name = "Bronze Plating";
				}
				
				this->tier = tier;
				this->level = level;
				this->speed = level + rand()%3 + 1;
				this->defense = level + rand()%5;
				this->value = level * 25 + defense * 50 + speed * 75;
			}
		}
		
		string getName()
		{
			return this->name;
		}
		
		int getTier()
		{
			return this->tier;
		}
		
		int getLevel()
		{
			return this->level;
		}
		
		int getSpeed()
		{
			return this->speed;
		}
		
		int getDefense()
		{
			return this->defense;
		}
		
		int getValue()
		{
			return this->value;
		}
};

class Player
{
	private:
		string name;
		int level;
		int maxhealth;
		int currenthealth;
		int maxmana;
		int currentmana;
		int strength;
		int speed;
		int defense;
		int exp;
		int healthpotion;
		int manapotion;
		Skill skill_list[10];
		int skillamount;
		
	public:
		Player(string name, int level,int health, int mana, int strength, int speed, int defense)
		{
			this->name = name;
			this->level = level;
			this->maxhealth = health;
			this->currenthealth = health;
			this->currentmana = maxmana;
			this->strength = strength;
			this->speed = speed;
			this->defense = defense;
			this->healthpotion = 5;
			this->manapotion = 3;
			
			Skill temp;
			temp.damage = 1;
			temp.manacost = 0;
			temp.name = "Strike";
			this->skill_list[0] = temp;
			this->skillamount = 1;
			

		}
		string getName()
		{
			return this->name;
		}
		
		int getLevel()
		{
			return this->level;
		}
		
		int getMaxHealth()
		{
			return this->maxhealth;
		}
		
		int getCurrentHealth()
		{
			return this->currenthealth;
		}
		
		int getMaxMana()
		{
			return this->maxmana;
		}
		
		int getCurrentMana()
		{
			return this->currentmana;
		}
		
		int getStrength()
		{
			return this->strength;
		}
		
		int getSpeed()
		{
			return this->speed;
		}
		
		int getDefense()
		{
			return this->defense;
		}
		
		void printSkills()
		{
			for(int x = 0; x<skillamount;x++)
			{
				Skill temp = skill_list[x];
				cout << (to_string(x + 1) + ". " + temp.name + " Damage: " + to_string(temp.damage) + " Mana Cost: " + to_string(temp.manacost)) << endl;;
			}
		}
		
		Skill getSkill(int x)
		{
			return skill_list[x-1];
		}
		
		
		void setCurrentHealth(int health)
		{
			this->currenthealth = health;
		}
				
		void setCurrentMana(int mana)
		{
			this->currentmana = currentmana;
		}
		
		void setStrength(int strength)
		{
			
			this->strength = strength;
		}
		
		void setSpeed(int speed)
		{
			
			this->speed = speed;
		}
		
		void setDefense(int defense)
		{
			
			this->defense = defense;
		}
		
		void checklevelUp()
		{
			int tempstat;
			if((this->level >= 30) == false)
			{
				if(this->exp >= level * 5 + 5)
				{
					cout << (this->name + "has levelled up!") << endl;
					this->level = this->level + 1;
					this->maxhealth += 5;
					this->currenthealth = maxhealth;
					this->currentmana = maxmana;
					
					tempstat = (1 + rand()%2);
					cout << ("Strength increased by = " + to_string(tempstat)) << endl;
					this->strength += tempstat;
					
					cout << ("Speed increased by = " + to_string(tempstat)) << endl;
					tempstat = (1 + rand()%2);
					this->speed += tempstat;
					
					cout << "Defense increased by = " + to_string(tempstat) << endl;
					tempstat = (1 + rand()%2);
					this->defense += tempstat;
						
				}	
			}
		}
		
		bool useHealthPotion()
		{
			bool temp;
			
			if(this->healthpotion <= 0)
			{
				temp = false;
			}
			
			else
			{
				this->healthpotion -= 1;
				this->currenthealth + this->maxhealth * 0.25;
				if(this->currenthealth > this->maxhealth)
				{
					this->currenthealth = this->maxhealth;
				}
				temp = true;
			}
			return temp;
		}
		
		bool useManaPotion()
		{
			bool temp;
			
			if(this->manapotion <= 0)
			{
				temp = false;
			}
			
			else
			{
				this->manapotion -= 1;
				this->currentmana + this->maxmana * 0.25;
				if(this->currentmana > this->maxmana)
				{
					this->currentmana = this->maxmana;
				}
				temp = true;
			}
			return temp;
		}
		
};

