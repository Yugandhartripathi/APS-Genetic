#include "dataStorage.hpp"

int main()
{
    //Let the TESTS Begin!
    int teamSize = -1;
    Gene person1,person2,person3,person4;
    Chromosome test(1,4);
    Population testP(1,100,4);
    //Main Workflow
    //int teamSize, populationSize, gen;
    //cin >> teamSize >> populationSize >> gen;
    //Population p(1, populationSize, teamSize);
    //train(p, gen);
    person1=readRecordAtIndexAndReturnGene(1);
    person2=readRecordAtIndexAndReturnGene(2);
    person3=readRecordAtIndexAndReturnGene(3);
    person4=readRecordAtIndexAndReturnGene(4);
    vector<Gene> genee(4);
    genee[0]=person1;
    genee[1]=person2;
    genee[2]=person3;
    genee[3]=person4;
    //cout<<genee[0].getName()<<endl;
    //cout<<genee[1].getName()<<" "<<genee[1].getExperienceBySkill(2)<<endl;
    test.setGenes(genee);
    cout<<test.getGeneAtIndex(3).getExperienceBySkill(1)<<endl;
    bool rS[]={true,false,true,false,false,false,false};
    cout<<test.getFitnessVal()<<endl;
    test.fitnessFunction(rS);
    cout<<test.getFitnessVal();
    return 0;
}