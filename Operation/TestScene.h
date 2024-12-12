#pragma once
#include "GameObject.h"
#include <DxLib.h>
class TestScene:public GameObject
{public:
	int x = 0.0f, y = 0.0f, z = 0.0f;
	XINPUT_STATE input;
	VECTOR Position = VGet(x, y, z);
	TestScene(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

