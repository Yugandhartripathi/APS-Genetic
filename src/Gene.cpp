#include "dataStorage.hpp"
#include <vector>
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
  switch(skillNo)
  {
    case 1: return e1;

    case 2: return e2;
        
    case 3: return e3;
        
    case 4: return e4;
        
    case 5: return e5;
        
    case 6: return e6;
        
    case 7: return e7;
  }
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
  switch(skillNo)
  {
    case 1: {
          e1 =val;
          break;        
          }            
    case 2: {
          e2 =val;
          break;        
        }
    case 3: {
          e3 =val;
          break;        
        }
    case 4: {
          e4 =val;
          break;        
        }
    case 5: {
          e5 =val;
          break;        
        }
    case 6: {
          e6 =val;
          break;        
        }
    case 7: {
          e7 =val;
          break;        
        }
  }
}
