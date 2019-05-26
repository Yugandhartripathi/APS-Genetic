#include "backBone.hpp"

vector<Gene> Genealogy;
/*
Modifications required
void createCSV()
{
    fstream fout;
    int n;
    fout.open("processedDataOutput.csv", ios::out | ios::app);
    cout << "Enter number of entries: ";
    cin >> n;
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
*/
void readRecordsAndSaveGene()
{
    Genealogy.clear();
    fstream fin;
    fin.open("processedData.csv", ios::in);
    vector<string> row;
    string line,word,temp;
    int count=0;
    while(fin>>temp)
    {
        row.clear();
        Gene G;
        line=temp;
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        int eidR = stoi(row[0]);
        G.setGid(stoi(row[0]));
        G.setName(row[1]);
        G.setSQ(stoi(row[5]));
        G.setEQ(stoi(row[9]));
        G.setAptitude(stoi(row[13]));
        G.setExperienceBySkill(0,stoi(row[14])); //C++
        G.setExperienceBySkill(1,stoi(row[15])); //PHP
        G.setExperienceBySkill(2,stoi(row[16])); //JS
        G.setExperienceBySkill(3,stoi(row[17])); //SQL
        G.setExperienceBySkill(4,stoi(row[18])); //Java
        G.setExperienceBySkill(5,stoi(row[19])); //Python
        G.setExperienceBySkill(6,stoi(row[20])); //HTML/CSS
        G.setAreaOfInterestByDomain(0,stoi(row[21])); 
        G.setAreaOfInterestByDomain(1,stoi(row[22])); 
        G.setAreaOfInterestByDomain(2,stoi(row[23])); 
        G.setAreaOfInterestByDomain(3,stoi(row[24])); 
        G.setAreaOfInterestByDomain(4,stoi(row[25])); 
        G.setAreaOfInterestByDomain(5,stoi(row[26])); 
        Genealogy.push_back(G);
    }
}
