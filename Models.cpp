#include<iostream>
using namespace std;

class Player
{
	private:
		string name;
		int level;
		int health;
		int mana;
		int strength;
		int speed;
		int defense;
		int exp;
		int potion;
		
	public:
		Player(string name, int level,int health, int mana, int strength, int speed, int defense)
		{
			this->name = name;
			this->level = level;
			this->health = health;
			this->mana = mana;
			this->strength = strength;
			this->speed = speed;
			this->defense = defense;

		}
		string getName()
		{
			return this->name;
		}
		
		int getLevel()
		{
			return this->level;
		}
		
		int getHealth()
		{
			return this->health;
		}
		
		int getMana()
		{
			return this->mana;
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
		
		void setLevel(int level)
		{
			this->level = level;
		}
		
		void setHealth(int health)
		{
			this->health = health;
		}
				
		void setMana()
		{
			this->mana = mana;
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
				this->expdrop = level + rand()%2 + 1;
				this->moneydrop = level + rand()%10 + 100;
			}
			
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
		
		Weapon(int tier){
			if(tier == 1)
			{
				this->tier = tier;
				this->level = rand()%9 + 1;
				this->strength = level + rand()%7;
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
		
		Armor(int tier){
			if(tier == 1)
			{
				this->tier = tier;
				this->level = rand()%9 + 1;
				this->speed = level + rand()%3 + 1;
				this->defense = level + rand()%7;
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
