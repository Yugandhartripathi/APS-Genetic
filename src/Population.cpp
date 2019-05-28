#include "backBone.hpp"

Population::Population()
{
  pid = 0;
  populationSize = 100;
  sizeOfEachTeam = 4;
  numOfEmployees = Genealogy.size();
  chromosomes.resize(populationSize);
}

Population::Population(int id, int ps, int ts)
{
  pid = id;
  populationSize = ps;
  sizeOfEachTeam = ts;
  numOfEmployees = Genealogy.size();
  chromosomes.resize(populationSize);
}

int Population::getID()
{
  return pid;
}

void Population::setID(int id)
{
  pid = id;
}

int Population::getPopulationSize()
{
  return populationSize;
}

void Population::setPopulationSize(int ps)
{
  populationSize = ps;
}

int Population::getTeamSize()
{
  return sizeOfEachTeam;
}

void Population::setTeamSize(int ts)
{
  sizeOfEachTeam = ts;
}

Chromosome Population::fittestMember()
{
  Chromosome fittest;
  vector<Chromosome>::iterator i;
  i = chromosomes.begin();
  fittest = (*i);
  for (; i != chromosomes.end(); ++i)
  {
    if ((*i).getFitnessVal() >= fittest.getFitnessVal())
    {
      fittest = (*i);
      fittest.setFitnessVal((*i).getFitnessVal());
    }
  }
  return fittest;
}

void Population::populate()
{ 
  srand(time(0));
  vector<int> r;
  int checker[sizeOfEachTeam];
  int random;
  for (int i = 0; i < populationSize; i++)
  {
    r.clear();
    for (int j = 0; j < sizeOfEachTeam; j++)   //Can improve complexity by using set
    {
      checker[j]=-1;
    }
    Chromosome newOrder(i, sizeOfEachTeam);
    for (int j = 0; j < sizeOfEachTeam; j++)
    { chooseGene: 
      random = rand() % (Genealogy.size());
      for (int l = 0; l < j; l++)
        if (checker[l] == random)    
          goto chooseGene;
      checker[j] = random;
      r.push_back(random);
    }
    newOrder.setGenes(r);
    chromosomes.at(i) = newOrder;
  }
}
void Population::mutation()
{
  for (int i = 0; i < populationSize; i++)
  {
    int loopR = rand() % 100;
    if (loopR < 50)
    {
      for (int j = 0; j < loopR; j++)
      {
        int r1 = rand() % populationSize;
        int r2 = rand() % sizeOfEachTeam;
        int r3 = rand() % sizeOfEachTeam;
        chromosomes[i].setGeneAtIndex(r2, chromosomes[r1].getGeneAtIndex(r3));
      }
    }
  }
}

void Population::randomResettingMutation()
{ 
  float mutationProb = 0.6;
  int checker[populationSize];
  for (int j = 0; j < populationSize; j++)   //Can improve complexity by using set
      checker[j]=-1;
  for(int i = 0; i < (mutationProb * populationSize); i++)
  {
    chooseRandomChromosome:
    int r = rand() % populationSize ; //Random Chromosome
    for (int j = 0; j < populationSize; j++)
      if(checker[j] == r)
        goto chooseRandomChromosome;
    
    checker[i] = r;
    int r1 = rand() % sizeOfEachTeam;  //Random Gene chosen to be mutated
    chooseRandomGene: 
    int r2 = rand() % (Genealogy.size());  //Random Gene value to be set after mutation
    for(int j = 0; j < sizeOfEachTeam; j++)
    {
      if(chromosomes[r].getGeneAtIndex(j) == r2)
       goto chooseRandomGene;
    } 
    chromosomes[r].setGeneAtIndex(r1,r2);
  }
}

//OX1 or order 1 crossover because it's the fastest and fulfills our need for uniqueness within chromosome
Population Population::crossOver()
{
  Population newPopulation(pid + 1, populationSize, sizeOfEachTeam);
  for (int i = 0; i < populationSize; i++)
  {
    vector<int> crossedGenes;
    crossedGenes.resize(sizeOfEachTeam);
    //cout<<"entered crossover\n";
    int r1 = rand() % sizeOfEachTeam;
    //int r2 = rand() % sizeOfEachTeam;
    int r2 = ( r1 + 3 ) % sizeOfEachTeam;
    if (r1 > r2)
    {
      //make a swap function in helperFunctions file for this
      int temp = r2;
      r2 = r1;
      r1 = temp;
    }

    //cout<<"\nIteration Number "<<i<<"r1 = "<<r1<<" r2 = "<<r2<<endl;
    for (int j = r1; j < r2; j++)
    {
      crossedGenes[j] = chromosomes[i].getGeneAtIndex(j);
      //cout<<Genealogy.at(chromosomes.at(i).getGeneAtIndex(j)).getName()<<endl;
    }
    //cout<<"copied section complete\n";
    int r = rand() % populationSize;
    int curr = r2;
    for (int j = r2; j < (sizeOfEachTeam + r2); j++)   //we can do better complexity wise here
    {
      bool found = false;
      int index = j % sizeOfEachTeam;
      for (int k = r1; k < r2; k++)
      { //cout<<"inside checker\n";
        if (chromosomes[r].getGeneAtIndex(index) == crossedGenes[k])
        {
          found = true;
        }
      }
      if (!found)
      { //cout<<"found"<<r1<<r2<<r<<curr<<"\n";
        crossedGenes[curr] = chromosomes[r].getGeneAtIndex(index);
        curr++;
        curr %= sizeOfEachTeam;
        //cout<<"notfound task done\n";
      }
      if(curr == r1)
        break;
    }
    Chromosome X(i, sizeOfEachTeam);
    /*for(int z=0;z<sizeOfEachTeam;z++)
    {
      X.setGeneAtIndex(z,crossedGenes[z]);
    }*/
    X.setGenes(crossedGenes);
    newPopulation.setChromosomeAtIndex(i,X);
  }
  return newPopulation;
}

vector<Chromosome> Population::getChromosomes()
{
  return chromosomes;
}

void Population::setChromosomes(const vector<Chromosome>& a)
{
  chromosomes=a;
}

Chromosome Population::getChromosomeAtIndex(int ind)
{
  return chromosomes.at(ind);
}

void Population::setChromosomeAtIndex(int index, Chromosome a)
{
  chromosomes.at(index)=a;
}

void Population::calculateFitness(const vector<int>& requiredSkills,const vector<int>& domains)
{
  for(int i = 0; i < populationSize; i++)
    chromosomes[i].fitnessFunction(requiredSkills,domains);
}

void Population::updateFitnessVal(int i,int val)
{ 
  chromosomes[i].setFitnessVal(val);
}
