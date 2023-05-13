#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Mao
{
    int energy;    //�G�l���M�[
    int pos;       //�ʒu
public:
    Mao() :energy(100), pos(rand() % 10) {}
    void Attacked(int n);                    //�U�����ꂽ�Ƃ��̔����̊֐�
    int GetEnergy() const { return energy; }  //�G�l���M�[��߂��֐�
};

//���[�U�̍U���ʒu��n�ł������Ƃ��A�A�A�Ƃ����֐�
void Mao::Attacked(int n) {
    if (n == pos) {
        cout << "����[�B�������I" << endl;
        energy -= 50;
        pos += rand() % 3 - 1;   //pos��ς���i������Ƃ������Ɓj
    }
    else if (n == pos - 1 || n == pos + 1) {
        cout << "�����Ɗ�Ȃ��I�@�����͂��ꂾ�B" << endl;
        energy -= 10;
    }
    else {
        cout << "�ǂ����˂���Ă���H�@�܂������͂��ꂾ�B" << endl;
    }
    if (energy <= 0) {
        cout << "�����A���ꂽ�I�@�N�͉p�Y����B" << endl;
    }
}

class Hero
{
    int energy;
public:
    Hero() :energy(50) {}
    int Attack();
    int GetEnergy() const { return energy; }
};

int Hero::Attack() {
    energy -= 10;
    int a;
    cout << endl;
    cout << "���`�̗͂��󂯂Ă݂�I" << endl;
    cout << "�i0����9�̔��p�����ŁA�U���ʒu���w�����Ă��������B�j" << endl;
    cin >> a;
    return a;
}

int main()
{
    srand((unsigned)time(NULL));
    Mao m;
    Hero h;
    cout << "���ꂩ�疂���Ɛ킢�܂��B����΂�I" << endl;
    cout << "�����̎c��G�l���M�[�F" << m.GetEnergy() << endl;

    while (h.GetEnergy() > 0) {
        if (m.GetEnergy() <= 0) {
            break;
        }
        int x;
        x = h.Attack();
        m.Attacked(x);
    }
    if (m.GetEnergy() > 0) {
        cout << "���߂��B�����͓����Ă��܂����B" << endl;
    }
    system("pause>0");
}
