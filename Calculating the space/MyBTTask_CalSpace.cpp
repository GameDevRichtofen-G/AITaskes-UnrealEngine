
/*                      What is this ?? 
           I used this code to determine, whether ai
		   should run,walk or walk slowly base on the
		   distance of player from ai.


*/

#include "MyBTTask_CalSpace.h"
#include "AISystemController.h"
#include "AI.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_CalSpace::UMyBTTask_CalSpace(FObjectInitializer const& ObjectInitializer)
{
	//Name of the node
	NodeName = "Distance_CAL";
}

EBTNodeResult::Type UMyBTTask_CalSpace::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//getting the AI controller
	if (auto* const AICont = Cast<AAISystemController>(OwnerComp.GetAIOwner()))
	{
		//getting the BlackboardComponent
		if (auto* const bc = OwnerComp.GetBlackboardComponent())
		{
			//Getting the location of a player from blackboard key
			auto const CalLoc = bc->GetValueAsVector(SearchLoc.SelectedKeyName);

			//getting the ai itself
			if (auto* const AIself = Cast<AAI>(AICont->GetPawn()))
			{
				//calculating the distance between player and AI using UKismetMath::VectorDistance

				/* Above 1000 : Running fast
				*  less than 1000 and above 500 : walking
				*  less than 500 : walking slowly
				*/
				if (UKismetMathLibrary::Vector_Distance(AIself->GetActorLocation(), CalLoc) >= 1000)
				{
					AIself->DistanceFromOBJ = 1;
				}
				else if (UKismetMathLibrary::Vector_Distance(AIself->GetActorLocation(), CalLoc) < 1000 && UKismetMathLibrary::Vector_Distance(AIself->GetActorLocation(), CalLoc) >= 500)
				{
					AIself->DistanceFromOBJ = 0;
				}
				else if (UKismetMathLibrary::Vector_Distance(AIself->GetActorLocation(), CalLoc) < 500)
				{
					AIself->DistanceFromOBJ = 0.5;
				}
				

				//finishing the task with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
		
	}
	return EBTNodeResult::Failed;
}