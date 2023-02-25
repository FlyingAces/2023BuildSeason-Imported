#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ArmSubsystem.h"

// Uses inputs from controller to control the drivetrain
class MoveArmWithController
    : public frc2::CommandHelper<frc2::CommandBase, MoveArmWithController> {
 public:
  explicit MoveArmWithController(ArmSubsystem* p_Arm);
  
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
  ArmSubsystem* mp_Arm;
};