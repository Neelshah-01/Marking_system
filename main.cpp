#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
/* t1 and t2 are of 20 marks
    Final Exam exam is of 80 marks*/
class Student
{

protected:
    vector<vector<string>> marks;
    int ph_no;
    string fname, name, mname, address;
    int roll_no;
    float per;
    string overall;
    friend class Test;
    friend class Result;
    friend class Storage;

public:
    Student()
    {
        address = mname = fname = name = "";
        per = roll_no = ph_no = 0;
    }
    Student(int roll, string n, string fn, string mn, int ph, string ad)
    {
        marks.push_back(vector<string>()); // making row for subject
        marks.push_back(vector<string>()); // making row for unit test 1 marks
        marks.push_back(vector<string>()); // making row for unit test 2 marks
        marks.push_back(vector<string>()); // making row for Final Exam marks
        marks.push_back(vector<string>()); // making row for Total marks
        marks.push_back(vector<string>()); // making row for grades
        for (size_t i = 1; i < marks.size(); i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                marks[i].push_back("0");
            }
        }
        marks[0].push_back("English       ");
        marks[0].push_back("Maths         ");
        marks[0].push_back("Science       ");
        marks[0].push_back("Computer      ");
        marks[0].push_back("Social Studies");
        roll_no = roll;
        ph_no = ph;
        name = n;
        fname = fn;
        mname = mn;
        address = ad;
    }
};

class Test : public Student
{
    int acad_yr;
    int tstMM = 20, fnlMM = 80;
    string classnm;

