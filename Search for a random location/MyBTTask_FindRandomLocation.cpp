/*                      What is this ??
		   I used this code to allow ai to search
		   for the random location in navigable 
							area


*/



#include "MyBTTask_FindRandomLocation.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AISystemController.h"

UMyBTTask_FindRandomLocation::UMyBTTask_FindRandomLocation(FObjectInitializer const& ObjectInitializer)
{
	//setting up node name
	NodeName = "Random Location";
}

EBTNodeResult::Type UMyBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	//getting the AI controller
	if (auto* const cont = Cast<AAISystemController>(OwnerComp.GetAIOwner()))
	{
		//getting the ai itself
		if (auto* const AISelf = cont->GetPawn())
		{
			//saving ai location in a variable
			auto const OriginFVector = AISelf->GetActorLocation();

			//getting Navmeshsystem
			if (auto* const NavSystem = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				//setting up Navmesh area
				FNavLocation Loc;
				//Search for a random location and Check if Navmeshsystem give true value for searching area near to player, 
				if (NavSystem->GetRandomPointInNavigableRadius(OriginFVector, 1500.0f,Loc))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Loc.Location);
				}
				//finish the task with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}
