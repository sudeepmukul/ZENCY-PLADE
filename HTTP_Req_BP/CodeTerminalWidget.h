#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CodeTerminalWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCodeSubmitted, const FString&, Code);

UCLASS()
class YOURPROJECT_API UCodeTerminalWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // 🔥 Event Dispatcher
    UPROPERTY(BlueprintAssignable)
    FOnCodeSubmitted OnCodeSubmitted;

    UFUNCTION(BlueprintCallable)
    void SubmitCode(const FString& Code);
};