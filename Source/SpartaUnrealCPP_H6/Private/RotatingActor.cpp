#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(Scene);

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

