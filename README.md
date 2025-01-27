# AITaskes-UnrealEngine

## About
These are some of the useful AI task operations in UnrealEngine/C++

## How to start 
### `Create the class`
1.First create a C++ class in **C++ Classes** →  **Your Project** → **Right-Click** → **Click on New C++ class** → **Check show all class** → **Search for BBTASK-BlackboardBase**,  `DO NOT CHOOSE BLUEPRINT BASE VERSION`. 

### `Implementations`
Add these two function to the header file :
``` cpp
public:

	//creating class init function
	explicit UMyBTTask_NAME(FObjectInitializer const& ObjectInitializer);

	//creating node executetask function
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
```

in the cpp file implement them :

``` cpp
UMyBTTask_NAME::UMyBTTask_NAME(FObjectInitializer const& ObjectInitializer)
{
	  //Name of the node
	  NodeName = "Distance_CAL";
}

EBTNodeResult::Type UMyBTTask_CalSpace::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
}
```
## `MyBTTask_FindRandomLocation`
This class can be useful for searching a random location in navigable area

## `MyBTTask_ChasingPlayer`
This classs can be useful for chasing the player in navigable area

## `MyBTTask_CalSpace`

This class is useful for calculating the space between AI and player.
I used it to determine whether AI should run,walk or walk slowly during
the gameplay



## `MyBTTask_FindPlayerLocation`
This class can be useful giving the playerlocation to ai or just search the area around the player

## `MyBTTask_PathFind`
This class can be useful for moving AI to specefic point

##
