#pragma once
#include "Object.h"



class Player1 :public Object
{

public:


	Player1();
	virtual ~Player1() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC mdc) override;


public:
	bool _is_jumping;
	int _motion_cnt;

	float _jump_counting;
	float _jump_height;
	HDC mdc2;
	HBITMAP hbit2;
	CImage player1_img_left;
	CImage player1_img_right;
	Motion _motion;

	


};

