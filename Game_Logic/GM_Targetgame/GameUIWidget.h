#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameUIWidget.generated.h"

UCLASS()
class YOURPROJECT_API UGameUIWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateScore(int32 Current, int32 Max);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateTime(int32 Time);

    UFUNCTION(BlueprintImplementableEvent)
    void ShowEndScreen(bool bLost);
};