#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

// Structure to hold a quiz question and its options
struct Question {
    string questionText;
    vector<string> options;
    int correctOption; // 0-based index of the correct answer

    // Constructor to initialize a question
    Question(string qText, vector<string> opts, int correct) {
        questionText = qText;
        options = opts;
        correctOption = correct;
    }
};

// Function to display a question and get the user's answer
int askQuestion(Question& q) {
    cout << q.questionText << "\n";
    for (int i = 0; i < q.options.size(); i++) {
        cout << i + 1 << ". " << q.options[i] << "\n";
    }

    int userAnswer;
    cout << "Enter your answer (1-" << q.options.size() << "): ";
    cin >> userAnswer;

    // Convert the user answer to 0-based index for comparison
    return userAnswer - 1;
}

// Function to run the quiz game
void runQuiz(vector<Question>& quiz) {
    int score = 0; // Initialize the user's score
    int totalQuestions = quiz.size();

    for (int i = 0; i < totalQuestions; i++) {
        cout << "\nQuestion " << i + 1 << ":\n";
        int userAnswer = askQuestion(quiz[i]);

        // Check if the user's answer is correct
        if (userAnswer == quiz[i].correctOption) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! The correct answer was: " 
                 << quiz[i].options[quiz[i].correctOption] << "\n";
        }
    }

    // Final score and feedback
    cout << "\nQuiz finished!\n";
    cout << "Your score: " << score << "/" << totalQuestions << "\n";

    // Feedback based on performance
    if (score == totalQuestions) {
        cout << "Excellent! You got all the answers right!\n";
    } else if (score >= totalQuestions / 2) {
        cout << "Good job! You got more than half correct.\n";
    } else {
        cout << "Keep trying! You can improve your score.\n";
    }
}

int main() {
    // Sample quiz questions
    vector<Question> quiz = {
        Question("What is the capital of France?",
                 {"Paris", "London", "Berlin", "Rome"}, 0),
        Question("Who developed the theory of relativity?",
                 {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}, 1),
        Question("Which planet is known as the Red Planet?",
                 {"Earth", "Mars", "Jupiter", "Venus"}, 1),
        Question("What is the largest ocean on Earth?",
                 {"Atlantic", "Indian", "Pacific", "Arctic"}, 2)
    };

    // Start the quiz game
    runQuiz(quiz);

    return 0;
}
