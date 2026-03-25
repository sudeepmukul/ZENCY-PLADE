void AMyFPSCharacter::EvaluateCode(const FString& Code)
{
    FString Expected = "print('hello')"; // example

    if (Code.Equals(Expected))
    {
        UE_LOG(LogTemp, Warning, TEXT("Correct Code!"));

        // 🧠 Example reward
        ATargetGameMode* GM = Cast<ATargetGameMode>(UGameplayStatics::GetGameMode(this));
        if (GM)
        {
            GM->AddScore();
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Wrong Code"));
    }
}