#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Student
{
    int _rollno;
    string _name;
    double _subjects[3];
    public:
       
        Student()
        {
            _rollno = 0;
            _name = "abc";
            _subjects[3] = {0.0};
        }

        Student(const int& rollno, const string& name, double arr[3])
        {
            _rollno = rollno;
            _name = name;
            for(int i=0; i<3; i++)
            {
                _subjects[i] = arr[i];
            }
            
        }
        void setName(string name)
        {
           _name = name;
        }

        void setRollno(int rollno)
        {
            _rollno = rollno;
        }

        void setSubjects(double arr[])
        {
            for(int i=0; i<3; i++)
            {
                _subjects[i] = arr[i];
            }
        }

        void printData(vector<Student> s, int num);
        void getData(vector<Student> &s, int num);
        void searchStudent(vector<Student> s, int num);


};


void Student::getData(vector<Student> &s, int num)
{

    Student stud;
    int rollno;
    string name;
    string subjects[3] = {"Physics", "Chemistry", "Math"};
    double arr[3];
    

    for(int i = 0; i<num; i++)
    {
        cout<<"\nEnter the Rollno: ";
        cin>>rollno;
        cout<<"\nEnter the name: ";
        cin>>name;
        for(int i=0; i<3; i++)
        {
            cout<<"\nEnter marks of "<<subjects[i]<<" : ";
            cin>>arr[i];
        }

        stud.setName(name);
        stud.setRollno(rollno);
        stud.setSubjects(arr);
        s.push_back(stud);

        
    }

}



void Student::printData(vector<Student> s, int num)
{
    for(int i=0; i<num;i++)
    {
    cout<<"\nRoll no: "<<s[i]._rollno;
    cout<<"\nName :"<<s[i]._name;
    cout<<"\nMarks: ";
    for(int j=0; j<3; j++)
    {
        cout<<s[i]._subjects[j]<<" ";
    }
}
}

void Student::searchStudent(vector<Student> s, int num)
{
    int rollno;
    cout<<"\Enter the roll no: ";
    cin>>rollno;

    for(int i=0; i<num; i++)
    {
        if(s[i]._rollno == rollno)
        {
            cout<<"\nName   : "<<s[i]._name;
            cout<<"\nRoll no: "<<s[i]._rollno;
            cout<<"\nMarks   : "<<endl;
            cout<<"Physics     - "<<s[i]._subjects[0];
            cout<<"\nChemistry - "<<s[i]._subjects[1];
            cout<<"\nMath      - "<<s[i]._subjects[2];
        }else{
            cout<<"\nNo records!";
        }
    }
}

int main()
{
    Student student;
    int num;
    vector<Student> s;
    char ch = 'y';
    do{
        int choice;
        cout<<"\nPress 1 to Store Data.\nPress 2 to Print Data\nPress 3 to search a record.\n Enter your Choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"\nEnter the number of records to input: ";
            cin>>num;
            student.getData(s,num);
            break;
        
        case 2:
            student.printData(s,num);
            break;
        case 3:
            student.searchStudent(s,num);
            break;
        default:
            puts("Invalid Choice");
        }
        cout<<"\n Do you want to continue y/n:";
        cin>>ch;

    }while(ch=='y');
    
    


    
    return 0;
}