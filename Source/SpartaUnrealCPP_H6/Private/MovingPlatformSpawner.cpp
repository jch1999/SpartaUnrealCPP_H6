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
	TSet<int32> CreatedIdx;
	for (int i = 0; i < MaxSpawnCnt; i++)
	{
		if (FMath::RandRange(0.0f, 100.0f) < SpawnRate)
		{
			int Idx = -1;
			while (Idx == -1)
			{
				Idx = FMath::RandRange(0, SpawnLocations.Num());
				if (CreatedIdx.Contains(Idx))
				{
					Idx = -1;
				}
			}
			FTransform Transform;
			Transform.SetLocation(SpawnLocations[Idx]);
			Transform.SetRotation(FRotator::ZeroRotator.Quaternion());
			Transform.SetScale3D(FVector(1));

			AMovingActor* MovingActor = GetWorld()->SpawnActorDeferred<AMovingActor>(SpawnActorClass, Transform);

			if (MovingActor)
			{
				FVector NewSpeed(MoveSpeeds[Idx] * FMath::RandRange(0.5f, 2.0f));
				MovingActor->SetMoveSpeed(NewSpeed);
				MovingActor->SetMaxRange(MaxRanges[Idx]);
				MovingActor->FinishSpawning(Transform);
			}
		}
	}
}
