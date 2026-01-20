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
	bIsMovable = true;
	StopbyTime = 3.0f;
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
		if (bIsOnGoing && (GetActorLocation() - StartLocation).Length() >= MaxRange)
		{
			bIsOnGoing = false;
			bIsMovable = false;
			GetWorldTimerManager().SetTimer(MoveDelayTimerHandle, this, &AMovingActor::RestartMove, StopbyTime);
		}
		else if (!bIsOnGoing &&(GetActorLocation() - StartLocation).Length() < MoveSpeed.Length() * DeltaTime)
		{
			bIsOnGoing = true;
			bIsMovable = false;
			GetWorldTimerManager().SetTimer(MoveDelayTimerHandle, this, &AMovingActor::RestartMove, StopbyTime);
		}
	}
}

void AMovingActor::RestartMove()
{
	bIsMovable = true;
}

void AMovingActor::SetMoveSpeed(FVector InSpeed)
{
	MoveSpeed = InSpeed;
}

void AMovingActor::SetMaxRange(float InRange)
{
	MaxRange = InRange;
}
