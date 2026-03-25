#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

    if (Input)
    {
        Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
        Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
        Input->BindAction(JumpAction, ETriggerEvent::Started, this, &AMyCharacter::StartJump);
        Input->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyCharacter::StopJump);
    }
}

void AMyCharacter::Move(const FVector2D& Value)
{
    AddMovementInput(GetActorForwardVector(), Value.Y);
    AddMovementInput(GetActorRightVector(), Value.X);
}

void AMyCharacter::Look(const FVector2D& Value)
{
    AddControllerYawInput(Value.X);
    AddControllerPitchInput(Value.Y);
}

void AMyCharacter::StartJump()
{
    Jump();
}

void AMyCharacter::StopJump()
{
    StopJumping();
}