#include "dataStorage.hpp"
#include<vector>
using namespace std;

Gene::Gene()
{

}

/*Gene::Gene(Gene &G)
{
  gid = G.gid;
  name = G.name;
  copy((G.experience).begin(), (G.experience).end(), back_inserter(experience)); 
  aptitude = G.aptitude;;
  emotionalQuotient = G.emotionalQuotient;
  socialQuotient = G.socialQuotient;
}*/

int Gene::getGid()
{
  return gid;
}

string Gene::getName()
{ 
  return name;
}

int Gene::getAptitude()
{
  return aptitude;
}

int Gene::getEQ()
{
  return emotionalQuotient;
}

int Gene::getSQ()
{
  return socialQuotient;
}

int Gene::getExperienceBySkill(int skillNo)
{
  return experience[skillNo];
}

bool Gene::checkAreaOfInterest(int domainNo)
{
  return areasOfInterest[domainNo];
}

void Gene::setGid(int gid)
{
  this->gid=gid;
}

void Gene::setName(string name)
{
  this->name=name;
}

void Gene::setAptitude(int aptitude)
{
  this->aptitude=aptitude;
}

void Gene::setEQ(int EQ)
{
  this->emotionalQuotient=EQ;
}

void Gene::setSQ(int SQ)
{
  this->socialQuotient=SQ;
}

void Gene::setExperienceBySkill(int skillNo,int val)
{
  experience[skillNo] = val;
}

void Gene::setAreaOfInterest(int domainNo,bool val)
{
  areasOfInterest[domainNo] = val;
}
