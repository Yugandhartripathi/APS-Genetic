#include "backBone.hpp"
int main()
{
    srand(time(0));
    readRecordsAndSaveGene();
    /*cout<<Genealogy.size()<<endl;
    int ts=5;
    Chromosome C(1,ts);
    for(int i=0;i<ts;i++)
    {
        int r=rand()%Genealogy.size();
        cout<<Genealogy.at(r).getName()<<endl;
        C.setGeneAtIndex(i,r);
    }
    Chromosome C2;
    C2=C;
    for(int i=0;i<ts;i++)
    {
        cout<<Genealogy.at(C2.getGeneAtIndex(i)).getName()<<" ";
    }
    vector<int> rS={1,0,1,0,1,0,0};
    C2.fitnessFunction(rS);
    cout<<"\n"<<C2.getFitnessVal();
    cout<<endl;*/
    //Main Workflow
    int teamSize, populationSize, gen;
    int rs[]={1,0,1,0,1,0,1};
    int dom[]={1,0,0,0,1,1};
    vector<int> rS(rs,rs+7);
    vector<int> domains(dom,dom+6);
    populationSize=5;
    teamSize=5;
    gen=800;
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
        RequiredSkills[i]=temp;
    }*/
    Population p(1, populationSize, teamSize);
    train(p,gen,rS,domains);
    return 0;
}