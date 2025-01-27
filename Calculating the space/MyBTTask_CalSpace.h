// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_CalSpace.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTONA_API UMyBTTask_CalSpace : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:

	//creating class init function
	explicit UMyBTTask_CalSpace(FObjectInitializer const& ObjectInitializer);

	//creating nodee executetask function
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:

	//blackboard key for getting the player location
	UPROPERTY(EditAnywhere, Category = "PPathKeySelector")
		FBlackboardKeySelector SearchLoc;
};
