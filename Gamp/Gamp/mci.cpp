#include<windows.h>
#include<mmsystem.h>
#include<Digitalv.h>
#include<string>
#include "mci.h";
#pragma comment(lib, "winmm.lib")

UINT BgmId;
UINT Effectid;

void PlayBgm(LPCWSTR _soundName, int _volume)
{
	//다시 블러졌을 떄 기존 거 닫기 위함
	mciSendCommand(BgmId, MCI_CLOSE, NULL, (DWORD)NULL);
	MCI_OPEN_PARMS openBgm;
	openBgm.lpstrElementName = _soundName;
	// mp3: mpegvideo, wav: waveaudio
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openBgm);
	BgmId = openBgm.wDeviceID;

	//볼륨 로직
	std::wstring msg = L"setaudio "+std::wstring(_soundName) + L" volume to " + std::to_wstring(_volume);
	mciSendString(msg.c_str(), NULL, NULL, NULL);

	MCI_PLAY_PARMS playBgm;;
	mciSendCommand(BgmId, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&playBgm);
}

void PlayEffect(LPCWSTR _soundname)
{
    // PLAY
    MCI_PLAY_PARMS playEffect;
    if (Effectid != 0)
    {
        mciSendCommand(Effectid, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playEffect);
        mciSendCommand(Effectid, MCI_CLOSE, NULL, (DWORD)NULL); // RAII
        Effectid = 0;
    }
    // OPEN
    MCI_OPEN_PARMS openEffect;
    // mp3: mpegvideo, wav: waveaudio, avi: avivideo
    openEffect.lpstrDeviceType = TEXT("mpegvideo");
    openEffect.lpstrElementName = _soundname;
    mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
    Effectid = openEffect.wDeviceID;


    mciSendCommand(Effectid, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
    while (mciSendCommand(Effectid, MCI_STATUS, MCI_STATUS_MODE, (DWORD_PTR)&playEffect))
    {
        break;
    }
}
