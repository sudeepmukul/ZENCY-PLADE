#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MyFPSCharacter.generated.h"

UCLASS()
class YOURPROJECT_API AMyFPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMyFPSCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    // 🎮 Input Actions
    UPROPERTY(EditAnywhere, Category="Input")
    class UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditAnywhere, Category="Input")
    class UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, Category="Input")
    class UInputAction* LookAction;

    UPROPERTY(EditAnywhere, Category="Input")
    class UInputAction* JumpAction;

    // 🧠 Functions
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void StartJump(const FInputActionValue& Value);
    void StopJump(const FInputActionValue& Value);
};