    void enterMarks(Student &t)
    {
        int mark;
        while (true)
        {
            cout << "Enter Marks obtained in English in test 1 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[1][0] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in English in test 2 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[2][0] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in English in Final Exam exam : ";
            cin >> mark;
            if (mark <= fnlMM)
            {
                t.marks[3][0] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }

        while (true)
        {
            cout << "Enter Marks obtained in Maths in test 1 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[1][1] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Maths in test 2 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[2][1] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Maths in Final Exam exam : ";
            cin >> mark;
            if (mark <= fnlMM)
            {
                t.marks[3][1] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }

        while (true)
        {
            cout << "Enter Marks obtained in Science in test 1 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[1][2] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Science in test 2 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[2][2] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Science in Final Exam exam : ";
            cin >> mark;
            if (mark <= fnlMM)
            {
                t.marks[3][2] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }

        while (true)
        {
            cout << "Enter Marks obtained in Computer in test 1 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[1][3] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Computer in test 2 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[2][3] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Computer in Final Exam exam : ";
            cin >> mark;
            if (mark <= fnlMM)
            {
                t.marks[3][3] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Social Studies in test 1 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[1][4] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Social Studies in test 2 : ";
            cin >> mark;
            if (mark <= tstMM)
            {
                t.marks[2][4] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
        while (true)
        {
            cout << "Enter Marks obtained in Social Studies in Final Exam exam : ";
            cin >> mark;
            if (mark <= fnlMM)
            {
                t.marks[3][4] = to_string(mark);
                break;
            }
            else
                cout << "Invalid Mark! Try again\n";
        }
    }

public:
    Test()
    {
    }
    Test(int yr, string cnm, Student &t)
    {
        acad_yr = yr;
        classnm = cnm;
        enterMarks(t);
    }
};

class Result : public Test
{
    void calcPer(Student &t)
    {
        float sum = 0;
        int eng = 0, mat = 0, sci = 0, soc = 0, comp = 0;

        eng += stoi(t.marks[1][0]) + stoi(t.marks[2][0]) + stoi(t.marks[3][0]);
        mat += stoi(t.marks[1][1]) + stoi(t.marks[2][1]) + stoi(t.marks[3][1]);
        sci += stoi(t.marks[1][2]) + stoi(t.marks[2][2]) + stoi(t.marks[3][2]);
        comp += stoi(t.marks[1][3]) + stoi(t.marks[2][3]) + stoi(t.marks[3][3]);
        soc += stoi(t.marks[1][4]) + stoi(t.marks[2][4]) + stoi(t.marks[3][4]);

        t.marks[4][0] = to_string(eng);
        t.marks[4][1] = to_string(mat);
        t.marks[4][2] = to_string(sci);
        t.marks[4][3] = to_string(comp);
        t.marks[4][4] = to_string(soc);

        sum = eng + mat + sci + soc + comp;
        t.per = (sum / 600.0) * 100;
    }

    void gradeAlloc(Student &t)
    {
        bool failed = false;
        for (size_t i = 0; i < 5; i++)
        {
            if (stoi(t.marks[4][i]) > 100 && stoi(t.marks[4][i]) <= 120)
                t.marks[5][i] = "A";
            else if (stoi(t.marks[4][i]) > 80 && stoi(t.marks[4][i]) <= 90)
                t.marks[5][i] = "B";
            else if (stoi(t.marks[4][i]) > 70 && stoi(t.marks[4][i]) <= 80)
                t.marks[5][i] = "C";
            else if (stoi(t.marks[4][i]) > 60 && stoi(t.marks[4][i]) <= 70)
                t.marks[5][i] = "D";
            else if (stoi(t.marks[4][i]) > 50 && stoi(t.marks[4][i]) <= 60)
                t.marks[5][i] = "E";
            else
            {
                t.marks[5][i] = "F";
                failed = true;
            }
        }
        if (!failed)
        {
            if (t.per >= 90)
                t.overall = "Passed with A Grade";
            else if (t.per >= 80 && t.per < 90)
                t.overall = "Passed with B Grade";
            else if (t.per >= 70 && t.per < 80)
                t.overall = "Passed with C Grade";
            else if (t.per >= 60 && t.per < 70)
                t.overall = "Passed with D Grade";
            else if (t.per >= 40 && t.per < 60)
                t.overall = "Passed with E Grade";
            else
                t.overall = "Promoted with F Grade";
        }
        else
            t.overall = "Failed";
    }

public:
    Result()
    {
    }
    Result(Student &t)
    {
        calcPer(t);
        gradeAlloc(t);
    }
};

class Storage : public Result
{
    map<int, Student> data;

public:
    void writeFile(Student &t)
    {
        Result o(t);
        fstream fio;
        string line, word;
        fio.open("storage.dat", ios::app | ios::out | ios::binary);
        fio << "Name : " << t.name << "\t\t\t"
            << "Father's Name : " << t.fname << "\t\t\t"
            << "Mother's Name : " << t.mname << "\n";
        fio << "Roll no : " << t.roll_no << "\t\t\t"
            << "Phone : " << t.ph_no << "\t\t\nAddress : " << t.address;

        fio << "\n\nMarks obtained : \n+---------------+----------+----------+----------+-------+\n|    Subject \t|  Test 1  |  Test 2  |  Finals  | Grade |\n";
        fio << "+---------------+----------+----------+----------+-------+\n";
        for (size_t j = 0; j < 5; j++)
        {
            fio << "| " << t.marks[0][j] << "|\t  " << t.marks[1][j] << "\t   |\t" << t.marks[2][j] << "\t  |\t  " << t.marks[3][j] << "\t     |\t" << t.marks[5][j] << "\t |\t\n";
            fio << "+---------------+----------+----------+----------+-------+\n";
        }
        int sum = 0;
        for (size_t h = 0; h < 5; h++)
        {
            sum += stoi(t.marks[4][h]);
        }

        fio << "Total marks obtained out of 600 : " << sum << "\t\t\t Percentage : " << t.per << "%";
        fio << "\nOverall Grade : " << t.overall;
        fio << "\n\n";
        fio.close();
    }
    Storage()
    {
        while (1)
        {
            string name, fname, mname, add1, add2, add3;
            int roll;
            long long int phone_num;
            cout << "\nEnter roll number: ";
            cin >> roll;
            cout << "Enter student's name: ";
            getline(cin >> ws, name);
            cout << "Enter student's father's name: ";
            getline(cin >> ws, fname);
            cout << "Enter student's mother's name: ";
            getline(cin >> ws, mname);
            cout << "Enter student's phone number: ";
            cin >> phone_num;
            cout << "Enter students address in 3 lines below\n";
            cin >> ws;
            getline(cin, add1);
            getline(cin, add2);
            getline(cin, add3);
            Student stu(roll, name, fname, mname, phone_num, add1 + ", " + add2 + ", " + add3);
            cout << "Enter academic year: ";
            cin >> roll;
            cout << "Enter class name: ";
            string c_name;
            getline(cin >> ws, c_name); // using old one instead of creating a new variable

            Test obj(roll, c_name, stu);
            data[roll] = stu;

            cout << "Do you want to add more students? (Y/n) ";
            char choice;
            cin >> choice; // using old one instead of creating a new variable
            if (!(choice == 'y' || choice == 'Y'))
                break;
        }
        for (auto it = data.begin(); it != data.end(); it++)
        {
            writeFile(it->second);
        }
    }
};
int main()
{
    FILE *fp;
    fp = fopen("storage.dat", "w"); // creates a file if it doesnt exist already
    fclose(fp);
    Storage obj;
    cout << "\nThank You\n";
    return 0;
}