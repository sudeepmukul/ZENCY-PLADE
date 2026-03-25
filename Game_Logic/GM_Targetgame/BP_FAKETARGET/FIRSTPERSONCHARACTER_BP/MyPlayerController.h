#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

UCLASS()
class YOURPROJECT_API AMyPlayerController : public APlayerController
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

private:

    // 🖥️ Menu Widget Class
    UPROPERTY(EditAnywhere)
    TSubclassOf<class UUserWidget> MenuWidgetClass;

    // Instance
    UUserWidget* MenuWidget;
};