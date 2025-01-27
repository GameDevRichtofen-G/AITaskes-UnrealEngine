// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "AISystemController.h"
#include "MyBTTask_ChasingPlayer.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTONA_API UMyBTTask_ChasingPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	//creating class init function
	explicit UMyBTTask_ChasingPlayer(FObjectInitializer const& ObjectInitializer);
	//creating nodee executetask function
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
