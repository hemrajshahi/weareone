#ifndef ECTOMORPH_H
#define ECTOMORPH_H

#include <string>

class Ectomorph{
public:
    void characteristics();
    void nutrientsAndDiet();
    void exercises();
    void showExerciseDetails(const std::string &exerciseName) const;
};

#endif

