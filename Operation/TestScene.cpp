#include "TestScene.h"

TestScene::TestScene(GameObject* parent)
{

}
void TestScene::Initialize()
{
	// ３Ｄ空間上に線分を描画する
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