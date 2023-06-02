#include "pch.h"
#include "Player2.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "Stage1.h"
#include "GAME.h"
#include "Object.h"
#include "Camera.h"

Player2::Player2() :Object(ObjectType::PLAYER2)
{

}
Player2::~Player2()
{

	player2_img_left.Destroy();
	player2_img_right.Destroy();

}

void Player2::Init()
{


	player2_img_left.Load(L"리소스\\ch2\\LEFT.png");
	player2_img_right.Load(L"리소스\\ch2\\RIGHT.png");

	_pos.x = 600;
	_pos.y = 400;

	size.x = 32;
	size.y = 32;

	_stat.speed = 100;

	_motion = Motion::RIGHT;
}

void Player2::Update()
{

	float deletaTime = GET_SINGLE(TimeManager)->GetDeltaTime(); //프레임동기화 (컴퓨터마다 속도를 똑같이맞춰줌)


	if (GET_SINGLE(KeyManager)->Getbutton(KeyType::Left))
	{
		_motion = Motion::LEFT;
		_pos.x -= _stat.speed * deletaTime;
		_motion_cnt++;
		_motion_cnt %= 6;
	}

	if (GET_SINGLE(KeyManager)->Getbutton(KeyType::Right))
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


	if (GET_SINGLE(KeyManager)->GetbuttonDown(KeyType::F))//점프
	{

	}

	if (GET_SINGLE(KeyManager)->GetbuttonDown(KeyType::G))//스킬
	{

	}

}


void Player2::Render(HDC mdc)
{

	mdc2 = CreateCompatibleDC(mdc);
	hbit2 = CreateCompatibleBitmap(mdc, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(mdc2, (HBITMAP)hbit2);

	if (_motion == Motion::LEFT)
	{
		player2_img_left.Draw(mdc2, _pos.x, _pos.y, size.x, size.y, _motion_cnt * 32, 0, 32, 32);
	}


	if (_motion == Motion::RIGHT)
	{
		player2_img_right.Draw(mdc2, _pos.x, _pos.y, size.x, size.y, _motion_cnt * 32, 0, 32, 32);
	}

	Pos render_pos = GET_SINGLE(CameraManager)->GetRenderPos(_pos);

	TransparentBlt(mdc, render_pos.x, render_pos.y, size.x, size.y,
		mdc2, _pos.x, _pos.y, size.x, size.y, RGB(0, 0, 0));


	DeleteDC(mdc2);
	DeleteObject(hbit2);

}

