#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void createCSV()
{
    fstream fout;
    int n;
    fout.open("testing.csv", ios::out | ios::app);
    cout<<"Enter number of entries: ";
    cin>>n;
    cout << "Enter the details of"<<n<<"people:\n roll name C++ Java Python Javascript\n";
    int i, roll, C, Java, Python, Javascript;
    string name;

    for (i = 0; i < n; i++)
    {
        cin >> roll >> name >> Java >> C >> Python >> Javascript;

        fout << roll << ","
             << name << ","
             << Java << ","
             << C << ","
             << Python << ","
             << Javascript
             << "\n";
    }
}

//Halted because data needs some preprocessing like one hot encoding of interest/OS/TE columns
//which will make the process much easier

/*void readRecordAtIndexAndReturnGene(int index)
{
    fstream fin;
    fin.open("GAdataFromgForm.csv", ios::in);
    vector<string> row;
    string line,word,temp;
    while(fin>>temp)
    {
        row.clear();
        line=temp;
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }

    }
}*/

void read_record()
{
    fstream fin;

    fin.open("testing.csv", ios::in);

    int rollnum, roll2, count = 0;
    cout << "Enter the roll number "
         << "of the student to display details: ";
    cin >> rollnum;

    vector<string> row;
    string line, word, temp;

    while (fin >> temp)
    {
        //cout<<temp<<endl;
        row.clear();
        line = temp;
        stringstream s(line);
        //cout<<"got before while\n";
        while (getline(s, word, ','))
        {
            //cout<<word;
            row.push_back(word);
        }

        roll2 = stoi(row[0]);

        if (roll2 == rollnum)
        {

            count = 1;
            cout << "Details of Roll " << row[0] << " : \n";
            cout << "Name: " << row[1] << "\n";
            cout << "Java: " << row[2] << "\n";
            cout << "C: " << row[3] << "\n";
            cout << "Python: " << row[4] << "\n";
            cout << "Javascript: " << row[5] << "\n";
            break;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void update_record()
{

    fstream fin, fout;

    fin.open("testing.csv", ios::in);

    fout.open("testingNew.csv", ios::out);

    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    cout << "Enter the roll number "
         << "of the record to be updated: ";
    cin >> rollnum;
    cout << "Enter the subject "
         << "to be updated(M/P/C/B): ";
    cin >> sub;

    if (sub == 'm' || sub == 'M')
        index = 2;
    else if (sub == 'p' || sub == 'P')
        index = 3;
    else if (sub == 'c' || sub == 'C')
        index = 4;
    else if (sub == 'b' || sub == 'B')
        index = 5;
    else
    {
        cout << "Wrong choice.Enter again\n";
        update_record();
    }

    cout << "Enter new marks: ";
    cin >> new_marks;

    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        roll1 = stoi(row[0]);
        int row_size = row.size();

        if (roll1 == rollnum)
        {
            count = 1;
            stringstream convert;

            convert << new_marks;

            row[index] = convert.str();

            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    fout << row[i] << ",";
                }

                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    fout << row[i] << ",";
                }

                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
        cout << "Record not found\n";

    fin.close();
    fout.close();
    remove("testing.csv");

    rename("testingNew.csv", "testing.csv");
}

void delete_record()
{
    fstream fin, fout;

    fin.open("testing.csv", ios::in);

    fout.open("testingNew.csv", ios::out);

    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    cout << "Enter the roll number "
         << "of the record to be deleted: ";
    cin >> rollnum;

    while (!fin.eof())
    {

        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        roll1 = stoi(row[0]);

        if (roll1 != rollnum)
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";

    // Close the pointers
    fin.close();
    fout.close();

    // removing the existing file
    remove("testing.csv");

    // renaming the new file with the existing file name
    rename("testingNew.csv", "testing.csv");
}
