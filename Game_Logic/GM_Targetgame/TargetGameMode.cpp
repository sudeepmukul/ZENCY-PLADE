#include "TargetGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameUIWidget.h"
#include "TargetActor.h"

void ATargetGameMode::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

    if (PC)
    {
        PC->SetInputMode(FInputModeGameOnly());
        PC->bShowMouseCursor = false;
    }

    // 🎯 Count Targets
    TArray<AActor*> Targets;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetActor::StaticClass(), Targets);
    MaxScore = Targets.Num();

    // 🖥️ Create UI
    if (UIClass)
    {
        UI = CreateWidget<UGameUIWidget>(PC, UIClass);
        if (UI)
        {
            UI->AddToViewport();
        }
    }

    UpdateUI();

    // ⏱️ Timer loop
    GetWorldTimerManager().SetTimer(
        TimerHandle,
        this,
        &ATargetGameMode::DecreaseTime,
        1.0f,
        true
    );
}

void ATargetGameMode::AddScore()
{
    CurrentScore++;
    UpdateUI();

    if (CurrentScore >= MaxScore)
    {
        ShowEndScreen(false); // Win
    }
}

void ATargetGameMode::DecreaseTime()
{
    if (Time > 0)
    {
        Time--;
        UpdateUI();
    }
    else
    {
        ShowEndScreen(true); // Lose
        GetWorldTimerManager().ClearTimer(TimerHandle);
    }
}

void ATargetGameMode::UpdateUI()
{
    if (UI)
    {
        UI->UpdateScore(CurrentScore, MaxScore);
        UI->UpdateTime(Time);
    }
}

void ATargetGameMode::ShowEndScreen(bool bLost)
{
    if (UI)
    {
        UI->ShowEndScreen(bLost);
    }
}