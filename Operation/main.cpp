
#include "DxLib.h"

#include "global.h"
#include "RootObject.h"

namespace Screen {
	static const int WIDTH = 1280;
	static const int HEIGHT = 720;
	static const char* WINDOW_NAME = "SampleGame";
	static const int WINDOW_EXTEND = 0;
	static const int WINDOW_MODE = 1;
};

// エントリーポイント
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(Screen::WIDTH, Screen::HEIGHT, 32);
	SetOutApplicationLogValidFlag(FALSE); // ログを出さない

	SetMainWindowText(Screen::WINDOW_NAME);
	SetWindowSizeExtendRate(Screen::WINDOW_EXTEND);
	ChangeWindowMode(Screen::WINDOW_MODE); // Windowモードの場合

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);
	SetAlwaysRunFlag(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	//SetFPSLimit(60);
	RootObject* pRootObject = new RootObject;
	pRootObject->Initialize();

	while (true) {
		//全オブジェクトの更新処理
		//ルートオブジェクトのUpdateを呼んだあと、自動的に子、孫のUpdateが呼ばれる
		pRootObject->UpdateSub();


		if (DxLib::ProcessMessage() == -1 /*|| AppIsExit()*/)
			break;

		ClearDrawScreen();
		//全オブジェクトを描画
		//ルートオブジェクトのDrawを呼んだあと、自動的に子、孫のUpdateが呼ばれる
		pRootObject->DrawSub();


		RefreshDxLibDirect3DSetting();

		ScreenFlip();
	}
	pRootObject->ReleaseSub();
	delete pRootObject;

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;
}