#include "IncreaseLogic.h"

AYourClass::AYourClass()
{
    CurrentScore = 0;
    MaxScore = 100;
}

void AYourClass::BeginPlay()
{
    Super::BeginPlay();
}

void AYourClass::AddScore(int32 Amount)
{
    // Add like your blueprint "+"
    CurrentScore += Amount;

    // Clamp so it doesn't overflow
    CurrentScore = FMath::Clamp(CurrentScore, 0, MaxScore);

    // Update UI (your Update Score node)
    UpdateScoreUI();

    // Branch: CurrentScore == MaxScore
    if (CurrentScore == MaxScore)
    {
        ShowEndScreen(false); // LostGame = false → WIN
    }
}

void AYourClass::UpdateScoreUI()
{
    UE_LOG(LogTemp, Warning, TEXT("Score Updated: %d / %d"), CurrentScore, MaxScore);

    // Example if using widget:
    // YourWidget->UpdateScore(CurrentScore, MaxScore);
}

void AYourClass::ShowEndScreen(bool bLostGame)
{
    if (!bLostGame)
    {
        UE_LOG(LogTemp, Warning, TEXT("You Win!"));
    }

    // CreateWidget<UYourEndScreen>(GetWorld(), EndScreenClass)->AddToViewport();
}