#include <dplay8.h>

IDirectPlay8Peer* g_pDP   = NULL;    // DirectPlay peer object
HWND              g_hDlg  = NULL;    // UI dialog handle
HINSTANCE         g_hInst = NULL;    // Program instance handle

HRESULT InitDirectPlay();
HRESULT ListServiceProviders();
void    OutputError( TCHAR* str, HRESULT hr = 0 );
void    CleanupDirectPlay();
INT_PTR CALLBACK MainDlgProc( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam );
HRESULT WINAPI DirectPlayMessageHandler(PVOID pvUserContext, DWORD dwMessageId, PVOID pMsgBuffer);

TCHAR g_strAppTitle[MAX_PATH] = {0};
int main(void){

	LoadString( hInst, IDS_APP_TITLE, g_strAppTitle, MAX_PATH );
	HRESULT hr = S_OK;
    g_hInst = hInst;

    InitCommonControls();

    // Init COM so we can use CoCreateInstance
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
	// Create the IDirectPlay8Peer Object
   hr = CoCreateInstance( CLSID_DirectPlay8Peer, NULL, 
                          CLSCTX_INPROC_SERVER,
                          IID_IDirectPlay8Peer, 
                          (LPVOID*) &g_pDP );

// Initialize DirectPlay
   hr = g_pDP->Initialize(NULL, DirectPlayMessageHandler, 0 );



	return 0;
}
