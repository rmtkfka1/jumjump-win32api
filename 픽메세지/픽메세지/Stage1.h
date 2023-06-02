#pragma once
#include "Scene.h"

class Player1;
class Player2;
class BackGround;


class Stage1 : public Scene
{
public:
	DECLARE_SINGLE(Stage1);
	virtual ~Stage1();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC mdc) override;
	Player1* Getp1() { return p1; }

public:
	BackGround *bg = nullptr;
	Player1* p1 = nullptr;
	Player2* p2 = nullptr;
	

};

