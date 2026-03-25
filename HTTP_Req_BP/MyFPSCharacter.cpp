#include "AIService.h"

void AMyFPSCharacter::EvaluateCodeWithAI(const FString& Code)
{
    if (!AIService)
    {
        AIService = NewObject<UAIService>();
    }

    UE_LOG(LogTemp, Warning, TEXT("Sending code to AI..."));

    FOnAIResponse Callback;
    Callback.BindUFunction(this, "OnAIResponse");

    AIService->EvaluateCode(Code, Callback);
}

void AMyFPSCharacter::OnAIResponse(FString Response)
{
    UE_LOG(LogTemp, Warning, TEXT("AI Response: %s"), *Response);

    if (Response.Contains("correct"))
    {
        // 🏆 WIN
        ShowEndScreen(false);
    }
    else
    {
        // ❌ WRONG
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Wrong Answer"));
    }
}