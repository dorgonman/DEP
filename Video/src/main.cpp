#include "hge.h"
#include <dshow.h> 
#include "iostream"
#include "VideoManager.h"
// Pointer to the HGE interface.
// Helper classes require this to work.




HGE* hge;
VideoManager* vm;
bool FrameFunc(){
	static float dt= 0;
	dt += hge->Timer_GetDelta();
	if(!vm->isPlaying()){
		vm->stop();
		//vm->playFile(L".\\test2.avi");
		dt = 0;
	}
	vm->handleEvent();

	if(hge->Input_KeyDown(HGEK_1)){
		vm->pause();
	}
	if(hge->Input_KeyDown(HGEK_2)){
		vm->play();
	}


	return false;
}


bool RenderFunc(){

	if(!vm->isPlaying()){
	// Render graphics
		hge->Gfx_BeginScene();
		hge->Gfx_Clear(0);

		hge->Gfx_EndScene();
	}
	return false;
}






int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	  vm = new VideoManager();
	//videoHello2();
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hge_tut03.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "HGE Tutorial 03 - Using helper classes");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(hge->System_Initiate()) {
		vm->init();
		vm->playFile(L".\\test.avi");
		//vm->pause();
		// Let's rock now!
		hge->System_Start();
	}

	// Clean up and shutdown
	vm->release();
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
/*
void videoHello(){
	IGraphBuilder *pGraph; 
	IMediaControl *pMediaControl; 
	IMediaEvent *pEvent; 
	CoInitialize(NULL); 

	// Create the filter graph manager and query for interfaces. CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, 	IID_IGraphBuilder, (void **)&pGraph); 
	pGraph->QueryInterface(IID_IMediaControl, (void **)&pMediaControl); 
	pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent); 

	// Build the graph. 
	pGraph->RenderFile(L"test.avi", NULL); 

	pMediaControl->Run(); // Run the graph. 
	long evCode;
	pEvent->WaitForCompletion(INFINITE, &evCode); // Wait for completion. 

	// Clean up. 
	pMediaControl->Release(); pEvent->Release(); pGraph->Release(); 

	CoUninitialize(); 
}*/


void videoHello2(){
	IGraphBuilder *pGraph = NULL;
    IMediaControl *pControl = NULL;
    IMediaEvent   *pEvent = NULL;

    // Initialize the COM library.
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr)){
        return;
    }

    // Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, 
                        IID_IGraphBuilder, (void **)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
        return;
    }

    hr = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);

    // Build the graph. IMPORTANT: Change this string to a file on your system.
    hr = pGraph->RenderFile(L".\\test.avi", NULL);
    if (SUCCEEDED(hr))
    {
        // Run the graph.
        hr = pControl->Run();
        if (SUCCEEDED(hr))
        {
            // Wait for completion.
            long evCode;
            pEvent->WaitForCompletion(INFINITE, &evCode);

            // Note: Do not use INFINITE in a real application, because it
            // can block indefinitely.
        }
    }
    pControl->Release();
    pEvent->Release();
    pGraph->Release();
    CoUninitialize();


}