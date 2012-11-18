#include "BAR.h"


BAR::BAR(float _high, float _width, int color){
	int i;
	for(i = 0; i < 4 ; i ++){
		quad.v[i].col = color;
		quad.v[i].z = 0.5f;
	}
	quad.tex = 0;
	quad.blend = BLEND_DEFAULT;
	high = _high;
	width = _width;
	length = _width;
	hge = hgeCreate(HGE_VERSION);
	x = 0; y = 0;
}

BAR::~BAR(){
	hge->Release();
}


void BAR::Render(float _x, float _y){
	x = _x - (width / 2); 
	y = _y  - (high / 2);
	quad.v[0].x = x;		  quad.v[0].y = y;
	quad.v[1].x = x + length; quad.v[1].y = y;
	quad.v[2].x = x + length; quad.v[2].y = y + 5;
	quad.v[3].x = x ;		  quad.v[3].y = y + 5;
	hge->Gfx_RenderQuad(&quad);

}

void BAR::setLength(float _multiplier){

	length = width * _multiplier;
	if(_multiplier < 0){
		length = width;
	}


}