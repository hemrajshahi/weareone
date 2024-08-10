#include "Endomorph.h"
#include <iostream>

void Endomorph::characteristics() {
     std::cout << "The Endomorph Body Type" << std::endl;
            std::cout << "Characteristics:\n";
	    std::cout << "Build: Endomorphs tend to have a rounder, softer physique with wider hips and a broader waist." << std::endl;
        std::cout << "They may appear stockier and more solid." << std::endl;
        std::cout << "Muscle Development: They can gain muscle, but they also tend to store more fat." << std::endl;
        std::cout << "Building lean muscle can be a challenge due to their body’s propensity to store fat." << std::endl;
        std::cout << "Fat Storage: They have a slower metabolism, which means they gain weight easily, particularly around the midsection." << std::endl;
        std::cout << "Managing fat requires more effort and discipline." << std::endl;
        std::cout << "Metabolism: Their metabolism is slower, which can make it harder to lose fat and requires careful management of caloric intake." << std::endl;

}

void Endomorph::nutrientsAndDiet() {
std::cout << "Endomorph" << std::endl;
    std::cout << "Nutritional Goals:" << std::endl;
    std::cout << "Reduce overall caloric intake to lose fat" << std::endl;
    std::cout << "Increase protein intake to build lean muscle mass" << std::endl;
    std::cout << "Focus on a balanced diet with controlled carbohydrate intake" << std::endl;

    std::cout << "Recommended Diet:" << std::endl;
    std::cout << "Protein:" << std::endl;
    std::cout << "Chicken, Fish, Turkey, Eggs, Almonds" << std::endl;
    std::cout << "Dairy:" << std::endl;
    std::cout << "Milk, Yogurt" << std::endl;
    std::cout << "Whole Grains:" << std::endl;
    std::cout << "Quinoa, Brown Rice" << std::endl;
    std::cout << "Vegetables:" << std::endl;
    std::cout << "Broccoli, Cauliflower, Sweet Potato, Beans, Zucchini" << std::endl;
    std::cout << "Fruits:" << std::endl;
    std::cout << "Pear, Oranges, Berries" << std::endl;

    std::cout << "Tips:" << std::endl;
    std::cout << "Follow a high-protein, low-calorie diet to support fat loss and muscle gain." << std::endl;
    std::cout << "Aim for just over 1 gram of protein per pound of body weight." << std::endl;
    std::cout << "Balance the remaining calorie intake between fats and carbohydrates." << std::endl;
    std::cout << "Consider intermittent fasting to control calorie intake." << std::endl;
    std::cout << "Avoid processed junk foods and focus on whole foods." << std::endl;
    std::cout << "Stay hydrated with water, black coffee, or tea." << std::endl;
    std::cout << "Limit carbohydrate intake to prevent excessive calorie consumption." << std::endl;

}
void Endomorph::exercises() {
 std::cout << "Endomorph" << std::endl;
    std::cout << "Endomorphs generally have a higher body fat percentage and may struggle with weight management." << std::endl;
    std::cout << "Their exercise routines focus on fat loss and muscle maintenance." << std::endl;

    std::cout << "Strength Training:" << std::endl;
    std::cout << "1. Bench Press: Essential for upper body strength." << std::endl;
    std::cout << "2. Squats: Builds lower body strength and power." << std::endl;
    std::cout << "3. Deadlifts: Overall body strength and muscle growth." << std::endl;
    std::cout << "4. Lat Pulldowns: Targets the back muscles." << std::endl;
    std::cout << "5. Leg Press: Strengthens the lower body." << std::endl;
    std::cout << "6. Dumbbell Press: Versatile for upper body workouts." << std::endl;
    std::cout << "7. Kettlebell Swings: Full-body exercise that also boosts cardio." << std::endl;

    std::cout << "Cardio:" << std::endl;
    std::cout << "1. Walking/Jogging: Easy to start and effective for weight loss." << std::endl;
    std::cout << "2. Cycling: Low-impact and great for burning calories." << std::endl;
    std::cout << "3. Swimming: Full-body workout that is gentle on joints." << std::endl;
    std::cout << "4. Elliptical Trainer: Effective for cardiovascular health and fat loss." <<std::endl;
    std::cout << "5. Rowing Machine: Full-body exercise that burns calories." <<std::endl;
}

