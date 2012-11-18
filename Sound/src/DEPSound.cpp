#include "DEPSound.h"
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "audiere.lib")
DEPSound* DEPSound::instance = NULL;

DEPSound* DEPSound::getInstance(){
	if(instance == NULL){
		instance = new DEPSound();
	}
	return instance;
}



DEPSound::DEPSound(){
	const int nBufSize = 512;
    wchar_t chBuf[nBufSize];
    ZeroMemory(chBuf,nBufSize);
    GetModuleFileNameW(NULL,chBuf,nBufSize);
    LPWSTR lpStrPath = chBuf;
    PathRemoveFileSpecW(lpStrPath);
	SetCurrentDirectoryW(lpStrPath);
	AudioDevicePtr tmpDevice(OpenDevice());
	device = tmpDevice;
	sound = NULL;
	streamSound = NULL;
}


void DEPSound::setSoundEffect(string fileName, float volume, float pan, float pitch){
	map<string,SoundEffectPtr>::iterator it = seResMap.find(fileName);

	if(it != seResMap.end()){//找不到則回傳end
		cout << "find in sound resource map, file path:" << it->first << endl;
		sound = it->second;
	}else{
		//cout << "load file to sound resource map:" << fileName << endl;
		SoundEffectPtr tmpSound(OpenSoundEffect(device, fileName.c_str(), MULTIPLE));
		if(tmpSound != NULL){
			printf("load file to sound resource map, file path:%s \n", fileName.c_str());
			seResMap.insert(make_pair(fileName, tmpSound));
		}else{
			cout << "can't load sound resource.(file not exsist?)" << endl;
		}
		sound = tmpSound;
	}
	if(sound !=NULL){
		sound->setVolume(volume / 100);
		sound->setPan(pan);
		sound->setPitchShift(pitch);
	}
}


void DEPSound::setStream(std::string fileName, float volume, float pan, float pitch, bool bloop, int position){
	map<string,OutputStreamPtr>::iterator it = streamResMap.find(fileName);
	if(it != streamResMap.end()){//找不到會回傳end，因此不是end則代表有找到
		cout << "find in stream resource map, file path:" << it->first << endl;
		streamSound = it->second;
	}else{
		OutputStreamPtr tmpSound(OpenSound(device, fileName.c_str(), true));
		if(tmpSound != NULL){
			cout << "load file to stream resource map, file path:" << fileName << endl;
			streamResMap.insert(make_pair(fileName, tmpSound));
		}else{
			cout << "can't load stream resource.(file not exsist?)" << endl;
		}
		streamSound = tmpSound;
	}
	if(streamSound != NULL){
		streamSound->setVolume(volume/100);
		streamSound->setPan(pan);
		streamSound->setPitchShift(pitch);
		streamSound->setPosition(position);
		streamSound->setRepeat(bloop);
	}



}

void DEPSound::playStream(){
	if(streamSound != NULL){
		streamSound->play();
	}
}


void DEPSound::playSoundEffect(){
	if(sound != NULL){
		sound->play();
	}

}

void DEPSound::streamFree(){
	if(streamSound != NULL){
		streamSound->stop();
		streamSound->unref();
	}
	streamResMap.clear();
}

void DEPSound::soundFree(){
	if(sound != NULL){
		sound->stop();
		sound->unref();
	}
	seResMap.clear();
}


void DEPSound::stopStream(){
	if(streamSound != NULL){
		streamSound->stop();
	}

}