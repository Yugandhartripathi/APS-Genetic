#include "dataStorage.hpp"

int main()
{
    //Let the TESTS Begin!
    int teamSize = -1;
    cout << "hello from main.cpp\n";
    printSec();
    Gene person1;
    Chromosome test;
    Population testP;
    person1.setGid(1);
    person1.setName("Yugandhar");
    person1.setAptitude(100);
    person1.setEQ(75);
    person1.setSQ(50);
    //cout << person1.getName() << "\n";
    //createCSV();reportcard
    //update_record();
    //read_record();
    //update_record();
    //read_record();
    //Endgame for TESTS

    //Main Workflow
    //int teamSize, populationSize, gen;
    //cin >> teamSize >> populationSize >> gen;
    //Population p(1, populationSize, teamSize);
    //train(p, gen);
    person1=readRecordAtIndexAndReturnGene(1);
    cout<<person1.getName()<<endl;
    return 0;
}