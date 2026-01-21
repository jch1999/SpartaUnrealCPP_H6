#include "MovingPlatformSpawner.h"
#include "MovingActor.h"

AMovingPlatformSpawner::AMovingPlatformSpawner()
{
	SpawnRate = 0.0f;
	MaxSpawnCnt = 10;
	CurrentSpawnCnt = 0;

}

void AMovingPlatformSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnRandomMovingPlatform();
}

void AMovingPlatformSpawner::SpawnRandomMovingPlatform()
{
	for (int i = 0; i < MaxSpawnCnt; i++)
	{
		if (FMath::RandRange(0.0f, 100.0f) < SpawnRate)
		{
			FTransform Transform;
			Transform.SetLocation(SpawnLocations[i]);
			Transform.SetRotation(FRotator::ZeroRotator.Quaternion());
			Transform.SetScale3D(FVector(1));

			AMovingActor* MovingActor = GetWorld()->SpawnActorDeferred<AMovingActor>(SpawnActorClass, Transform);

			if (MovingActor)
			{
				FVector NewSpeed(MoveSpeeds[i] * FMath::RandRange(0.5f, 2.0f));
				MovingActor->SetMoveSpeed(NewSpeed);
				MovingActor->SetMaxRange(MaxRanges[i]);
				MovingActor->FinishSpawning(Transform);
			}
		}
	}
}
