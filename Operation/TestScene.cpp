#include "TestScene.h"

TestScene::TestScene(GameObject* parent)
{
}
void TestScene::Initialize()
{

}

void TestScene::Update() 
{
	// �J�����̈ʒu�ƒ����_���Z�b�g
	//SetCameraPositionAndTarget_UpVecY(VGet(x+1, y-500, z),VGet(x,y,z));
	// ���͏�Ԃ��擾
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	if (input.ThumbLX >= 10000)
	{
		x += 25;
	};
	if (input.ThumbLY >= 10000)
	{
		y += 25;
	};
	if (input.ThumbLX <= -10000)
	{
		x -= 25;
	};
	if (input.ThumbLY <= -10000)
	{
		y -= 25;
	};
}

void TestScene::Draw()
{
	// �R�c��ԏ�ɐ�����`�悷��
	DrawSphere3D(VGet(x, y, z), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}

void TestScene::Release()
{

}