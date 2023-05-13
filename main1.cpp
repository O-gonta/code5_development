#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Mao
{
    int energy;    //エネルギー
    int pos;       //位置
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
    cout << "正義の力を受けてみよ！" << endl;
    cout << "（0から9の半角数字で、攻撃位置を指示してください。）" << endl;
    cin >> a;
    return a;
}

int main()
{
    srand((unsigned)time(NULL));
    Mao m;
    Hero h;
    cout << "これから魔王と戦います。がんばれ！" << endl;
    cout << "魔王の残りエネルギー：" << m.GetEnergy() << endl;

    while (h.GetEnergy() > 0) {
        if (m.GetEnergy() <= 0) {
            break;
        }
        int x;
        x = h.Attack();
        m.Attacked(x);
    }
    if (m.GetEnergy() > 0) {
        cout << "だめだ。魔王は逃げてしまった。" << endl;
    }
    system("pause>0");
}
