#include<iostream>
#include"VIEW.H"
#include<ctime>
using namespace std;

int main() {
	srand ( time(NULL) );
	
	Player player = IntroductionPhase();
	//city(player); 
	BattlePhase(1,player);

}
