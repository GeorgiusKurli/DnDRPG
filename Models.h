#ifndef MODELS_H // header guard
#define MODELS_H

struct Skill
{
	float damage;
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
			
			if(tier == 2)
			{
				int enemyname = rand()%2;
				
				if(enemyname == 0)
				{
					this->name = "Tiger";
				}
				
				else if(enemyname == 1)
				{
					this->name = "Raptor";
				}
				
				this->tier = 2;
				this->level = rand()%9 + 11;
				this->maxhealth = level * (rand()%2 + 3);
				this->currenthealth = maxhealth;
				this->strength = level + rand()%3 + 1;
				this->speed = level + rand()%4 +1;
				this->defense = level + rand()%3;
				this->expdrop = level * 2 + rand()%10;
				this->golddrop = level + rand()%10 + 100;
			}
			
			else if(tier == -1)
			{
				this->name = "Garland";
				this->tier = -1;
				this->level = 999999;
				this->maxhealth = 100;
				this->currenthealth = maxhealth;
				this->strength = 50;
				this->speed = 1;
				this->defense = 1;
				this->expdrop = 100;
				this->golddrop = 500;
			}
			
			else if(tier == -2)
			{
				this->name = "Lahabrea";
				this->tier = -2;
				this->level = 99999;
				this->maxhealth = 400;
				this->currenthealth = maxhealth;
				this->strength = 18;
				this->speed = 1;
				this->defense = 60;
				this->expdrop = 200;
				this->golddrop = 1000;
			}
			
			else if(tier == -3)
			{
				this->name = "Geppetto";
				this->tier = -3;
				this->level = 999999;
				this->maxhealth = 500;
				this->currenthealth = maxhealth;
				this->strength = 70;
				this->speed = 1;
				this->defense = 30;
				this->expdrop = 500;
				this->golddrop = 100000;
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
			
			if(tier == 2)
			{
				
				int name = rand()%3;
				
				if(name == 0)
				{
					this->name = "Steel Scimitar";
				}
				
				else if(name == 1)
				{
					this->name = "Steel Broadsword";
				}
				
				else if(name == 3)
				{
					this->name = "Steel Rapier";
				}
				
				this->tier = tier;
				this->level = level;
				this->strength = level + rand()%5 + 3;
				this->value = level * 25 + strength * 50;
			}
			
			else if(tier == -1)
			{
				this->name = "Gut Render";
				this->tier = 999999;
				this->level = 999999;
				this->strength = 50;
				this->value = 999999;
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
			
			if(tier == 2)
			{
				this->name = name;
				this->tier = tier;
				this->level = level;
				this->strength = level + rand()%5 + 3;
				this->value = level * 25 + strength * 50;
			}
			
			else if(tier == -1)
			{
				this->name = "Gut Render";
				this->tier = 999999;
				this->level = 999999;
				this->strength = 50;
				this->value = 999999;
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
			cout << "Level: " << this->level << endl;
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
				this->defense = level + rand()%5 + 2;
				this->value = level * 25 + defense * 50 + speed * 75;
			}
			
			if(tier == 2)
			{
				
				int name = rand()%2;
				
				if(name == 0)
				{
					this->name = "Mithril Chainmail";
				}
				
				else if(name == 1)
				{
					this->name = "Steel Plating";
				}
				
				this->tier = tier;
				this->level = level;
				this->speed = level + rand()%3 + 3;
				this->defense = level + rand()%5 + 5;
				this->value = level * 25 + defense * 50 + speed * 75;
			}
			
			else if(tier == -1)
			{
				this->name = "Bastion of Hope";
				this->tier = 999999;
				this->level = 999999;
				this->speed = 50;
				this->defense = 50;
				this->value = 999999;
			}
		}
		
		Armor(int tier, int level, string name){
			if(tier == 1)
			{
				
				this->name = name;
				this->tier = tier;
				this->level = level;
				this->speed = level + rand()%3 + 1;
				this->defense = level + rand()%5 + 2;
				this->value = level * 25 + defense * 50 + speed * 75;
			}
			
			if(tier == 2)
			{
				
				int name = rand()%2;
				
				this->name = name;
				
				this->tier = tier;
				this->level = level;
				this->speed = level + rand()%3 + 3;
				this->defense = level + rand()%5 + 5;
				this->value = level * 25 + defense * 50 + speed * 75;
			}
			
			else if(tier == -1)
			{
				this->name = "Bastion of Hope";
				this->tier = 999999;
				this->level = 999999;
				this->speed = 50;
				this->defense = 50;
				this->value = 999999;
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
		int bosskillcount;
		Weapon playerweapon;
		Armor playerarmor;
		Skill skill_list[5];
		
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
			this->exp = 0;
			this->healthpotion = 5;
			this->manapotion = 3;
			this->gold = 300;
			this->bosskillcount = 0;
			
			Weapon tempweapon(1,1,"Beginner Sword");
			this->playerweapon = tempweapon;
			
			Armor temparmor(1,1,"Beginner Armor");
			this->playerarmor = temparmor;
			
			Skill temp;
			temp.damage = 99999;
			temp.manacost = 0;
			temp.name = "Strike";
			this->skill_list[0] = temp;
			
			temp.damage = 1.2;
			temp.manacost = 10;
			temp.name = "Power Strike";
			this->skill_list[1] = temp;
			this->skillamount = 2;
			

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
		
		int getBossKillCount()
		{
			return this->bosskillcount;
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
		
		void setBossKillCount(int amount)
		{
			this->bosskillcount = amount;
		}
		
		void setHealthPotion(int amount)
		{
			this->healthpotion = amount;
		}
		
		void setManaPotion(int amount)
		{
			this->manapotion = amount;
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
				cout << "Exp: " << this->exp << "/" << level * 5 + 5 << endl;
			}
			
			while((this->level >= 30) == false && (this->exp >= level * 5 + 5 ))
			{
				this->exp = this->exp - level*5+5;
				cout << this->name << " has levelled up!" << endl;
				this->level = this->level + 1;
				this->maxhealth += 5;
				this->currenthealth = maxhealth;
				this->currentmana = maxmana;
				
				tempstat = (1 + rand()%2);
				cout << "Strength increased by = " << tempstat << endl;
				this->strength += tempstat;
				
				cout << "Speed increased by = " << tempstat << endl;
				tempstat = (1 + rand()%2);
				this->speed += tempstat;
				
				cout << "Defense increased by = " << tempstat << endl;
				tempstat = (1 + rand()%2);
				this->defense += tempstat;
				
				if(this->level == 10)
				{
					Skill tempskill;
					tempskill.damage = 2;
					tempskill.manacost = 25;
					tempskill.name = "Fatal Stab";
					this->skill_list[skillamount] = tempskill;
					this->skillamount += 1;
				}
					
				if(this->level == 25)
				{
					Skill tempskill;
					tempskill.damage = 3.5;
					tempskill.manacost = 35;
					tempskill.name = "Flare Blade";
					this->skill_list[skillamount] = tempskill;
					this->skillamount += 1;
					
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
				heal = this->maxhealth * 0.25;
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
				heal = this->maxmana * 0.5;
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
