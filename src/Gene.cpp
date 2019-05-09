#include "dataStorage.hpp"

Gene::Gene()
{
 for(int i=0;i<6;i++)
 {
   experience[i]=0;
   areasOfInterest[i]=false;
 } 
 experience[6]=0;
}
/*
Gene::Gene(const Gene &G)
{
  gid = G.gid;
  name = G.name;
  copy((G.experience).begin(), (G.experience).end(), back_inserter(experience)); 
  copy((G.areasOfInterest).begin(), (G.areasOfInterest).end(), back_inserter(areasOfInterest)); 
  aptitude = G.aptitude;
  emotionalQuotient = G.emotionalQuotient;
  socialQuotient = G.socialQuotient;
}

Gene & Gene::operator= (const Gene &G) 
{ 
  cout<<"assigncalled\n";
  gid = G.gid;
  name = G.name;
  cout<<"nameset\n";
  for(int i=0;i<7;i++)
  {
    experience[i]=G.experience[i];
  }
  for(int i=0;i<6;i++)
  {
    areasOfInterest[i]=G.areasOfInterest[i];
  }
  aptitude = G.aptitude;
  emotionalQuotient = G.emotionalQuotient;
  return *this; 
}
*/
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
  this->gid = gid;
}

void Gene::setName(string name)
{
  this->name = name;
}

void Gene::setAptitude(int aptitude)
{
  this->aptitude = aptitude;
}

void Gene::setEQ(int EQ)
{
  this->emotionalQuotient = EQ;
}

void Gene::setSQ(int SQ)
{
  this->socialQuotient = SQ;
}

void Gene::setExperienceBySkill(int skillNo, int val)
{
  experience[skillNo] = val;
}

void Gene::setAreaOfInterest(int domainNo, bool val)
{
  areasOfInterest[domainNo] = val;
}

void Gene::printInterest()
{
  for(int i=0;i<6;i++)
  {
    cout<<areasOfInterest[i]<<" ";
  }
  cout<<endl;
}

void Gene::printExp()
{
  for(int i=0;i<7;i++)
  {
    cout<<experience[i]<<" ";
  }
  cout<<endl;
}