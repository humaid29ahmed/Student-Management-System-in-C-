#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<conio.h>
#include<fstream>

using namespace std;

class Student
{
    int _rollno;
    char _name[50];
    double _marks[3];

    public:
        Student()
        {
            _rollno = 0;
            strcpy(_name, "My Name");
            _marks[3] = {0.0};
        }

        void showStudentData()
        {
            cout<<"\n"<<_rollno<<" | "<<_name<<" | "<<_marks[0]<<" | "<<_marks[1]<<" | "<<_marks[2];
        }

        void getStudentData()
        {
            string subjects[3] = {"Physics", "Chemistry", "Math"};
            cout<<"Enter the rollno : ";
            cin>>_rollno;
            cout<<"\nEnter the Name :";
            cin.ignore();
            cin.getline(_name, 50);
            cout<<"\nEnter your marks : ";
            for(int i =0; i<3;i++)
            {
                cout<<"\nEnter the "<<subjects[i]<<" marks : ";
                cin>>_marks[i];
            }

        }

        void storeStudentRecord();
        void viewAllStudentsRecord();
        void searchStudentRecord(int);
        void getStudentPercentage(int);
        void deleteStudentRecord(int);
        void updateStudentRecord(int);

};

void Student::storeStudentRecord()
{
    ofstream fout;
    fout.open("Student.txt", ios::app);
    if(!fout)
    {
        cout<<"File failed to Open!";
    }
    else
    {
        fout.write((char*)this, sizeof(*this));
        fout.close();
    }
}

void Student::viewAllStudentsRecord()
{
    ifstream fin;
    fin.open("Student.txt");
    if(!fin)
    {
        cout<<"Failed to open the file";
    }
    else
    {
        while(fin.read((char*)this, sizeof(*this)))
        {
            showStudentData();
        }
        fin.close();
    }
}

void Student::searchStudentRecord(int rollno)
{
    ifstream fin;
    int flag =0;
    fin.open("Student.txt");
    if(!fin)
    {
        cout<<"Failed to open the file";
    }
    else
    {
        while(fin.read((char*)this, sizeof(*this)))
        {
            if(rollno == _rollno)
            {
                showStudentData();
                flag = 1;
            }
        }
        if(flag == 0)
        {
            cout<<"Record not Found"<<endl;
        }
        fin.close();
    }

}

void Student::getStudentPercentage(int rollno)
{
    ifstream fin;
    int flag =0;
    fin.open("Student.txt");
    if(!fin)
    {
        cout<<"Failed to open the file";
    }
    else
    {
        while(fin.read((char*)this, sizeof(*this)))
        {
            if(rollno == _rollno)
            {
                double percentage = (_marks[0] + _marks[1] + _marks[2])/3.0;
                cout<<"The percentage of "<<_name<<" : "<<percentage<<" %\n";
                if(percentage > 40.0)
                {
                    cout<<"Status: Pass\n";
                }
                else
                {
                    cout<<"Status: Fail\n";
                }
                flag = 1;
            }
        }
        if(flag == 0)
        {
            cout<<"Record not Found"<<endl;
        }
        fin.close();
    }

}

void Student::deleteStudentRecord(int rollno)
{
    ifstream fin;
    fin.open("Student.txt");

    if(!fin)
    {
        cout<<"File failed to open\n";
    }
    else
    {
        ofstream fout;
        fout.open("tempfile.txt");

        if(!fout)
        {
            cout<<"Temp File failed to open\n";
        }
        else
        {
            while(fin.read((char*)this, sizeof(*this)))
            {
                if(rollno != _rollno)
                {
                    fout.write((char*)this, sizeof(*this));
                }
            }
            fin.close();
            fout.close();
            remove("Student.txt");
            rename("tempfile.txt", "Student.txt");
        }
    }
}

void Student::updateStudentRecord(int rollno)
{
    fstream file;

    file.open("Student.txt", ios::in|ios::out);
    if(!file)
    {
        cout<<"File has failed to Open!";
    }
    else
    {
        while(file.read((char*)this, sizeof(*this)))
        {
            if(rollno == _rollno)
            {
                file.seekg(-sizeof(*this),ios::cur);
                getStudentData();
                file.write((char*)this, sizeof(*this));
                break;
            }
        }
        file.close();
    }

}
int menu()
{
    int choice;
    cout<<"\nPress 1 for Add the Student Record.";
    cout<<"\nPress 2 for Viewing the Student Records.";
    cout<<"\nPress 3 for Searching a Student Record.";
    cout<<"\nPress 4 for Deleting a Student Record.";
    cout<<"\nPress 5 for Updating a Student Record.";
    cout<<"\nPress 6 for gettting a Student Percentage and result.";
    cout<<"\nPress 7 for Exit.";
    cout<<"\nEnter your Choice: ";
    cin>>choice;
    return choice;
}
int main()
{
    Student stud;
    int rollno;
    while(1)
    {
        system("cls");
        switch(menu())
        {
            case 1:
                stud.getStudentData();
                stud.storeStudentRecord();
                cout<<"\nRecord has been Successfully Added.";
                cout<<"\nPress any key to Continue";
                getch();
            break;
            case 2:
                stud.viewAllStudentsRecord();
                cout<<"\nPress any key to Continue";
                getch();
            break;
            case 3:
                cout<<"\nEnter the Roll no : ";
                cin.ignore();
                cin>>rollno;
                stud.searchStudentRecord(rollno);
                cout<<"\nPress any key to Continue";
                getch();
            break;
            case 4:
                cout<<"\nEnter the Roll no : ";
                cin.ignore();
                cin>>rollno;
                stud.deleteStudentRecord(rollno);
                cout<<"\nRecord has been Sucessfully deleted.";
                cout<<"\nPress any key to Continue";
                getch();
            break;
            case 5:
                cout<<"\nEnter the Roll no : ";
                cin.ignore();
                cin>>rollno;
                stud.updateStudentRecord(rollno);
                cout<<"\nRecord has been Updated.";
                cout<<"\nPress any key to Continue";
                getch();
            break;
            case 6:
                cout<<"\nEnter the Roll no : ";
                cin.ignore();
                cin>>rollno;
                stud.getStudentPercentage(rollno);
                cout<<"\nPress any key to Continue";
                getch();
                break;
            case 7:
                cout<<"\nThanks for using the Student Management System.";
                cout<<"\nPress any key to exit.";
                getch();
                exit(0);
            break;
            default:
                cout<<"\nInvalid Choice.";
                cout<<"\nPress any key to Continue";
                getch();
            break;

        }
    }

    return 0;
}