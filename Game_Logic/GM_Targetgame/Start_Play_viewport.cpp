#include "GameManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "EngineUtils.h"

void AGameManager::BeginPlay()
{
    Super::BeginPlay();

    // 🎮 Set Input Mode Game Only
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (PC)
    {
        PC->SetInputMode(FInputModeGameOnly());
        PC->bShowMouseCursor = false;
    }

    // 🎯 Count Targets → MaxScore
    TArray<AActor*> Targets;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), Targets);
    MaxScore = Targets.Num();

    // 🖥️ Create UI
    if (UIClass)
    {
        UIInstance = CreateWidget<UUserWidget>(PC, UIClass);
        if (UIInstance)
        {
            UIInstance->AddToViewport();
        }
    }

    UpdateUI();

    // ⏱️ Start Timer (looping like your blueprint)
    GetWorldTimerManager().SetTimer(
        TimerHandle,
        this,
        &AGameManager::DecreaseTime,
        0.1f,
        true
    );
}

void AGameManager::DecreaseTime()
{
    if (Time > 0)
    {
        Time--;

        UpdateUI();
    }
    else
    {
        ShowEndScreen(true); // Lost
        GetWorldTimerManager().ClearTimer(TimerHandle);
    }
}

void AGameManager::UpdateUI()
{
    UE_LOG(LogTemp, Warning, TEXT("Score: %d / %d | Time: %d"), CurrentScore, MaxScore, Time);

    // If you made custom widget:
    // Cast<UMyWidget>(UIInstance)->UpdateScore(CurrentScore, MaxScore);
    // Cast<UMyWidget>(UIInstance)->UpdateTime(Time);
}

void AGameManager::ShowEndScreen(bool bLostGame)
{
    UE_LOG(LogTemp, Error, TEXT("Game Ended: %s"), bLostGame ? TEXT("Lost") : TEXT("Won"));
}