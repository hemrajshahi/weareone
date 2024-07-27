#include "Ectomorph.h"
#include <iostream>

void Ectomorph::characteristics() {
    std::cout << "The Ectomorph Body Type" << std::endl;
            std::cout << "Characteristics:\n";
std::cout << "Build: Ectomorphs are characterized by a thin, lean physique with narrow shoulders and hips." << std::endl;
        std::cout << "They often appear tall and slender, with long limbs and little body fat." << std::endl;
        std::cout << "Muscle Development: They typically have a hard time gaining muscle mass." << std::endl;
        std::cout << "Their muscle definition is usually less prominent, and they may struggle to bulk up even with strength training." << std::endl;
        std::cout << "Fat Storage: Ectomorphs generally have a fast metabolism, which means they don’t gain weight easily." << std::endl;
        std::cout << "They can eat more without gaining excess fat but may find it difficult to put on weight at all." << std::endl;
        std::cout << "Metabolism: Their metabolism is fast, which helps them burn calories quickly." << std::endl;
        std::cout << "This is beneficial for keeping slim but can be a challenge when trying to gain weight." << std::endl;
}

void Ectomorph::nutrientsAndDiet() {
	std::cout << "Ectomorph" << std::endl;
    std::cout << "Nutritional Goals:" << std::endl;
    std::cout << "Increase caloric intake to gain muscle mass" << std::endl;
    std::cout << "Higher protein intake to support muscle growth" << std::endl;
    std::cout << "Consume nutrient-dense, high-calorie foods" << std::endl;

    std::cout << "Recommended Diet:" << std::endl;
    std::cout << "Protein:" << std::endl;
    std::cout << "Beef, Chicken, Fish, Pork, Turkey, Eggs, Peanuts, Almonds, Sunflower seeds" << std::endl;
    std::cout << "Dairy:" << std::endl;
    std::cout << "Milk, Yogurt" << std::endl;
    std::cout << "Whole Grains:" << std::endl;
    std::cout << "Quinoa, Whole wheat bread, Oats, Brown Rice" << std::endl;
    std::cout << "Vegetables:" << std::endl;
    std::cout << "Broccoli, Cauliflower, Sweet Potato, Beans, Squash" << std::endl;
    std::cout << "Fruits:" << std::endl;
    std::cout << "Bananas, Apples, Oranges, Berries" << std::endl;

    std::cout << "Tips:" << std::endl;
    std::cout << "Eat multiple small meals throughout the day to meet caloric needs." << std::endl;
    std::cout << "Consider using mass gainer supplements to easily increase calorie intake." << std::endl;
    std::cout << "Ensure protein intake is at least 1 gram per pound of bodyweight." << std::endl;
    std::cout << "Focus on slow-digesting protein shakes at night to promote muscle growth during sleep." << std::endl;
    std::cout << "Aim for a diet with an energy surplus to support weight gain." << std::endl;


}

