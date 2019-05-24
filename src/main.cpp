#include "backBone.hpp"

int main()
{
    readRecordsAndSaveGene();
    cout<<Genealogy.size()<<endl;
    cout<<Genealogy.at(1).getName()<<endl;
    //Main Workflow
    //int teamSize, populationSize, gen;
    //bool rS[]={true,true,true,true,true,true,true};
    /*string s[]={"C/C++","PHP","JavaScript","MySQL","Java","Python","HTML/CSS"};
    bool RequiredSkills[7];
    cout<<"Enter Team Size for your project - ";
    cin >> teamSize;
    cout<<"Enter Genetic Population Size - ";
    cin >> populationSize;
    cout<<"Enter number of Generations - ";
    cin >> gen;
    cout<<"Enter 0 or 1 against the tech-skills relevant for the project \n";
    for(int i=0;i<7;i++)
    {
        int temp;
        cout<<s[i]<<" - ";
        cin>>temp;
        RequiredSkills[i]=(temp==0)?false:true;
    }
    */
    //Population p(1, populationSize, teamSize);
    //newTrain(p, gen, RequiredSkills);
    return 0;
}