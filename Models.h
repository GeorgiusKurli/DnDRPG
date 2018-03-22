#ifndef MODELS_H // header guard
#define MODELS_H

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
		int maxhealth;
		int currenthealth;
		int strength;
		int speed;
		int defense;
		int expdrop;
		int golddrop;
	
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
				this->maxhealth = level * (rand()%2 + 3);
				this->currenthealth = maxhealth;
				this->strength = level + rand()%3 + 1;
				this->speed = level + rand()%4 +1;
				this->defense = level + rand()%3;
				this->expdrop = level * 2 + rand()%10;
				this->golddrop = level + rand()%10 + 100;
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
		
		int getMaxHealth()
		{
			return this->maxhealth;
		}
		
		int getCurrentHealth()
		{
			return this->currenthealth;
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
		
		int getGoldDrop()
		{
			return this->golddrop;
		}
		
		int getExpDrop()
		{
			return this->expdrop;
		}
		
		void setCurrentHealth(int health)
		{
			this->currenthealth = health;
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
		
		Weapon(int tier,int level, string name){
			if(tier == 1)
			{
				
				this->name = name;
				this->tier = tier;
				this->level = level;
				this->strength = level + rand()%5;
				this->value = level * 25 + strength * 50;
			}
		}
		
		Weapon(){}
		
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
		
		void printStats()
		{
			cout << "Level" << this->level << endl;
			cout << "Strength: " << this->strength << endl;
			cout << "Value: " << this->value << endl;
		}
};

class Armor
{
	private:
		string name;
		int tier;
		int level;
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
		
		Armor(int tier, int level, string name){
			if(tier == 1)
			{
				
				this->name = name;
				this->tier = tier;
				this->level = level;
				this->speed = level + rand()%3 + 1;
				this->defense = level + rand()%5;
				this->value = level * 25 + defense * 50 + speed * 75;
			}
		}
		
		Armor(){
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
		
		void printStats()
		{
			cout << "Level: " << this->level << endl;
			cout << "Speed: " << this->speed << endl;
			cout << "Defense: " << this->defense << endl;
			cout << "Value: " << this->value << endl;
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
		int gold;
		int exp;
		int healthpotion;
		int manapotion;
		Weapon playerweapon;
		Armor playerarmor;
		Skill skill_list[10];
		
		int skillamount;
		
	public:
		Player(string name, int level,int health, int mana, int strength, int speed, int defense)
		{
			this->name = name;
			this->level = level;
			this->maxhealth = health;
			this->currenthealth = health;
			this->maxmana = 100;
			this->currentmana = maxmana;
			this->strength = strength;
			this->speed = speed;
			this->defense = defense;
			this->healthpotion = 5;
			this->manapotion = 3;
			this->gold = 300;
			
			Weapon tempweapon(1,1,"Beginner Sword");
			this->playerweapon = tempweapon;
			
			Armor temparmor(1,1,"Beginner Armor");
			this->playerarmor = temparmor;
			
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
		
		int getCombinedStrength()
		{
			return (this->strength + this->playerweapon.getStrength());
		}
		
		int getSpeed()
		{
			return this->speed;
		}
		
		int getCombinedSpeed()
		{
			return (this->speed + this->playerarmor.getSpeed());
		}
		
		int getDefense()
		{
			return this->defense;
		}
		
		int getCombinedDefense()
		{
			return (this->defense + this->playerarmor.getDefense());
		}
		
		int getGold()
		{
			return this->gold;
		}
		
		int getExp()
		{
			return this->exp;
		}
		
		int getHealthPotion()
		{
			return this->healthpotion;
		}
		
		int getManaPotion()
		{
			return this->manapotion;
		}
		
		Weapon getWeapon()
		{
			return this->playerweapon;
		}
		
		Armor getArmor()
		{
			return this->playerarmor;
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
			this->currentmana = mana;
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
		
		void setGold(int amount)
		{
			this->gold = amount;
		}
		
		void setExp(int amount)
		{
			this->exp = amount;
		}
		
		void setWeapon(Weapon tempweapon)
		{
			this->playerweapon = tempweapon;
		}
		
		void setArmor(Armor temparmor)
		{
			this->playerarmor = temparmor;
		}
		
		void checklevelUp()
		{
			int tempstat;
			if((this->level >= 30) == false)
			{
				if(this->exp >= level * 5 + 5)
				{
					cout << this->name << " has levelled up!" << endl;
					this->level = this->level + 1;
					this->maxhealth += 5;
					this->currenthealth = maxhealth;
					this->currentmana = maxmana;
					
					tempstat = (1 + rand()%2);
					cout << "Strength increased by = " << to_string(tempstat) << endl;
					this->strength += tempstat;
					
					cout << "Speed increased by = " << to_string(tempstat) << endl;
					tempstat = (1 + rand()%2);
					this->speed += tempstat;
					
					cout << "Defense increased by = " << to_string(tempstat) << endl;
					tempstat = (1 + rand()%2);
					this->defense += tempstat;
						
				}	
			}
		}
		
		bool useHealthPotion()
		{
			bool temp;
			int heal;
			
			if(this->healthpotion <= 0)
			{
				temp = false;
			}
			
			else
			{
				this->healthpotion -= 1;
				heal = this->currenthealth + this->maxhealth * 0.25;
				if(this->maxhealth < this->currenthealth + heal)
				{
					heal = this->maxhealth - this->currenthealth;
				}
				cout << this->name << " healed for " << heal << " health." << endl;
				this->currenthealth += heal;
				temp = true;
			}
			return temp;
		}
		
		bool useManaPotion()
		{
			bool temp;
			int heal;
			
			if(this->manapotion <= 0)
			{
				temp = false;
			}
			
			else
			{
				this->manapotion -= 1;
				heal = this->currentmana + this->maxmana * 0.25;
				if(this->maxmana < this->currentmana + heal)
				{
					heal = this->maxmana - this->currentmana;
				}
				cout << this->name << " restored " << heal << " mana." << endl;
				this->currentmana += heal;
				temp = true;
			}
			return temp;
		}
		
};
#endif
