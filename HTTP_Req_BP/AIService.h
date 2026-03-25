#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "AIService.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAIResponse, FString, Response);

UCLASS()
class YOURPROJECT_API UAIService : public UObject
{
    GENERATED_BODY()

public:
    void EvaluateCode(const FString& Code, FOnAIResponse Callback);

private:
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

    FOnAIResponse ResponseCallback;
};