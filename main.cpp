#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Mao
{
    int energy;     //�G�l���M�[
    int pos;        //�ʒu
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

int main()
{
    srand((unsigned)time(NULL));
    Mao m;
    int i, a;
    for (i = 0; i < 5; i++) {
        if (m.GetEnergy() <= 0) {
            break;    //���[�v�𔲂���Ƃ�������(���Ő����j
        }
        cout << "�����ɍU���������܂��B" << endl;
        cout << "�U���ʒu����͂��Ă��������B�i0����9�̔��p�����j" << endl;
        cout << "�����̎c��G�l���M�[�F" << m.GetEnergy() << endl;
        cout << "�U���񐔂͂���" << 5 - i << "��" << endl;
        cin >> a;      //���[�U�̓��͂�a�Ɋi�[
        m.Attacked(a);
    }
    //�U����ɂ܂������ɃG�l���M�[���c���Ă���΁A�A�A
    if (m.GetEnergy() > 0) {
        cout << "���߂��B�����͓����Ă��܂����B" << endl;
    }
}
