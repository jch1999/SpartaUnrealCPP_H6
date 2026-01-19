#include "LightPanel.h"
#include "Components/RectLightComponent.h"

ALightPanel::ALightPanel()
{
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	RectLight = CreateDefaultSubobject<URectLightComponent>(TEXT("RectLight"));
	RectLight->SetupAttachment(Scene);
}

