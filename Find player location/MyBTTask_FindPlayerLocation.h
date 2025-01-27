// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_FindPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTONA_API UMyBTTask_FindPlayerLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	

public:
	//creating class init function
	explicit UMyBTTask_FindPlayerLocation(FObjectInitializer const& ObjectInitializer);
	//creating nodee executetask function
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	//determine, whether to search for player in near area
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vars")
		bool SearchRandom;

	//search radius
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vars")
		float SearchRa = 1500;
};
