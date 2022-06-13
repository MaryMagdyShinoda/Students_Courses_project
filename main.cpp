#include <iostream>
#include <iomanip>
using namespace std;

void gpa (double grades[5][3],string students_name [5])
{
    double avg, GPA;
    for (int r=0; r<5; r++)
    {
        double sum=0;
        for (int c=0; c<3; c++)
        {
            sum+=grades[r][c];
        }
        avg= sum/3;
        if (avg >=90)
            GPA=4;
        else if (avg >=80)
            GPA=3.5;
        else if (avg >=70)
            GPA=3;
        else if (avg >=60)
            GPA=2.5;
        else if (avg >=50)
            GPA=2;
        else if (avg <50)
            GPA=0;
        cout << students_name [r] <<" :: ";
        cout<< GPA <<endl;
        cout<<endl;
    }
}

void highest_grade (double grades[5][3],string students_name [5],string courses_name [3])
{
    int temp,i;
    for (int c=0; c<3; c++)
    {
        temp=grades[0][c];
        i=0;
        for (int r=1; r<5; r++)
        {
            if (temp<grades[r][c]){
                temp=grades[r][c];
                i=r;
            }
        }
        cout<< "student " << students_name[i] << " get the highest grade in " << courses_name[c] << " with degree " <<temp <<endl;
        cout<<endl;
    }
}

void lowest_grade (double grades[5][3],string students_name [5],string courses_name [3])
{
    int temp,i;
    for (int c=0; c<3; c++)
    {
        temp=grades[0][c];
        i=0;
        for (int r=1; r<5; r++)
        {
            if (temp>grades[r][c]){
                temp=grades[r][c];
                i=r;
            }
        }
        cout<< "student " << students_name[i] << " get the highest grade in " << courses_name[c] << " with degree " <<temp <<endl;
        cout<<endl;
    }
}

void avg_courses (double grades [5][3], string courses_name [3])
{
    double avg;
    for (int c=0; c<3; c++)
    {
        double sum=0;
        for (int r=0; r<5; r++)
        {
            sum+=grades[r][c];
        }
        avg= sum/5;
        cout << courses_name [c] <<" :: ";
        cout<< avg <<endl;
        cout<<endl;
    }
}

void print (double grades[5][3],string students_name [5],string courses_name [3])
{
    cout<< setw(10) << "student";
    for (int j=0; j<3; j++)
    {
        cout << setw(10) << courses_name [j];
    }
    cout<<endl<<endl;
    for (int r=0; r<5; r++)
    {
      cout << setw(10) << students_name [r];
      for (int c=0; c<3; c++)
      {
         cout<< setw(10) << grades [r][c];
      }
      cout<<endl<<endl;
    }
}

void print_courses_name (string courses_name [3])
{
    for (int j=0; j<3; j++)
    {
        cout << courses_name [j] <<endl;
        cout<<endl;
    }
}

void print_students_name (string students_name [5])
{
    for (int i=0; i<5; i++)
    {
        cout << students_name [i] <<endl;
        cout<<endl;
    }
}

void modify_grades (double grades[5][3],string students_name [5],string courses_name [3])
{
    string student,course;
    int grade,x,y;
    cout<<"enter student name" <<endl;
    cin>>student;
    cout<<"enter course name" <<endl;
    cin>>course;
    for (int r=0; r<5; r++)
    {
      if (student==students_name [r]){
        x=r;
        break;}
    }
    for (int c=0; c<3; c++)
    {
      if (course==courses_name[c]){
        y=c;
        break;}
    }
    cout<<"old grade is : " << grades[x][y] <<endl<<endl;
    cout<<"enter new grade" <<endl;
    cin>> grade;
    cout<<endl;
    grades[x][y]=grade;
    cout<<"new grade is : " << grades[x][y] <<endl;
}

