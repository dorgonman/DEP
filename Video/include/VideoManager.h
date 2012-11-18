#include <hge.h>
#include "DShow.h"


#ifndef DEP_VIDEO
#define DEP_VIDEO
class VideoManager{
public:
 VideoManager();
 ~VideoManager();

 bool init();     //��l��
 void playFile( WCHAR* _fileName);  //�[�^�S��
 void play();    //����
 bool isPlaying()const { return m_bIsPlaying;} //���񥿦b����
 void release();  //�\��V��
 void pause();   //�ܰ�
 void stop();    //���� 
 void setContinuePlay(bool value) { m_bIsContinuePlay=value; }
 bool handleEvent(); //�T���B�z
private:
 HGE*            m_phge;
 IGraphBuilder* m_pGraph;
 IMediaControl* m_pMediaControl;
 IMediaEventEx* m_pEvent;
 HWND            m_hwnd;
 IVideoWindow* m_pVidWin;
 WCHAR* fileName;
 bool  m_bIsPlaying; //�O�_�b����
 bool  m_bIsContinuePlay; //�O�_��������]���}�ʡ^
};
#endif