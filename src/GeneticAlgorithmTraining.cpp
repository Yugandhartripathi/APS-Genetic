#include "dataStorage.hpp"
#include <iostream>

void train(Population p, int generations,bool reqSkill[7])
{
    p.populate();
    cout<<"populated\n";
    for (int i = 0; i < generations; i++)
    {
        cout<<"in gen loop\n";
        Population newP;
        vector<Chromosome> topFitnessOld,topFitnessNew;
        cout<<p.getChromosomeAtIndex(0).getGeneAtIndex(0).getName()<<endl;
        //get topK fittest chromosomes write them in CSV for visualisations
        newP = p.crossOver();
        cout<<"crossed\n";
        newP.mutation();
        for(int i=0;i<newP.getPopulationSize();i++)
        {
            newP.getChromosomeAtIndex(i).fitnessFunction(reqSkill);
        }
        for(int j=0;j<p.getPopulationSize();j++)
        {
            //cout<<"in old loop"<<j<<"\n";
            topFitnessOld.push_back(p.fittestMember());
            p.removeChromosomeWithCID(topFitnessOld[j].getCid());
        }
        for(int j=0;j<newP.getPopulationSize();j++)
        {
            topFitnessNew.push_back(newP.fittestMember());
            newP.removeChromosomeWithCID(topFitnessNew[j].getCid());
        }
        //sort old and new population wrt fitness values descending - done
        //take top 20% of old population
        int ranged=(int)(0.2*p.getPopulationSize());
        for(int j=0;j<ranged;j++)
        {
            newP.addNewChromosome(topFitnessOld[j]);
        }
        //80% of new
        for(int j=ranged;j<p.getPopulationSize();j++)
        {
            newP.addNewChromosome(topFitnessNew[j-ranged]);
        }
        Chromosome topFitness;
        if (topFitnessOld[0].getFitnessVal() < topFitnessNew[0].getFitnessVal())
        {
            topFitness = newP.fittestMember();
        }
        p = newP;
        // Here we go again
    }
}