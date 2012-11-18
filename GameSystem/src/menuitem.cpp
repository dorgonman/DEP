
#include "depGUI.h"
#include "GlobalVariable.h"
#include "DEPSprite.h"

// This is a GUI control constructor,
// we should initialize all the variables here
hgeGUIMenuItem::hgeGUIMenuItem(int _id, Font *_fnt, string sndPath, float x, float y, float _delay, wchar_t *_title){
	float w;
	float h;
	id=_id;
	fnt=_fnt;
	snd= sndPath;
	delay=_delay;
	title=_title;


	color.SetHWColor(0xFF8800BB);
	shadow.SetHWColor(0x30000000);
	offset=0.0f;
	timer=-1.0f;
	timer2=-1.0f;

	bStatic=false;
	bVisible=true;
	bEnabled=true;



	spr = new hgeSprite(g_rm->GetTexture(".\\Picture\\job\\yumemiShootType01.png"), 0, 0, 45, 45);
	spr->SetHotSpot(45 / 2, 45 / 2);


	w = fnt->getStringWidth(title);
	h = fnt->getStringHeight(title);
	rect.Set(x - w / 2, y - h ,  x + w / 2 , y + h );
}

// This method is called when the control should be rendered
void hgeGUIMenuItem::Render()
{
	fnt->setColor(shadow.GetHWColor());
	fnt->drawString( title, rect.x1+offset+3, rect.y1+3);
	fnt->setColor(color.GetHWColor());
	fnt->drawString(title, rect.x1-offset, rect.y1-offset);
	hge->Random_Seed();
	if(gui->GetFocus() == id){
		spr->RenderEx(rect.x1, rect.y1, hge->Random_Float(0, 100), 0.5, 0.5);
	}

	
}

// This method is called each frame,
// we should update the animation here
void hgeGUIMenuItem::Update(float dt)
{
	if(timer2 != -1.0f)
	{
		timer2+=dt;
		if(timer2 >= delay+0.1f)
		{
			color=scolor2+dcolor2;
			shadow=sshadow+dshadow;
			offset=0.0f;
			timer2=-1.0f;
		}
		else
		{
			if(timer2 < delay) { color=scolor2; shadow=sshadow; }
			else { color=scolor2+dcolor2*(timer2-delay)*10; shadow=sshadow+dshadow*(timer2-delay)*10; }
		}
	}
	else if(timer != -1.0f)
	{
		timer+=dt;
		if(timer >= 0.2f)
		{
			color=scolor+dcolor;
			offset=soffset+doffset;
			timer=-1.0f;
		}
		else
		{
			color=scolor+dcolor*timer*5;
			offset=soffset+doffset*timer*5;
		}
	}
}

// This method is called when the GUI
// is about to appear on the screen
void hgeGUIMenuItem::Enter()
{
	hgeColor tcolor2;

	scolor2.SetHWColor(0x008800BB);
	tcolor2.SetHWColor(0xFF8800BB);
	dcolor2=tcolor2-scolor2;

	sshadow.SetHWColor(0x00000000);
	tcolor2.SetHWColor(0x30000000);
	dshadow=tcolor2-sshadow;

	timer2=0.0f;
}

// This method is called when the GUI
// is about to disappear from the screen
void hgeGUIMenuItem::Leave()
{
	hgeColor tcolor2;

	scolor2.SetHWColor(0xFF8800BB);
	tcolor2.SetHWColor(0x008800BB);
	dcolor2=tcolor2-scolor2;

	sshadow.SetHWColor(0x30000000);
	tcolor2.SetHWColor(0x00000000);
	dshadow=tcolor2-sshadow;

	timer2=0.0f;
}

// This method is called to test whether the control
// have finished it's Enter/Leave animation
bool hgeGUIMenuItem::IsDone()
{
	if(timer2==-1.0f) return true;
	else return false;
}

// This method is called when the control
// receives or loses keyboard input focus
void hgeGUIMenuItem::Focus(bool bFocused)
{
	hgeColor tcolor;

	if(bFocused)
	{
		DEPSound::getInstance()->setSoundEffect(snd);
		DEPSound::getInstance()->playSoundEffect();
	

		scolor.SetHWColor(0xFF8800BB);
		tcolor.SetHWColor(0xFF9966FF);//
		soffset=0;
		doffset=4;
		
	}
	else
	{
		scolor.SetHWColor(0xFF9966FF);//
		tcolor.SetHWColor(0xFF8800BB);
		soffset=4;
		doffset=-4;
	}

	dcolor=tcolor-scolor;
	timer=0.0f;
}

// This method is called to notify the control
// that the mouse cursor has entered or left it's area
void hgeGUIMenuItem::MouseOver(bool bOver)
{
	if(bOver) gui->SetFocus(id);
}

// This method is called to notify the control
// that the left mouse button state has changed.
// If it returns true - the caller will receive
// the control's ID
bool hgeGUIMenuItem::MouseLButton(bool bDown)
{
	if(!bDown)
	{
		offset=4;
		return true;
	}
	else 
	{
			
		DEPSound::getInstance()->setSoundEffect(".\\sounds\\decide2.wav");
		DEPSound::getInstance()->playSoundEffect();
		offset=0;
		return false;
	}
}

// This method is called to notify the
// control that a key has been clicked.
// If it returns true - the caller will
// receive the control's ID
bool hgeGUIMenuItem::KeyClick(int key, int chr)
{
	if(key==HGEK_ENTER || key==HGEK_SPACE)
	{
		MouseLButton(true);
		return MouseLButton(false);
	}

	return false;
}

void hgeGUIMenuItem::setTitle(wchar_t *_title){
	title = _title;
}