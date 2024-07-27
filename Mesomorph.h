#ifndef MESOMORPH_H
#define MESOMORPH_H

#include <string>
#include<iostream>

class Mesomorph{
public:
    void characteristics();
    void nutrientsAndDiet();
    void exercises();
    void showExerciseDetails(const std::string &exerciseName) const;
};

#endif
