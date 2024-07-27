#include "Mesomorph.h"
#include <iostream>

void Mesomorph::characteristics() {
    std::cout << "The Mesomorph Body Type" << std::endl;
            std::cout << "Characteristics:\n";
std::cout << "Build: Mesomorphs have a naturally muscular and athletic physique." << std::endl;
        std::cout << "They often have broad shoulders, a narrow waist, and a well-defined muscular structure." << std::endl;
        std::cout << "Muscle Development: They gain muscle relatively easily and have a good muscle definition." << std::endl;
        std::cout << "Their body responds well to both resistance training and physical activity." << std::endl;
        std::cout << "Fat Storage: Mesomorphs can gain fat but are also able to lose it effectively." << std::endl;
        std::cout << "Their balanced metabolism allows them to manage their weight with moderate effort." << std::endl;
        std::cout << "Metabolism: Their metabolism is generally well-balanced, not too fast or slow." << std::endl;
        std::cout << "This allows for effective muscle gain and fat management." << std::endl;
}

void Mesomorph::nutrientsAndDiet() {
 std::cout << "Mesomorph" << std::endl;
    std::cout << "Nutritional Goals:" << std::endl;
    std::cout << "Maintain a balanced diet with sufficient protein intake" << std::endl;
    std::cout << "Adjust calorie and macronutrient intake based on specific fitness goals" << std::endl;

    std::cout << "Recommended Diet:" << std::endl;
    std::cout << "Protein:" << std::endl;
    std::cout << "Chicken,Fish, Eggs, Almonds, Sunflower seeds, Cashews" << std::endl;
    std::cout << "Dairy:" << std::endl;
    std::cout << "Milk, Yogurt, Cottage Cheese" << std::endl;
    std::cout << "Whole Grains:" << std::endl;
    std::cout << "Quinoa, Whole wheat bread, Oats, Brown Rice" << std::endl;
    std::cout << "Vegetables:" << std::endl;
    std::cout << "Broccoli, Lentils, Sweet Potato, Beans, Zucchini" << std::endl;
    std::cout << "Fruits:" << std::endl;
    std::cout << "Avocado, Oranges, Berries" << std::endl;

    std::cout << "Tips:" << std::endl;
    std::cout << "Follow a balanced diet that includes a variety of whole foods." << std::endl;
    std::cout << "Ensure adequate protein intake for muscle maintenance and growth." << std::endl;
    std::cout << "Adjust caloric intake based on activity level and fitness goals." << std::endl;
    std::cout << "Avoid excessive consumption of unhealthy foods." << std::endl;
    std::cout << "Incorporate both steady-state and high-intensity cardio exercises." << std::endl;

}

void Mesomorph::exercises() {
     std::cout << "Mesomorph" << std::endl;
    std::cout << "Mesomorphs have a naturally athletic build and can gain muscle and strength easily." << std::endl;
    std::cout << "Their exercise routine focuses on maintaining muscle mass and reducing body fat." << std::endl;

    std::cout << "Strength Training:" << std::endl;
    std::cout << "1. Bench Press: Essential for upper body strength." << std::endl;
    std::cout << "2. Squats: Builds lower body strength and power." << std::endl;
    std::cout << "3. Deadlifts: Overall body strength and muscle growth." << std::endl;
    std::cout << "4. Overhead Press: Strengthens shoulders and upper body." << std::endl;
    std::cout << "5. Pull-Ups/Chin-Ups: Effective for back and biceps." << std::endl;
    std::cout << "6. Dumbbell Rows: Builds back strength and muscle definition." << std::endl;
    std::cout << "7. Leg Curls: Targets the hamstrings." << std::endl;

    std::cout << "Cardio:" << std::endl;
    std::cout << "1. High-Intensity Interval Training (HIIT): Effective for burning fat and maintaining muscle." << std::endl;
    std::cout << "2. Running: Improves cardiovascular health and endurance." << std::endl;
    std::cout << "3. Jump Rope: Great for quick cardio sessions and coordination." << std::endl;
}

