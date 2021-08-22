//
// Created by aljoh on 4/9/2021.
//

#ifndef TONETRAINER_ENVELOPE_H
#define TONETRAINER_ENVELOPE_H

#include <forward_list>
using namespace std;

class Envelope {
public:
    Envelope(forward_list<double> env){

    };
    double next(){
        double v = env.front();
        env.pop_front();
        return v;
    };

private:
    Envelope();

    forward_list<double> env;

};


#endif //TONETRAINER_ENVELOPE_H
