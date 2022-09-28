#pragma once
#include "Base/Base.h"
#include <GLLibrary.h>

class obuzye : public Base {
private:
	//マップ上オブジェクト
	CImage m_obuzye;
	
public:
	/// コンストラクタ
	obuzye();
	/// 描画
	void Draw();

};