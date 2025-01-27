/*                      What is this ??
		   I used this code to search and find
		   the player location in navigable area
		                 near to it.


*/


#include "MyBTTask_FindPlayerLocation.h"
#include "GameFramework/Character.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UMyBTTask_FindPlayerLocation::UMyBTTask_FindPlayerLocation(FObjectInitializer const& ObjectInitializer)
{
	//setting up the node name
	NodeName = "Find Player LocationM";
}

EBTNodeResult::Type UMyBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//getting the player character location
	if (auto* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		//saving the player location in a vector variable
		auto const PlayerLocation = Player->GetActorLocation();

		//if SearchRandom was true then just look for player
		//if not give the ai the location of player without searching
		if (SearchRandom)
		{
			//setting up Navmesh area
			FNavLocation Loc;

			//getting navmeshsystem
			if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				//Search for a random location and Check if Navmeshsystem give true value for searching area near to player, 
				if (NavSys->GetRandomPointInNavigableRadius(PlayerLocation, SearchRa, Loc))
				{
					//passing the random location around player area
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),Loc.Location);
					FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
					return EBTNodeResult::Succeeded;
				}
			}
		}
		else
		{
			//passing the player location right away
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerLocation);
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}