void Endomorph::showExerciseDetails(const std::string &exerciseName) const {
	if (exerciseName == "Bench Press") {
    std::cout << "Exercise: Bench Press\n";
    std::cout << "Description: Essential for upper body strength.\n";
    std::cout << "Muscles Worked: Chest, Shoulders, Triceps\n";
    std::cout << "Equipment: Barbell\n";
    std::cout << "Procedure:\n";
    std::cout << "Lie on a bench with your feet flat on the floor.\n";
    std::cout << "Grasp the barbell with hands slightly wider than shoulder-width apart.\n";
    std::cout << "Lower the barbell to your chest, then press it back up to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 8-10 reps\n";
    std::cout << "Intermediate: 4 sets of 6-8 reps\n";
    std::cout << "Advanced: 5 sets of 5 reps\n";
} else if (exerciseName == "Squats") {
    std::cout << "Exercise: Squats\n";
    std::cout << "Description: Builds lower body strength and power.\n";
    std::cout << "Muscles Worked: Quadriceps, Hamstrings, Glutes\n";
    std::cout << "Equipment: Barbell\n";
    std::cout << "Procedure:\n";
    std::cout << "Stand with feet shoulder-width apart, barbell resting on your upper back.\n";
    std::cout << "Lower your body by bending your knees and hips, keeping your back straight.\n";
    std::cout << "Descend until your thighs are parallel to the ground.\n";
    std::cout << "Push through your heels to return to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 10-12 reps\n";
    std::cout << "Intermediate: 4 sets of 8-10 reps\n";
    std::cout << "Advanced: 5 sets of 6-8 reps\n";
} else if (exerciseName == "Deadlifts") {
    std::cout << "Exercise: Deadlifts\n";
    std::cout << "Description: Overall body strength and muscle growth.\n";
    std::cout << "Muscles Worked: Back, Legs, Core\n";
    std::cout << "Equipment: Barbell\n";
    std::cout << "Procedure:\n";
    std::cout << "Stand with your feet hip-width apart, barbell in front.\n";
    std::cout << "Bend at your hips and knees to lower your body and grasp the barbell with an overhand grip.\n";
    std::cout << "Lift the barbell by extending your hips and knees to full extension.\n";
    std::cout << "Lower the barbell back to the ground in a controlled manner.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 8-10 reps\n";
    std::cout << "Intermediate: 4 sets of 6-8 reps\n";
    std::cout << "Advanced: 5 sets of 5 reps\n";
}
else if (exerciseName == "Overhead Press") {
    std::cout << "Exercise: Overhead Press\n";
    std::cout << "Description: Strengthens shoulders and upper body.\n";
    std::cout << "Muscles Worked: Shoulders, Triceps\n";
    std::cout << "Equipment: Barbell or Dumbbells\n";
    std::cout << "Procedure:\n";
    std::cout << "Stand with feet shoulder-width apart, holding the barbell or dumbbells at shoulder height.\n";
    std::cout << "Press the weight overhead until your arms are fully extended.\n";
    std::cout << "Lower the weight back to shoulder height.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 10-12 reps\n";
    std::cout << "Intermediate: 4 sets of 8-10 reps\n";
    std::cout << "Advanced: 5 sets of 6-8 reps\n";
} else if (exerciseName == "Pull-Ups/Chin-Ups") {
    std::cout << "Exercise: Pull-Ups/Chin-Ups\n";
    std::cout << "Description: Effective for back and biceps.\n";
    std::cout << "Muscles Worked: Back, Biceps\n";
    std::cout << "Equipment: Pull-Up Bar\n";
    std::cout << "Procedure:\n";
    std::cout << "Grasp the pull-up bar with an overhand grip for pull-ups or underhand grip for chin-ups.\n";
    std::cout << "Pull your body up until your chin is above the bar.\n";
    std::cout << "Lower your body back to the starting position in a controlled manner.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 4-6 reps\n";
    std::cout << "Intermediate: 4 sets of 6-8 reps\n";
    std::cout << "Advanced: 5 sets of 8-10 reps\n";
} else if (exerciseName == "Dumbbell Rows") {
    std::cout << "Exercise: Dumbbell Rows\n";
    std::cout << "Description: Builds back strength and muscle definition.\n";
    std::cout << "Muscles Worked: Back, Biceps\n";
    std::cout << "Equipment: Dumbbells\n";
    std::cout << "Procedure:\n";
    std::cout << "Place one knee and one hand on a bench for support, holding a dumbbell in the opposite hand.\n";
    std::cout << "Pull the dumbbell towards your hip while squeezing your shoulder blade.\n";
    std::cout << "Lower the dumbbell back to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 10-12 reps\n";
    std::cout << "Intermediate: 4 sets of 8-10 reps\n";
    std::cout << "Advanced: 5 sets of 6-8 reps\n";
} else if (exerciseName == "Leg Curls") {
    std::cout << "Exercise: Leg Curls\n";
    std::cout << "Description: Targets the hamstrings.\n";
    std::cout << "Muscles Worked: Hamstrings\n";
    std::cout << "Equipment: Leg Curl Machine\n";
    std::cout << "Procedure:\n";
    std::cout << "Sit on the leg curl machine with your legs positioned under the pad.\n";
    std::cout << "Curl your legs towards your glutes.\n";
    std::cout << "Slowly lower your legs back to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 12-15 reps\n";
    std::cout << "Intermediate: 4 sets of 10-12 reps\n";
    std::cout << "Advanced: 5 sets of 8-10 reps\n";
}
else if (exerciseName == "High-Intensity Interval Training (HIIT)") {
    std::cout << "Workout: High-Intensity Interval Training (HIIT)\n";
    std::cout << "Description: Effective for burning fat and maintaining muscle.\n";
    std::cout << "Procedure:\n";
    std::cout << "Alternate between short bursts of intense exercise and periods of rest or low-intensity exercise.\n";
    std::cout << "Example: 30 seconds of sprinting followed by 30 seconds of walking.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 15-20 minutes, 3 times a week\n";
    std::cout << "Intermediate: 20-30 minutes, 4 times a week\n";
    std::cout << "Advanced: 30-40 minutes, 5 times a week\n";
} else if (exerciseName == "Running") {
    std::cout << "Workout: Running\n";
    std::cout << "Description: Improves cardiovascular health and endurance.\n";
    std::cout << "Procedure:\n";
    std::cout << "Run at a steady pace, focusing on maintaining good form.\n";
    std::cout << "Increase duration and intensity gradually.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 5 times a week\n";
} else if (exerciseName == "Jump Rope") {
    std::cout << "Workout: Jump Rope\n";
    std::cout << "Description: Great for quick cardio sessions and coordination.\n";
    std::cout << "Procedure:\n";
    std::cout << "Jump rope at a steady pace, keeping your jumps small and quick.\n";
    std::cout << "Focus on timing and rhythm.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 5 minutes, 3 times a week\n";
    std::cout << "Intermediate: 10 minutes, 4 times a week\n";
    std::cout << "Advanced: 15 minutes, 5 times a week\n";
}
else {
	std::cout<<"please write the name of the exercise from the showing list\n\n";
}
}
