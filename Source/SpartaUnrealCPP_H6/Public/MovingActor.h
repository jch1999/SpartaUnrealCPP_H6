#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class SPARTAUNREALCPP_H6_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void RestartMove();
	void SetMoveSpeed(FVector InSpeed);
	void SetMaxRange(float InRange);
	
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Move")
	FVector MoveSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Move")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	bool bIsOnGoing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	bool bIsMovable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float StopbyTime;

	FTimerHandle MoveDelayTimerHandle;
};
