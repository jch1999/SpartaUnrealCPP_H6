#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RotateSpeed = FRotator::ZeroRotator;
	bIsRotatable = true;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
		
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsRotatable)
	{
		AddActorLocalRotation(RotateSpeed * DeltaTime);
	}
}

