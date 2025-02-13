#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

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

        void printData();
        void getData(int num);
        void searchStudent();


};


void Student::getData( int num)
{
    fstream fout;
    fout.open("StudentData.txt",ios::app | ios::out | ios::in);
    if(!fout)
    {
        cout<<"File failed to create!\n";
    }
    Student stud;
    int rollno;
    string name;
    string subjects[3] = {"Physics", "Chemistry", "Math"};
    double arr[3];
    

    for(int i = 0; i<num; i++)
    {
        cout<<"\nEnter the Rollno: ";
        cin>>rollno;
        cin.ignore();
        cout<<"\nEnter the name: ";
        getline(cin, name);
        for(int i=0; i<3; i++)
        {
            cout<<"\nEnter marks of "<<subjects[i]<<" : ";
            cin>>arr[i];
        }

        stud.setName(name);
        stud.setRollno(rollno);
        stud.setSubjects(arr);

        fout<<stud._rollno<<"\t"<<stud._name<<"\t\t\t"<<stud._subjects[0]<<"\t"<<stud._subjects[1]<<"\t"<<stud._subjects[2]<<endl;


        
    }
    fout.close();

}



void Student::printData()
{
    ifstream fin("StudentData.txt");
    if(!fin.is_open())
    {
        cerr<<"Error opening the file!";
    }
    string record;
    cout<<"Roll No"<<"\t"<<"Name"<<"\t\t\t"<<"Physics"<<"\t"<<"Chemistry"<<"\t"<<"Math\n";
    while(getline(fin, record))
    {
        cout<<record<<endl;
    }

    fin.close();
    

}

void Student::searchStudent()
{
    string rollno;
    cout<<"\nEnter the roll no: ";
    cin>>rollno;
    string line;
    fstream fin("StudentData.txt");

    if(!fin.is_open())
    {
        cout<<"Failed to Open the File!\n";
    }else{
        while(getline(fin,line))
        {
            stringstream ss(line);
            string word;
            while(ss>>word)
            {
                if(word == rollno)
                {
                    cout<<line<<endl;
                }
                break;
            }

        }
    }
    fin.close();
   
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
            student.getData(num);
            break;
        
        case 2:
            student.printData();
            break;
        case 3:
            student.searchStudent();
            break;
        default:
            puts("Invalid Choice");
        }
        cout<<"\n Do you want to continue y/n:";
        cin>>ch;

    }while(ch=='y');
    
    


    
    return 0;
}