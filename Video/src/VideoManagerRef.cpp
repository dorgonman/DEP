//#include "VideoManager.h"

//#define WM_GRAPHNOTIFY  WM_APP + 1
/*�ϥ΃��N����l�ơA�M�Z����
�A�̦Z�\��C�i�H�ϥ�IsPlaying()
�P�ʅS���O�_���b����A�Y�O�h�������L�[��F
���O������_�N�O�Y���b����S�����x�C���n��B�q���A
�h�ѨυS�������������]�d�F�@��S�S��ڼ���S�����O���ॴ�ʪ��A
�ҥH�i�H�bm_pMediaControl->Run()�Z�[�Wm_pEvent->WaitForCompletion�S�F�������A
����S���C���C*/
/*
#include "VideoManager.h"
#include <shlwapi.h> 
#pragma comment(lib, "shlwapi.lib.")
#define WM_GRAPHNOTIFY  WM_APP + 1

VideoManager::VideoManager(){ 
	const int nBufSize = 512;
    wchar_t chBuf[nBufSize];
    ZeroMemory(chBuf,nBufSize);
    GetModuleFileNameW(NULL,chBuf,nBufSize);
    LPWSTR lpStrPath = chBuf;
    PathRemoveFileSpecW(lpStrPath);
	SetCurrentDirectoryW(lpStrPath);
	m_bIsPlaying = false;
	m_phge = 0;
	m_pGraph = 0;
	m_pMediaControl = 0;
	m_pEvent = 0; 
	m_pVidWin = 0;
	m_bIsContinuePlay = false;
}

VideoManager::~VideoManager(){ 
}


bool VideoManager::init(){
   m_phge = hgeCreate(HGE_VERSION);
   m_hwnd = m_phge->System_GetState(HGE_HWND);   
   HRESULT hr = CoInitialize(NULL);
   if (FAILED(hr)){return false;}
   hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&m_pGraph);
   if (FAILED(hr)){return false;}
   hr = m_pGraph->QueryInterface(IID_IMediaControl, (void **)&m_pMediaControl);
   if (FAILED(hr)){return false;}
   hr = m_pGraph->QueryInterface(IID_IMediaEvent, (void **)&m_pEvent);
   if (FAILED(hr)){return false;}
   hr = m_pGraph->QueryInterface(IID_IVideoWindow, (void **)&m_pVidWin);
   if (FAILED(hr)){return false;}
   return true;
}

void VideoManager::playFile(WCHAR* filename){ 
	 m_pGraph->RenderFile(filename,NULL);
	 RECT rc;
	 GetClientRect(m_hwnd, &rc);
	 m_pVidWin->SetWindowPosition(0, 0, rc.right, rc.bottom);
	 m_pVidWin->put_Owner((OAHWND)m_hwnd); 
	 m_pVidWin->put_WindowStyle( WS_CHILD | WS_CLIPSIBLINGS);
	 play();
}


void VideoManager::play(){
 if(m_pMediaControl){
  m_pMediaControl->Run();
  m_bIsPlaying = true;  

  if(m_bIsContinuePlay){
   long evCode;
   m_pEvent->WaitForCompletion(INFINITE, &evCode);  //�F���������]��������L�����^
   m_bIsPlaying = false;
  }
 }
}



//�ܰ�
void VideoManager::pause()
{
 if(m_pMediaControl) m_pMediaControl->Pause();
}

//����
void VideoManager::stop()
{
 if(m_pMediaControl)
 {
  m_pMediaControl->Stop();
  m_pMediaControl->Release();
  m_bIsPlaying = false;
 }
    if(m_pEvent)  m_pEvent->Release();
    if(m_pGraph)  m_pGraph->Release();
	if(m_pVidWin) m_pVidWin->Release();

	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void **)&m_pGraph);

    m_pGraph->QueryInterface(IID_IVideoWindow, (void **)&m_pVidWin);  
    m_pGraph->QueryInterface(IID_IMediaEventEx, (void **)&m_pEvent);
    m_pEvent->SetNotifyWindow((OAHWND)m_hwnd, WM_GRAPHNOTIFY, 0);
  
    m_pGraph->QueryInterface(IID_IMediaControl, (void **)&m_pMediaControl);  
}

//�����z�z
bool VideoManager::handleEvent()
{
    long evCode, param1, param2;
    HRESULT hr;
    while (hr = m_pEvent->GetEvent(&evCode, &param1, &param2, 0), SUCCEEDED(hr))
    {
        hr = m_pEvent->FreeEventParams(evCode, param1, param2);
        if ((EC_COMPLETE == evCode) || (EC_USERABORT == evCode)){    
			 stop();    
            break;
        }
    }
 return false;
}
*/