#include "pch.h"
#include "Stage1.h"
#include "TimeManager.h"
#include "Player1.h"
#include "Player2.h"
#include "BackGround.h"
#include "Camera.h"
#include "KeyManager.h"


Stage1::~Stage1()
{
	delete p1;
	p1 = nullptr;
	delete p2;
	p2 = nullptr;


}

void Stage1::Init()
{


	p1 = new Player1;

	p1->Init();

	p2 = new Player2;
	p2->Init();

	bg = new BackGround;
	bg->Init();

	GET_SINGLE(CameraManager)->SetTarget1(p1);



}

void Stage1::Update()
{
	if (GET_SINGLE(KeyManager)->GetbuttonDown(KeyType::I)) //1눌림
	{
		GET_SINGLE(CameraManager)->SetTarget2(nullptr);
		GET_SINGLE(CameraManager)->SetTarget1(p1);
	}


	if (GET_SINGLE(KeyManager)->GetbuttonDown(KeyType::O)) //2눌림
	{
		GET_SINGLE(CameraManager)->SetTarget1(nullptr);
		GET_SINGLE(CameraManager)->SetTarget2(p2);
	}


	p1->Update();
	p2->Update();
	bg->Update();


}

void Stage1::Render(HDC mdc)
{
	bg->Render(mdc);
	p1->Render(mdc);
	p2->Render(mdc);
	
}
