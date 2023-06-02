#pragma once


class Player1;
class Player2;

class CameraManager
{
public:
	DECLARE_SINGLE(CameraManager);


	void Init();
	void Update();


	void Setlookat(Pos lookat) { _lookat = lookat; }
	void SetTarget1(Player1* object) { _target_p1 = object; }
	void SetTarget2(Player2* object) { _target_p2 = object; }
	void CallDiff();
	Pos GetRenderPos(Pos object);
	Pos GetRenderPos2(Pos object);

	Pos _vdiff;
	Pos _lookat;
	Player1* _target_p1;
	Player2* _target_p2;

};


