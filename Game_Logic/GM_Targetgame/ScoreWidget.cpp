#include "ScoreManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

AScoreManager::AScoreManager()
{
}

void AScoreManager::BeginPlay()
{
    Super::BeginPlay();
}

void AScoreManager::ShowEndScreen(bool bLostGame)
{
    if (!EndScreenClass) return;

    // 🎯 Get Player Controller
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC) return;

    // 🎯 Create Widget
    UUserWidget* EndScreen = CreateWidget<UUserWidget>(PC, EndScreenClass);
    if (!EndScreen) return;

    // 🎯 Add to Viewport
    EndScreen->AddToViewport();

    // 🧠 OPTIONAL (ADVANCED - like your IsGameOver variable)
    // If you made a custom widget class, cast and set variable:
    /*
    UMyEndScreenWidget* MyWidget = Cast<UMyEndScreenWidget>(EndScreen);
    if (MyWidget)
    {
        MyWidget->bIsGameOver = bLostGame;
    }
    */

    // 🎮 Set Input Mode UI Only
    FInputModeUIOnly InputMode;
    InputMode.SetWidgetToFocus(EndScreen->TakeWidget());
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

    PC->SetInputMode(InputMode);

    // 🖱️ Show Cursor
    PC->bShowMouseCursor = true;

    // 🚫 Disable Movement
    PC->SetIgnoreMoveInput(true);
}