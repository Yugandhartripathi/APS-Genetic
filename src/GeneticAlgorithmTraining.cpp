#include "backBone.hpp"

void train(Population p, int generations, int reqSkill[7])
{
    p.populate();
    for(int i=0;i<p.getPopulationSize();i++)
    {
        cout<<"Chromosome : "<<i<<" ";
        for(int j=0;j<p.getTeamSize();j++)
        {
            cout<<p.getChromosomeAtIndex(i).getGeneAtIndex(j)<<" "<<Genealogy.at(p.getChromosomeAtIndex(i).getGeneAtIndex(j)).getName()<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < generations; i++)
    {
        Population newP;
        vector<Chromosome> topFitnessOld, topFitnessNew;
        //cout<<p.getChromosomeAtIndex(0).getGeneAtIndex(0).getName()<<endl;
        //get topK fittest chromosomes write them in CSV for visualisations
        newP = p.crossOver();
        cout<<"crossed\n";
        newP.mutation();
        /*
        for (int i = 0; i < newP.getPopulationSize(); i++)
        {
            newP.getChromosomeAtIndex(i).fitnessFunction(reqSkill);
        }
        for (int j = 0; j < p.getPopulationSize(); j++)
        {
            //cout<<"in old loop"<<j<<"\n";
            topFitnessOld.push_back(p.fittestMember());
            p.removeChromosomeWithCID(topFitnessOld[j].getCid());
        }
        for (int j = 0; j < newP.getPopulationSize(); j++)
        {
            topFitnessNew.push_back(newP.fittestMember());
            newP.removeChromosomeWithCID(topFitnessNew[j].getCid());
        }
        //sort old and new population wrt fitness values descending - done
        //take top 20% of old population
        int ranged = (int)(0.2 * p.getPopulationSize());
        for (int j = 0; j < ranged; j++)
        {
            newP.addNewChromosome(topFitnessOld[j]);
        }
        //80% of new
        for (int j = ranged; j < p.getPopulationSize(); j++)
        {
            newP.addNewChromosome(topFitnessNew[j - ranged]);
        }
        Chromosome topFitness;
        if (topFitnessOld[0].getFitnessVal() < topFitnessNew[0].getFitnessVal())
        {
            topFitness = newP.fittestMember();
        }
        p = newP;
        // Here we go again
        */
    }
}
/*
void newTrain(Population p, int generations, bool reqSkill[7])
{
    Gene randomGene;
    int checker[p.getTeamSize()];
    Chromosome optimumTeam(1, p.getTeamSize());
    for (int k = 0; k < generations; k++)
    {
        for (int i = 0; i < p.getPopulationSize(); i++)
        {
            Chromosome newOrder(i, p.getTeamSize());
            for (int j = 0; j < p.getTeamSize(); j++)
                checker[j] = -1;

            for (int j = 0; j < p.getTeamSize(); j++)
            {
            LabelA:
                int r = (rand() % 60) + 1;
                for (int l = 0; l < j; l++)
                    if (checker[l] == r)
                        goto LabelA;
                checker[j] = r;
                randomGene = readRecordAtIndexAndReturnGene(r);
                //cout<<"Got here";
                newOrder.setGeneAtIndex(j, randomGene);
            }
            newOrder.fitnessFunction(reqSkill);
            //for (int l = 0; l < p.getTeamSize(); l++)
                //cout << newOrder.getGeneAtIndex(l).getName() << " ";
            //cout << newOrder.getFitnessVal() << endl;
            if (newOrder.getFitnessVal() > optimumTeam.getFitnessVal())
            {
                optimumTeam = newOrder;
            }
        }
        if((k+1)%5==0)
        {
            cout<<"Fittest Team in Generation "<<k+1<<" => ";
            for (int i = 0; i < p.getTeamSize(); i++)
                cout << optimumTeam.getGeneAtIndex(i).getName() << " ";

            cout << optimumTeam.getFitnessVal() << endl;
        }
    }
    cout<<"Best Fit Team for the task : ";
    for (int i = 0; i < p.getTeamSize(); i++)
        cout << optimumTeam.getGeneAtIndex(i).getName() << " ";

    cout << optimumTeam.getFitnessVal() << endl;
}
*/