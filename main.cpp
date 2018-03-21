#include <iostream> 
#include "View.h"
using namespace std;

int main() {
	
	Player player = IntroductionPhase();
	
	BattlePhase(1,player);
}
