#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightPanel.generated.h"

class URectLightComponent;
UCLASS()
class SPARTAUNREALCPP_H6_API ALightPanel : public AActor
{
	GENERATED_BODY()
	
public:	
	ALightPanel();


protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Components")
	USceneComponent* Scene;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	URectLightComponent* RectLight;
};
