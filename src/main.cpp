#include "dataStorage.hpp"

int main()
{
    /*Let the TESTS Begin!
    int teamSize = -1;
    Gene person1,person2,person3,person4;
    Chromosome test(1,4);
    Population testP(1,100,4);
    person1=readRecordAtIndexAndReturnGene(5);
    person2=readRecordAtIndexAndReturnGene(25);
    person3=readRecordAtIndexAndReturnGene(18);
    person4=readRecordAtIndexAndReturnGene(60);
    vector<Gene> genee(4);
    genee[0]=person1;
    genee[1]=person2;
    genee[2]=person3;
    genee[3]=person4;
    //cout<<genee[0].getName()<<endl;
    //cout<<genee[1].getName()<<" "<<genee[1].getExperienceBySkill(2)<<endl;
    test.setGenes(genee);
    cout<<test.getGeneAtIndex(3).getExperienceBySkill(1)<<endl;
    cout<<test.getFitnessVal()<<endl;
    test.fitnessFunction(rS);
    cout<<test.getFitnessVal()<<endl;
    cout<<testP.getID()<<endl;
    testP.addNewChromosome(test);
    cout<<testP.getChromosomeAtIndex(0).getFitnessVal();
    End Game for tests*/
    //Main Workflow
    int teamSize, populationSize, gen;
    //bool rS[]={true,true,true,true,true,true,true};
    string s[]={"C/C++","PHP","JavaScript","MySQL","Java","Python","HTML/CSS"};
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
    Population p(1, populationSize, teamSize);
    newTrain(p, gen, RequiredSkills);
    return 0;
}