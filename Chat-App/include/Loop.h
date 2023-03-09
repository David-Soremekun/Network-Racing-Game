#ifndef LOOP_H
#define LOOP_H

#include <chrono>
class Loop
{
    private:

    bool l_hasToStop{true};

    public:

    Loop();
    void Run(bool toStop){

        TimeWait();

        if(l_hasToStop)
        {


        }

     };
    void TimeWait(){

    };
};

#endif // LOOP_H
