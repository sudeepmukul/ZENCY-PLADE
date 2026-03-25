#include "DecreaseLogic.h"

AYourClass::AYourClass()
{
    CurrentScore = 100;  // example
    MaxScore = 100;
    MinScore = 0;
}

void AYourClass::BeginPlay()
{
    Super::BeginPlay();
}

void AYourClass::DecreaseScore()
{
    // Equivalent to subtract node
    CurrentScore -= 1;

    // Clamp just in case (optional but smart)
    CurrentScore = FMath::Clamp(CurrentScore, MinScore, MaxScore);

    // Update UI (your "Update Score" node)
    UpdateScoreUI();

    // Branch condition (CurrentScore == MinScore)
    if (CurrentScore == MinScore)
    {
        ShowEndScreen(true); // Lost Game = true
    }
}

void AYourClass::UpdateScoreUI()
{
    // Equivalent to your Widget call
    UE_LOG(LogTemp, Warning, TEXT("Score Updated: %d / %d"), CurrentScore, MaxScore);

    // If you have a widget:
    // YourWidget->UpdateScore(CurrentScore, MaxScore);
}

void AYourClass::ShowEndScreen(bool bLostGame)
{
    if (bLostGame)
    {
        UE_LOG(LogTemp, Error, TEXT("Game Over!"));
    }

    // Example:
    // CreateWidget<UYourEndScreen>(GetWorld(), EndScreenClass)->AddToViewport();
}