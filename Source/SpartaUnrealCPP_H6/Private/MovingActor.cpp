#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(Scene);

	StartLocation = FVector::ZeroVector;
	MoveSpeed = FVector::ZeroVector;
	bIsOnGoing = true;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bIsMovable)
	{
		SetActorLocation(GetActorLocation() + (bIsOnGoing ? MoveSpeed * DeltaTime : -MoveSpeed * DeltaTime));
		if ((GetActorLocation() - StartLocation).Length() >= MaxRange)
		{
			if (CheckContinue())
			{
				bIsOnGoing = false;
			}
		}
		else if (FMath::IsNearlyZero((GetActorLocation() - StartLocation).Length()))
		{
			if (CheckContinue())
			{
				bIsOnGoing = true;
			}
		}
	}
}

bool AMovingActor::CheckContinue()
{
	return false;
}
