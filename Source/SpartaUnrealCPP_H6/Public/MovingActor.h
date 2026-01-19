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

	bool CheckContinue();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components")
	USceneComponent* Scene;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Move")
	FVector MoveSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Move")
	FVector StartLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Move")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	bool bIsOnGoing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	bool bIsMovable;
};
