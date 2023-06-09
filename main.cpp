#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Mao
{
    int energy;     //エネルギー
    int pos;        //位置
public:
    Mao() :energy(100), pos(rand() % 10) {}
    void Attacked(int n);                    //攻撃されたときの反応の関数
    int GetEnergy() const { return energy; }  //エネルギーを戻す関数
};

//ユーザの攻撃位置がnであったとき、、、という関数
void Mao::Attacked(int n) {
    if (n == pos) {
        cout << "ぎゃー。命中だ！" << endl;
        energy -= 50;
        pos += rand() % 3 - 1;   //posを変える（逃げるということ）
    }
    else if (n == pos - 1 || n == pos + 1) {
        cout << "おっと危ない！　だがはずれだ。" << endl;
        energy -= 10;
    }
    else {
        cout << "どこをねらっている？　まったくはずれだ。" << endl;
    }
    if (energy <= 0) {
        cout << "ああ、やられた！　君は英雄だよ。" << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    Mao m;
    int i, a;
    for (i = 0; i < 5; i++) {
        if (m.GetEnergy() <= 0) {
            break;    //ループを抜けろという命令(下で説明）
        }
        cout << "魔王に攻撃を加えます。" << endl;
        cout << "攻撃位置を入力してください。（0から9の半角数字）" << endl;
        cout << "魔王の残りエネルギー：" << m.GetEnergy() << endl;
        cout << "攻撃回数はあと" << 5 - i << "回" << endl;
        cin >> a;      //ユーザの入力をaに格納
        m.Attacked(a);
    }
    //攻撃後にまだ魔王にエネルギーが残っていれば、、、
    if (m.GetEnergy() > 0) {
        cout << "だめだ。魔王は逃げてしまった。" << endl;
    }
}