void Mesomorph::showExerciseDetails(const std::string &exerciseName) const {
if (exerciseName == "Deadlifts") {
    std::cout << "Exercise: Deadlifts\n";
    std::cout << "Description: Builds overall body strength and muscle mass.\n";
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
} else if (exerciseName == "Squats") {
    std::cout << "Exercise: Squats\n";
    std::cout << "Description: Essential for lower body strength.\n";
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
} else if (exerciseName == "Bench Press") {
    std::cout << "Exercise: Bench Press\n";
    std::cout << "Description: Upper body strength and muscle gain.\n";
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
} else if (exerciseName == "Lat Pulldowns") {
    std::cout << "Exercise: Lat Pulldowns\n";
    std::cout << "Description: Targets the back muscles.\n";
    std::cout << "Muscles Worked: Latissimus Dorsi, Biceps\n";
    std::cout << "Equipment: Lat Pulldown Machine\n";
    std::cout << "Procedure:\n";
    std::cout << "Sit at the lat pulldown machine and grasp the bar with a wide grip.\n";
    std::cout << "Pull the bar down to your chest while squeezing your shoulder blades together.\n";
    std::cout << "Slowly return the bar to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 10-12 reps\n";
    std::cout << "Intermediate: 4 sets of 8-10 reps\n";
    std::cout << "Advanced: 5 sets of 6-8 reps\n";
}
 else if (exerciseName == "Leg Press") {
    std::cout << "Exercise: Leg Press\n";
    std::cout << "Description: Strengthens the lower body.\n";
    std::cout << "Muscles Worked: Quadriceps, Hamstrings, Glutes\n";
    std::cout << "Equipment: Leg Press Machine\n";
    std::cout << "Procedure:\n";
    std::cout << "Sit on the leg press machine with feet shoulder-width apart on the platform.\n";
    std::cout << "Push the platform away by extending your legs.\n";
    std::cout << "Slowly bend your knees to return to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 12-15 reps\n";
    std::cout << "Intermediate: 4 sets of 10-12 reps\n";
    std::cout << "Advanced: 5 sets of 8-10 reps\n";
} else if (exerciseName == "Dumbbell Press") {
    std::cout << "Exercise: Dumbbell Press\n";
    std::cout << "Description: Versatile for upper body workouts.\n";
    std::cout << "Muscles Worked: Chest, Shoulders, Triceps\n";
    std::cout << "Equipment: Dumbbells\n";
    std::cout << "Procedure:\n";
    std::cout << "Lie on a bench with a dumbbell in each hand.\n";
    std::cout << "Press the dumbbells above your chest until your arms are fully extended.\n";
    std::cout << "Lower the dumbbells to the starting position.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 10-12 reps\n";
    std::cout << "Intermediate: 4 sets of 8-10 reps\n";
    std::cout << "Advanced: 5 sets of 6-8 reps\n";
} else if (exerciseName == "Kettlebell Swings") {
    std::cout << "Exercise: Kettlebell Swings\n";
    std::cout << "Description: Full-body exercise that also boosts cardio.\n";
    std::cout << "Muscles Worked: Glutes, Hamstrings, Core\n";
    std::cout << "Equipment: Kettlebell\n";
    std::cout << "Procedure:\n";
    std::cout << "Stand with feet hip-width apart, holding the kettlebell with both hands.\n";
    std::cout << "Bend at your hips and swing the kettlebell between your legs.\n";
    std::cout << "Thrust your hips forward to swing the kettlebell to shoulder height.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 3 sets of 15-20 reps\n";
    std::cout << "Intermediate: 4 sets of 12-15 reps\n";
    std::cout << "Advanced: 5 sets of 10-12 reps\n";
}
else if (exerciseName == "Walking/Jogging") {
    std::cout << "Exercise: Walking/Jogging\n";
    std::cout << "Description: Easy to start and effective for weight loss.\n";
    std::cout << "Procedure:\n";
    std::cout << "Walk or jog at a steady pace, focusing on maintaining good form.\n";
    std::cout << "Increase duration and intensity gradually.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 5 times a week\n";
} else if (exerciseName == "Cycling") {
    std::cout << "Exercise: Cycling\n";
    std::cout << "Description: Low-impact and great for burning calories.\n";
    std::cout << "Procedure:\n";
    std::cout << "Adjust the bike seat to your height.\n";
    std::cout << "Pedal at a steady pace.\n";
    std::cout << "Maintain a consistent speed and resistance level.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 5 times a week\n";
} else if (exerciseName == "Swimming") {
    std::cout << "Exercise: Swimming\n";
    std::cout << "Description: Full-body workout that is gentle on joints.\n";
    std::cout << "Procedure:\n";
    std::cout << "Choose a swimming stroke you are comfortable with.\n";
    std::cout << "Swim at a steady pace.\n";
    std::cout << "Focus on maintaining good form.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 2-3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 3-4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 4-5 times a week\n";
} else if (exerciseName == "Elliptical Trainer") {
    std::cout << "Exercise: Elliptical Trainer\n";
    std::cout << "Description: Effective for cardiovascular health and fat loss.\n";
    std::cout << "Procedure:\n";
    std::cout << "Set the resistance and incline according to your fitness level.\n";
    std::cout << "Maintain a steady pace, focusing on smooth movements.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 5 times a week\n";
} else if (exerciseName == "Rowing Machine") {
    std::cout << "Exercise: Rowing Machine\n";
    std::cout << "Description: Full-body exercise that burns calories.\n";
    std::cout << "Procedure:\n";
    std::cout << "Sit on the rowing machine with feet secured on the footrests.\n";
    std::cout << "Grasp the handle with an overhand grip.\n";
    std::cout << "Push through your legs, then pull the handle towards your chest.\n";
    std::cout << "Return to the starting position in a controlled manner.\n";
    std::cout << "Repetitions:\n";
    std::cout << "Beginner: 20-30 minutes, 3 times a week\n";
    std::cout << "Intermediate: 30-40 minutes, 4 times a week\n";
    std::cout << "Advanced: 40-60 minutes, 5 times a week\n";
}
else {
std::cout<<"please write the name of the exercise from the showing list.\n\n";
}
}
