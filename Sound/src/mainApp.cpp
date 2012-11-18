#include "DEPSound.h"

string filename = ".\\Footsteps.wav";



int main(void){
	DEPSound* sound = new DEPSound();
	sound->setSoundEffect(filename, 50);
	sound->playSoundEffect();
	getchar();
	sound->setSoundEffect(filename);
	sound->playSoundEffect();
	getchar();
	sound->setStream(".\\sounds\\khs_adjutant_mighty.mp3");
	sound->playStream();
	getchar();
	sound->setStream(".\\sounds\\khs_adjutant_mighty.mp3");
	sound->playStream();
	getchar();


	return 0;
}
