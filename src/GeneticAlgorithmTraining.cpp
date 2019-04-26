#include "dataStorage.hpp"
#include<iostream>

void train(Population p,int generations)
{
    p.populate();
    for(int i=0;i<generations;i++)
    {
        Population newP;
        Chromosome topFitness = p.fittestMember();
        //get topK fittest chromosomes write them in CSV for visualisations
        newP = p.crossOver();
        newP.mutation();
        //compute fitness values for newP
        //sort old and new population wrt fitness values descending
        //take top 20% of old population
        //take top 80% of new population
        if(topFitness.getFitnessVal<newP.fittestMember().getFitnessVal())
        {
            topFitness = newP.fittestMember();
        }
        p=newP;
        // Here we go again
    }
}