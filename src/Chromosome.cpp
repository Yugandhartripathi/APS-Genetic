#include "dataStorage.hpp"

Chromosome::Chromosome()
{
}

Chromosome::Chromosome(int id, int ts)
{
  cid = id;
  teamSize = ts;
  genes.reserve(teamSize);
  fitnessVal = -1;
}

int Chromosome::getCid()
{
  return cid;
}

int Chromosome::getTeamSize()
{
  return teamSize;
}

int Chromosome::getFitnessVal()
{
  return fitnessVal;
}

void Chromosome::setCid(int cid1)
{
  cid = cid1;
}

void Chromosome::setTeamSize(int teamSize1)
{
  teamSize = teamSize1;
}

void Chromosome::setGenes(vector<Gene> genes1)
{
  copy(genes1.begin(), genes1.end(), back_inserter(genes));
}

void Chromosome::setFitnessVal(int fitnessVal1)
{
  fitnessVal = fitnessVal1;
}

void Chromosome::setGeneAtIndex(int i, Gene X)
{
  genes[i] = X;
}

Gene Chromosome::getGeneAtIndex(int index)
{
  return genes[index];
}

void Chromosome::fitnessFunction(bool requiredSkill[7])
{

  int avgSQ = 0, avgEQ = 0, avgAptitude = 0, avgMatchingSkill = 0, avgNonMatchingSkill = 0;
  int match = 0, nonMatch = 0;
  vector<Gene>::iterator i;
  for (i = genes.begin(); i != genes.end(); ++i)
  {
    avgSQ += (*i).getSQ();
    avgEQ += (*i).getEQ();
    avgAptitude += (*i).getAptitude();
    for (int j = 0; j < 7; j++)
    {
      if (requiredSkill[j] == true)
      {
        avgMatchingSkill += (*i).getExperienceBySkill(j);
        match++;
      }
      else
      {
        avgNonMatchingSkill += (*i).getExperienceBySkill(j);
        nonMatch++;
      }
    }
  }
  cout<<avgSQ<<" "<<avgEQ<<endl;
  fitnessVal = avgSQ / teamSize + avgEQ / teamSize + avgAptitude / teamSize + avgMatchingSkill / match + 0.5 * avgNonMatchingSkill / nonMatch ;
}
