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
        std::cout << "Description: Builds overall body strength and muscle mass.\n";
        std::cout << "Muscles Worked: Back, Glutes, Hamstrings\n";
        std::cout << "Equipment: Barbell\n";
        std::cout << "Procedure:\n";
        std::cout << "Stand with feet hip-width apart, barbell in front of you.\n";
        std::cout << "Bend at the hips and knees to grip the barbell with both hands.\n";
        std::cout << "Lift the bar by straightening your back and legs, keeping the bar close to your body.\n";
        std::cout << "Lower the bar back to the ground with control.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 3 sets of 6-8 reps\n";
        std::cout << "Intermediate: 4 sets of 5-7 reps\n";
        std::cout << "Advanced: 5 sets of 4-6 reps\n";
    } else if (exerciseName == "Lat Pulldowns") {
        std::cout << "Exercise: Lat Pulldowns\n";
        std::cout << "Description: Targets the back muscles.\n";
        std::cout << "Muscles Worked: Latissimus Dorsi, Biceps\n";
        std::cout << "Equipment: Lat Pulldown Machine\n";
        std::cout << "Procedure:\n";
        std::cout << "Sit at the lat pulldown machine and grasp the bar with a wide grip.\n";
        std::cout << "Pull the bar down towards your chest, squeezing your shoulder blades together.\n";
        std::cout << "Slowly return the bar to the starting position.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 3 sets of 10-12 reps\n";
        std::cout << "Intermediate: 4 sets of 8-10 reps\n";
        std::cout << "Advanced: 5 sets of 6-8 reps\n";
    } else if (exerciseName == "Leg Press") {
        std::cout << "Exercise: Leg Press\n";
        std::cout << "Description: Strengthens the lower body.\n";
        std::cout << "Muscles Worked: Quadriceps, Hamstrings, Glutes\n";
        std::cout << "Equipment: Leg Press Machine\n";
        std::cout << "Procedure:\n";
        std::cout << "Sit in the leg press machine with feet shoulder-width apart on the platform.\n";
        std::cout << "Push the platform away from you by extending your legs, without locking your knees.\n";
        std::cout << "Slowly return to the starting position.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 3 sets of 10-12 reps\n";
        std::cout << "Intermediate: 4 sets of 8-10 reps\n";
        std::cout << "Advanced: 5 sets of 6-8 reps\n";
    } else if (exerciseName == "Dumbbell Press") {
        std::cout << "Exercise: Dumbbell Press\n";
        std::cout << "Description: Versatile for upper body workouts.\n";
        std::cout << "Muscles Worked: Chest, Shoulders, Triceps\n";
        std::cout << "Equipment: Dumbbells\n";
        std::cout << "Procedure:\n";
        std::cout << "Lie on a bench with a dumbbell in each hand, arms extended above your chest.\n";
        std::cout << "Lower the dumbbells to the sides of your chest, keeping elbows slightly bent.\n";
        std::cout << "Press the dumbbells back up to the starting position.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 3 sets of 8-10 reps\n";
        std::cout << "Intermediate: 4 sets of 6-8 reps\n";
        std::cout << "Advanced: 5 sets of 5 reps\n";
    } else if (exerciseName == "Kettlebell Swings") {
        std::cout << "Exercise: Kettlebell Swings\n";
        std::cout << "Description: Full-body exercise that also boosts cardio.\n";
        std::cout << "Muscles Worked: Glutes, Hamstrings, Shoulders\n";
        std::cout << "Equipment: Kettlebell\n";
        std::cout << "Procedure:\n";
        std::cout << "Stand with feet shoulder-width apart, holding the kettlebell with both hands.\n";
        std::cout << "Bend your knees slightly and swing the kettlebell between your legs.\n";
        std::cout << "Explosively drive your hips forward to swing the kettlebell up to shoulder height.\n";
        std::cout << "Control the descent of the kettlebell back between your legs and repeat.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 3 sets of 15 reps\n";
        std::cout << "Intermediate: 4 sets of 12 reps\n";
        std::cout << "Advanced: 5 sets of 10 reps\n";
    } else if (exerciseName == "Walking/Jogging") {
        std::cout << "Exercise: Walking/Jogging\n";
        std::cout << "Description: Easy to start and effective for weight loss.\n";
        std::cout << "Muscles Worked: Legs, Core\n";
        std::cout << "Equipment: None\n";
        std::cout << "Procedure:\n";
        std::cout << "Begin with a warm-up walk for 5-10 minutes.\n";
        std::cout << "Gradually increase your pace to a brisk walk or light jog.\n";
        std::cout << "Maintain the pace for the desired time, then cool down with a slower walk.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 20-30 minutes\n";
        std::cout << "Intermediate: 30-45 minutes\n";
        std::cout << "Advanced: 45-60 minutes\n";
    } else if (exerciseName == "Cycling") {
        std::cout << "Exercise: Cycling\n";
        std::cout << "Description: Low-impact and great for burning calories.\n";
        std::cout << "Muscles Worked: Legs, Glutes, Core\n";
        std::cout << "Equipment: Bicycle\n";
        std::cout << "Procedure:\n";
        std::cout << "Start with a 5-10 minute warm-up at a low resistance.\n";
        std::cout << "Gradually increase your speed or resistance.\n";
        std::cout << "Cycle at a steady pace for the desired time, then cool down at a low resistance.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 20-30 minutes\n";
        std::cout << "Intermediate: 30-45 minutes\n";
        std::cout << "Advanced: 45-60 minutes\n";
    } else if (exerciseName == "Swimming") {
        std::cout << "Exercise: Swimming\n";
        std::cout << "Description: Full-body workout that is gentle on joints.\n";
        std::cout << "Muscles Worked: Full Body\n";
        std::cout << "Equipment: Pool\n";
        std::cout << "Procedure:\n";
        std::cout << "Warm up with a few easy laps.\n";
        std::cout << "Increase your speed and distance based on your fitness level.\n";
        std::cout << "Incorporate different strokes to target various muscle groups.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 20-30 minutes\n";
        std::cout << "Intermediate: 30-45 minutes\n";
        std::cout << "Advanced: 45-60 minutes\n";
    } else if (exerciseName == "Elliptical Trainer") {
        std::cout << "Exercise: Elliptical Trainer\n";
        std::cout << "Description: Effective for cardiovascular health and fat loss.\n";
        std::cout << "Muscles Worked: Legs, Core, Arms\n";
        std::cout << "Equipment: Elliptical Trainer\n";
        std::cout << "Procedure:\n";
        std::cout << "Start with a warm-up at a low resistance.\n";
        std::cout << "Increase the resistance and speed to a moderate level.\n";
        std::cout << "Maintain the pace for the desired time, then cool down at a low resistance.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 20-30 minutes\n";
        std::cout << "Intermediate: 30-45 minutes\n";
        std::cout << "Advanced: 45-60 minutes\n";
    } else if (exerciseName == "Rowing Machine") {
        std::cout << "Exercise: Rowing Machine\n";
        std::cout << "Description: Full-body exercise that burns calories.\n";
        std::cout << "Muscles Worked: Back, Legs, Core\n";
        std::cout << "Equipment: Rowing Machine\n";
        std::cout << "Procedure:\n";
        std::cout << "Start with a 5-minute warm-up at a low resistance.\n";
        std::cout << "Increase the resistance and row at a steady pace.\n";
        std::cout << "Maintain good posture, driving through your legs and pulling with your arms.\n";
        std::cout << "Cool down with a few minutes of easy rowing.\n";
        std::cout << "Repetitions:\n";
        std::cout << "Beginner: 20 minutes\n";
        std::cout << "Intermediate: 30 minutes\n";
        std::cout << "Advanced: 45 minutes\n";
    }
else {
	std::cout<<"please write the name of the exercise from the showing list\n\n";
}
}
