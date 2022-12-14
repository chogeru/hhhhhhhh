#include "Enemy.h"
//#include "AnimData.h"

Enemy::Enemy(const CVector2D& p, bool flip) :
	Base(eType_Enemy) {
	//画像複製
	m_img = COPY_RESOURCE("Enemy", CImage);
	//再生アニメーション設定
	//m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(128, 224);
	//反転フラグ
	m_flip = flip;
}
void Enemy::Update() {

	//待機アニメーション
	//m_img.ChangeAnimation(eAnimIdle);
	//アニメーション更新
	//m_img.UpdateAnimation();

}

void Enemy::Draw() {
	//位置設定
	m_img.SetPos(m_pos);
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
}
void Enemy::Collision(Base* b)
{

}
