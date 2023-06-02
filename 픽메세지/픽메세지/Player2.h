#pragma once
#include "Object.h"

class Player2 :public Object
{

public:

	Player2();
	virtual ~Player2() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC mdc) override;


public:

	int _motion_cnt;
	HDC mdc2;
	HBITMAP hbit2;
	CImage player2_img_left;
	CImage player2_img_right;
	Motion _motion;


};
