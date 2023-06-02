#include "pch.h"
#include "GAME.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "SceanManager.h"
#include "Camera.h"



GAME::~GAME()
{

}

void GAME::Init(HWND _hwnd)
{
	hwnd =_hwnd;
	hdc = GetDC(_hwnd);
	//������۸�
	mdc = CreateCompatibleDC(hdc);
	hbitmap = CreateCompatibleBitmap(hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
	HBITMAP prev = (HBITMAP)SelectObject(mdc, hbitmap);
	DeleteObject(prev);
	//������۸� ó��

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(KeyManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::STAGE1);
	GET_SINGLE(CameraManager)->Init();
	
}

void GAME::Update()
{

	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(KeyManager)->Update();
	GET_SINGLE(SceneManager)->Update();
	GET_SINGLE(CameraManager)->Update();
}

void GAME::Render()
{
	GET_SINGLE(SceneManager)->Render(mdc);

	BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, mdc, 0, 0, SRCCOPY);
	PatBlt(mdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, WHITENESS); // INVAILDRECT ��ü �ϴ� �Լ�
}

