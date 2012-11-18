#include <hge.h>
#include "DShow.h"


#ifndef DEP_VIDEO
#define DEP_VIDEO
class VideoManager{
public:
 VideoManager();
 ~VideoManager();

 bool init();     //ªì©l¤Æ
 void playFile( WCHAR* _fileName);  //¥[†^…S‰±
 void play();    //¼½©ñ
 bool isPlaying()const { return m_bIsPlaying;} //ÄÀ©ñ¥¿¦b¼½©ñ
 void release();  //Œ\©ñ†V·½
 void pause();   //‡Ü°±
 void stop();    //°±¤î 
 void setContinuePlay(bool value) { m_bIsContinuePlay=value; }
 bool handleEvent(); //°T®§³B²z
private:
 HGE*            m_phge;
 IGraphBuilder* m_pGraph;
 IMediaControl* m_pMediaControl;
 IMediaEventEx* m_pEvent;
 HWND            m_hwnd;
 IVideoWindow* m_pVidWin;
 WCHAR* fileName;
 bool  m_bIsPlaying; //¬O§_¦b¼½©ñ
 bool  m_bIsContinuePlay; //¬O§_«ùŒ¢¼½©ñ¡]¤£…}ŠÊ¡^
};
#endif