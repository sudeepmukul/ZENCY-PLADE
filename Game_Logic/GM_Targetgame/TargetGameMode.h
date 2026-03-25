#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TargetGameMode.generated.h"

UCLASS()
class YOURPROJECT_API ATargetGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    void AddScore();
    void DecreaseTime();

private:
    int32 CurrentScore = 0;
    int32 MaxScore = 0;
    int32 Time = 60;

    FTimerHandle TimerHandle;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class UGameUIWidget> UIClass;

    UPROPERTY()
    UGameUIWidget* UI;

    void UpdateUI();
    void ShowEndScreen(bool bLost);
};