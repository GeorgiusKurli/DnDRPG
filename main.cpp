#include<iostream>
#include"VIEW.H"
#include<ctime>
using namespace std;

int main() {
	srand ( time(NULL) );
	
	Player player = IntroductionPhase();
	Story(player);


	//battle testing bosses
//	for(int x = 0; x<10; x++)
//	{
//		player.setExp(1000);
//		player.checklevelUp();
//	}
//	BattlePhase(-1,player);
//	player.setCurrentHealth(player.getMaxHealth());
//	player.setCurrentMana(player.getCurrentMana());
//	player.setHealthPotion(100);
//	player.setManaPotion(100);
//	BattlePhase(-2,player);
//	for(int x = 0; x<20; x++)
//	{
//		player.setExp(1000);
//		player.checklevelUp();
//	}
//	BattlePhase(-3,player);

}
