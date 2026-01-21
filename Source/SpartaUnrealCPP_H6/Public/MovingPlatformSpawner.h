#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformSpawner.generated.h"

class AMovingActor;

UCLASS()
class SPARTAUNREALCPP_H6_API AMovingPlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatformSpawner();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable,Category="Spawn")
	void SpawnRandomMovingPlatform();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawn")
	TArray<FVector> SpawnLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TArray<FVector> MoveSpeeds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TArray<float> MaxRanges;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	float SpawnRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 MaxSpawnCnt;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn")
	int32 CurrentSpawnCnt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<AMovingActor> SpawnActorClass;
};
