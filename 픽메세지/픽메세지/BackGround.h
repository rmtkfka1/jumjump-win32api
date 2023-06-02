#pragma once
#include "Object.h"


class BackGround :public Object
{
public:


	BackGround();
	virtual ~BackGround() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC mdc) override;
		

public:

	HDC mdc2;
	HBITMAP hbit2;
	CImage background_img;


};

