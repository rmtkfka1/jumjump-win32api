#include "pch.h"
#include "BackGround.h"
#include "Camera.h"
#include "Stage1.h"
#include "Player1.h"
#include "KeyManager.h"
BackGround::BackGround() :Object(ObjectType::PLAYER1)
{

}

BackGround::~BackGround()
{
	background_img.Destroy();
	
}

void BackGround::Init()
{
	background_img.Load(L"¸®¼Ò½º\\BackGround.png");

	
 
}

void BackGround::Update()
{
	
}

void BackGround::Render(HDC mdc)
{

	mdc2 = CreateCompatibleDC(mdc);
	hbit2 = CreateCompatibleBitmap(mdc, background_img.GetWidth(), background_img.GetHeight());
	SelectObject(mdc2, (HBRUSH)hbit2);

	background_img.Draw(mdc2, 0, 0, background_img.GetWidth(), background_img.GetHeight()
		, 0, 0, background_img.GetWidth(), background_img.GetHeight());

	TransparentBlt(mdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
		mdc2,0,0, WINDOW_WIDTH, WINDOW_HEIGHT,RGB(0,0,0));

	DeleteDC(mdc2);
	DeleteObject(hbit2);

}
