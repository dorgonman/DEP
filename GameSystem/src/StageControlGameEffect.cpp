#include "StageControl.h"
#include "DepControl.h"


class ScreenEffect{
public:
	ScreenEffect(bool _active, float _rot, float _vscale, float _wscale){
		setAttribute(_active, _rot, _vscale, _wscale);	
	};
	void setAttribute(bool _active, float _rot, float _vscale, float _wscale){
		active = _active;
		rot = _rot;
		vscale = _vscale;
		wscale = _wscale;
	};
	bool  active;
	float vscale;
	float wscale;
	float rot;
};


static ScreenEffect* shock = new ScreenEffect(false, 0, 0, 0); 
static ScreenEffect* renderEx = new ScreenEffect(false, 0, 0, 0); 
static bool brenderEx = false;
static float rot = 0;
static float vscale = 1;
static float wscale = 1;


void StageControl::shockView(bool b, float _v, float _w){
	shock->setAttribute(b, 0, _v, _w);
}





void StageControl::renderViewEx(bool b, float _rot, float _vscale, float _wscale){
	renderEx->setAttribute(b, _rot, _vscale, _wscale);
}


void StageControl::gameEffect(){
	float vx = DepControl::getInstance()->cameraViewX / 2;
	float vy = DepControl::getInstance()->cameraViewY / 2;
	if(shock->active){
		cameraView->Render(vx + g_hge->Random_Float(-shock->vscale, shock->vscale) , vy + g_hge->Random_Float(-shock->wscale, shock->wscale));
		return;
	}else{		
		cameraView->Render(vx , vy);
		return;
	}

	if(renderEx->active){
		cameraView->RenderEx(vx, vy, renderEx->rot, renderEx->vscale, renderEx->wscale);
	}else{
		cameraView->Render(vx , vy);
		return;
	}


}


void StageControl::snowEffectAt(float x, float y, int amount, float minGravity, float maxGravity){
	static hgeParticleSystem* par = new hgeParticleSystem(".\\ParticleSystem\\particle3.psi", 
									new hgeSprite(g_rm->GetTexture(".\\Picture\\job\\bullet10.png"), 
									                              0, 0, 45, 45));
	par->Fire();
	par->MoveTo(x, y, true);
	par->info.nEmission = amount;
	par->info.colColorStart = 0x55FFFFFF;
	par->info.colColorEnd = 0x55FFFFFF;
	par->info.fGravityMin = minGravity;
	par->info.fGravityMax = maxGravity;
	par->info.fParticleLifeMin = 10;
	par->info.fParticleLifeMax = 30;
	par->Update(g_hge->Timer_GetDelta());
	par->Render();

}