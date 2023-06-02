
#include "pch.h"
#include "Camera.h"
#include "Player1.h"
#include "Player2.h"
#include "KeyManager.h"


void CameraManager::Init()
{
}

void CameraManager::Update()
{

	if (_target_p1)
	{
		
		_lookat = _target_p1->GetPos();
	}
	else if (_target_p2)
	{
		
		_lookat = _target_p2->GetPos();
	}

	CallDiff();

	if (GET_SINGLE(KeyManager)->Getbutton(KeyType::SpaceBar)) {
		_lookat.x += 1;
	}
}

void CameraManager::CallDiff()
{

	Pos center;
	center.x = WINDOW_WIDTH  / 2;
	center.y = WINDOW_HEIGHT / 2;
	_vdiff=_lookat-center;
}

Pos CameraManager::GetRenderPos(Pos object)
{
	Pos temp;
	temp.x = object.x - _vdiff.x;
	temp.y = object.y - _vdiff.y;
	return temp;
}


Pos CameraManager::GetRenderPos2(Pos object)
{
	Pos temp;
	temp.x = object.x + _vdiff.x;
	temp.y = object.y + _vdiff.y;
	return temp;
}