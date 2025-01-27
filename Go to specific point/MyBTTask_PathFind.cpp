/*                      What is this ??
		   I used this code to move ai to specific point


*/


#include "MyBTTask_PathFind.h"
#include "AISystemController.h"
#include "AI.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"



UMyBTTask_PathFind::UMyBTTask_PathFind(FObjectInitializer const& ObjectInitializer)
{
	//setting up the Node name
	NodeName = "Find PPath";
}

EBTNodeResult::Type UMyBTTask_PathFind::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//getting the ai controller
	if (auto* const AIcont = Cast<AAISystemController>(OwnerComp.GetAIOwner()))
	{
		//getting the blackboard
		if (auto* const bc = OwnerComp.GetBlackboardComponent())
		{
			//getting the index of the point I want ai to go
			//To give more information, in ai class there is 
			//a array that contains list of locations and we 
			//use this index to move ai to those locations
			auto const Indexs = bc->GetValueAsInt(GetSelectedBlackboardKey());


			//getting the ai itself
			if (auto* AIch = Cast<AAI>(AIcont->GetPawn()))
			{
				//getting the location of the point we want ai to go
				auto const Point = AIch->GetPatPath()->GetPPoint(Indexs);

				//making the location global(absolute) not relative
				auto const GlobalPoint = AIch->GetPatPath()->GetActorTransform().TransformPosition(Point);
				
				//passing the the location to selected blackboard key
				bc->SetValueAsVector(PPkey.SelectedKeyName, GlobalPoint);

				

				//Finish the task with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;


			}
		}
	}

	return EBTNodeResult::Failed;
}