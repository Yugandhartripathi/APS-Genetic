#include "backBone.hpp"

Gene::Gene()
{
  experience.resize(7);
  areasOfInterest.resize(6);
}

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
  return experience.at(skillNo);
}

int Gene::checkAreaOfInterest(int domainNo)
{
  return areasOfInterest.at(domainNo);
}

void Gene::setGid(int id)
{
  gid = id;
}

void Gene::setName(string n)
{
  name = n;
}

void Gene::setAptitude(int apt)
{
  aptitude = apt;
}

void Gene::setEQ(int EQ)
{
  emotionalQuotient = EQ;
}

void Gene::setSQ(int SQ)
{
  socialQuotient = SQ;
}

void Gene::setExperienceBySkill(int skillNo, int val)
{
  experience.at(skillNo)=val;
}

void Gene::setAreaOfInterestByDomain(int domainNo, int val)
{
  areasOfInterest.at(domainNo)=val;
}

vector<int> Gene::getExperience()
{
  return experience;
}

vector<int> Gene::getInterest()
{
  return areasOfInterest;
}

void Gene::setExperience(const vector<int>& a)
{
  experience=a;
}

void Gene::setInterest(const vector<int>& a)
{
  areasOfInterest=a;
}
