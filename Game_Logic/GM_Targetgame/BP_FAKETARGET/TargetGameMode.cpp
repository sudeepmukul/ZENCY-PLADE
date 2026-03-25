void ATargetGameMode::DecreaseScore(int32 Amount)
{
    CurrentScore -= Amount;
    CurrentScore = FMath::Clamp(CurrentScore, 0, MaxScore);

    UpdateUI();

    if (CurrentScore <= 0)
    {
        ShowEndScreen(true); // Lose
    }
}