#include "Enemy.h"
//#include "AnimData.h"

Enemy::Enemy(const CVector2D& p, bool flip) :
	Base(eType_Enemy) {
	//�摜����
	m_img = COPY_RESOURCE("Enemy", CImage);
	//�Đ��A�j���[�V�����ݒ�
	//m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(128, 224);
	//���]�t���O
	m_flip = flip;
}
void Enemy::Update() {

	//�ҋ@�A�j���[�V����
	//m_img.ChangeAnimation(eAnimIdle);
	//�A�j���[�V�����X�V
	//m_img.UpdateAnimation();

}

void Enemy::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(m_pos);
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
}
void Enemy::Collision(Base* b)
{

}
