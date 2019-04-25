#include<datastorage.hpp>
#include<vector>
using namespace std;

Gene::Gene()
{
}

Gene::Gene(Gene &G)
{
  this->gid = G.gid;
  this->name = G.name;
  copy( (G.experience).beign() , (G.experience).end , back_inserter(this->experience) ); 
  this->aptitude = G.aptitude;;
  this->emotionalQuotient = G.emotionalQuotient;
  this->socialQuotient = G.socialQuotient;
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
int Gene::getSQ();
{
  return socialQuotient;
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
