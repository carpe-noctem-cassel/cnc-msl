#ifndef DriveForward_H_
#define DriveForward_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1414840433813) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
class DriveForward : public DomainBehaviour
{
public:
  DriveForward();
  virtual ~DriveForward();
  virtual void run(void* msg);
  /*PROTECTED REGION ID(pub1414840433813) ENABLED START*/ //Add additional public methods here
  /*PROTECTED REGION END*/
protected:
  virtual void initialiseParameters();
  /*PROTECTED REGION ID(pro1414840433813) ENABLED START*/ //Add additional protected methods here
  /*PROTECTED REGION END*/
private:
  /*PROTECTED REGION ID(prv1414840433813) ENABLED START*/ //Add additional private methods here
  /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* DriveForward_H_ */
