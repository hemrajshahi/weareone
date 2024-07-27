#ifndef ENDOMORPH_H
#define ENDOMORPH_H

#include <string>
#include<iostream>
class Endomorph{
public:
    void characteristics();
    void nutrientsAndDiet();
    void exercises() ;
    void showExerciseDetails(const std::string &exerciseName) const;
};

#endif

