#include <string>
#include <cstdio>
#include "audiere.h"
#include <IOstream>
#include "windows.h"
#include <shlwapi.h> 
#include <map>
using namespace audiere;
using namespace std;


#ifndef DEP_SOUND
#define DEP_SOUND
class DEPSound{
public:
	DEPSound();
	~DEPSound(){
		if(streamSound != NULL){
			streamFree();
		}
		if(sound != NULL){
			soundFree();
		}
	};
	//the loading method will check whether the resource is already in the resource map that keep by the instance, if ture, then return it
	//, else then add the resource to the resource map.
	void setSoundEffect(string fileName, float volume = 100, float pan = 0.0f, float pitch = 1.0f);
	void setStream(string fileName, float volume = 100, float pan = 0.0f, float pitch = 1.0f, bool bloop = true, int position = 0);
	void playSoundEffect();
	void playStream();
	void stopStream();
	void streamFree();
	void soundFree();
	bool streamPlaying(){
		return streamSound->isPlaying();
	};
public:
	static DEPSound* getInstance();
private:
	static DEPSound* instance;
private:
	map<string, SoundEffectPtr> seResMap;
	map<string, OutputStreamPtr> streamResMap;
	AudioDevicePtr device;
	SoundEffectPtr sound;
	OutputStreamPtr streamSound;

};
#endif