void modify_courses (string courses_name [3])
{
    string course,new_course;
    int x;
    cout<<"enter course name" <<endl;
    cin>>course;
    for (int c=0; c<3; c++)
    {
        if (course==courses_name[c]){
            x=c;
            break;}
    }
    cout<<"course is : " << courses_name[x] <<endl<<endl;
    cout<<"enter new course" <<endl;
    cin>> new_course;
    cout<<endl;
    courses_name[x]=new_course;
    cout<<"new course is : " << courses_name[x] <<endl;
}

void sort_alphabetically (double grades[5][3],string students_name [5],string courses_name [3])
{
    double new_grades [52][3]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string new_student_name[52];
    char alphabetical [52]={'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z'};
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<52; j++)
        {
            if (students_name [i].at(0)==alphabetical [j])
            {
                new_student_name [j]= students_name [i];
                for (int c=0; c<3; c++)
                {
                    new_grades [j][c]=grades [i][c];
                }
                break;
            }
        }
    }
    cout<< setw(10) << "student";
    for (int x=0; x<3; x++)
    {
        cout << setw(10) << courses_name [x];
    }
    cout<<endl<<endl;
    for (int r=0; r<52; r++)
    {
        cout<< setw(10) << new_student_name [r];
        for (int c=0; c<3; c++)
      {
         if ( new_grades [r][c] !=0)
             cout<< setw(10) << new_grades [r][c];
      }
      cout<<endl;
    }
}

int main()
{
    int press;
    string students_name [5];
    string courses_name [3];
    double grades [5][3];
    do{
    for (int i=0; i<5; i++)
    {
        cout <<"enter student name"<<endl;
        cin >> students_name[i];
        cout<<endl;
    }
    for (int j=0; j<3; j++)
    {
        cout <<"enter courses name"<<endl;
        cin >> courses_name [j];
        cout<<endl;
    }
    for (int r=0; r<5; r++)
    {
        cout<<"enter grades of student :: "<< students_name[r] <<endl;
        for (int c=0; c<3; c++)
        {
            cout<<"grade of course : " <<courses_name [c] <<endl;
            cin >> grades [r][c];
            cout<<endl;
        }
    }
    cout<<"press (1) : to calculate the average GPA for each student" <<endl<<endl;
    cout<<"press (2) : to display the student with the highest grade in each course" <<endl<<endl;
    cout<<"press (3) : to display the student with the lowest grade in each course" <<endl<<endl;
    cout<<"press (4) : to Display the average grade in each course" <<endl<<endl;
    cout<<"press (5) : to Display table of students and their grades in all courses" <<endl<<endl;
    cout<<"press (6) : to Display Course names" <<endl<<endl;
    cout<<"press (7) : to Display students names" <<endl<<endl;
    cout<<"press (8) : to Modify a student’s grade in a course" <<endl<<endl;
    cout<<"press (9) : to Modify a course name" <<endl<<endl;
    cout<<"press (10) : to Sort the students alphabetically" <<endl<<endl;
    cin >> press;
    cout<<endl;
    if (press==1){
        cout<< "students and their GPA" <<endl;
        cout<<endl;
        gpa (grades,students_name);
    }
    else if (press==2){
        highest_grade (grades,students_name,courses_name);
    }
    else if (press==3){
        lowest_grade (grades,students_name,courses_name);
    }
    else if (press==4){
        cout<< "average grade in each course" <<endl;
        cout<<endl;
        avg_courses (grades,courses_name);
    }
    else if (press==5){
        print (grades,students_name,courses_name);
    }
    else if (press==6){
        print_courses_name (courses_name);
    }
    else if (press==7){
        print_students_name (students_name);
    }
    else if (press==8){
        modify_grades (grades,students_name,courses_name);
    }
    else if (press==9){
        modify_courses (courses_name);
    }
    else if (press==10){
        sort_alphabetically (grades,students_name,courses_name);
    }
    cout<<"if you want to continue enter (0)" <<endl;
    cin >>press;
    cout<<endl;
    } while (press==0);
    return 0;
}

