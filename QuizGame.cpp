// date : 8-08-2021
// project : Quiz Game
// author : Priyanshi Agrawal
// co-author : Atharv Vani
#include <iostream>
#include <conio.h>
using namespace std;
int total_score = 0;         //final score
int no_of_correct_ans = 0;   //number of correct ans
int no_of_incorrect_ans = 0; //number of incorrect ans

class Questions
{
private:
    string ques, ans1, ans2, ans3, ans4;
    char correct_option, selected_option;
    int ques_score;

public:
    //setter function
    void set_values(string ques, string ans1, string ans2, string ans3, string ans4, char correct_option, int ques_score);

    //prints ques
    void print_question();
};
int main()
{
    // printing basic information
    cout << "\n--------------------------------------------------------------------------------------\n";
    cout << "\n--------------------------------------QUIZ TIME--------------------------------------\n";
    cout << "\n--------------------------------------------------------------------------------------\n";
    cout << "\t\t\tTOPIC : Basic Science";
    cout << "\nIMPORTANT INFORMATION : \n";
    cout << "1.Total number of questions are 10 each of 10 points\n";
    cout << "2.Negative marking of [-5] will be there for wrong answer\n";

    int age;
    string name;
    cout << "Enter your name : ";
    getline(cin, name);
    cout << "enter age : ";
    cin >> age;
    system("cls");
    cout << "\n--------------------------------------WELCOME "<<name<<"--------------------------------------\n";

    // cout << "\nWelcome " << name << " your age is " << age << endl;
    char confirm;
    cout << "Enter y/Y to start the Quiz : ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') //confirms the start of quiz else exit the program
    {
        system("cls");
    }
    else
    {
        return 0;
    }

    Questions ques[10]; //array of objects of class Questions

    // setting questions,options,correct options,point of ques
    ques[0].set_values("\tQ1.What is the PH of H2O?", "10", "3", "7", "5", 'C', 10);

    ques[1].set_values("\tQ2.Which of the following compound is mainly used in hand sanitizer?", "Aldehyde", "Acetic acid", "Alcohol", "Keton", 'C', 10);

    ques[2].set_values("\tQ3.What is the unit of wavelength?", "Hertz", "Diopter", "Faraday", "Meter", 'D', 10);

    ques[3].set_values("\tQ4.Name the metal which is most ductile?", "Gold", "Silver", "Copper", "Iron", 'A', 10);

    ques[4].set_values("\tQ5.Name the part of the body on which coronavirus affects the most?", "Heart", "Lungs", "Liver", "Brain", 'B', 10);

    ques[5].set_values("\tQ6.Which of the following diseases is caused by dog bites?", "Scurvy", "Madness", "Rabies", "Colorblindness", 'C', 10);

    ques[6].set_values("\tQ7.What is the S.I unit of lens power?", "Diopter", "Calorie", "Joule", "Hertz", 'A', 10);

    ques[7].set_values("\tQ8.What is the scientific name of humans?", "Mangifera indica", "Rana tigrina", "Homo sapiens", "Homo species", 'C', 10);

    ques[8].set_values("\tQ9. Name the metal which is easily cut by a simple knife?", "Sodium", "Lead", "Tin", "Mercury", 'A', 10);

    ques[9].set_values("\tQ10.What is the S.I unit of current?", "Volt", "Ampere", "Ohm", "Newton", 'B', 10);

    // asking ques and calculating current score
    for (int i = 0; i < 10; i++)
    {
        ques[i].print_question();
        cout << "\nHit ENTER to Continue..";
        getch();
        system("cls");
    }

    //showing result
    char ch;
    int total_ques_answered =no_of_correct_ans + no_of_incorrect_ans;

    cout << "\n\n--------------------------------------RESULT--------------------------------------\n";
    cout<<"\n\t\t\tNAME : "<<name<<"\n\t\t\tAGE : "<<age<<endl;
    cout << "\n--------------------------------------------------------------------------------------\n";
    cout << "\t\t\tTotal question attempted : " << total_ques_answered<<"/10" << endl;
    cout << "\t\t\tTotal correct questions : " << no_of_correct_ans<<"/"<<total_ques_answered << endl;
    cout << "\t\t\tTotal incorrect questions : " << no_of_incorrect_ans<<"/"<<total_ques_answered  << endl;
    cout << "\t\t\tTotal skipped questions : " << 10 - no_of_correct_ans - no_of_incorrect_ans <<"/10"<< endl;
    cout << "\n--------------------------------------------------------------------------------------\n";

    cout << "\t\t\tTOTAL SCORE : " << total_score << "/"  << "100" << endl;

    //cheking pass/fail condition
    if (total_score >= 50)
    {
        ch = 2; //ascii value for smile emoji
        cout << "Deabak! You got this quiz " << ch;
    }
    else
    {
        ch = 3; // ascii value for heart emoji
        cout<<"\nCut-off is of 50 points...\n";
        cout << "Alas! You lost this quiz..\nBetter Luck Next Time " << ch;
    }
    return 0;
}

void Questions::set_values(string ques, string ans1, string ans2, string ans3, string ans4, char correct_option, int ques_score)
{
    this->ques = ques;
    this->ans1 = ans1;
    this->ans2 = ans2;
    this->ans3 = ans3;
    this->ans4 = ans4;
    this->correct_option = correct_option;
    this->ques_score = ques_score;
}

void Questions::print_question()
{
    cout << ques << endl;
    cout << "\t\tA." << ans1 << endl;
    cout << "\t\tB." << ans2 << endl;
    cout << "\t\tC." << ans3 << endl;
    cout << "\t\tD." << ans4 << endl;

select_option_again: //goto label for incorrect option selection

    cout << "Please select [A/B/C/D] and [S/s] to skip the ques: ";
    cin >> selected_option;
    switch (selected_option)
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
        if (selected_option == correct_option || selected_option == correct_option + 32)
        {
            no_of_correct_ans++;
            cout << "\n\t\t******CORRECT******" << endl;
            total_score += 10;
            cout << "CURRENT SCORE : " << total_score << "/"
                 << "100" << endl;
        }
        else
        {
            no_of_incorrect_ans++;
            cout << "\n\t\t******WRONG******" << endl;
            cout << "correct option is " << correct_option << endl;
            cout << "5 points will be deducted.." << endl;
            total_score -= 5;
            cout << "CURRENT SCORE : " << total_score << "/"
                 << "100" << endl;
        }
        break;

    case 's':
    case 'S':
    cout<<"\nThis question has been SKIPPED..!!\n";
        break;
    default:
        cout << "\n Please enter correct code [A/B/C/D]...." << endl;
        goto select_option_again;
    }
}