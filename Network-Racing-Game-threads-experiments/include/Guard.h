#ifndef GUARD_H
#define GUARD_H
#include<chrono>
#include <thread>
#include <iostream>
#include <random>
class Rolfor;

class Guard
{
private:
    int m_GuardHealth=100;
    int m_GuardDefense=40;
    int m_GuardAttack=rand()%20;
    float m_GuardDamageTaken;
protected:

public:
    Guard();
    void Run();
    int TakeDamage(int EnemyAttack) return m_DamageTaken;
    void Attack();
    virtual ~Guard();





};

#endif // GUARD_H
