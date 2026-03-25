#include "MyFPSCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"

AMyFPSCharacter::AMyFPSCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyFPSCharacter::BeginPlay()
{
    Super::BeginPlay();

    // 🎯 Add Input Mapping Context (this replaces your BP top section)
    if (APlayerController* PC = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
    }
}

void AMyFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // 🎮 Movement
        Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyFPSCharacter::Move);

        // 👁️ Look
        Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyFPSCharacter::Look);

        // 🦘 Jump
        Input->BindAction(JumpAction, ETriggerEvent::Started, this, &AMyFPSCharacter::StartJump);
        Input->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyFPSCharacter::StopJump);
    }
}

void AMyFPSCharacter::Move(const FInputActionValue& Value)
{
    FVector2D Input = Value.Get<FVector2D>();

    AddMovementInput(GetActorForwardVector(), Input.Y);
    AddMovementInput(GetActorRightVector(), Input.X);
}

void AMyFPSCharacter::Look(const FInputActionValue& Value)
{
    FVector2D Input = Value.Get<FVector2D>();

    AddControllerYawInput(Input.X);
    AddControllerPitchInput(Input.Y);
}

void AMyFPSCharacter::StartJump(const FInputActionValue& Value)
{
    Jump();
}

void AMyFPSCharacter::StopJump(const FInputActionValue& Value)
{
    StopJumping();
}