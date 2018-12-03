#include "DxLib.h"


//FとJに指を置いて捜査する
//グローバル変数

static int g = 1;									//重力



//クラスの定義

//ポジションのストラクタ
struct Point {
	int x, y;
};

class Character {
	struct Point v = { 0,0 };					//速度
	struct Point a = { 1,1 };					//アクセル値

	bool air = false;

public :

	struct Point pos;								//座標
	bool visible;									//表示するかしないか

	//コンストラクタ
	Character(int xx, int yy, bool show) : pos({xx,yy}), visible(show) {
	};
	void Jump_init();							//ジャンプの初期設定
	void Jump();									//ジャンプの処理
};

class Keystatus {
		
		char KeyBuf[256];
		byte keyflug[256];

	public:

		void Init() {
			for (int i = 0; i < 256; i++) keyflug[i] = 0;
		}
		void Update() {
			GetHitKeyStateAll(KeyBuf);
			for (int i = 0; i < 256; i++) {
				if (KeyBuf[i]) keyflug[i] = keyflug[i] == 0 ? 1 : 2;
				else keyflug[i] = 0;
			}
		}

		int Keyflug(int keycode) { return keyflug[keycode]; }

};


//ジャンプの初期設定
void Character::Jump_init() {
	a.y = -20;										//y軸方向のアクセルの初期値を設定
	air = true;										//空中にいる判定にする。
}


//ジャンプの処理
void Character::Jump() {
	a.y += g;

	//あたり判定
	if (1) {
		air = false;
	}
}


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//変数の設定
	
	Character player();

	Keystatus key;



	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}



	//キーボード初期化
	key.Init();

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		key.Update();

		if (key.Keyflug(KEY_INPUT_E)) break;

	}

	//DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}