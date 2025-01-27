/*                      What is this ??
		   I used this code to allow ai to 
						chase player.


*/


#include "MyBTTask_ChasingPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

UMyBTTask_ChasingPlayer::UMyBTTask_ChasingPlayer(FObjectInitializer const& ObjectInitializer)
{
	//giving the node name
	NodeName = "Chase Player";
}

EBTNodeResult::Type UMyBTTask_ChasingPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//getting the AI contoller
	if (auto* const cont = Cast<AAISystemController>(OwnerComp.GetAIOwner()))
	{
		//getting player location by a blackboard key
		auto const PlayerLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());

		//Using SimpleMoveTolocation to chase the player
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont, PlayerLocation);

		//finish the task with success
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;


}