#include "Player.h"
#include "AnimData.h"
#include"Field.h"



Player::Player(const CVector2D& p, bool flip) :
	Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(16, 16);
	//反転フラグ
	m_flip = flip;
	m_state = eState_Idle;
	m_is_ground = true;

}
void Player::Update() {
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
	}
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;



	//アニメーション更新
	m_img.UpdateAnimation();
	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2;


}

void Player::Draw() {
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));;
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		//Field型へキャスト、型変換できたら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下にいったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さに戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
		break;
	}

}
void Player::StateIdle()
{
	const float move_speed = 6;
	//ジャンプ力
	const float jump_pow = 12;


	bool move_flag = false;
	if (HOLD(CInput::eLeft)) {
		m_pos.x += -move_speed;
		m_flip = true;
		move_flag = true;
	}
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}
	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}


	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	//移動中なら
	else
	{

		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}

void Player::StateAttack()
{
}

void Player::StateDamage()
{
}

void Player::StateDown()
{
}