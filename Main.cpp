#include "DxLib.h"


//F��J�Ɏw��u���đ{������
//�O���[�o���ϐ�

static int g = 1;									//�d��



//�N���X�̒�`

//�|�W�V�����̃X�g���N�^
struct Point {
	int x, y;
};

class Character {
	struct Point v = { 0,0 };					//���x
	struct Point a = { 1,1 };					//�A�N�Z���l

	bool air = false;

public :

	struct Point pos;								//���W
	bool visible;									//�\�����邩���Ȃ���

	//�R���X�g���N�^
	Character(int xx, int yy, bool show) : pos({xx,yy}), visible(show) {
	};
	void Jump_init();							//�W�����v�̏����ݒ�
	void Jump();									//�W�����v�̏���
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


//�W�����v�̏����ݒ�
void Character::Jump_init() {
	a.y = -20;										//y�������̃A�N�Z���̏����l��ݒ�
	air = true;										//�󒆂ɂ��锻��ɂ���B
}


//�W�����v�̏���
void Character::Jump() {
	a.y += g;

	//�����蔻��
	if (1) {
		air = false;
	}
}


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//�ϐ��̐ݒ�
	
	Character player();

	Keystatus key;



	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}



	//�L�[�{�[�h������
	key.Init();

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		key.Update();

		if (key.Keyflug(KEY_INPUT_E)) break;

	}

	//DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}