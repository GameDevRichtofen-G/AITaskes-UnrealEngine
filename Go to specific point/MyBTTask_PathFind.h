// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_PathFind.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTONA_API UMyBTTask_PathFind : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	

public:
	//creating class init function
	explicit UMyBTTask_PathFind(FObjectInitializer const& ObjectInitializer);
	//creating nodee executetask function
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


protected:

	//Blackboard key variable, we use this for setting up the targetlocation(the location where AI must go)
	UPROPERTY(EditAnywhere, Category = "PPathKeySelector")
		FBlackboardKeySelector PPkey;
};