void Ectomorph::exercises(){
    std::cout << "Ectomorph" << std::endl;
    std::cout << "Ectomorphs typically have a lean and long body type with difficulty gaining muscle mass." << std::endl;
    std::cout << "Exercises for ectomorphs often focus on building muscle mass and strength." << std::endl;

    std::cout << "Strength Training:" << std::endl;
    std::cout << "1. Squats: Excellent for lower body strength and muscle gain." << std::endl;
    std::cout << "2. Deadlifts: Great for overall strength and muscle development." << std::endl;
    std::cout << "3. Bench Press: Targets the chest, shoulders, and triceps." << std::endl;
    std::cout << "4. Pull-Ups/Chin-Ups: Effective for back and biceps development." << std::endl;
    std::cout << "5. Shoulder Press: Builds shoulder and upper body strength." << std::endl;
    std::cout << "6. Barbell Rows: Targets the back muscles and helps in gaining upper body strength." << std::endl;
    std::cout << "7. Leg Press: Complements squats for lower body strength." << std::endl;

    std::cout << "Cardio (in moderation):" << std::endl;
    std::cout << "1. Rowing Machine: Full-body workout that also builds endurance." << std::endl;
    std::cout << "2. Cycling: Low impact and good for cardiovascular health." << std::endl;
    std::cout << "3. Swimming: Full-body exercise that is easy on the joints." << std::endl;

}
void Ectomorph::showExerciseDetails(const std::string &exerciseName) const {
    if (exerciseName == "Squats") {
    std::cout << "Exercise: Squats\n";
    std::cout << "Description: Excellent for lower body strength and muscle gain.\n";
    std::cout << "Muscles Worked: Quadriceps, Hamstrings, Glutes\n";
    std::cout << "Equipment: Barbell\n\n";
    std::cout << "Procedure:\n";
    std::cout << "Stand with feet shoulder-width apart, barbell resting on your upper back.\n";
    std::cout << "Lower your body by bending your knees and hips, keeping your back straight.\n";
    std::cout << "Descend until your thighs are parallel to the ground.\n";
    std::cout << "Push through your heels to return to the starting position.\n\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 10-12 reps\n";
    std::cout << "Intermediate: 4 sets of 8-10 reps\n";
    std::cout << "Advanced: 5 sets of 6-8 reps\n";
}
else if(exerciseName == "Deadlifts"){
    std::cout << "Exercise: Deadlifts\n";
    std::cout << "Description: Great for overall strength and muscle development.\n";
    std::cout << "Muscles Worked: Back, Legs, Core\n";
    std::cout << "Equipment: Barbell\n";
    std::cout << "Procedure:\n";
    std::cout << "Stand with your feet hip-width apart, barbell in front.\n";
    std::cout << "Bend at your hips and knees to lower your body and grasp the barbell with an overhand grip.\n";
    std::cout << "Lift the barbell by extending your hips and knees to full extension.\n";
    std::cout << "Lower the barbell back to the ground in a controlled manner.\n\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 8-10 reps\n";
    std::cout << "Intermediate: 4 sets of 6-8 reps\n";
    std::cout << "Advanced: 5 sets of 5 reps\n\n";
}
else if (exerciseName == "Bench Press") {
    std::cout << "Exercise: Bench Press\n";
    std::cout << "Description: Targets the chest, shoulders, and triceps.\n";
    std::cout << "Muscles Worked: Chest, Shoulders, Triceps\n";
    std::cout << "Equipment: Barbell\n";
    std::cout << "Procedure:\n";
    std::cout << "Lie on a bench with your feet flat on the floor.\n";
    std::cout << "Grasp the barbell with hands slightly wider than shoulder-width apart.\n";
    std::cout << "Lower the barbell to your chest, then press it back up to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 8-10 reps\n";
    std::cout << "Intermediate: 4 sets of 6-8 reps\n";
    std::cout << "Advanced: 5 sets of 5 reps\n\n";
}
else if (exerciseName == "Pull-Ups/Chin-Ups") {
    std::cout << "Exercise: Pull-Ups/Chin-Ups\n";
    std::cout << "Description: Effective for back and biceps development.\n";
    std::cout << "Muscles Worked: Back, Biceps\n";
    std::cout << "Equipment: Pull-Up Bar\n";
    std::cout << "Procedure:\n";
    std::cout << "Grasp the pull-up bar with an overhand grip for pull-ups or underhand grip for chin-ups.\n";
    std::cout << "Pull your body up until your chin is above the bar.\n";
    std::cout << "Lower your body back to the starting position in a controlled manner.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 4-6 reps\n";
    std::cout << "Intermediate: 4 sets of 6-8 reps\n";
    std::cout << "Advanced: 5 sets of 8-10 reps\n\n";
}
else if (exerciseName == "Shoulder Press") {
    std::cout << "Exercise: Shoulder Press\n";
    std::cout << "Description: Builds shoulder and upper body strength.\n";
    std::cout << "Muscles Worked: Shoulders, Triceps\n";
    std::cout << "Equipment: Barbell or Dumbbells\n";
    std::cout << "Procedure:\n";
    std::cout << "Stand with feet shoulder-width apart, holding the barbell or dumbbells at shoulder height.\n";
    std::cout << "Press the weight overhead until your arms are fully extended.\n";
    std::cout << "Lower the weight back to shoulder height.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 10-12 reps\n";
    std::cout << "Intermediate: 4 sets of 8-10 reps\n";
    std::cout << "Advanced: 5 sets of 6-8 reps\n\n";
}
else if (exerciseName == "Barbell Rows") {
    std::cout << "Exercise: Barbell Rows\n";
    std::cout << "Description: Targets the back muscles and helps in gaining upper body strength.\n";
    std::cout << "Muscles Worked: Back, Biceps\n";
    std::cout << "Equipment: Barbell\n";
    std::cout << "Procedure:\n";
    std::cout << "Stand with feet shoulder-width apart, holding the barbell with an overhand grip.\n";
    std::cout << "Bend at the hips and knees, keeping your back straight.\n";
    std::cout << "Pull the barbell towards your abdomen, squeezing your shoulder blades together.\n";
    std::cout << "Lower the barbell back to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 10-12 reps\n";
    std::cout << "Intermediate: 4 sets of 8-10 reps\n";
    std::cout << "Advanced: 5 sets of 6-8 reps\n\n";
}
else if (exerciseName == "Leg Press") {
    std::cout << "Exercise: Leg Press\n";
    std::cout << "Description: Complements squats for lower body strength.\n";
    std::cout << "Muscles Worked: Quadriceps, Hamstrings, Glutes\n";
    std::cout << "Equipment: Leg Press Machine\n";
    std::cout << "Procedure:\n";
    std::cout << "Sit on the leg press machine with feet shoulder-width apart on the platform.\n";
    std::cout << "Push the platform away by extending your legs.\n";
    std::cout << "Slowly bend your knees to return to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 12-15 reps\n";
    std::cout << "Intermediate: 4 sets of 10-12 reps\n";
    std::cout << "Advanced: 5 sets of 8-10 reps\n\n";
}
else if (exerciseName == "Rowing Machine") {
    std::cout << "Exercise: Rowing Machine\n";
    std::cout << "Description: Full-body workout that also builds endurance.\n";
    std::cout << "Procedure:\n";
    std::cout << "Sit on the rowing machine with feet secured on the footrests.\n";
    std::cout << "Grasp the handle with an overhand grip.\n";
    std::cout << "Push through your legs, then pull the handle towards your chest.\n";
    std::cout << "Return to the starting position in a controlled manner.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 5 times a week\n\n";
} else if (exerciseName == "Cycling") {
    std::cout << "Exercise: Cycling\n";
    std::cout << "Description: Low impact and good for cardiovascular health.\n";
    std::cout << "Procedure:\n";
    std::cout << "Adjust the bike seat to your height.\n";
    std::cout << "Pedal at a steady pace.\n";
    std::cout << "Maintain a consistent speed and resistance level.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 5 times a week\n\n";
} else if (exerciseName == "Swimming") {
    std::cout << "Exercise: Swimming\n";
    std::cout << "Description: Full-body exercise that is easy on the joints.\n";
    std::cout << "Procedure:\n";
    std::cout << "Choose a swimming stroke you are comfortable with.\n";
    std::cout << "Swim at a steady pace.\n";
    std::cout << "Focus on maintaining good form.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 2-3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 3-4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 4-5 times a week\n\n";
}
else{
	std::cout<<"please write the name of the exercise from the showing list.\n\n";
}
}
