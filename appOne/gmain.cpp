#include"libOne.h"

class CHARACTER { //class�̓f�t�H���g��private,struct��public
protected:   //�O�ŕϐ���ς��邱�Ƃ��֎~����(�p���́Z)
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;
public:    //�v���C�x�[�g�ɑ΂��Ă����₯



    void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }
    virtual void move() {       //���z�N���X
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};
class PLAYER : public CHARACTER { //PLAYER��CHARACTER�Ɠ����ɂ���
public:                           //�p�������N���X�����N���X
    void move() {                 
        Px += Vx;
    }
};

void gmain() {
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");

    PLAYER player;
    CHARACTER* chara = &player; //�p�������N���X�̃A�h���X

    chara->setImage(playerImg);
    chara->init();
    while(notQuit) {
        chara->move();
        clear();
        chara->draw();

    }
}