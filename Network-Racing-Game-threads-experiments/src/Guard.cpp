#include "Guard.h"
#include "Rolfor.h"
Guard::Guard()
{
    //ctor
}
Guard::~Guard()
{
    //dtor
}
void Guard::Attack(Rolfor* r)
{
    int AttackAccuracy=rand()%2+1;

    switch(AttackAccuracy){
        case 1:
            std::cout<<"Guard Dan Attacks Success :)"<<std::endl;

            break;
        case 2:
            std::cout<< "Guard misses! :("<<std::endl;

            break;
    }

}

int Guard::TakeDamage(int EnemyAttack)
{
    float damageRatio=EnemyAttack / (float) m_GuardDefense;

    m_GuardDamageTaken=damageRatio * static_cast<float>(m_GuardHealth);

    m_GuardHealth = m_GuardHealth-static_cast<int>(m_GuardDamageTaken);


}

void Guard::Run()
{
    //if(m_HealthGuard<=0){

    //}

    std::this_thread::sleep_for(std::chrono::milliseconds(100+rand()%100));
    Attack();

}
