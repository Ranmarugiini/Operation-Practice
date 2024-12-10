#include "TestScene.h"

TestScene::TestScene(GameObject* parent)
{

}
void TestScene::Initialize()
{
	// ‚R‚c‹óŠÔã‚Éü•ª‚ğ•`‰æ‚·‚é
	DrawLine3D(VGet(100.0f, 100.0f, 0.0f), VGet(300.0f, 200.0f, 0.0f), GetColor(255, 255, 0));
}

void TestScene::Update() 
{

}

void TestScene::Draw()
{

}

void TestScene::Release()
{

}