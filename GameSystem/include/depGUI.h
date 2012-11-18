/*
** Haaf's Game Engine 1.7
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** Tutorial 06 - Creating menus
*/

// In menuitem.cpp/h we define the
// behaviour of our custom GUI control

#ifndef DEP_GUI
#define DEP_GUI
#include "hge.h"
#include "hgegui.h"
#include "Font.h"
#include "hgecolor.h"
#include "hgeguictrls.h"
#include  "hgeresource.h"
#include "DEPSound.h"
using namespace hgeTTF;


class hgeGUIMenuItem : public hgeGUIObject
{
public:
	hgeGUIMenuItem(int id, Font *fnt, string sndPath, float x, float y, float delay, wchar_t *title);

	virtual void	Render();
	virtual void	Update(float dt);

	virtual void	Enter();
	virtual void	Leave();
	virtual bool	IsDone();
	virtual void	Focus(bool bFocused);
	virtual void	MouseOver(bool bOver);

	virtual bool	MouseLButton(bool bDown);
	virtual bool	KeyClick(int key, int chr);
	virtual void    setTitle(wchar_t *_title);
	virtual void    setID(int _id){id = _id;};

private:
	Font		*fnt;
	string		snd;
	float		delay;
	wchar_t		*title;
	hgeColor	scolor, dcolor, scolor2, dcolor2, sshadow, dshadow;
	hgeColor	color, shadow;
	float		soffset, doffset, offset;
	float		timer, timer2;
	hgeSprite*  spr;//Ωb¿Y
};



#endif