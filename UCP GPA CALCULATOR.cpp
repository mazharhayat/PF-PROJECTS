#include<iostream>
using namespace std;
void calculate_GPA()
{
    float sum_of_credits = 0, credit_and_points_sum = 0, multiply = 0, GPA = 0, per_subject_gpa = 0,lost_credits=0,earned_credits=0;
    int size = 0, k = 0;
    cout << "\n\n\t\t\t\t\t**********GPA CALCULATING**********\n\n";
    cout << "\n\nHow many subject's GPA do you want to calculate : ";
    cin >> size;
    cout << endl << endl;
    char grade[2] = { '\0' };
    float* credits = new float[size];
    for (int i = 0; i < size; i++)
    {
        system("CLS");
        k = 0;
        cout << "Enter credits for the subject " << i + 1 << " : ";
        cin >> credits[i];
        sum_of_credits = sum_of_credits + credits[i];
        cout << endl;
        while (k == 0)
        {
            cout << "Enter the GRADE of subject  " << i + 1 << " : ";
            cin >> grade;
            cout << "\n|-----------------------------------|\n";

            if (grade[0] == 'A' && grade[1] == '-' || grade[0] == '-' && grade[1] == 'A' || grade[0] == 'a' && grade[1] == '-' || grade[0] == '-' && grade[1] == 'a')
            {
                per_subject_gpa = 3.67;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }
            else if (grade[0] == 'B' && grade[1] == '+' || grade[0] == '+' && grade[1] == 'B' || grade[0] == 'b' && grade[1] == '+' || grade[0] == '+' && grade[1] == 'b')
            {
                per_subject_gpa = 3.33;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }

            else if (grade[0] == 'B' && grade[1] == '-' || grade[0] == '-' && grade[1] == 'B' || grade[0] == 'b' && grade[1] == '-' || grade[0] == '-' && grade[1] == 'b')
            {
                per_subject_gpa = 2.67;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }
            else if (grade[0] == 'C' && grade[1] == '+' || grade[0] == '+' && grade[1] == 'C' || grade[0] == 'c' && grade[1] == '+' || grade[0] == '+' && grade[1] == 'c')
            {
                per_subject_gpa = 2.33;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }

            else if (grade[0] == 'C' && grade[1] == '-' || grade[0] == '-' && grade[1] == 'C' || grade[0] == 'c' && grade[1] == '-' || grade[0] == '-' && grade[1] == 'c')
            {
                per_subject_gpa = 1.67;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }
            else if (grade[0] == 'D' && grade[1] == '+' || grade[0] == '+' && grade[1] == 'D' || grade[0] == 'd' && grade[1] == '+' || grade[0] == '+' && grade[1] == 'd')
            {
                per_subject_gpa = 1.33;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }

            else if (grade[0] == 'F' || grade[0] == 'f')
            {
            	lost_credits=lost_credits+credits[i];
                per_subject_gpa = 0;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }
            else if (grade[0] == 'A' && grade[1] == '\0' || grade[0] == 'a' && grade[1] == '\0')
            {
                per_subject_gpa = 4.0;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }
            else if (grade[0] == 'B' && grade[1] == '\0' || grade[0] == 'b' && grade[1] == '\0')
            {
                per_subject_gpa = 3.0;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }
            else if (grade[0] == 'C' && grade[1] == '\0' || grade[0] == 'c' && grade[1] == '\0')
            {
                per_subject_gpa = 2.0;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }
            else if (grade[0] == 'D' && grade[1] == '\0' || grade[0] == 'd' && grade[1] == '\0')
            {
                per_subject_gpa = 1.0;
                multiply = per_subject_gpa * credits[i];
                credit_and_points_sum = credit_and_points_sum + multiply;
                k = 1;
            }
            else
            {
                cout << "Invalid Input\nRe-";
            }
            for (int j = 0; grade[j] != '\0'; j++)
            {
                grade[j] = '\0';
            }
        }


    }
    earned_credits=sum_of_credits-lost_credits;
    GPA = credit_and_points_sum / sum_of_credits;
    cout << "\n\n|---------------------------|\n      TOTAL CREDITS : " << sum_of_credits;
    cout << "\n|---------------------------|\n      EARNED CREDITS : " << earned_credits;
    cout << "\n|---------------------------|\n      LOST CREDITS : " << lost_credits;
    cout << "\n|---------------------------|\n      TOTAL POINTS : " << credit_and_points_sum;
    cout << "\n|---------------------------|\n      TOTAL GPA : " << GPA;
    cout << "\n|---------------------------|\n\n";
    

   
}
void calculate_CGPA()
{
    float CGPA = 0, sum_of_GPA = 0;
    int total_semesters = 0;
    cout << "\n\n\t\t\t\t\t**********CGPA CALCULATING**********\n\n";
    cout << "How many Smesters CPGA do you want to calculate : ";
    cin >> total_semesters;
    float *semesters_GPA = new float[total_semesters];
    for (int i = 0; i < total_semesters; i++)
    {
        system("cls");
        cout << "Enter Semester " << i + 1 << "'s GPA : ";
        cin >> semesters_GPA[i];
        sum_of_GPA = sum_of_GPA + semesters_GPA[i];
    }
    CGPA = sum_of_GPA / total_semesters;
    cout << "\n\n|----------------------------------|\n";
    cout << "      CGPA OF " << total_semesters << " SEMESTERS : " << CGPA;
    cout << "\n|----------------------------------|\n\n";
    

   
}
int main()
{
    int j = 1;
   
    
    while (j == 1)
    {
        system("CLS");
        cout << "***/------------------------------------------------------------------------------------/***" << endl;
        cout << "                    UCP GPA & CGPA Calculator (Developed by MAZHAR HAYAT L1F20BSSE0460)             " << endl;
        cout << "***/------------------------------------------------------------------------------------/***\n" << endl;
        cout << "            MENU : " << endl;
        cout << "                   1.  Calculate GPA (Grade Point Average)" << endl;
        cout << "                   2.  Calculate CGPA (Cummulative Grade Point Average)" << endl;
        cout << "                   3.  Exit Application" << endl;
        cout << "\n***___/------------------------------------------------------------------------------/___***" << endl<<endl<<endl;
        int choice = 0;
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice > 0 && choice < 4)
        {
            int m = 1;
           
            if (choice == 1)
            {

                calculate_GPA();
                while (m == 1)
                {

                    cout << "\n\n1.To calculate again GPA\n";
                    cout << "2.To go back Main Menu\n";
                    cout << "Enter your choice : ";
                    cin>>choice;
                    if (choice > 0 && choice < 3)
                    {
                        if (choice == 1)
                        {
                            calculate_GPA();
                        }
                        else if (choice == 2)
                        {
                            cout << "\n<<<<<WELCOME BACK TO MAIN MENU>>>>>\n\n";
                            m = 0;
                        }
                    }
                    else
                    {
                        cout << "Invalid Choice!!! Re-Enter your choice...\n";
                    }
                }
                
            }
            else if (choice == 2)
            {
                int h = 1;
                calculate_CGPA();
                while (h== 1)
                {

                    cout << "\n\n1.To calculate again CGPA\n";
                    cout << "2.To go back Main Menu\n";
                    cout << "Enter your choice : ";
                    cin >> choice;
                    if (choice > 0 && choice < 3)
                    {
                        if (choice == 1)
                        {
                            calculate_CGPA();
                        }
                        else if (choice == 2)
                        {
                            cout << "\n<<<<<WELCOME BACK TO MAIN MENU>>>>>\n\n";
                            h = 0;
                        }
                    }
                    else
                    {
                        cout << "Invalid Choice!!! Re-Enter your choice...\n";
                    }
                }
            }
            else if (choice == 3)
            {
                cout << "you have been exit Successfully!\n";
                j = 0;

            }

        }
        else
        {
            cout << "Invalid choice\nRe-select one of the following!\n";
        }
        system("pause");
    }



   
	return 0;
}
