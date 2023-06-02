#include "pch.h"
#include "Player1.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "Stage1.h"
#include "GAME.h"
#include "Object.h"
#include "Camera.h"
Player1::Player1() :Object(ObjectType::PLAYER1)
{

}
Player1::~Player1()
{
	
	player1_img_left.Destroy();
	player1_img_right.Destroy();



}

void Player1::Init()
{


	player1_img_left.Load(L"리소스\\ch1\\LEFT.png");
	player1_img_right.Load(L"리소스\\ch1\\RIGHT.png");

	_pos.x = 400;
	_pos.y = 400;

	size.x = 32;
	size.y = 32;

	_stat.speed = 100;

	_motion = Motion::RIGHT;
}

void Player1::Update()
{

	float deletaTime = GET_SINGLE(TimeManager)->GetDeltaTime(); //프레임동기화 (컴퓨터마다 속도를 똑같이맞춰줌)


	if (GET_SINGLE(KeyManager)->Getbutton(KeyType::A))
	{
		_motion = Motion::LEFT;
		_pos.x -= _stat.speed * deletaTime;
		_motion_cnt++;
		_motion_cnt %= 6;
	}

	if (GET_SINGLE(KeyManager)->Getbutton(KeyType::D))
	{
		_motion = Motion::RIGHT;
		_pos.x += _stat.speed * deletaTime;
		_motion_cnt++;
		_motion_cnt %= 6;
	}

	if (GET_SINGLE(KeyManager)->Getbutton(KeyType::W))
	{
		
	}

	if (GET_SINGLE(KeyManager)->Getbutton(KeyType::S))
	{
	
	}


	if (GET_SINGLE(KeyManager)->GetbuttonDown(KeyType::G))//스킬
	{
	
	}


	if (GET_SINGLE(KeyManager)->GetbuttonDown(KeyType::F))//점프
	{
	}
}




void Player1::Render(HDC mdc)
{

	mdc2 = CreateCompatibleDC(mdc);
	hbit2 = CreateCompatibleBitmap(mdc, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(mdc2, (HBITMAP)hbit2);


	if (_motion == Motion::LEFT)
	{
		player1_img_left.Draw(mdc2, _pos.x, _pos.y, size.x, size.y, _motion_cnt * 32, 0, 32, 32);
	}

	if (_motion == Motion::RIGHT) 
	{
		player1_img_right.Draw(mdc2, _pos.x, _pos.y, size.x, size.y, _motion_cnt * 32, 0, 32, 32);
	}
	
	
	Pos render_pos =GET_SINGLE(CameraManager)->GetRenderPos(_pos);

	TransparentBlt(mdc, render_pos.x, render_pos.y, size.x, size.y,
		mdc2, _pos.x, _pos.y, size.x, size.y, RGB(0, 0, 0));

	DeleteDC(mdc2);
	DeleteObject(hbit2);

}

